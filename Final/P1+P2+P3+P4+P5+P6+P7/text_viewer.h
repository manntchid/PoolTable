#ifndef PRJ_TEXT_VIEWER_H
#define PRJ_TEXT_VIEWER_H
 
 
#include <iostream>
#include "support_a_dessin.h"
 
 
class TextViewer : public SupportADessin {
	private:
      std::ostream& flot;
	
	public:
		//Constructeur
	    TextViewer(std::ostream& flot_)
		: flot(flot_)
	    {}
	    
	    //Destructeur
	    virtual ~TextViewer() {}
		
		//Prototypes des méthodes 
	    void dessine(Boule const& boule) override;
	    void dessine(Systeme const& systeme) override;
	    void dessine(Paroi const& paroi) override;
	    void dessine(Sol const& sol) override;
 
};
 
#endif
