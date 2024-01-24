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

    const map < string, Noeud >& getArrayLinks();
    // Mode d'emploi :
    //

    bool addLink(string nodeName1, string nodeName2, bool cond = true);
    // Mode d'emploi :
    //

    const vector < Noeud > getMostConnected(int n) const;
    // Mode d'emploi :
    //


//-------------------------------------------- Constructeur - destructeur

    Graphe();
    // Mode d'emploi :
    // Constructeur de Graphe

    virtual ~Graphe();
    // Mode d'emploi :
    // Destructeur virtuel de Graphe
    

//------------------------------------------------------------------ PRIVE 
protected:

    //----------------------------------------------------- Attributs protégés

    map < string, Noeud > arrayLinks;
    unsigned int countNodes;
};

#endif // GRAPHE_H