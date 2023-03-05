#include <iostream>
#include <cstring>
#include "Trajet.h"
#include "TrajetS.h"
#include "TrajetC.h"
#include "Catalogue.h"
#include "Sauvegarde.h"

using namespace std;

int main()
{
	Catalogue c;
	bool fin=false;
	char depart[45],arrivee[45],transport[30];
	TrajetC* tc;
	
	while (!fin)
	{
		cout << "-----MENU - entrez un entier pour accéder à une fonctionnalité ou q pour quitter-----" << endl;
		cout << "1-> Ajouter un trajet simple dans le catalogue" << endl;
		cout << "2-> Ajouter un trajet composé dans le catalogue" << endl;
		cout << "3-> Afficher le catalogue par ordre alphabétique" << endl;
		cout << "4-> Rechercher un trajet" << endl;
		cout << "5-> Recherche avancée d'un trajet" << endl;
		cout << "6-> Sauvegarder le catalogue courant" << endl;
		cout << "q-> Quitter" << endl;
		
		char choix;
		char choix2;
		int type;
		char nom[40];
		char nomdepart[40];
		char nomarrivee[40];
		int nbre1;
		int nbre2;
		cin >> choix;
		switch(choix)
		{
			case '1':
				cout << endl;
				cout << "-----Ajouter un trajet simple dans le catalogue-----" << endl;
				cout << "Quel est le point de départ du trajet ?" << endl;
				cin >> depart;
				cout << "Quelle est la destination ?" << endl;
				cin >> arrivee;
				if (strcmp(depart,arrivee)==0)
				{
					cout << "Vous ne pouvez pas rentrer un trajet où le point de départ est celui d'arrivee" << endl << endl;
					break;
				}
				cout << "Avec quel moyen de transport ce trajet sera effectué ?" << endl;
				cin >> transport;
				c.Ajouter(new TrajetS(depart,arrivee,transport));
				cout << endl;
				break;
			case '2':
				cout << "-----Ajouter un trajet composé dans le catalogue-----" << endl;
				cout << "Quel est le point de depart du trajet ?" << endl;
				cin >> depart;
				cout << "Quel est le prochain arrêt ?" << endl;
				cin >> arrivee;
				tc=new TrajetC(depart);
				while (strcmp(arrivee,"stop")==0)
				{
					cout << "Ce n'est pas possible d'avoir un arrêt appelé stop, Retapez un arrêt valide" << endl;;
					cin >> arrivee;
				}
				char transport[30];
				while (strcmp(arrivee,"stop")!=0)
				{
					cout << "Avec quel transport cette section de trajet est-elle effectuée ?" << endl;
					cin >> transport;
					tc->Ajouter(new TrajetS(depart,arrivee,transport));
					strcpy(depart,arrivee);
					cout << "Quel est le prochain arrêt ? (Tapez \"stop\" si c'était le terminus)" << endl;
					cin >> arrivee;
				}
				tc->SetArrivee(depart);
				c.Ajouter(tc);
				cout << endl;
				break;
			case '3':
				cout << endl;
				cout << "-----Afficher le catalogue par ordre alphabétique-----" << endl;
				c.Afficher();
				cout << endl;
				break;
			case '4':
				cout << endl;
				cout << "-----Rechercher un trajet-----" << endl;
				cout << "D'où voulez vous partir ?" << endl;
				cin >> depart;
				cout << "A quelle destination ?" << endl;
				cin >> arrivee;
				cout << endl;
				cout << "Voici les trajets qui correspondent à votre recherche :" << endl;
				if(!c.Rechercher(depart,arrivee))
					cout << "Désolé, le catalogue ne contient pas de trajet qui correspond :(" << endl;
				cout << endl;
				break;
			case '5':
				cout << endl;
				cout << "-----Recherche avancée-----" << endl;
				cout << "D'où voulez vous partir ?" << endl;
				cin >> depart;
				cout << "A quelle destination ?" << endl;
				cin >> arrivee;
				cout << endl;
				cout << "Voici les trajets qui correspondent à votre recherche :" << endl;
				if(!c.RechercheAvancee(depart,arrivee))
					cout << "Désolé, le catalogue ne contient pas de trajet qui correspond :(" << endl;
				cout << endl;
				break;
			case '6':
				cout << endl;
				cout << "1-> Sauvegarde Totale" << endl;
		        cout << "2-> Sauvegarde selon le type de trajets" << endl;
		        cout << "3-> Sauvegarde selon la ville de départ et/ou arrivée" << endl;
		        cout << "4-> Sauvegarde selon une sélection de trajets" << endl;
		        cin >> choix2;
		        
				
				switch (choix2){         //Sous-menu pour le choix de type de sauvegarde
				 
							case '1' :
								
								cout << endl;
								cout << "Entrez le nom du fichier" << endl;
								cin >> nom;
								sauvegardeTotale(c,nom);
								break;
							case '2' :
								cout << endl;
								cout << "1-> Sauvegarder les trajets simples" << endl;
								cout << "2-> Sauvegarder les trajets composés" << endl;
								cin >> type;
								cout << "Entrez le nom du fichier" << endl;
								cin >> nom;
								if(type==1 || type==2){
								  sauvegardeType (c,nom,type);
									
								}else {
								  cout<< "Ce choix n'est pas reconnu" <<endl;
								 
								}
							break;
							case '3' :
							    cout << endl;
								cout << "1-> Selon la ville de départ" << endl;
								cout << "2-> Selon la ville d'arrivée" << endl;
								cout << "3-> Selon la ville de départ et la ville d'arrivée" << endl;
								cout << "4-> Selon la ville de départ ou la ville d'arrivée" << endl;
								char choix3;
								cin >>choix3;
								switch(choix3){              //Deuxieme sous-menu pour la précision de la sélectivité selon la ville
									
											case '1':
											   cout << endl;
											   cout<<"Entrez la ville de départ"<<endl;
											   cin>> nomdepart;
								               cout << "Entrez le nom du fichier" << endl;
								               cin >> nom;
								               sauvegardedep(c,nom,nomdepart);
											break;
											
											case '2':
											   cout << endl;
											   cout<<"Entrez la ville d'arrivée"<<endl;
											   cin>> nomarrivee;
								               cout << "Entrez le nom du fichier" << endl;
								               cin >> nom;
								               sauvegardearr(c,nom,nomarrivee);
											break;
											
											case '3':
											   cout << endl;
											   cout<<"Entrez la ville de départ"<<endl;
											   cin>> nomdepart;
											   cout<<"Entrez la ville d'arrivée"<<endl;
											   cin>> nomarrivee;
								               cout << "Entrez le nom du fichier" << endl;
								               cin >> nom;
								               sauvegardedepetarr(c,nom,nomdepart,nomarrivee);
											
											break;
											
											case '4':
											   cout << endl;
											   cout<<"Entrez la ville de départ"<<endl;
											   cin>> nomdepart;
											   cout<<"Entrez la ville d'arrivée"<<endl;
											   cin>> nomarrivee;
								               cout << "Entrez le nom du fichier" << endl;
								               cin >> nom;
								               sauvegardedepouarr(c,nom,nomdepart,nomarrivee);
											break;
											
											
											default :
											   cout << "Ce choix n'est pas reconnu" << endl;
											   cout << endl;
											   break;
									
								}//fermeture du switch(choix3)
							
							break;
							
							case '4':
								cout<<endl;
								cout<< "Entrez le premier chiffre de l'intervalle"<<endl;
								cin>> nbre1;
								cout<<"Enrez le deuxieme chiffre de l'intervalle"<<endl;
								cin>> nbre2;
								if ((nbre1 > nbre2) || (nbre1<=0) || (nbre2<=0)){
									cout<<"Intervalle incorrect"<<endl;
								}else{
									cout << "Entrez le nom du fichier" << endl;
									cin >> nom;
									sauvegardeselection(c,nom,nbre1,nbre2);	
								}
							break;
							
							default  :
							cout << "Ce choix n'est pas reconnu" << endl;
				            cout << endl;
							break;
							
		        } //fermeture du switch(choix2)
		        break;
		    
			case 'q':
				fin=true;
				break;
			default:
				cout << "Ce choix n'est pas reconnu" << endl;
				cout << endl;
				break;
					
		}//fermeture du switch(choix)
	}
	
	return 0;
}
