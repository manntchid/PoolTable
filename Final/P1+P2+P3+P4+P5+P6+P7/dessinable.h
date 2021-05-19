#ifndef PRJ_DESSINABLE_H
#define PRJ_DESSINABLE_H

#include "support_a_dessin.h"

class Dessinable{
	
	protected:
	    SupportADessin* support;
	
	public:
		//Constructeur
	    Dessinable(SupportADessin* support_)
	    :support(support_)
	    {}
	  
	    //Destructeur
	    virtual ~Dessinable() {} ;
	  
	    //Méthode pour dessiner
	    virtual void dessine() = 0;
	    
};


#endif
