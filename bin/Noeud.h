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

#include <string>
#include <map>
using namespace std;

class Noeud
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
//-------------------------------------------- Constructeurs - destructeur
    Noeud();
    
    Noeud(string NodeName);

    virtual ~Noeud();
    unsigned int getCountLinks() const;

    unsigned int getNodeNum() const;

    const map < string, int > & getLinks() const;

    const string getNodeName() const;

    void addLink(string referer, bool cond);
    
    int ArcVal(string doc) const;
//------------------------------------------------- Surcharge d'opérateur
    bool operator > (const Noeud & newNode) const;
    
//------------------------------------------------------------------ PRIVE 
//----------------------------------------------------- Attributs protégés
protected:
    string NodeName;
    unsigned int NodeNum;
    unsigned int countLinks;
    map < string, int> links;
    static unsigned int CountNodes;

};

#endif // NOEUD_H