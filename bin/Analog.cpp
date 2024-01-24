/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation du module <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Analog.h"
#include "Noeud.h"
#include "Graphe.h"
#include "LectureLog.h"
#include "Affichage.h"

using namespace std;

//------------------------------------------------------------- Constantes
#define DEFAUT  10;
//----------------------------------------------------------------- PUBLIC

//---------------------------	-------------------------- Méthodes publiques

int main( int argc, char ** argv)
{
	
	bool argsOK = true; 
	vector < bool (*)(Log & ,Parametres) > options;
	vector < Parametres > parametresFonctions;
	bool dessinerGraphe = false;
	string nomGraphe;
	bool presenceLog = false;
	string nomLog;
	bool choixFait = false;
	int nbChoix = DEFAUT;
	//bool forceDemande = false; //dqkedaed
	for ( int i = 1 ; i < argc && argsOK ; i++ )
	{
		string argCourant = argv[ i ] ;
		if( strlen( argv[i] ) < 1 ) 
		{
			argsOK = false;
		}
		if( argCourant == "-g" )
		{
			if( i == argc -1 )
			{
				argsOK = false;
				cerr << "Erreur : Paramètre non valide pour l'option -g" << endl;
			}
			else
			{
				nomGraphe = argv [ i+1 ];
				dessinerGraphe = true;
				i++;
			}
		}
		else if( argCourant == "-t" )
		{
			if( i == argc -1 )
			{
				argsOK = false;
				cerr << "Erreur : Paramètre non valide pour l'option -t " << endl;
			}
			else
			{
				int heureDebut = convertHeure(argv[ i + 1 ] );
				if( heureDebut == -1)
				{
					argsOK = false;
					cerr << "Erreur : Paramètre non valide pour l'option -t " << endl;
				}
				else
				{
					//creer un pointeur de fonction vers la selection Horaire, la ref, les ajouter dans les vector
					Parametres parametresHeure = {};
					parametresHeure.intParametre = heureDebut ;
					parametresFonctions.push_back(parametresHeure);
					options.push_back(&checkHeure);
					i++;
				}
			}
		}
		else if( argCourant == "-e")
		{
			parametresFonctions.push_back({});
			options.push_back(&castExtensions);
		}

		else if (argCourant.size()>4 && argCourant.substr(argCourant.size() - 4) == ".log")
		{
			presenceLog = true;
			nomLog = argCourant;
		}
		else
		{
			cerr << "L'option  "<< argv[i] <<" n'est pas définie " << endl;
			argsOK = false; 
		}
	}

	if(!presenceLog && argsOK)
	{
		cerr << "Erreur : pas de log présent" << endl;
		argsOK = false;
	}
	if(!argsOK)
	{
		cerr << "Erreur d'execution : l'option n'est pas reconnue"<< endl;
		return 1;
	}


	LectureLog curseur; //curseur pour lire les logs
	if(!curseur.OuvrirFichier(nomLog))
	{
		cerr << "Erreur : Impossible d'ouvrir le log" << endl;
		return 1;
	}
	//On construit le graphe
	Graphe monGraphe;
	bool deb = true;
	bool empty = true;
	while( curseur.LogSuivant() )
	{
		Log log = curseur.GetLog();
		if( verifModes( log, options, parametresFonctions ) )
		{
			empty = false;
			monGraphe.ajouterLien( log.referer, log.URL , dessinerGraphe ) ;
		}
		deb = false;
	}
	if(deb || empty )
	{
		cerr << "Erreur : Le log spécifié est empty" << endl;
		return 1;
	}
	if( dessinerGraphe ) // On écrit le graphe dans le fichier spécifique
	{
		Affichage graphique;
		fluxEtat etat = graphique.Open( nomGraphe );
		
		if( etat == ERR_wr )
		{
			cout<< "Erreur."<<endl;
		}
		if( etat == ERR_open)
		{
			cerr << "Erreur : Erreur d'écriture dans le fichier" << endl;
			return 1;
		}
		else if( etat == VALIDE )
		{
			if(!choixFait)
			{
				graphique.AfficherGraphe( monGraphe.getTableauLiens() );
			}
			else 
			{
				graphique.AfficherLiensGraphe( monGraphe.getPlusConnectes ( nbChoix ) );
			}
			
			graphique.Close();
		}
	}
	else
	{
		Affichage maListe;
		maListe.AfficherNoeuds( monGraphe.getPlusConnectes ( nbChoix ) );
	}
	return 0;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool castExtensions( Log & LogaEssayer , Parametres param)
{
	static unsigned int nbExtensions = 8;
	static string exclues[] = {"jpg","js","png","ico","jpeg","gif","css","tiff",};
	for(unsigned int i = 0 ; i < nbExtensions ; i++ )
	{
		if(LogaEssayer.typeDoc == exclues[i]) return false;
	}
	return true;
}

int convertHeure(string heure)
{
  for( unsigned int i = 0 ; i < heure.size() ; i++)
    {
  	if( !isdigit( heure[i] ) ) //Verification du format
    {
      return -1;
    }
  }
  int Heure = stoi (heure) ; //Conversion sans risques
  if( Heure < 0 or Heure > 23 ) //Verification de la cohérence avant retour
  {
    return -1;
  }
  return Heure;
}

bool checkNombre( string nombre )
{
	for(unsigned int i = 0 ; i < nombre.size() ; i++)
  {
		if( !isdigit( nombre[i] ) )
		{
			return false;
		}
  }
	return true;
}

bool checkHeure ( Log & LogaEssayer , Parametres param)
{
	return (LogaEssayer.date.heure == param.intParametre);
}

bool choixSurEcritureFichier()
{
  cout << "Le fichier est déjà existant. Voulez-vous écrire dessus ?" << endl;
  cout << "Répondez par \"Oui\" ou par \"Non\" "<<endl;
  string choix = "";
  cin >> choix;
  if(choix=="Oui")
  {
  	return true;
  }
  return false;
}

bool verifModes( Log LogaEssayer,vector < bool (*)(Log & ,Parametres) > & tests, vector < Parametres > & refr)
{
	for (unsigned int i = 0 ; i < tests.size() ; i++ )
	{
		if(!tests[i](LogaEssayer, refr[ i ] ) )
		{
			return false;
		}
	}
	return true;
}