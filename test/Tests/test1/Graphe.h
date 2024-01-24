/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2023 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Implémentation de la classe <Graphe> (fichier Graphe.h) --
#if ! defined (GRAPHE_H)
#define GRAPHE_H

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
    const map < string, Noeud > & getArrayLinks();

    bool addLien(string NoeudName, string nomNode, bool condition = true);

    const vector < Noeud > getNoeudsPlusConnectes(int n) const;

//------------------------------------------------------------------ PRIVATE 
//----------------------------------------------------- Attributs protégés
protected:
    map < string, Noeud > tableLiens;
    unsigned int nombreNoeuds;
};

#endif // GRAPHE_H