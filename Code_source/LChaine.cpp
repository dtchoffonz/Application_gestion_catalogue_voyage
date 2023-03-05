/*************************************************************************
                           LChaine  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LChainee> (fichier LChaine.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LChaine.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Maillon* LChaine::GetTete() const
{
	return tete;
}

void LChaine::AjouterEnQueue( Trajet * unTrajet)
{
// Algorithme :
//  Parcours la liste jusqu'au dernier maillon et modifie sont suivant.

	if (tete==nullptr)
	{
		tete=new Maillon(unTrajet);
	}
	else
	{
		Maillon* curseur=tete; // Le curseur est un pointeur qui parcours la liste.
		while (curseur->GetSuivant()!=nullptr)
		{
			curseur=curseur->GetSuivant();
		}
		curseur->SetSuivant(new Maillon(unTrajet));
	}
} //----- Fin de AjouterEnQueue

void LChaine::Afficher(char sep) const
{
	if (tete!=nullptr)
	{
		tete->Afficher(sep); // Affiche la tête et les maillons suivants.
	}
} //----- Fin de Afficher

bool LChaine::Rechercher( const char * dep, const char * arr ) const
{
// Algorithme :
//  Parcours la liste jusqu'a la fin en affichant les trajets correspondants.

	Trajet unTrajet(dep,arr);
	bool trouve=false;
	Maillon* curseur=tete;
	
	while (curseur!=nullptr)
	{
		if (unTrajet == *curseur->GetElem())
		{
			trouve=true;
			curseur->GetElem()->Afficher();
			cout << endl;
		}
		curseur=curseur->GetSuivant();
	}
	return trouve;
} //----- Fin de Rechercher

bool LChaine::RechercheAvancee( const char * dep,const char * arr ) const
{
// Algorithme :
//  On créé une pile vide puis on appelle la fonction récursive.

	Pile p;
	return rechercheRec(dep,arr,p);
} //----- Fin de RechercheAvancee

void LChaine::AjouterOrdonne( Trajet * unTrajet )
{
// Algorithme :
//  Parcours la liste jusqu'à ce que unTrajet soit "<" à l'élément.

	Maillon * curseur=tete;
	if (tete==nullptr) // Cas particulier de la liste vide
	{
		tete=new Maillon(unTrajet);
	}
	else if (*tete->GetElem() > *unTrajet) // Cas où le trajet doit être ajouté en tête.
	{
		tete=new Maillon(unTrajet);
		tete->SetSuivant(curseur);
	}
	else
	{
		while (curseur->GetSuivant()!=nullptr && *unTrajet > *(curseur->GetSuivant()->GetElem()))
		{
			curseur=curseur->GetSuivant();
		}
		// Ici, curseur pointe vers la case qui précède celle où le nouvel élément doit
		// être inséré.
		Maillon * nouveau=new Maillon(unTrajet);
		nouveau->SetSuivant(curseur->GetSuivant()); 
		curseur->SetSuivant(nouveau);
	}
} //----- Fin de AjouteOrdonne

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


LChaine::LChaine ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <LChaine>" << endl;
#endif
	tete=nullptr;
} //----- Fin de LChaine


LChaine::~LChaine ( )
// Algorithme :
//  Parcours la liste pour supprimer chaque maillon.
{
#ifdef MAP
    cout << "Appel au destructeur de <LChaine>" << endl;
#endif
	Maillon * curseur;
	while (tete!=nullptr)
	{
		delete tete->GetElem();
		curseur=tete;
		tete=tete->GetSuivant();
		delete curseur;
	}
		
} //----- Fin de ~LChaine


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool LChaine::rechercheRec(const char * dep,const char* arr,Pile & p) const
{
// Algorithme :
//  On fait un parcours en profondeur :
//  On empile le premier trajet dont le départ match avec dep, on recherche 
//  récursivement à partir de son arrivée.
//  Quand arr match aussi, on affiche le contenue de la pile et on dépile.

	Maillon* curseur=tete;
	bool trouve=false;
	while (curseur!=nullptr) // Parcours de la liste
	{
		if (curseur->GetElem()->DepIs(dep))
		{
			if (curseur->GetElem()->ArrIs(arr))
			{
				// Le départ et l'arrivée matchent => on empile, 
				// on affiche tout et on dépile
				p.Empiler(curseur->GetElem());
				trouve=true;
				p.Afficher();
				p.Depiler();
				cout << endl;
			}
			else
			{
				// On s'assure que la pile ne contient pas déjà un élément dont le départ est 
				// le même que l'arrivée de l'élément pointé par curseur afin d'éviter
				// les boucles infinies (appel récursif avec les mêmes paramètres).
				if (!p.Contient(curseur->GetElem())) 
				{
					p.Empiler(curseur->GetElem());
					trouve = rechercheRec(curseur->GetElem()->GetArrivee(),arr,p) || trouve;
					p.Depiler();
				}
			}
		}
		curseur=curseur->GetSuivant();
	}
	return trouve;
} //----- Fin de rechercherRec

