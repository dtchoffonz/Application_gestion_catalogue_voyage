#include <iostream>
#include <fstream>
#include "Catalogue.h"
#include "LChaine.h"
#include "Maillon.h"
#include "TrajetC.h"
#include "Trajet.h"
#include "TrajetS.h"
#include <cstring>
#include "Sauvegarde.h"

/*Contient toutes les fonctions de sauvegarde*/

using namespace std;

void sauvegardeTotale (Catalogue & c,char* nomfichier){

	ofstream fic ( nomfichier );                                              //ouverture du fichier
	Maillon * curseur=c.liste.GetTete();                                      //Recupération du premier élément du catalogue
	Maillon* elem3;
	while(curseur!=nullptr)
	{
		TrajetS* elem=dynamic_cast<TrajetS*>(curseur->GetElem());             //Cet élément pointe vers un Trajet, mais est-ce un TrajetS ou un TrajetC ???  
		if(elem!=nullptr)
		{
			fic.write("S,",2);
			fic.write(elem->GetDepart(),strlen(elem->GetDepart()));            //Ecriture dans le fichier, si c'est un TrajetS
			fic.put(',');
			fic.write(elem->GetArrivee(),strlen(elem->GetArrivee()));
			fic.put(',');
			fic.write(elem->GetTransport(),strlen(elem->GetTransport()));
			fic.put('\n');
		}
		else
		{
			fic.write("C,",2);
			fic.write(curseur->GetElem()->GetDepart(),strlen(curseur->GetElem()->GetDepart()));    //Ecriture du départ et de l'arrivée d'un TrajetC
			fic.put(',');
			fic.write(curseur->GetElem()->GetArrivee(),strlen(curseur->GetElem()->GetArrivee()));
			fic.put('\n');
			TrajetC* elem2=dynamic_cast<TrajetC*>(curseur->GetElem());
			elem3=elem2->GetTete();                                                                 //Récupération du premier élément du TrajetC
			
			while(elem3!=nullptr){
				
				TrajetS* curseur2=dynamic_cast<TrajetS*>(elem3->GetElem());                         //Ecriture ligne par ligne des sous-Trajets du TrajetC
				fic.put('-');
				fic.write(curseur2->GetDepart(),strlen(curseur2->GetDepart()));
			    fic.put(',');
			    fic.write(curseur2->GetArrivee(),strlen(curseur2->GetArrivee()));
			    fic.put(',');
			    fic.write(curseur2->GetTransport(),strlen(curseur2->GetTransport()));
			    fic.put('\n');
			    
			    
				elem3=elem3->GetSuivant();
			}
			
		}
		curseur=curseur->GetSuivant();
	}
	fic.close();
	
}


void sauvegardeType (Catalogue & c,char* nomfichier,int type){
	
	
	ofstream fic ( nomfichier );
	Maillon * curseur=c.liste.GetTete();
	Maillon* elem3;
	while(curseur!=nullptr)
	{
		TrajetS* elem=dynamic_cast<TrajetS*>(curseur->GetElem());
		if(elem!=nullptr)
		{
			if(type==1){                                                            //Type=1, l'utilisateur veut sauvegarder les trajets simples
			fic.write("S,",2);
			fic.write(elem->GetDepart(),strlen(elem->GetDepart()));
			fic.put(',');
			fic.write(elem->GetArrivee(),strlen(elem->GetArrivee()));
			fic.put(',');
			fic.write(elem->GetTransport(),strlen(elem->GetTransport()));
			fic.put('\n');
		}
		}
		else
		{
			if(type==2){                                                               //Type=2, l'utilisateur veut sauvegarder les trajets composés
			fic.write("C,",2);
			fic.write(curseur->GetElem()->GetDepart(),strlen(curseur->GetElem()->GetDepart()));
			fic.put(',');
			fic.write(curseur->GetElem()->GetArrivee(),strlen(curseur->GetElem()->GetArrivee()));
			fic.put('\n');
			TrajetC* elem2=dynamic_cast<TrajetC*>(curseur->GetElem());
			elem3=elem2->GetTete();
			
			while(elem3!=nullptr){
				
				TrajetS* curseur2=dynamic_cast<TrajetS*>(elem3->GetElem());
				fic.put('-');
				fic.write(curseur2->GetDepart(),strlen(curseur2->GetDepart()));
			    fic.put(',');
			    fic.write(curseur2->GetArrivee(),strlen(curseur2->GetArrivee()));
			    fic.put(',');
			    fic.write(curseur2->GetTransport(),strlen(curseur2->GetTransport()));
			    fic.put('\n');
			    
			    
				elem3=elem3->GetSuivant();
			}
			
		}
			
		}
		curseur=curseur->GetSuivant();
	}
	fic.close();
	
}



void sauvegardedep(Catalogue& c,char* nomfichier,char* nomdepart){
	
	ofstream fic ( nomfichier );
	Maillon * curseur=c.liste.GetTete();
	Maillon* elem3;
	
	while(curseur!=nullptr)
	{
		TrajetS* elem=dynamic_cast<TrajetS*>(curseur->GetElem());
		if(elem!=nullptr)
		{
			if(strcmp(elem->GetDepart(),nomdepart)==0){                                  //Si la ville de départ correspond on sauvegarde dans le fichier
			fic.write("S,",2);
			fic.write(elem->GetDepart(),strlen(elem->GetDepart()));
			fic.put(',');
			fic.write(elem->GetArrivee(),strlen(elem->GetArrivee()));
			fic.put(',');
			fic.write(elem->GetTransport(),strlen(elem->GetTransport()));
			fic.put('\n');
		}
		}
		else
		{
			if(strcmp(curseur->GetElem()->GetDepart(),nomdepart)==0){                  //Si la ville de départ correspond on sauvegarde dans le fichier
			fic.write("C,",2);
			fic.write(curseur->GetElem()->GetDepart(),strlen(curseur->GetElem()->GetDepart()));
			fic.put(',');
			fic.write(curseur->GetElem()->GetArrivee(),strlen(curseur->GetElem()->GetArrivee()));
			fic.put('\n');
			TrajetC* elem2=dynamic_cast<TrajetC*>(curseur->GetElem());
			elem3=elem2->GetTete();
			
			while(elem3!=nullptr){
				
				TrajetS* curseur2=dynamic_cast<TrajetS*>(elem3->GetElem());
				fic.put('-');
				fic.write(curseur2->GetDepart(),strlen(curseur2->GetDepart()));
			    fic.put(',');
			    fic.write(curseur2->GetArrivee(),strlen(curseur2->GetArrivee()));
			    fic.put(',');
			    fic.write(curseur2->GetTransport(),strlen(curseur2->GetTransport()));
			    fic.put('\n');
			    
				elem3=elem3->GetSuivant();
			}
			
		}
			
		}
		curseur=curseur->GetSuivant();
	}
	fic.close();
	
}

void sauvegardearr(Catalogue& c,char* nomfichier,char* nomarrivee){
	
	ofstream fic ( nomfichier );
	Maillon * curseur=c.liste.GetTete();
	Maillon* elem3;
	
	while(curseur!=nullptr)
	{
		TrajetS* elem=dynamic_cast<TrajetS*>(curseur->GetElem());
		if(elem!=nullptr)
		{
			if(strcmp(elem->GetArrivee(),nomarrivee)==0){                               //Si la ville d'arrivée correspond on sauvegarde dans le fichier
			fic.write("S,",2);
			fic.write(elem->GetDepart(),strlen(elem->GetDepart()));
			fic.put(',');
			fic.write(elem->GetArrivee(),strlen(elem->GetArrivee()));
			fic.put(',');
			fic.write(elem->GetTransport(),strlen(elem->GetTransport()));
			fic.put('\n');
		}
		}
		else
		{
			if(strcmp(curseur->GetElem()->GetArrivee(),nomarrivee)==0){                      //Si la ville d'arrivée correspond on sauvegarde dans le fichier
			fic.write("C,",2);
			fic.write(curseur->GetElem()->GetDepart(),strlen(curseur->GetElem()->GetDepart()));
			fic.put(',');
			fic.write(curseur->GetElem()->GetArrivee(),strlen(curseur->GetElem()->GetArrivee()));
			fic.put('\n');
			TrajetC* elem2=dynamic_cast<TrajetC*>(curseur->GetElem());
			elem3=elem2->GetTete();
			
			while(elem3!=nullptr){
				
				TrajetS* curseur2=dynamic_cast<TrajetS*>(elem3->GetElem());
				fic.put('-');
				fic.write(curseur2->GetDepart(),strlen(curseur2->GetDepart()));
			    fic.put(',');
			    fic.write(curseur2->GetArrivee(),strlen(curseur2->GetArrivee()));
			    fic.put(',');
			    fic.write(curseur2->GetTransport(),strlen(curseur2->GetTransport()));
			    fic.put('\n');
			    
				elem3=elem3->GetSuivant();
			}
			
		}
			
		}
		curseur=curseur->GetSuivant();
	}
	fic.close();
	
}


void sauvegardedepetarr(Catalogue& c,char* nomfichier,char* nomdepart,char* nomarrivee){
	
	ofstream fic ( nomfichier );
	Maillon * curseur=c.liste.GetTete();
	Maillon* elem3;
	
	while(curseur!=nullptr)
	{
		TrajetS* elem=dynamic_cast<TrajetS*>(curseur->GetElem());
		if(elem!=nullptr)
		{
			if(strcmp(elem->GetDepart(),nomdepart)==0   && strcmp(elem->GetArrivee(),nomarrivee)==0){   //Si la ville de départ et la ville d'arrivée correspond on sauvegarde dans le fichier
			fic.write("S,",2);
			fic.write(elem->GetDepart(),strlen(elem->GetDepart()));
			fic.put(',');
			fic.write(elem->GetArrivee(),strlen(elem->GetArrivee()));
			fic.put(',');
			fic.write(elem->GetTransport(),strlen(elem->GetTransport()));
			fic.put('\n');
		}
		}
		else
		{
			if(strcmp(curseur->GetElem()->GetDepart(),nomdepart)==0 && strcmp(curseur->GetElem()->GetArrivee(),nomarrivee)==0){   //Si la ville de départ et la ville d'arrivée correspond on sauvegarde dans le fichier
			fic.write("C,",2);
			fic.write(curseur->GetElem()->GetDepart(),strlen(curseur->GetElem()->GetDepart()));
			fic.put(',');
			fic.write(curseur->GetElem()->GetArrivee(),strlen(curseur->GetElem()->GetArrivee()));
			fic.put('\n');
			TrajetC* elem2=dynamic_cast<TrajetC*>(curseur->GetElem());
			elem3=elem2->GetTete();
			
			while(elem3!=nullptr){
				
				TrajetS* curseur2=dynamic_cast<TrajetS*>(elem3->GetElem());
				fic.put('-');
				fic.write(curseur2->GetDepart(),strlen(curseur2->GetDepart()));
			    fic.put(',');
			    fic.write(curseur2->GetArrivee(),strlen(curseur2->GetArrivee()));
			    fic.put(',');
			    fic.write(curseur2->GetTransport(),strlen(curseur2->GetTransport()));
			    fic.put('\n');
			    
				elem3=elem3->GetSuivant();
			}
			
		}
			
		}
		curseur=curseur->GetSuivant();
	}
	fic.close();
	
}

void sauvegardedepouarr(Catalogue& c,char* nomfichier,char* nomdepart,char* nomarrivee){
	
	ofstream fic ( nomfichier );
	Maillon * curseur=c.liste.GetTete();
	Maillon* elem3;
	
	while(curseur!=nullptr)
	{
		TrajetS* elem=dynamic_cast<TrajetS*>(curseur->GetElem());
		if(elem!=nullptr)
		{
			if(strcmp(elem->GetDepart(),nomdepart)==0   || strcmp(elem->GetArrivee(),nomarrivee)==0){  //Si la ville de départ ou la ville d'arrivée correspond on sauvegarde dans le fichier
			fic.write("S,",2);
			fic.write(elem->GetDepart(),strlen(elem->GetDepart()));
			fic.put(',');
			fic.write(elem->GetArrivee(),strlen(elem->GetArrivee()));
			fic.put(',');
			fic.write(elem->GetTransport(),strlen(elem->GetTransport()));
			fic.put('\n');
		}
		}
		else
		{
			if(strcmp(curseur->GetElem()->GetDepart(),nomdepart)==0 || strcmp(curseur->GetElem()->GetArrivee(),nomarrivee)==0){ //Si la ville de départ ou la ville d'arrivée correspond on sauvegarde dans le fichier
			fic.write("C,",2);
			fic.write(curseur->GetElem()->GetDepart(),strlen(curseur->GetElem()->GetDepart()));
			fic.put(',');
			fic.write(curseur->GetElem()->GetArrivee(),strlen(curseur->GetElem()->GetArrivee()));
			fic.put('\n');
			TrajetC* elem2=dynamic_cast<TrajetC*>(curseur->GetElem());
			elem3=elem2->GetTete();
			
			while(elem3!=nullptr){
				
				TrajetS* curseur2=dynamic_cast<TrajetS*>(elem3->GetElem());
				fic.put('-');
				fic.write(curseur2->GetDepart(),strlen(curseur2->GetDepart()));
			    fic.put(',');
			    fic.write(curseur2->GetArrivee(),strlen(curseur2->GetArrivee()));
			    fic.put(',');
			    fic.write(curseur2->GetTransport(),strlen(curseur2->GetTransport()));
			    fic.put('\n');
			    
				elem3=elem3->GetSuivant();
			}
			
		}
			
		}
		curseur=curseur->GetSuivant();
	}
	fic.close();
	
}


void sauvegardeselection(Catalogue& c,char* nomfichier,int nbre1,int nbre2)
{
	ofstream fic ( nomfichier );
	Maillon * curseur=c.liste.GetTete();
	Maillon* elem3;
	int n=1;
	
	while(curseur!=nullptr)
	{
		if (n>=nbre1 && n<=nbre2){                                              //Si on est dans l'intervalle fournit par l'utilisateur, on sauvegarde
		TrajetS* elem=dynamic_cast<TrajetS*>(curseur->GetElem());
		if(elem!=nullptr)
		{
			fic.write("S,",2);
			fic.write(elem->GetDepart(),strlen(elem->GetDepart()));
			fic.put(',');
			fic.write(elem->GetArrivee(),strlen(elem->GetArrivee()));
			fic.put(',');
			fic.write(elem->GetTransport(),strlen(elem->GetTransport()));
			fic.put('\n');
		}
		else
		{
			fic.write("C,",2);
			fic.write(curseur->GetElem()->GetDepart(),strlen(curseur->GetElem()->GetDepart()));
			fic.put(',');
			fic.write(curseur->GetElem()->GetArrivee(),strlen(curseur->GetElem()->GetArrivee()));
			fic.put('\n');
			TrajetC* elem2=dynamic_cast<TrajetC*>(curseur->GetElem());
			elem3=elem2->GetTete();
			
			while(elem3!=nullptr){
				
				TrajetS* curseur2=dynamic_cast<TrajetS*>(elem3->GetElem());
				fic.put('-');
				fic.write(curseur2->GetDepart(),strlen(curseur2->GetDepart()));
			    fic.put(',');
			    fic.write(curseur2->GetArrivee(),strlen(curseur2->GetArrivee()));
			    fic.put(',');
			    fic.write(curseur2->GetTransport(),strlen(curseur2->GetTransport()));
			    fic.put('\n');
			    
				elem3=elem3->GetSuivant();
			}
			
			
		}
	}
		curseur=curseur->GetSuivant();
		n=n+1;                                     //incrémentation du compteur de trajets 
	}
	fic.close();
	
}

	
	
	

