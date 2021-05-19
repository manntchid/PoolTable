#include <iostream>
#include <vector>
#include <cmath>
#include "Integrateur.h"


using namespace std ;


////// Définition du constructeur
Integrateur :: Integrateur (double pasdetemps_ , double temps_)
		: pasdetemps(pasdetemps_), temps(temps_) 
		{}
		
////// Définition de la méthode
double Integrateur :: getPasdetemps() {
	return pasdetemps;
	}
  
