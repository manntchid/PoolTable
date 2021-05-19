#ifndef PRJ_OBJET_H
#define PRJ_OBJET_H


#include "Vecteur.h"
#include "dessinable.h"

class Boule ;
class IntegrateurEuler;

class Objet : public Dessinable {
	
	public:
		//Constructeur
		Objet(SupportADessin* support)
		:Dessinable(support)
		{}
		
		//Destructeur virtuel
		virtual ~Objet(){}
		
		//Méthodes virtuelles pures (toutes définies dans les sous-classes)
		virtual Vecteur distance(Boule bille) = 0; 															//vecteur de la distance entre deux objets
		virtual double t_collision(Boule bille, double temps, double duree, IntegrateurEuler inte_eul) = 0; //temps de collision entre deux objets
		virtual void collision(Boule& bille) = 0;															//détermination de la collision entre deux objets
		
};

#endif
