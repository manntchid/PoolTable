#include <iostream>
#include "text_viewer.h"
#include "Boule.h"
#include "Systeme.h"


using namespace std ;

 
void TextViewer::dessine(Systeme const& systeme)
{
  for(auto const& objet : systeme.getMobile()){
	  dessine(*objet);
	  }
}

void TextViewer::dessine(Boule const& boule)
{
 
  flot <<boule<<endl;
}

void TextViewer:: dessine(Paroi const& paroi){
	
	flot<<"Paroi allant de "<<endl;
	}
	
void TextViewer:: dessine(Sol const& sol){
	
	flot<<"Sol allant de "<<endl;
	}
