/*************************************************************************
                           LChaine  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LChaine> (fichier LChaine.h) ----------------
#if ! defined ( LChaine_H )
#define LChaine_H

//--------------------------------------------------- Interfaces utilisées
#include "Maillon.h"
#include "Pile.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LChaine>
//  Une LChaine est une classe gestionnaire de liste chainée contenant des
//  trajets de tout type.
//------------------------------------------------------------------------

class LChaine
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	Maillon* GetTete() const;
    
    void AjouterEnQueue( Trajet * unTrajet );
    // Mode d'emploi :
    //  Ajoute unTrajet à la fin de la liste
    
    void Afficher(char sep) const;
    // Mode d'emploi :
    //  Affichage du contenu de la liste chainée avec un séparateur sep
    //  entre chaque trajet
    
    void AjouterOrdonne( Trajet * unTrajet );
    // Mode d'emploi :
    //  Ajoute unTrajet à la bonne place dans la liste dans l'ordre lexicographique
    // Contrat :
    //  La liste doit déjà être ordonnée
    
    bool Rechercher( const char * dep, const char * arr ) const;
    // Mode d'emploi :
    //  Affiche les trajets qui correspondent dans la liste,
    //  retourne vrai si au moins un trajet correspond, faux sinon.
    
    bool RechercheAvancee( const char * dep, const char * arr ) const;
    // Mode d'emploi :
    //  Recherche d'un départ à une arrivée en prenant en compte toutes
    //  les combinaisons de trajets possibles dans la liste
    


//------------------------------------------------- Surcharge d'opérateurs
    LChaine & operator = ( const LChaine & unLChaine );
    // Mode d'emploi :
    //  Fonction non définie


//-------------------------------------------- Constructeurs - destructeur
    LChaine ( const LChaine & unLChaine );
    // Mode d'emploi (constructeur de copie) :
    //  Fonction non définie
    
    LChaine ( );
    // Mode d'emploi :
    //  Construction d'une liste vide

    virtual ~LChaine ( );
    // Mode d'emploi :
    //  Destruction d'une liste et de son contenu

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	bool rechercheRec(const char* dep,const char * arr, Pile & p) const;
    // Mode d'emploi :
    //  recherche récursive avec la pile des éléments parcourus
    
	
//----------------------------------------------------- Attributs protégés
	Maillon* tete;

};

//-------------------------------- Autres définitions dépendantes de <LChaine>

#endif // LChaine_H

