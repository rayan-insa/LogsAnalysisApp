/*************************************************************************
                           LectureLog  -  Récuperation des log
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2024 by Chikhi Djalil & Thabet Yasmine
                            & Cavagna Justine  & Hanader Rayan
*************************************************************************/


//---------- Réalisation de la classe <LectureLog> (fichier LectureLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "LectureLog.h"

const string LOC_REFERER = "http://intranet-if.insa-lyon.fr";

const string months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };


bool LectureLog::openFile(string fileName) // Ouverture du fichier
// Algorithme : 
{
    file.open(fileName, ios::in);
    if (file) {
        return true;
    }
    return false;
}//---------Fin de openFile

bool LectureLog::nextLog() // Lecture des informations du log et écriture dans current
//Algorithme : 
{
    string line;
    getline(file, line);
    if (line.size() == 0)
    {
        return false;
    }
    current.clientIP = separate(line, " ");
    current.username = separate(line, " ");
    current.usernameAuth = separate(line, " ");
    current.date.day = stoi(separate(line, "/").substr(1));
    string month = separate(line, "/");
    int monthIndex = 0;
    while (monthIndex < 12 && months[monthIndex] != month) 
    { 
        monthIndex++; 
    }
    current.date.month = monthIndex + 1;
    current.date.year = stoi(separate(line, ":"));
    current.date.hour = stoi(separate(line, ":"));
    current.date.minute = stoi(separate(line, ":"));
    current.date.second = stoi(separate(line, " "));
    string offset = separate(line, "]");
    current.date.difference = (offset[0] == '+');
    current.date.timeSlotHour = stoi(offset.substr(1, 2));
    current.date.timeSlotMinute = stoi(offset.substr(3, 2));
    separate(line, "\"");
    current.actionType = separate(line, " ");
    current.URL = separate(line, " ");
    separate(line, "\" ");
    current.docType = current.URL.substr(current.URL.find_last_of(".") + 1);
    current.status = stoi(separate(line, " "));

    bool isDigit = true;
    string data = separate(line, " \"");
    for (int i = 0; i < data.size() && isDigit; i++) {
        isDigit = isdigit(data[i]);
    }
    if (isDigit) {
        current.dataQuantity = stoi(data);
    }
    else {
        current.dataQuantity = -1;
    }
    string ref = separate(line, "\"");

    if (ref.substr(0, LOC_REFERER.size()) == LOC_REFERER)
    {
        ref = ref.substr(LOC_REFERER.size(), ref.size() - LOC_REFERER.size());
    }
    current.referer = ref;
    separate(line, "\"");
    current.clientNav = separate(line, "\"");
    return true;
}//---------Fin de nextLog


Log LectureLog::getLog() // Renvoie current qui contient toutes les informations du log
// Algorithme :
{
    return current;
}//---------Fin de getLog


string LectureLog::separate(string& line, string separator)
// Algorithme : 
{
    int index = line.find(separator);
    string start = line.substr(0, index);
    line = line.substr(index + separator.size());
    return start;
} //---------Fin de separate



//-------------------------------------------- Constructeurs - destructeur

LectureLog::LectureLog() // Constructeur de LectureLog
//Algorithme : 
{
#ifdef MAP
    cout << "Appel au constructeur de <LectureLog>" << endl;
#endif
} //----- Fin de LectureLog


LectureLog::~LectureLog() // Destructeur de LectureLog
// Algorithme : 
{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~LectureLog

