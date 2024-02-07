/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Analog.h"
#include "Noeud.h"
#include "Graphe.h"
#include "LectureLog.h"
#include "Affichage.h"

using namespace std;

//------------------------------------------------------------- Constantes
#define DEFAULT  10;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int main( int argc, char ** argv)
// Algorithme :
//
{
	
	bool argsOK = true; 
	vector < bool (*)(Log & ,Parameters) > options;
	vector < Parameters > functionsParameters;
	bool drawGraph = false;
	string graphName;
	bool logPresence = false;
	string logName;
	bool argG = false;
	bool choiceMade = false;
	int choiceNb = DEFAULT;

	for ( int i = 1 ; i < argc && argsOK ; i++ )
	{
		string currentArg = argv[ i ] ;
		if( strlen( argv[i] ) < 1 ) 
		{
			argsOK = false;
		}
		if( currentArg == "-g" )
		{
			if( i == argc -1 )
			{
				argsOK = false;
				cerr << "Erreur : Paramètre non valide pour l'option -g" << endl;
			}
			else
			{
				graphName = argv [ i+1 ];
				drawGraph = true;
				i++;
				argG = true;
			}
		}
		else if( currentArg == "-t" )
		{
			if( i == argc -1 )
			{
				argsOK = false;
				cerr << "Erreur : Paramètre non valide pour l'option -t " << endl;
			}
			else
			{
				int startHour = hourConvert(argv[ i + 1 ] );
				if( startHour == -1)
				{
					argsOK = false;
					cerr << "Erreur : Paramètre non valide pour l'option -t " << endl;
				}
				else
				{
					//creer un pointeur de fonction vers la selection Horaire, la ref, les ajouter dans les vector
					Parameters hourParameters = {};
					hourParameters.intParameter = startHour ;
					functionsParameters.push_back(hourParameters);
					options.push_back(&hourCheck);
					i++;
				}
			}
		}
		else if( currentArg == "-e")
		{
			functionsParameters.push_back({});
			options.push_back(&castExtensions);
		}

		else if (currentArg.size()>4 && currentArg.substr(currentArg.size() - 4) == ".log")
		{
			logPresence = true;
			logName = currentArg;
		}
		else
		{
			cerr << "L'option  "<< argv[i] <<" n'est pas définie " << endl;
			argsOK = false; 
		}
	}

	if(!logPresence && argsOK)
	{
		cerr << "Erreur : pas de log présent" << endl;
		argsOK = false;
		return 1;
	}
	if(!argsOK)
	{
		cerr << "Erreur d'execution : l'option n'est pas reconnue"<< endl;
		return 1;
	}


	LectureLog curseur; //curseur pour lire les logs
	if(!curseur.openFile(logName))
	{
		cerr << "Erreur : Impossible d'ouvrir le log" << endl;
		return 1;
	}
	//On construit le graphe
	Graphe myGraph;
	bool deb = true;
	bool empty = true;
	while( curseur.nextLog() )
	{
		Log log = curseur.getLog();
		if( modesCheck( log, options, functionsParameters ) )
		{
			empty = false;
			myGraph.addLink( log.referer, log.URL , drawGraph ) ;
		}
		deb = false;
	}
	if(deb)
	{
		cerr << "Erreur : Le log spécifié est vide" << endl;
		return 1;
	}
	if (empty) {
		cerr << "Pas de pages correspondantes" << endl;
		return 1;
	}
	if( drawGraph ) // On écrit le graphe dans le fichier spécifique
	{
		Affichage graphic;
		//streamState etat = graphic.Open(graphName);
		// Si on veut activer l'écriture dans un fichier .dot qui existe déjà :
		streamState etat = graphic.Open(graphName,FORCE);
		
		if( etat == ERR_WRITE )
		{
			cout<< "Erreur."<<endl;
		}
		if( etat == ERR_OPEN)
		{
			cerr << "Erreur : Erreur d'écriture dans le fichier" << endl;
			return 1;
		}
		else if( etat == VALID )
		{
			if(!choiceMade)
			{
				graphic.showGraph( myGraph.getArrayLinks() );
			}
			else 
			{
				graphic.showGraphLinks( myGraph.getMostConnected ( choiceNb ) );
			}
			cout << "Dot-file " << graphName << " generated." << endl;
			graphic.Close();
		}
	}
	    vector<bool(*)(Log&, Parameters)>::iterator findt = find(options.begin(), options.end(), &hourCheck);
		vector<bool(*)(Log&, Parameters)>::iterator finde = find(options.begin(), options.end(), &castExtensions);
	if ((findt!=options.end()) || (finde!=options.end()) || (options.empty() && !argG))
	{
		Affichage myList;
		myList.showNodes( myGraph.getMostConnected ( choiceNb ) );
	}
	return 0;
} //----- Fin de main

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool castExtensions( Log & logToTry , Parameters param)
//Algorithme :
//
{
	static unsigned int extensionsNb = 8;
	static string excluded[] = {"jpg","js","png","ico","jpeg","gif","css","tiff",};
	for(unsigned int i = 0 ; i < extensionsNb ; i++ )
	{
		if(logToTry.docType == excluded[i]) return false;
	}
	return true;
} //----- Fin de castExtensions

int hourConvert(string hour)
// Algorithme :
//
{
  for( unsigned int i = 0 ; i < hour.size() ; i++)
    {
  	if( !isdigit( hour[i] ) ) //Verification du format
    {
      return -1;
    }
  }
  int Hour = stoi (hour) ; //Conversion sans risques
  if( Hour < 0 or Hour > 23 ) //Verification de la cohérence avant retour
  {
    return -1;
  }
  return Hour;
} //----- Fin de hourConvert

bool CheckNumber( string nb )
// Algorithme :
//
{
	for(unsigned int i = 0 ; i < nb.size() ; i++)
  {
		if( !isdigit( nb[i] ) )
		{
			return false;
		}
  }
	return true;
} //----- Fin de CheckNumber

bool hourCheck ( Log & logToTry , Parameters param)
// Algorithme :
//
{
	return (logToTry.date.hour == param.intParameter);
} //----- Fin de hourCheck

bool choiceOnFileWrite()
// Algorithme :
//
{
  cout << "Le fichier est déjà existant. Voulez-vous écrire dessus ?" << endl;
  cout << "Répondez par \"Oui\" ou par \"Non\" "<<endl;
  string choice = "";
  cin >> choice;
  if(choice=="Oui")
  {
  	return true;
  }
  return false;
} //----- Fin de choiceOnFileWrite

bool modesCheck( Log logToTry,vector < bool (*)(Log & ,Parameters) > & tests, vector < Parameters > & refr)
// Algorithme :
//
{

	for (unsigned int i = 0 ; i < tests.size() ; i++ )
	{
		if(!tests[i](logToTry, refr[ i ] ) )
		{
			return false;
		}
	}
	return true;
} //----- Fin de modesCheck