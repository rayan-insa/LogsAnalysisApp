/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.h) --
#if ! defined (NOEUD_H)
#define NOEUD_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <map>
using namespace std;


//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
//
//
//------------------------------------------------------------------------

class Noeud
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    unsigned int getCountLinks() const;
    // Mode d'emploi :
    //

    unsigned int getNodeNum() const;
    // Mode d'emploi :
    //

    const map < string, int >& getLinks() const;
    // Mode d'emploi :
    //

    const string getNodeName() const;
    // Mode d'emploi :
    //

    void addLink(string referer, bool cond);
    // Mode d'emploi :
    //

    int arcVal(string doc) const;
    // Mode d'emploi :
    //



//-------------------------------------------- Constructeurs - destructeur
    Noeud();
    // Mode d'emploi :
    // Constructeur de Noeud
    
    Noeud(string nodeName);
    // Mode d'emploi :
    // Constructeur de Noeud

    virtual ~Noeud();
    // Mode d'emploi :
    // Destructeur de Noeud
    
//------------------------------------------------- Surcharge d'opérateur
    bool operator > (const Noeud & newNode) const;
    // Mode d'emploi :
    // surcharge de l'opérateur >


    
//------------------------------------------------------------------ PRIVE 
protected:
    //----------------------------------------------------- Attributs protégés

    string nodeName;
    unsigned int nodeNum;
    unsigned int countLinks;
    map < string, int> links;
    static unsigned int countNodes;

};

#endif // NOEUD_H