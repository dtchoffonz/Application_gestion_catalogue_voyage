/*************************************************************************
                           TrajetC  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetC> (fichier TrajetC.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetC.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetC::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetC::Afficher() const
{
// Algorithme :
//  On affiche les sections de trajet séparés par des -
	liste.Afficher('-');
} //----- Fin de Afficher

void TrajetC::Ajouter(Trajet * unTrajet)
{
	liste.AjouterEnQueue(unTrajet);
} //----- Fin de Ajouter

Maillon* TrajetC::GetTete() const{
	return liste.GetTete();
}
void TrajetC::SetArrivee(const char* arr)
{
	delete[] arrivee;
	arrivee=new char[strlen(arr)+1];
	strcpy(arrivee,arr);
} //----- Fin de SetArrivee

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


TrajetC::TrajetC (const char * unDepart) : Trajet(unDepart,"")
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetC>" << endl;
#endif
} //----- Fin de TrajetC


TrajetC::~TrajetC ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetC>" << endl;
#endif
} //----- Fin de ~TrajetC


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

