/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Interface de la classe <Analog> (fichier Analog.h) ----------------
#if ! defined ( ANALOG_H )
#define ANALOG_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

#include "LectureLog.h"

//------------------------------------------------------------------ Types
typedef struct Parameters
{
    string strParameter;
    unsigned int intParameter;
} Parameters;


//------------------------------------------------------------------------
// Rôle de la classe <Analog>
//
//
//------------------------------------------------------------------------

//----------------------------------------------------- Méthodes publiques

int main( int argc, char** argv );
// Mode d'emploi : 
// Appelé à l'éxécution du programme
// Contrat : 

//-----------------------------------------------------------Fontions définies

int hourConvert (string hour);

bool CheckNumber (string nb);

bool hourCheck (Log & logToTry , Parameters param);
    
bool modesCheck(Log logToTry,vector < bool (*)(Log & ,Parameters) > & tests, vector < Parameters > & refr);

bool castExtensions (Log & logToTry , Parameters param);

bool choiceOnFileWrite ();




#endif // Analog_H

