/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Interface du module <Analog> (fichier Analog.h) ----------------
#if ! defined ( ANALOG_H )
#define ANALOG_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

#include "LectureLog.h"

//------------------------------------------------------------------ Types définis
typedef struct Parametres
{
    string strParametre;
    unsigned int intParametre;
} Parametres;

int main( int argc, char** argv );
// Mode d'emploi : 
// Appelé à l'éxécution du programme
// Contrat : 

//-----------------------------------------------------------Fontions définies

int convertHeure (string heure);

bool checkNombre (string nombre);

bool checkHeure (Log & LogaEssayer , Parametres param);
    
bool verifModes(Log LogaEssayer,vector < bool (*)(Log & ,Parametres) > & tests, vector < Parametres > & refr);

bool castExtensions (Log & LogaEssayer , Parametres param);

bool choixSurEcritureFichier ();




#endif // Analog_H

