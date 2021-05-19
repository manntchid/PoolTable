#include <iostream>
#include <cmath>

#include "Sol.h"


using namespace std ;

//Définition du Constructeur
Sol::Sol(double coeff_frot_, double restitution_, double fr_glis_, double fr_roul_, Vecteur Longueur_, Vecteur Largeur_, Vecteur Origine_,SupportADessin* support_)
	 : Paroi(coeff_frot_,restitution_,Longueur_,Largeur_,Origine_,support_), fr_glis(fr_glis_), fr_roul(fr_roul_)
	 {	
		Vecteur z(0.0,0.0,1.0);
		if(Normal != z and Normal != -z){
			cout<<"Le vecteur Normal du sol n'est pas parallèle à l'axe z"<<endl;
			}
		}

//////////////// Définition des méthodes //////////////////////////////////////////////////////////////////
void Sol::reaction(Boule& bille){
		
		if(abs(bille.vitesse().getvecteur()[2])<=1e-6 and abs(distance(bille).norme_vecteur()-bille.getRayon())<1e-3){
			bille.setfrt_glis(fr_glis*bille.getCoeff_frt());
			bille.setfrt_roul(fr_roul*bille.getCoeff_frt());
			bille.ajoute_force({0.0,0.0,bille.poids()});
			Vecteur x(bille.getEtat());
			Vecteur y({0.0,0.0,bille.getEtat().getvecteur()[2],0.0,0.0,0.0});
			Vecteur z({0.0,0.0,bille.getRayon(),0.0,0.0,0.0});
			x-=y;
			x+=z;
			bille.setEtat(x); //Mise à jour de la composante z de la boule par son rayon	
		}	
		else{
			
			bille.setfrt_glis(0.0);
			bille.setfrt_roul(0.0);
		}
	}
void Sol::collision(Boule& bille){
	
		if(abs(bille.getEtat_dt().getvecteur()[2]) < 0.1){
			Vecteur x(bille.getEtat_dt());
			Vecteur y({0.0,0.0,bille.getEtat_dt().getvecteur()[2],0.0,0.0,0.0});
			x=x-y;
			bille.setEtat_dt(x);
			if(bille.getForce().getvecteur()[2]!=0.0){ //On vérifie que la composante verticale de la force exercée sur la boule est nulle
					Vecteur x(0.0,0.0,(-1.0)*(bille.getForce().getvecteur()[2]));
					bille.ajoute_force(x);
				}
		}
		else{
			Paroi::collision(bille);
		 }
}
