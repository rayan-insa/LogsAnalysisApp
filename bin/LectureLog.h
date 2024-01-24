/*************************************************************************
                           LectureLog  -  Récuperation des log
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan
*************************************************************************/

//---------- Interface de la classe <LectureLog> --
#if ! defined (LECTURE_LOG_H)
#define LECTURE_LOG_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

//--------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//structure Date
typedef struct {
    unsigned int timeSlotHour;
    unsigned int timeSlotMinute;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int year;
    unsigned int month;
    unsigned int day;
    bool difference;
} Date;


//structure Log
typedef struct {
    Date date;
    string clientIP;
    string username;
    string usernameAuth;
    string actionType;
    string URL;
    string docType;
    int status;
    int dataQuantity;
    string referer;
    string clientNav;
} Log;


// Rôle de la classe <LectureLog>
//
//
//------------------------------------------------------------------------

class LectureLog
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    bool openFile(string fileName);
    // Mode d'emploi :
    // Permet d'ouvrir le fichier de log entré en paramètre. Retourne si l'ouverture s'est bien effectuée.

    bool nextLog();
    // Mode d'emploi :
    // Entre dans current les informations concernant le log, renvoie faux si le log est vide, vrai sinon.

    Log getLog();
    // Mode d'emploi :
    // Renvoie le log actuel (current)

    string separate(string& line, string separator);
    // Mode d'emploi :
    // Permet de séparer la chaîne de caractères jusqu'au separateur



//-------------------------------------------- Constructeurs - destructeur

    LectureLog();
    // Mode d'emploi :
    // Constructeur de la classe LectureLog

    virtual ~LectureLog();
    // Mode d'emploi :
    // Destructeur virtuel de la classe LectureLog

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés 
    Log current;
    ifstream file;
};

#endif //LectureLog_H