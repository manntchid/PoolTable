#include <iostream>
#include <cmath>
#include "IntegrateurNewmark.h"

using namespace std;

//Définition du constructeur
IntegrateurNewmark :: IntegrateurNewmark(double pdt , double t, double e)
	:Integrateur(pdt, t), epsilon(e)
	{}

//Définition de la méthode pour l'intégration
Boule IntegrateurNewmark :: integre(Boule n, double nombre){
	
	Boule newmark(n);
	Vecteur Omega_prime(newmark.getEtat_dt());			//Initialisation
	Vecteur Omega(newmark.getEtat());					//Initialisation
	Vecteur khi_prime(newmark.evolution());				//Initialisation
	Vecteur xi(6);										//Initialisation
	Vecteur khi(6);										//Initialisation
	  do{
		xi = newmark.getEtat();
		khi=newmark.evolution();
		newmark.setEtat_dt(Omega_prime + (pasdetemps/2.0)*(khi + khi_prime));
		newmark.setEtat(Omega + pasdetemps*Omega_prime + ((pow(pasdetemps, 2))/3.0)*((khi*0.5) + khi_prime));
      } while ((newmark.getEtat() - xi).norme_vecteur() >= epsilon);
    
	return newmark;
}
