#ifndef PRJ_INTEGRATEUR_NEWMARK_H
#define PRJ_INTEGRATEUR_NEWMARK_H

#include "Integrateur.h"
#include "Boule.h"

class IntegrateurNewmark : public Integrateur{

    protected:
       double epsilon;

    public:
		//Prototype du Constructeur
		IntegrateurNewmark(double pdt , double t, double e);

		//Prototype de la méthode pour l'intégration
		Boule integre(Boule n, double nombre);

};

#endif // PRJ_INTEGRATEUR_NEWMARK_H
