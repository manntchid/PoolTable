#ifndef PRJ_VECTEUR_H
#define PRJ_VECTEUR_H

#include <vector>


class Vecteur{
	private :
		std::vector<double> vecteur ;
		bool arret ;
			
	public :
		//Prototype des Constructeurs
		Vecteur(size_t dimension);
		Vecteur(double x, double y, double z);
		Vecteur(std::initializer_list<double> const& liste);
		
		//Prototype du Constructeur de copie 
		Vecteur(const Vecteur& vecteur_a_copier);
		
		//Prototype des méthodes
		void augmente(double nombre) ;							//ajoute une composante à un vecteur
		std::ostream& affiche(std::ostream& sortie) const;		//affiche les composantes d'un vecteur
		std::vector<double> getvecteur() const;					//accesseur
		
		//Prototype des méthodes de calcul des vecteurs
		bool compare(Vecteur vector_comp);						//comparaison entre deux vecteurs
		void addition(Vecteur const& autre) ;					//addition de deux vecteurs
		void soustraction(Vecteur const& autre) ;				//soustraction d'un vecteur à un autre
		Vecteur oppose() const;									//opposé d'un vecteur
		void mult(double x);									//multiplication d'un vecteur par un scalaire
		double prod_scal(Vecteur autre) const;					//produit scalaire entre deux vecteurs
		Vecteur prod_vect(Vecteur autre) const;					//produit vectoriel entre deux vecteurs
		double norme_vecteur() ;								//norme d'un vecteur
		double carre_norme();									//le carré de la norme d'un vecteur
		
		//Prototype des opérateurs internes
		void operator-=(Vecteur const& w);
		void operator+=(Vecteur const& w);
		void operator*=(double k);  //v*= double
		
	};
	
	//Prototypes des opérateurs externes
	std::ostream& operator<<(std::ostream& sortie , Vecteur const& z) ; //opérateur de sortie
	bool operator==(Vecteur v, Vecteur const& w);						//égalité logique
	bool operator!=(Vecteur v, Vecteur const& w);						//non égalité
	Vecteur operator+(Vecteur v, Vecteur const& w); 					//addtition
	Vecteur operator-(Vecteur v, Vecteur const& w); 					//soutraction
	Vecteur operator-(Vecteur const& v);		    					//opposé
	Vecteur operator*(double k, Vecteur v); 							//commutativité de *
	Vecteur operator*(Vecteur v ,double k); 							//commutativité de *
	double operator*(Vecteur const& v ,Vecteur const& w);				//produit scalaire
	Vecteur operator^(Vecteur v ,Vecteur w);							//produit vectoriel
	

#endif // PRJ_VECTEUR_H
