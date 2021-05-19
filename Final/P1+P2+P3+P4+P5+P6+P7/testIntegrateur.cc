#include <iostream>
#include <vector>
#include <initializer_list>
#include "Vecteur.h"
#include "Boule.h"
#include "IntegrateurEuler.h"


using namespace std;


int main () {

//Initialisation d'une boule
Boule b3(0.127,0.02625, 0.2, 0.99,{0.0,0.0,1.0,0.0,0.0,0.0},{1.0,0.0,2.0,0.0,0.0,0.0});

//Affichage de la boule dans le temps
IntegrateurEuler p(0.01, 0.0);
	cout<<"Situation de départ :"<<endl ;
	cout<<b3<<endl ;
	cout<<"========================"<<endl;
	cout<<"t = 0.01"<<endl ;
	cout<<p.integre(b3, 0.01)<<endl;
	cout<<"========================"<<endl;
	cout<<"t = 0.02"<<endl ;
	cout<<p.integre(b3, 0.02)<<endl;
	cout<<"========================"<<endl;
	cout<<"t = 0.03"<<endl ;
	cout<<p.integre(b3, 0.03)<<endl;
	
	
	// -> affichage pour enregristrer les positions dans le fichier testIntegrateur.txt
	/*for (size_t i(0) ; i < 70; ++i){
		
		cout<<p.integre(b3, i*0.01)<<endl ;
		
		}*/

return 0;
}
