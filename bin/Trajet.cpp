/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Trajet::Afficher() const
{
	 cout << "de " <<depart << " à " << arrivee;
} //----- Fin de Afficher

bool Trajet::DepIs( const char * dep) const
{
	return strcmp(depart,dep)==0;
} // ----- Fin de DepIs

bool Trajet::ArrIs( const char * arr) const
{
	return strcmp(arrivee,arr)==0;
} //----- Fin de ArrIs

char* Trajet::GetArrivee() const
{
	return arrivee;
} //----- Fin de GetArrivee
char* Trajet::GetDepart() const
{
	return depart;
} //----- Fin de GetDepart


//------------------------------------------------- Surcharge d'opérateurs

bool Trajet::operator > (const Trajet & unTrajet ) const
{
// Algorithme : 
// Comparaison des départs dans l'ordre lexicographique. 
// Si les départs sont les mêmes, comparaison des arrivées

	int compareDep=strcmp(depart,unTrajet.depart);
	if (compareDep==0)
		return strcmp(arrivee,unTrajet.arrivee)>0;
	else
		return compareDep>0;
} // ----- Fin de operator >

bool Trajet::operator == (const Trajet & unTrajet ) const
{
	return strcmp(depart,unTrajet.depart)==0 && strcmp(arrivee, unTrajet.arrivee)==0;
} // ----- Fin de operator ==

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ( const char* unDepart,const char* uneArrivee )
// Algorithme :
// Copie les chaînes en paramètre dans départ et arrivée
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
	depart=new char[strlen(unDepart)+1];
	arrivee=new char[strlen(uneArrivee)+1];
	strcpy(depart,unDepart);
	strcpy(arrivee,uneArrivee);
} //----- Fin de Trajet


Trajet::~Trajet ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
	delete[] depart;
	delete[] arrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

