#ifndef PRJ_SOL_H
#define PRJ_SOL_H

#include "Paroi.h"

class Sol : public Paroi{
	private:
		double fr_glis;
		double fr_roul;
		
	public : 
		//Prototype du Constructeur
		Sol(double coeff_frot_, double restitution_,double fr_glis_, double fr_roul_, Vecteur Longueur_, Vecteur Largeur_, Vecteur Origine_,SupportADessin* support_=nullptr);
		
		//Destructeur
		virtual ~Sol(){}
		
		//Prototype des méthodes
		void reaction(Boule& bille);
		void collision(Boule& bille) override;           //détermination de la collision entre une boule et un sol
		
		//Méthode de dessin
		virtual void dessine()override{ support->dessine(*this); } ;

//////////////Convention sur l'origine pour un sol /////////////////
/*                 ---------------
				   |	  		 |
			       o--------------
*/
		
};




#endif // PRJ_SOL_H
