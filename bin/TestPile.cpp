#include "Pile.h"
#include <iostream>
#include "TrajetS.h"
using namespace std;

int main()
{
	Pile p;
	TrajetS *t1=new TrajetS("A","B","T");
	TrajetS *t2 =new TrajetS("B","C","T");
	p.Empiler(t1);
	p.Afficher();
	delete t1;
	delete t2;
	return 0;
}
