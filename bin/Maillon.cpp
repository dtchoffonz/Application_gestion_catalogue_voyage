/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Maillon> (fichier Maillon.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Maillon.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Maillon::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Maillon::SetSuivant(Maillon * unMaillon)
{
	suivant=unMaillon;
}//----- Fin de SetSuivant

Maillon* Maillon::GetSuivant() const
{
	return suivant;
}//----- Fin de GetSuivant

Trajet* Maillon::GetElem() const
{
	return elem;
}//----- Fin de GetElem

void Maillon::Afficher(char sep) const
{
// Algorithme :
//  Affiche le trajet que contient le maillon, un séparateur,
//  puis le maillon suivant est affiché
	elem->Afficher();
	
	if (suivant!=nullptr)
	{
		cout << sep;
		suivant->Afficher(sep);
	}
}//----- Fin de Afficher

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


Maillon::Maillon ( Trajet * unTrajet)
{
#ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
#endif
	suivant=nullptr;
	elem = unTrajet;
} //----- Fin de Maillon


Maillon::~Maillon ( )
// Algorithme :
//  Les pointeurs ne sont pas détruits, c'est la classe LChaine qui fait cela.
{
#ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
#endif
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

