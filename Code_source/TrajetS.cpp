/*************************************************************************
                           TrajetS  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetS> (fichier TrajetS.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetS.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetS::Afficher() const
{
	cout << "de " << depart << " à " << arrivee << " en " << transport;
} //----- Fin de Afficher


char* 	TrajetS::GetTransport() const{
	return transport;
	
}
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


TrajetS::TrajetS ( const char* unDepart,const char* uneArrivee,const char* unTransport ):Trajet(unDepart,uneArrivee)
// Algorithme :
//  Copie des chaînes en paramètre
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetS>" << endl;
#endif
	transport=new char[strlen(unTransport)+1];
	strcpy(transport,unTransport);
} //----- Fin de TrajetS


TrajetS::~TrajetS ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetS>" << endl;
#endif
	delete[] transport;
} //----- Fin de ~TrajetS


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

