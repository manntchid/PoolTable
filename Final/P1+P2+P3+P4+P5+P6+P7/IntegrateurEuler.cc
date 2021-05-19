#include <iostream>
#include <vector>
#include <cmath>
#include "IntegrateurEuler.h"


using namespace std ;



//////Définition du constructeur 
IntegrateurEuler :: IntegrateurEuler(double pasdetempsE, double tempsE)
		: Integrateur(pasdetempsE, tempsE)
		{}
		
//////Définition de la méthode
Boule IntegrateurEuler :: integre(Boule z, double nombre){
		
		Boule zeuler(z);
		for(size_t i(1); i*pasdetemps <= nombre; ++i){
			
			zeuler.setEtat_dt(zeuler.getEtat_dt() + (zeuler.evolution()*pasdetemps));
			zeuler.setEtat(zeuler.getEtat() + ((zeuler.getEtat_dt())*pasdetemps));
			
			};
		
		return zeuler ;
	}
	
