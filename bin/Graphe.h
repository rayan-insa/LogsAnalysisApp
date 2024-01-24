/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.h) --
#if ! defined (GRAPHE_H)
#define GRAPHE_H

#include <vector>
#include <map>
using namespace std;
#include "Noeud.h"

class Graphe
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
//-------------------------------------------- Constructeur - destructeur
    Graphe();

    virtual ~Graphe();
    const map < string , Noeud > & getArrayLinks();

    bool addLink(string nodeName1,string nodeName2,bool cond = true);

    const vector < Noeud > getMostConnected(int n) const;

//------------------------------------------------------------------ PRIVE 
//----------------------------------------------------- Attributs protégés
protected:

    map < string, Noeud > arrayLinks;
    unsigned int countNodes;
};

#endif // GRAPHE_H