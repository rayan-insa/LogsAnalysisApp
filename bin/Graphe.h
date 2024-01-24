/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 15/01/2021
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
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
    const map < string, Noeud > & getTableauLiens();

    bool addLien(string nomNoeud1, string nomNoeud2, bool condition = true);

    const vector < Noeud > getNoeudsPlusConnectes(int n) const;

//------------------------------------------------------------------ PRIVATE 
//----------------------------------------------------- Attributs protégés
protected:
    map < string, Noeud > tableLiens;
    unsigned int countNodes;
};

#endif // GRAPHE_H