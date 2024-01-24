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
unsigned int Noeud::CountNodes = 0;
//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud ()
{
	#ifdef MAP
        cout << "Appel au constructeur de <Noeud>" << endl;
    #endif
    NodeName = "INCONNU";
	countLinks = 0;
    NodeNum = CountNodes;
    CountNodes++;
    links = map < string, int>();
}//----- Fin du constructeur de Noeud

Noeud::Noeud (string NodeName)
{
	#ifdef MAP
        cout << "Appel au constructeur de <Noeud>" << endl;
    #endif
    this->NodeName = NodeName;
	countLinks = 0;
    NodeNum = Noeud::CountNodes; 
    Noeud::CountNodes++;
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
} //----- Fin de getNombreliens

const map < string, int > & Noeud::getLinks() const
{
    return links;
} //----- Fin de getliens

const string Noeud::getNodeName() const
{
    return NodeName;
} //----- Fin de getNodeName

unsigned int Noeud::getNodeNum() const
{
    return NodeNum;
} //----- Fin de getNodeNum

void Noeud::addLink(string NodeName, bool cond)
{
    if(cond)
    {
        if(links.count(NodeName)!= 0)
        {
            links[NodeName]++;
        }
        else
        {
            links.emplace(NodeName,1);
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
    	compare = (NodeName > newNode.getNodeName());
    }
    return compare;
} //----- Fin de la surcharge de operator >