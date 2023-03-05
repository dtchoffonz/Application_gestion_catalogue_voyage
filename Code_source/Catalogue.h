/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "LChaine.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//  Un Catalogue est une collection ordonnée de trajets.
//
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    friend void sauvegardeTotale(Catalogue & c,char* nomfichier); 
    friend void sauvegardeType(Catalogue & c,char* nomfichier,int type);
    friend void sauvegardedep(Catalogue& c,char* nomfichier,char* nomdepart);
    friend void sauvegardearr(Catalogue& c,char* nomfichier,char* nomarrivee);
    friend void sauvegardedepetarr(Catalogue& c,char* nomfichier,char* nomdepart,char* nomarrivee);
    friend void sauvegardedepouarr(Catalogue& c,char* nomfichier,char* nomdepart,char* nomarrivee);
    friend void sauvegardeselection(Catalogue& c,char* nomfichier,int nbre1,int nbre2);
    
    void Afficher() const;
    // Mode d'emploi :
    //  Affiche le contenu du catalogue
    
    void Ajouter( Trajet * unTrajet );
    // Mode d'emploi :
    //  Ajouter un trajet au catalogue.
    // Contrat :
    //  unTrajet ne doit pas être détruit
    
    bool Rechercher( const char * dep, const char * arr ) const;
    // Mode d'emploi :
    //  Recherche d'un trajet dans le catalogue
    
    bool RechercheAvancee( const char * dep, const char * arr) const;
    // Mode d'emploi :
    //  Recherche d'un départ à une arrivée en prenant en compte toutes
    //  les combinaisons de trajets possibles

//------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & unCatalogue );
    // Mode d'emploi :
    //  Fonction non définie


//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //  Fonction non définie

    Catalogue ( );
    // Mode d'emploi :
    //  Construction d'un catalogue vide

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //  Destruction du contenu du catalogue

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	LChaine liste;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

