#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vecteur.h"

 
using namespace std ;


/////////// Définitions des Constructeurs ///////////////////////////////////////////
		Vecteur :: Vecteur(size_t dimension){
			for(size_t i(0) ; i < dimension; ++i){  //pour l'appel du constructeur, il faut faire -3 pour le nombre de coordonnées, construction d'un vecteur nul
				vecteur.push_back(0);
				} 
			}
		Vecteur :: Vecteur(double x, double y, double z){		//construction d'un vecteur 3D
			vecteur.push_back(x);
			vecteur.push_back(y); 
			vecteur.push_back(z);
			}
		Vecteur :: Vecteur(initializer_list<double> const& liste){ //construction d'un vecteur par liste
			for (auto a : liste){
				vecteur.push_back(a);
				}
			}
			
////////////////////// Définition du Constructeur de copie ////////////////////////////////
		Vecteur :: Vecteur(const Vecteur& vecteur_a_copier){
			vecteur.clear();
			for(auto composante : vecteur_a_copier.getvecteur()){
				vecteur.push_back(composante);
				}
			}
			
//Définitions des méthodes		
		void Vecteur::augmente(double nombre){
			vecteur.push_back(nombre);
			}
			
		ostream& Vecteur::affiche(ostream& sortie) const{
			for(size_t i(0) ; i < vecteur.size(); ++i){ 
				sortie << vecteur[i]<<" ";
				}
			 return sortie;
			}	
			
		vector<double> Vecteur::getvecteur() const{
			return vecteur ;
			}
				
//////////////////////// Définitions des méthodes de calcul des vecteurs ////////////////////////////////
		bool Vecteur::compare(Vecteur vector_comp){
			arret = true;  // J'ai initialisé la variable arret par true 
			for(size_t i(0) ; i < vecteur.size() && arret == true ; ++i){ // car sinon dans cette comparaison, il y a un problème
				if(vecteur[i] == vector_comp.getvecteur()[i]){
					arret = true ;
					}
				else{
					arret = false ; 
					}
			}
			return arret ;
		}
		
		void Vecteur::addition(Vecteur const& autre) {
				if(vecteur.size() == autre.getvecteur().size()){
					for(size_t i(0) ; i < vecteur.size() ; ++i){
						vecteur[i]+=autre.getvecteur()[i];
						}
				}
				else {
					throw string("Erreur : les vecteurs ");
					}
			}
			
		void Vecteur:: soustraction(Vecteur const& autre) {
				if(vecteur.size() == autre.getvecteur().size()){
					for(size_t i(0) ; i < vecteur.size() ; ++i){
						vecteur[i]-=autre.getvecteur()[i];
						}
				}
				else {
					throw string("Erreur : les vecteurs ");
					}
			}
			
		Vecteur Vecteur::oppose() const{
			Vecteur vecteur_oppose(0) ;
				for(size_t i(0) ; i < vecteur.size() ; ++i){
					if(vecteur[i] == 0.0){
						vecteur_oppose.augmente(0.0);
						}
					else{
						vecteur_oppose.augmente((-1.0)*vecteur[i]);
						}
					
				}
			return vecteur_oppose ;
			}
			
		void Vecteur::mult(double x){ 
			Vecteur vecteur_multiplie(0) ;
				for(size_t i(0) ; i < vecteur.size() ; ++i){
					vecteur[i]*= x;
				}
			}
			
		double Vecteur::prod_scal(Vecteur autre) const{
				if(vecteur.size() == autre.getvecteur().size()){
					double produit(0.0)  ;
					for(size_t i(0) ; i < vecteur.size() ; ++i){
							produit = produit + (vecteur[i]*autre.getvecteur()[i]);
						}
					return produit ;
				}
				else{
					throw string("Erreur : les vecteurs ");
					}
			}
		Vecteur Vecteur::prod_vect(Vecteur autre) const{
				if(vecteur.size() == autre.getvecteur().size()){
					Vecteur produitvect(0);
					if(vecteur.size()==3 && autre.getvecteur().size()==3){
					   for(size_t i(0) ;i < 3;++i){
							produitvect.augmente((vecteur[(i+1)%3]*autre.getvecteur()[(i+2)%3])-(vecteur[(i+2)%3]*autre.getvecteur()[(i+1)%3]));
							}
						/*Simplification du code ci_dessous en utilisant le modulo et une boucle for,
						   produitvect.augmente((vecteur[1]*autre.getvecteur()[2])-(vecteur[2]*autre.getvecteur()[1]));
						   produitvect.augmente((vecteur[2]*autre.getvecteur()[0])-(vecteur[0]*autre.getvecteur()[2]));
					       produitvect.augmente((vecteur[0]*autre.getvecteur()[1])-(vecteur[1]*autre.getvecteur()[0]));
					     */				
						}
					return produitvect ;
				}
				else{
					throw string("Erreur : les vecteurs ");
					}
			}

		double Vecteur::norme_vecteur(){
			double norme1(0.0);
			for(size_t i(0); i < vecteur.size(); ++i){
				norme1 = norme1 + pow(vecteur[i],2) ;
				}
			return sqrt(norme1);
			} 
			
		double Vecteur:: carre_norme(){
			return pow(norme_vecteur(),2);
			}
		
//////////// Défintions des opérateurs internes ////////////////////////////////////////////////
		void Vecteur:: operator-=(Vecteur const& w){
			soustraction(w);
			}
		void Vecteur::operator+=(Vecteur const& w){
			 addition(w);
			}
		void Vecteur:: operator*=(double k){  //v*= double
			mult(k);
			}
			
//////// Définitions des opérateurs externes ////////////////////////////////////////////////////
		ostream& operator<<(ostream& sortie , Vecteur const& z){
			return z.affiche(sortie);
			} 
			
		bool operator==(Vecteur v, Vecteur const& w){
			return v.compare(w);
			}
		bool operator!=(Vecteur v, Vecteur const& w){
			return (not v.compare(w));
			}
		Vecteur operator+(Vecteur v, Vecteur const& w){
			v.addition(w);
			return v;
			}
		
		Vecteur operator-(Vecteur v, Vecteur const& w){
			v.soustraction(w);
			return v;
			}
	    Vecteur operator*(double k, Vecteur v){
			v.mult(k);
			return v;
			}
		Vecteur operator*(Vecteur v ,double k){
			v.mult(k);
			return v;
			}
		
		Vecteur operator-(Vecteur const& v){
			return v.oppose();
			}

		
		double operator*(Vecteur const& v ,Vecteur const& w){
			return v.prod_scal(w);
			}
		Vecteur operator^(Vecteur v ,Vecteur w){
			return v.prod_vect(w);
			}
