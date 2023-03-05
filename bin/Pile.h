/*************************************************************************
                           Pile  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Pile> (fichier Pile.h) ----------------
#if ! defined ( PILE_H )
#define PILE_H

//--------------------------------------------------- Interfaces utilisées
#include "Maillon.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Pile>
//  Une Pile est une collection de trajets :
//  On peut empiler ou dépiler ses éléments qui sont des Maillons.
//------------------------------------------------------------------------

class Pile
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Empiler( Trajet* unTrajet );
    // Mode d'emploi :
    //  Rajout de unTrajet "au dessus" de la pile.
    // Contrat : 
    //  unTrajet ne doit pas être un pointeur null.
    
	void Afficher() const;
    // Mode d'emploi :
    //  Affiche la pile dans l'ordre d'arrivée des éléments
    
	void Depiler();
    // Mode d'emploi :
    //  On enlève l'élément au dessus de la pile
    
	bool Contient(Trajet * unTrajet)const;
    // Mode d'emploi :
    //  Renvoie true si la pile contient un trajet dont le départ est
    //  celui de l'arrivée de unTrajet.
    


//------------------------------------------------- Surcharge d'opérateurs
    Pile & operator = ( const Pile & unPile );
    // Mode d'emploi :
    //  Fonction non définie


//-------------------------------------------- Constructeurs - destructeur
    Pile ( const Pile & unPile );
    // Mode d'emploi (constructeur de copie) :
    //  Fonction non définie

    Pile ( );
    // Mode d'emploi :
    //  Construction d'une pile vide

    virtual ~Pile ( );
    // Mode d'emploi :
    //  Destructin d'une pile et de son contenu

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Maillon* tete;
	Maillon* fin;
};

//-------------------------------- Autres définitions dépendantes de <Pile>

#endif // PILE_H

