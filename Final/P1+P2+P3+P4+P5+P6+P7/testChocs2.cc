#include <iostream>
#include <vector>
#include <initializer_list>
#include "Boule.h"

using namespace std;

////////////////////////// Test choc avec rotation (P7.2.2)/////////////////////////////////////////
int main () {

//Initialisation des boules
Boule a(0.127, 0.02625, 0.2, 0.99,{0.0, 0.0, 1.0, 0.0, 0.0, 0.0},{1.0, 0.0, 2.0, 0.0, 0.0, 0.0});
Boule b(0.127, 0.02625, 0.2, 0.99,{0.08, 0.0, 1.16, 0.0, 0.0, 0.0},{0.0, 0.0, 0.0, 0.0, 5.0, 0.0});

//Initialisation des autres valeurs
double pas_de_temps(0.01);
double temps_initiale(pas_de_temps) ;
double temps_de_collision(0.0);
double ecart_de_collision(0.0);
Boule temp1(a);
Boule temp2(b);

IntegrateurEuler p(pas_de_temps, 0.0);

	//cout<<a<<endl;  //--> affichage pour sauvegarder les positions dans le fichier testChocs2.txt
	//cout<<b<<endl;
for(size_t i(1) ; i*pas_de_temps <= 0.10 ; ++i ){
	
	a=p.integre(a,pas_de_temps);
	b=p.integre(b,pas_de_temps);
    
	//cout<<a<<endl;  //--> affichage pour sauvegarder les positions dans le fichier testChocs2.txt
	//cout<<b<<endl;
	
	
	ecart_de_collision = temp1.t_collision(temp2, temps_initiale, pas_de_temps, p);
	
	if(ecart_de_collision != -1.0){
		a=p.integre(temp1,temps_initiale);
		b=p.integre(temp2,temps_initiale);
		temps_de_collision = temps_initiale+ecart_de_collision ;
		//Integration sur l'écart de temps
		IntegrateurEuler p_prime(ecart_de_collision,0.0); 
		a=p_prime.integre(a,ecart_de_collision);
		b=p_prime.integre(b,ecart_de_collision);
		
		cout<<"TEMPS COLLISION : "<<temps_de_collision<<endl;
		cout<<"COLLISION BOULE - BOULE"<<endl;
		cout<<"ENTRE Boule 1 : "<<endl<<a;
		cout<<"ET Boule 2 : "<<endl<<b;
		a.collision(b);
		cout<<"RESULTAT (apres collision) :"<<endl;
		cout<<"Boule 1 : "<<endl<<a;
		cout<<"Boule 2 : "<<b;
		//Integration sur le reste écart de temps pour que l'écart de temps + reste de l'écart = pas de temps
		IntegrateurEuler p_prime2(pas_de_temps-ecart_de_collision,0.0);
		a=p_prime2.integre(a,pas_de_temps-ecart_de_collision);
		b=p_prime2.integre(b,pas_de_temps-ecart_de_collision);
		
		} 
		
		temps_initiale += pas_de_temps ;
}	



return 0;
}
