#ifndef PRJ_INTEGRATEUR_H
#define PRJ_INTEGRATEUR_H



class Integrateur{
	protected :
		double pasdetemps ;
		double temps;
		
	public :
		////Prototype du Constructeur
		Integrateur(double pasdetemps_ , double temps_); 
		
		////Prototype de la méthode
		double getPasdetemps();
	};



#endif // PRJ_INTEGRATEUR_H
