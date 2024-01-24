/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <map>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Noeud.h"

//----------------------------------------------------------------- PUBLIC
unsigned int Noeud::countNodes = 0;
//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud ()
{
	#ifdef MAP
        cout << "Appel au constructeur de <Noeud>" << endl;
    #endif
    nodeName = "INCONNU";
	countLinks = 0;
    nodeNum = countNodes;
    countNodes++;
    links = map < string, int>();
}//----- Fin du constructeur de Noeud

Noeud::Noeud (string nodeName)
{
	#ifdef MAP
        cout << "Appel au constructeur de <Noeud>" << endl;
    #endif
    this->nodeName = nodeName;
	countLinks = 0;
    nodeNum = Noeud::countNodes; 
    Noeud::countNodes++;
}//----- Fin du constructeur de Noeud

Noeud::~Noeud()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Noeud>" << endl;
    #endif
}//----- Fin du destructeur de Noeud

unsigned int Noeud::getCountLinks() const
{
	return countLinks;
} //----- Fin de getCountLinks

const map < string, int > & Noeud::getLinks() const
{
    return links;
} //----- Fin de getLinks

const string Noeud::getNodeName() const
{
    return nodeName;
} //----- Fin de getNodeName

unsigned int Noeud::getNodeNum() const
{
    return nodeNum;
} //----- Fin de getNodeNum

void Noeud::addLink(string nodeName, bool cond)
{
    if(cond)
    {
        if(links.count(nodeName)!= 0)
        {
            links[nodeName]++;
        }
        else
        {
            links.emplace(nodeName,1);
        }
    }

	countLinks++;
} //----- Fin de addLink

int Noeud::ArcVal(string doc) const
{
    int val = -1;
    if(links.count(doc) != 0 )
    {
        val = links.at(doc);
    }
    return val;
} //----- Fin de ArcVal

//------------------------------------------------- Surcharge d'opérateur
bool Noeud::operator > (const Noeud & newNode) const
{
    bool compare;
    if(newNode.getCountLinks() != countLinks)
    {
    	compare = (countLinks > newNode.getCountLinks());
    }
    else
    {
    	compare = (nodeName > newNode.getNodeName());
    }
    return compare;
} //----- Fin de la surcharge de operator >