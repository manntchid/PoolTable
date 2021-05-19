#ifndef PRJ_PAROI_H
#define PRJ_PAROI_H

#include "Objet.h"
#include "Vecteur.h"
#include "IntegrateurEuler.h"

class Paroi : public Objet{
	protected :
		double coeff_frot;
		double restitution;
		Vecteur Normal;
		Vecteur Longueur;
		Vecteur Largeur;
		Vecteur Origine; //Convention décrite plus bas
		
	public :
		//Prototype du Constructeur
		Paroi(double coeff_frot_, double restitution_, Vecteur Longueur_, Vecteur Largeur_, Vecteur Origine_,SupportADessin* support_=nullptr);
		
		//Destructeur
		virtual ~Paroi(){}
		
		//Prototypes des méthodes pour avoir les points de la paroi
		Vecteur point_a() const;
		Vecteur point_b() const;
		Vecteur point_c() const;
		Vecteur point_d() const;
		
		//Prototype des méthodes de la super class Objet pour la sous classe Paroi
		Vecteur distance(Boule bille) override;  															//vecteur de la distance entre une boule et une paroi
		virtual double t_collision(Boule bille, double temps, double duree, IntegrateurEuler inte_eul); 	//temps de collision entre une boule et une paroi
		virtual void collision(Boule& bille);																//détermination de la collision entre une boule et une paroi
		
		//Méthode de dessin
		virtual void dessine()override{ support->dessine(*this); } ;
		
		
	
//////////////Convention sur l'origine pour une paroi /////////////////
/*                 ---------------
				   |			 |
			       o--------------
*/
	
	};
	
#endif // PRJ_PAROI_H
