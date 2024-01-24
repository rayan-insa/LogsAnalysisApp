/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Noeud.h"

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------- Constructeur - destructeur
Graphe::Graphe()
{
    #ifdef MAP
    	cout << "Appel au constructeur de <Graphe>" << endl;
	#endif
    countNodes = 0;
} //----- Fin du constructeur de Graphe

Graphe::~Graphe()
{
	#ifdef MAP
    	cout << "Appel au destructeur de <Graphe>" << endl;
	#endif
} //----- Fin du destructeur de Graphe

//----------------------------------------------------- Méthodes publiques
const map < string, Noeud > & Graphe::getArrayLinks() 
{
	return arrayLinks;
} //----- Fin de getArrayLinks

bool Graphe::addLink(string nodeName1, string nodeName2, bool cond)
{

	if(arrayLinks.count(nodeName2)!= 0)
	{
		arrayLinks[nodeName2].addLink(nodeName1,cond);
	}
	else
	{
		Noeud newNode = Noeud(nodeName2);
		newNode.addLink(nodeName1,cond);
		arrayLinks.emplace(nodeName2,newNode);
		countNodes++;
	}
	
	if(arrayLinks.count(nodeName1) == 0)
	{
		arrayLinks.emplace(nodeName1, Noeud(nodeName1));
		countNodes++;
	}
	return true;
} //----- Fin de ajouterLiens

const vector < Noeud > Graphe::getMostConnected(int n) const
{
	unsigned int returnNb = 0;
	if(n < 0 || (unsigned int)n > countNodes)
	{
		returnNb = countNodes;
	}
	else
	{
		returnNb = (unsigned int) n;
	}
	
	vector < Noeud > allDocs = vector < Noeud > (countNodes);
	unsigned int i = 0;
	for (map < string , Noeud > ::const_iterator it = arrayLinks.begin(); it != arrayLinks.end() ; ++ it )
	{
		allDocs[i] = it->second;
		i++;
	}
	vector < Noeud > selection = vector < Noeud> (returnNb);
	partial_sort_copy(allDocs.begin(), allDocs.end(), selection.begin() , selection.end(), // utilisation d'une fonction lambda
		[](const Noeud & docA, const Noeud & docB)
		{
			return (docA > docB);
		});
	return selection;
} //----- Fin de 