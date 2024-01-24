/*************************************************************************
                           Affichage  -  Manipule les sorties du programme
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Affichage> (fichier Affichage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <map>

//------------------------------------------------------ Include personnel
#include "Affichage.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


streamState Affichage::Open (string name, Modes mode )
{
	ifstream stream ( name , ios::in );
	if( stream && mode == Modes::ABORT )
	{
		stream.close();
		return streamState::ERR_WRITE;
	}
	if( stream )
	{
		stream.close();
	}
	//test  
	outputStream.open(name,ios::out|ios::trunc);
	if(!outputStream)
	{
		return streamState::ERR_OPEN;
	}
	fileName = name;
	return streamState::VALID;
}


bool Affichage::showGraph( const map < string , Noeud > & links )
{
	if(!outputStream)
	{
		return false;
	}
	outputStream << "digraph " <<  "{" << endl;
	//Ecriture des noeuds du graph
	for ( map <string , Noeud>::const_iterator it = links.cbegin() ; it !=  links.cend() ; it++ ) 
	{
		outputStream << "node" << it->second.getNodeNum() << " [label = \"" << it->first << "\"];" << endl;
	}
	//Parcours de la strcuture pour récupérer les liens entre noeuds
	for ( map <string , Noeud>::const_iterator it = links.cbegin() ; it !=  links.cend() ; it++ ) 
	{
		for ( map < string, int >::const_iterator itInterne = it->second.getLinks().cbegin() ; itInterne != it->second.getLinks().cend() ; itInterne++)
		{
			outputStream << "node" << links.at(itInterne->first).getNodeNum() << " -> node" << it->second.getNodeNum();
			outputStream << " [label=\"" << itInterne->second << "\"];" << endl;
		}
	}
	outputStream << "}"<< endl;
	return true;
}	



bool Affichage::showGraphLinks( const vector < Noeud > & graph )
{
	if(!outputStream)
	{
		return false;
	}
	outputStream << "digraph " << "{" <<endl;
	for( vector < Noeud > ::const_iterator it = graph.cbegin() ; it !=  graph.cend() ; it++ ) //parcours des noeuds du graph et ecriture
	{
		outputStream << "node" << it->getNodeNum() << " [label = \"" << it->getNodeName() << "\"];" << endl;
	}
	for( vector < Noeud > ::const_iterator itCible = graph.cbegin() ; itCible !=  graph.cend() ; itCible++ )
	{
		for( vector < Noeud > ::const_iterator itSource = graph.cbegin() ; itSource!=  graph.cend() ; itSource++ )
		{
			if(itCible->arcVal( itSource->getNodeName() ) != -1) //verification du lien entre les noeuds
			{
				outputStream << "node" << itSource->getNodeNum() << " -> node" << itCible->getNodeNum() << " [label=\"" << itCible->arcVal( itSource->getNodeName() ) << "\"];" << endl;
			}
		}
	}
	outputStream << "}"<< endl;
	return true;
}


void Affichage::Close()
{
	if (outputStream) outputStream.close();
}


void Affichage::showNodes( const vector < Noeud > & list )
{
	for ( unsigned int i = 0 ;i < list.size(); i ++ )
	{
		cout << list[i].getNodeName() << " (" << list[i].getCountLinks() << " hits)" << endl; 
	}
}


Affichage::Affichage ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Affichage>" << endl;
#endif
} //----- Fin de Affichage


Affichage::~Affichage ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Affichage>" << endl;
#endif
} //----- Fin de ~Affichage
