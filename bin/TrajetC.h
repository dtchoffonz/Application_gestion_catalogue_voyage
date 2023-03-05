/*************************************************************************
                           TrajetC  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetC> (fichier TrajetC.h) ----------------
#if ! defined ( TRAJETC_H )
#define TRAJETC_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "LChaine.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetC>
// Un TrajetC ou trajet "composé" est un trajet qui est composé de plusieurs 
// trajets
//------------------------------------------------------------------------

class TrajetC : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Afficher() const;
    // Mode d'emploi :
    //  Affichage d'un trajet composé
    
    void Ajouter(Trajet * unTrajet);
    // Mode d'emploi :
    //  Ajout d'une section de trajet dans e trajet actuel.
    // Contrat :
    //  Le départ de unTrajet doit être l'arrivée de précédent.
    
    void SetArrivee(const char *arr);
    // Mode d'emploi :
    //  arr est l'arrivée du trajet
    // Contrat :
    //  arr doit être l'arrrivée du dernier trajet ajouté.
    Maillon* GetTete() const;


//------------------------------------------------- Surcharge d'opérateurs
    TrajetC & operator = ( const TrajetC & unTrajetC );
    // Mode d'emploi :
    //  Fonction non définie


//-------------------------------------------- Constructeurs - destructeur
    TrajetC ( const TrajetC & unTrajetC );
    // Mode d'emploi (constructeur de copie) :
    //  Fonction non définie

    TrajetC ( const char *unDepart );
    // Mode d'emploi :
    //  Construction d'un trajet composé dont on ne connaît que le départ.
    

    virtual ~TrajetC ( );
    // Mode d'emploi :
    //  Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	LChaine liste;

};

//-------------------------------- Autres définitions dépendantes de <TrajetC>

#endif // TRAJETC_H

