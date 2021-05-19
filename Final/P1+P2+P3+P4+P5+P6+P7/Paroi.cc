#include <iostream>

#include "Paroi.h"
#include <cmath>

using namespace std ;

//Définition du Constructeur
Paroi :: Paroi(double coeff_frot_, double restitution_, Vecteur Longueur_, Vecteur Largeur_, Vecteur Origine_, SupportADessin* support_)
		 :Objet(support_),coeff_frot(coeff_frot_), restitution(restitution_), Normal((Longueur_^Largeur_)*(1.0/((Longueur_^Largeur_).norme_vecteur()))),Longueur(Longueur_), Largeur(Largeur_), Origine(Origine_)
		 {
			 if((Longueur*Largeur)!=0.0){
				 cout<<"Les vecteurs Longueur et Largeur ne sont pas orthogonaux !"<<endl;
				 }
			 }
			 
//Définition des méthodes pour aovir les points de la paroi
Vecteur Paroi::point_a() const{
    return Origine;
}
Vecteur Paroi::point_b() const{
    return Origine + Longueur;
}
Vecteur Paroi::point_c() const{
    return Origine + Largeur;
}
Vecteur Paroi::point_d() const{
    return Origine + Largeur + Longueur;
}

///////////// Définition des méthodes de la super classe Objet pour la sous classe Paroi /////////////
Vecteur Paroi :: distance(Boule bille){
	Vecteur x2((((Origine-bille.position())*Normal)*Normal)+bille.position());
	Vecteur EL((Longueur)*(1.0/Longueur.norme_vecteur()));
	Vecteur El(Normal^EL);
	
	double xKL((x2-Origine)*EL);
	double xKl((x2-Origine)*El);
	
	if(xKL > Longueur.norme_vecteur()){
		x2=x2-((xKL-Longueur.norme_vecteur())*EL);
		}
	else if(xKL < 0.0){
		x2=x2-(xKL*EL); 
		}
	if(xKl > Largeur.norme_vecteur()){
		x2=x2-((xKl-Largeur.norme_vecteur())*El);
		}
	else if(xKl < 0.0){
		x2=x2-(xKl*El);
		}
	return bille.position()-x2;
	
	} 

double Paroi :: t_collision(Boule bille, double temps, double duree, IntegrateurEuler inte_eul){
										
		 double temps_collision(0.0);
		 double tau0(0.0);
		 bille=inte_eul.integre(bille,temps);
		 //calcul des écarts vectoriels
			 Vecteur D(distance(bille)); //Distance avant l'intégration du prochain pas de temps
			 bille=inte_eul.integre(bille, duree);        
			 Vecteur D_prime(distance(bille));//Distance après l'intégration du prochain pas de temps
			 //cas où il y a une collision
			 if((D_prime.norme_vecteur() < bille.getRayon()) or ((D*D_prime) < 0.0)){
			 //calcul de tau pour ce cas de collision
			 tau0 = (bille.getRayon()-(Normal*D))/((Normal*D_prime)-(Normal*D));
			 temps_collision=tau0*duree;	 
			 }
			 else{
			 temps_collision = -1 ;
				 }
		//Si "duree" == 0.0, il n'y a pas de collision
		if(duree == 0.0){
			temps_collision = -1;
			}
		
		return temps_collision;	
	} 
		
void Paroi :: collision(Boule& bille){
	//Condition de collision
	
	if(distance(bille).norme_vecteur() <= bille.getRayon() or abs(distance(bille).norme_vecteur()-bille.getRayon()) < bille.getRayon()){
				double alpha(bille.getRestitution()*restitution);
				double mu(bille.getCoeff_frt() * coeff_frot);
				double lambda(1.0 + alpha);
				Vecteur delta_vit(3);
				Vecteur delta_vit_ang(3);
				//vitesse v*
				double v_etoile((-bille.vitesse())*Normal);		
				//vitesse de contact
				Vecteur v_c(bille.vitesse()+(v_etoile*Normal)+(Normal^(bille.getRayon()*bille.vitesse_angulaire())));
				
			    //condition sur mu alpha et v_c
				if ((7.0*mu*v_etoile*(1.0 + alpha)) >= 2.0* v_c.norme_vecteur()){
					delta_vit = (((lambda*v_etoile)*Normal) - ((2.0/7.0)*(v_c)));
					delta_vit_ang = ((5.0/(7.0*bille.getRayon()))*(Normal^v_c));
				} 
				else {
					double normaliser(1.0);
					//Division par 0
					if(v_c.norme_vecteur() != 0.0){
						normaliser = 1.0/v_c.norme_vecteur();
					}
					delta_vit = (lambda*v_etoile)*(Normal -(mu*(v_c*(normaliser))));
					delta_vit_ang = ((5.0*mu*lambda*v_etoile)/(2.0*bille.getRayon()))*(Normal^(v_c*(normaliser)));
				}
				//mise à jour
				Vecteur vect_vit1(bille.vitesse()+delta_vit);
				Vecteur vect_vit_angu1(bille.vitesse_angulaire() + delta_vit_ang);
				bille.setEtat_dt({vect_vit1.getvecteur()[0], vect_vit1.getvecteur()[1], vect_vit1.getvecteur()[2], vect_vit_angu1.getvecteur()[0], vect_vit_angu1.getvecteur()[1], vect_vit_angu1.getvecteur()[2]});				
	}
				
}

