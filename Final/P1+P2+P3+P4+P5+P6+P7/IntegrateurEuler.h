#ifndef PRJ_INTEGRATEUREULER_H
#define PRJ_INTEGRATEUREULER_H

#include "Boule.h"
#include "Integrateur.h"

class IntegrateurEuler : public Integrateur{
	
	public :
		//Prototype du Constructeur
		IntegrateurEuler(double pasdetempsE, double tempsE);
		
		//Prototype de la méthodes
		Boule integre(Boule z ,double nombre);
	};

#endif // PRJ_INTEGRATEUREULER_H
