/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( MAILLION_H )
#define MAILLION_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maillon>
//  Un Maillon est une "case" où l'on stocke tout type de trajet, et qui pointe 
//  vers une "case" suivante.
//------------------------------------------------------------------------

class Maillon
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    void SetSuivant( Maillon * unMaillon);
    // Mode d'emploi :
    //  unMaillon sera le nouveau suivant de l'instance appelante.
    // Contrat :
    //  L'élément "elem" de unMaillon ne doit pas être null.
    
    Maillon* GetSuivant() const;
    // Mode d'emploi :
    //  Renvoie le maillon suivant
    
    Trajet* GetElem() const;
    // Mode d'emploi :
    //  Renvoie l'élément que contient le maillon
    
    void Afficher(char sep) const;
    // Mode d'emploi :
    //  sep est un séparateur pour l'affichage (ex : '-', '\n')


//------------------------------------------------- Surcharge d'opérateurs
    Maillon & operator = ( const Maillon & unMaillon );
    // Mode d'emploi :
    //  Fonction non définie

//-------------------------------------------- Constructeurs - destructeur
    Maillon ( const Maillon & unMaillon );
    // Mode d'emploi (constructeur de copie) :
    //  Fonction non définie

    Maillon ( Trajet * unTrajet );
    // Mode d'emploi : 
    //  unTrajet est l'élément que l'on veut mettre dans le maillon.

    virtual ~Maillon ( );
    // Mode d'emploi :
    //  Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Maillon* suivant;
	Trajet* elem;

};

//-------------------------------- Autres définitions dépendantes de <Maillon>

#endif // MAILLION_H

