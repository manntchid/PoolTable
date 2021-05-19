#ifndef PRJ_BOULE_H
#define PRJ_BOULE_H

#include "Objet.h"
#include "Vecteur.h"
#include "IntegrateurEuler.h"

class Boule : public Objet {
	private :
		double  masse ;
		double  rayon ;
		Vecteur force;
		double  coeff_frt;
		double  restitution;
		double  frt_roul;
		double  frt_glis;
		Vecteur etat;
		Vecteur etat_dt;
				
	public :
		//Prototype du Constructeur
		Boule(double masse_ ,double rayon_, double frot_ , double rest_,Vecteur Etat, Vecteur Etat_dt, SupportADessin* support_=nullptr);
		
		//Destructeur
		~Boule(){}
		
		//Prototype des méthodes
		double  masse_() const;				  //accesseur
		double  massevolumique() const;  	  //accesseur
		Vecteur getEtat() const;			  //accesseur
		Vecteur getEtat_dt() const;			  //accesseur
		Vecteur force_fr()const;			  //accesseur
		Vecteur moment_fr()const;			  //accesseur
		Vecteur normale() const ;			  //accesseur
		Vecteur pesanteur() const;			  //accesseur
		double  getRayon() const;			  //accesseur
		double  getRestitution() const;       //accesseur
		double  getCoeff_frt() const;         //accesseur
		Vecteur getForce() const ;            //accesseur
		double  poids() const ;				  //méthode-outil poids
		
		void setfrt_roul(double fr);		  //modificateur
		void setfrt_glis(double fg);		  //modificateur
		void setEtat(Vecteur e);			  //modificateur
		void setEtat_dt(Vecteur e_dt);		  //modificateur
		void ajoute_force(Vecteur const& df); 
		
		Vecteur evolution();				  //évolution de la boule
		Vecteur frottements() const;		  //calcul des frottements de la boule
		Vecteur acceleration_angulaire();     //acceleration_angulaire avec condition si vitesse_angulaire = 0 car 1/0 pour vecteur unitaire
		
		Vecteur position() const ; 			  //position
		Vecteur angle() const; 				  //angles
		Vecteur vitesse() const;			  //vitesse
		Vecteur vitesse_angulaire() const;	  //vitesse angulaire 
			
		//Prototypes des méthodes de la super class Objet pour la sous classe Boule 
		Vecteur distance(Boule bille);                                                          //vecteur de la distance entre deux boules
		double t_collision(Boule bille, double temps, double duree, IntegrateurEuler inte_eul); //temps de collision entre deux boules
		void collision (Boule& bille);															//détermination de la collision entre deux boules
		
		//méthode dessin pour la classe dessinable (sous classe de dessinable)
		virtual void dessine()override{ support->dessine(*this); } ;	
		
		//Prototype de la méthode pour l'opérateur <<
		std::ostream& affiche(std::ostream& sortieboule) const;
};
	
	//Surcharge opérateur << pour la class Boule
	std::ostream& operator<<(std::ostream& sortieboule, Boule const& zboule) ;
	
	
#endif // PRJ_BOULE_H
