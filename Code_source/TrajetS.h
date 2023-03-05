/*************************************************************************
                           TrajetS  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetS> (fichier TrajetS.h) ----------------
#if ! defined ( TRAJETS_H )
#define TRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetS>
// Un TrajetS ou trajet "simple" est un trajet direct avec un moyen de transport.
//
//------------------------------------------------------------------------

class TrajetS : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    
    void Afficher() const;
	// Mode d'emploi :
	//	Affiche "de {départ} à {arrivée} en {transport}
	
	char* GetTransport() const;

//------------------------------------------------- Surcharge d'opérateurs
    TrajetS & operator = ( const TrajetS & unTrajetS );
    // Mode d'emploi :
    //  Fonction pas définie


//-------------------------------------------- Constructeurs - destructeur
    TrajetS ( const TrajetS & unTrajetS );
    // Mode d'emploi (constructeur de copie) :
    //  Fonction pas définie

    TrajetS ( const char* unDepart,const char* uneArrivee,const char* unTransport );
    // Mode d'emploi :
    //  Construction d'un TrahetS

    virtual ~TrajetS ( );
    // Mode d'emploi :
    //  Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	char* transport;

};

//-------------------------------- Autres définitions dépendantes de <TrajetS>

#endif // TRAJETS_H

