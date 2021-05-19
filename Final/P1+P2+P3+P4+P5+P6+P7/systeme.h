#ifndef PRJ_SYSTEME_H
#define PRJ_SYSTEME_H

#include <memory>
#include <vector>
#include "Boule.h"
#include "dessinable.h"
#include "Sol.h"


const double hauteur=0.2;

class Systeme : public Dessinable{
	
	private:
		std::vector<Boule*>mobile;
		std::vector<Objet*>collisionable;
		Sol sol_billard;
		Paroi paroi1;
		Paroi paroi2;
		Paroi paroi3;
		Paroi paroi4;
				
	public:
	  
	  //Prototype du Constructeur
	  Systeme(double longueur_, double largeur_,SupportADessin* vue=nullptr);
	  
	  //Destructeur virtuel
	  virtual ~Systeme() {};
	  
	  //Prototypes des Méthodes
	  virtual void dessine()override{ support->dessine(*this); } ;
	  void ajouter(Boule* const& boule1);
	  std::vector<Boule*> const& getMobile() const ;
	  std::vector<Objet*> const& getcollisionable() const ;
	  void evolue(double pas_de_temps) ;
	  void interpenetration();
};

#endif // SYSTEME_H
