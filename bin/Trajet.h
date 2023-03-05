/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Un trajet est un objet caractérisé par un départ et une arrivée.
// C'est la définition la plus basique d'un trajet.
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    virtual void Afficher() const;
    // Mode d'emploi :
    //	Affiche "de {depart} à {arrivee}"
    
    bool DepIs( const char * dep ) const;
    // Mode d'emploi :
    //	Renvoie true si le départ de l'instance appelante est le même 
    //	que la chaine de caractère entrée en paramètre
    // Contrat :
    //	dep doit être une chaine de caractère au sens du c
    
    bool ArrIs( const char * arr ) const;
    // Mode d'emploi :
    //	Renvoie true si l'arrivee de l'instance appelante est le même 
    //	que la chaine de caractère entrée en paramètre
    // Contrat :
    //	arr doit être une chaine de caractère au sens du c
    char * GetArrivee() const;
    char * GetDepart() const;
    // Mode d'emploi :
    //	Renvoie la chaîne de caractère de l'arrivee

//------------------------------------------------- Surcharge d'opérateurs

	bool operator > ( const Trajet & unTrajet ) const;
	bool operator == (const Trajet & unTrajet ) const;

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //	L'appel à cette fonction produit une erreur car elle n'est pas définie

    Trajet ( const char* unDepart,const char* uneArrivee);
    // Mode d'emploi :
    //	unDepart est le point de départ du trajet et uneArrivee est le point d'arrivée
    //	Le constructeur initialise le départ et l'arrivée
    // Contrat :
    //	unDepart et uneArrivee doivent être des chaîne de caractère au sens c

    virtual ~Trajet ( );
    // Mode d'emploi (destructeur) :
    //	Détruit les chaînes de caractères de la classe

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	char* depart;
	char* arrivee;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

