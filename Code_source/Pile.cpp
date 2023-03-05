/*************************************************************************
                           Pile  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Pile> (fichier Pile.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Pile.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Pile::Empiler( Trajet* unTrajet )
{
// Algorithme :
//  Ajoute unTrajet à la fin de la pile

	if (fin==nullptr)
	{
		fin= new Maillon( unTrajet ); 
		tete=fin;
	}
	else
	{
		Maillon* nouveau=new Maillon( unTrajet );
		fin->SetSuivant(nouveau);
		fin=nouveau;
	}
} //----- Fin de Empiler

void Pile::Afficher() const
{
// Algorithme :
//  Affiche les éléments à partir de la tête
	Maillon * curseur=tete;
	if (curseur==nullptr)
		return;
	curseur->GetElem()->Afficher();
	curseur=curseur->GetSuivant();
	while (curseur!=nullptr)
	{
		cout << " || ";
		curseur->GetElem()->Afficher();
		curseur=curseur->GetSuivant();
	}
} //----- Fin de Afficher

void Pile::Depiler()
{
// Algorithme :
//  Enlève le dernier élément de la pile. et reparcours pour replacer la fin
	if (tete!=nullptr)
	{
		if(tete==fin) // Cas de la pile avec un élément
		{
			delete fin;
			fin=nullptr;
			tete=nullptr;
		}
		else
		{
			Maillon* curseur=tete;
			while (curseur->GetSuivant()!=fin)
				curseur=curseur->GetSuivant();
			// curseur est le pointeur vers l'avant dernier élément.
			delete curseur->GetSuivant();
			curseur->SetSuivant(nullptr);
			fin=curseur;
		}
	}
} //----- Fin de Depiler

bool Pile::Contient(Trajet * unTrajet) const
{
// Algorithme :
//  Parcours la liste et renvoie true dès qu'un départ est le même que
//  l'arrivée de unTrajet.
	Maillon * curseur=tete;
	while (curseur!=nullptr)
	{
		if (curseur->GetElem()->DepIs(unTrajet->GetArrivee()))
			return true;
		curseur=curseur->GetSuivant();
	}
	return false;
} //----- Fin de Contient


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


Pile::Pile ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Pile>" << endl;
#endif
	tete=nullptr;
	fin=nullptr;
} //----- Fin de Pile


Pile::~Pile ( )
// Algorithme :
//  Parcours de la pile et suppression de chaque maillon
{
#ifdef MAP
    cout << "Appel au destructeur de <Pile>" << endl;
#endif
	Maillon* curseur;
	while (tete!=nullptr)
	{
		curseur=tete;
		tete=tete->GetSuivant();
		delete curseur;
	}
} //----- Fin de ~Pile


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

