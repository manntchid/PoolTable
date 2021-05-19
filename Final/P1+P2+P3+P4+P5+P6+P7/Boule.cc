#include <iostream>
#include <vector>
#include <cmath>
#include "Boule.h"


using namespace std ;


///////////////////// Définition du constructeur //////////////////////////////////////////
		Boule::Boule(double masse_ ,double rayon_, double frot_ , double rest_,Vecteur Etat, Vecteur Etat_dt, SupportADessin* support_)
		: Objet(support_),masse(masse_) , rayon(rayon_) , force(0.0,0.0,0.0),  coeff_frt(frot_), restitution(rest_), frt_roul(0.0), frt_glis(0.0), etat(Etat), etat_dt(Etat_dt) 
		{}

/////////////////////////Définitions des méthodes //////////////////////////////////
		double Boule::masse_()const{
			return masse;
			}
		double Boule::massevolumique() const{
			return ((3.0*masse)/(4*M_PI*(pow(rayon, 3))));
			}
		Vecteur Boule::getEtat() const {
			return etat;
			}
		Vecteur Boule::getEtat_dt() const {
			return etat_dt;
			}
		Vecteur Boule :: force_fr() const{
			Vecteur frt(0);
			for(size_t i(0); i <3 ;++i){
				frt.augmente(frottements().getvecteur()[i]);
				}
			return frt;	
			}
		Vecteur Boule :: moment_fr() const{
			Vecteur frt(0);
			for(size_t i(3); i <6 ;++i){
				frt.augmente(frottements().getvecteur()[i]);
				}
			return frt;	
			}
		Vecteur Boule :: normale() const{
			return -Vecteur(0.0,0.0,poids());
			}
		Vecteur Boule :: pesanteur() const{
			return Vecteur(0.0,0.0,poids());
			}
		double Boule::getRayon() const{
			return rayon ;
			}
		double Boule::getRestitution() const{
			return restitution;
			}
		double Boule::getCoeff_frt() const{
			return coeff_frt ;
			}
		Vecteur Boule :: getForce() const {
			return force;
			}
		double Boule :: poids() const{
			return masse*9.81;
			}
			
///////////////////////////////////////////////////////////////////////////////////////////////////	
		
		void Boule::setfrt_roul(double fr){
			frt_roul = fr;
			}
		void Boule::setfrt_glis(double fg) {
			frt_glis = fg;
			}
		void Boule::setEtat(Vecteur e){
			etat = e;
			}
		void Boule::setEtat_dt(Vecteur e_dt) {
			etat_dt = e_dt;
			}
		void Boule::ajoute_force(Vecteur const& df){
			force=force+df;                
			}
			
/////////////////////////////////////////////////////////////////////////////////////////////////////

		Vecteur Boule::evolution(){
			
			Vecteur acceleration(3);
			acceleration = (1.0/masse)*(force+force_fr());
			Vecteur equation(0) ;
			for(size_t i(0); i < acceleration.getvecteur().size(); ++i){
				equation.augmente(acceleration.getvecteur()[i]);
				}
			for(size_t i(0); i < acceleration_angulaire().getvecteur().size(); ++i){
				equation.augmente(acceleration_angulaire().getvecteur()[i]);
				}
			
			return equation ;
			}
		
		Vecteur Boule :: frottements() const{
			Vecteur vc(vitesse()+((rayon*Vecteur(0.0,0.0,1.0))^vitesse_angulaire()));
			Vecteur frot(0);
			Vecteur force_fr(3);
			Vecteur moment_fr((-masse*9.81)*vitesse_angulaire()*rayon);
			//Division par 0
			if(vitesse_angulaire().norme_vecteur()!=0.0){
					moment_fr=moment_fr*(1.0/vitesse_angulaire().norme_vecteur());
				}
			
			if(vc.norme_vecteur()<=0.1 and vitesse().getvecteur()[2]<1e-6){
				force_fr=(((-masse*9.81)*frt_roul)*vitesse());
				//Division par 0
                if(vitesse().norme_vecteur()!=0.0){
                    force_fr=force_fr*(1.0/vitesse().norme_vecteur());
                }
				moment_fr=moment_fr*frt_roul ;
				
				}
			else{
				force_fr=(((-masse*9.81)*frt_glis)*(vc*(1.0/vc.norme_vecteur())));
				moment_fr=(force_fr^(rayon*Vecteur(0.0,0.0,1.0))) ;
				
				}		
			for(size_t i(0); i <3 ;++i){
				frot.augmente(force_fr.getvecteur()[i]);
				}	
			for(size_t i(0); i <3 ;++i){
				frot.augmente(moment_fr.getvecteur()[i]);
				}	
			
			return frot;
			}
		

		Vecteur Boule :: acceleration_angulaire(){
			Vecteur vect_nulle(0.0,0.0,0.0) ;
			if(vitesse_angulaire() == vect_nulle){
				return vect_nulle ;
				}
			else {
				return moment_fr()*(1.0/((2.0/5.0)*masse*pow(rayon,2.0))); // moment de frottement*(1/J)
				}
			
			}	
			
///////////////////////////////////////////////////////////////////////////////////////////////////////

		Vecteur Boule::position() const{
			Vecteur position_(0);
			for(size_t i(0); i < 3; ++i){
				position_.augmente(etat.getvecteur()[i]);
				}
			 return position_ ;
			}
		Vecteur Boule::angle() const{
			Vecteur angle_(0);
			for(size_t i(3); i < 6; ++i){
				angle_.augmente(etat.getvecteur()[i]);
				}
			 return angle_ ;
			}
		Vecteur Boule::vitesse() const{
			Vecteur vitesse_(0);
			for(size_t i(0); i < 3; ++i){
				vitesse_.augmente(etat_dt.getvecteur()[i]);
				}
			 return vitesse_ ;
			}
		Vecteur Boule::vitesse_angulaire() const{
			Vecteur vitesse_angulaire_(0);
			for(size_t i(3); i < 6; ++i){
				vitesse_angulaire_.augmente(etat_dt.getvecteur()[i]);
				}
			 return vitesse_angulaire_ ;
			}
					
/////////////////// Définitions des méthodes de la super class Objet pour la sous classe Boule ///////////////////////////////////
		
		
//////////////// Première méthode "distance" ////////////////////////////////////////////////////////////////////////
			 Vecteur Boule::distance (Boule bille) {
				 //calcul du point sur bille le plus proche de balle
				 Vecteur x2_(bille.position()-position());
				 Vecteur x2unitaire(x2_*(1/x2_.norme_vecteur()));
				 Vecteur x2(position()+(rayon*x2unitaire));
				 //meme chose pour trouver le point le plus proche sur balle
				 Vecteur x1(bille.position()+(bille.rayon*(-x2unitaire)));
				 
				 return (x1-x2) ;
			 }
			 
			 
  //////////////// Deuxième méthode "t_collision"/////////////////////////////////////////////////////////////////////
			 double Boule::t_collision (Boule bille, double temps, double duree, IntegrateurEuler inte_eul) {
				 	 
				 Vecteur nul(3);                                       //Vecteur nul pour tester les conditions
				 double temps_collision(0.0);
				 double tau0(0.0);
				 Boule b1(bille);
				 Boule b2(*this);
				 
				 //On prend les vitesses des boules intégrées jusqu'au temps se trouvant en deuxième argument
				 Vecteur v1(inte_eul.integre(b1,temps).vitesse());
				 Vecteur v2(inte_eul.integre(b2,temps).vitesse());
	             //On prend les positions des boules intégrées jusqu'au temps se trouvant en deuxième argument
				 Vecteur x1(inte_eul.integre(b1,temps).position());
				 Vecteur x2(inte_eul.integre(b2,temps).position());
				 //On prend les positions des boules intégrées jusqu'au temps+duree (2ème + 3ème arguments)
				 Vecteur x1p(inte_eul.integre(b1,temps+duree).position());    
				 Vecteur x2p(inte_eul.integre(b2,temps+duree).position());    
				 //Interpolation linéaire
				 Vecteur av(x2-x1);
				 Vecteur bv(x2p - x1p - av);
				//Initialisation des coefficients de l'équation à résoudre
					double A(bv.carre_norme());
					double B((2.0*av)*bv);
					double C(av.carre_norme()-(pow(b1.rayon+b2.rayon, 2.0)));
				
				//Résolution de l'équation 
				double delta(pow(B, 2.0) - (4.0*A*C));
				  //si l'équation a une solution 
				  if (delta == 0.0){
					 tau0 = (-B/(2.0*A));	                                   
				  } 
				  // si l'équation a deux solutions
				  else if(delta > 0.0){ 
					                      
					 double tau1(0.0);
					 double tau2(0.0);
					 tau1 = ((-B + sqrt(delta))/(2.0*A));                
					 tau2 = ((-B - sqrt(delta))/(2.0*A));	
					 //prendre la plus petite des solutions
					 if ((tau1 > 0.0) and (tau2 > 0.0)){                     
						 if(tau1 > tau2){
							 tau0 = tau2;
						 } 
						 else if(tau2 > tau1){  
							 tau0 = tau1;                          
						 }                                        
					 }
					 //si une des solutions est négative
					 else if ((tau1 > 0.0) and (tau2 < 0.0)){              
						 tau0 = tau1;
					 } 
					 //si l'autre solution est négative
					 else if ((tau1 < 0.0) and (tau2 > 0.0)) {             
						 tau0 = tau2;
					 }                                   
				  }
				 //condition sur tau0 s'il y a une collision
				 if(tau0 > 0.0 and tau0 < 1.0){                           
					 temps_collision = tau0*duree;
					
				 }	
				 //S'il n'y a pas de collision	  
				 else{
					 return -1;
				 }
		 //Si le temps de colllision est inférieur
		 if(temps_collision < 2e-5){
			return -1;
		 }
		 else{
			return temps_collision;
		 }
		    
		} 


  ////////////////// Troisième méthode "collision" ////////////////////////////////////////////////////////
		void Boule::collision (Boule& bille) {
				//mu1: bille.coeff_frt     alpha1: bille.restitution
			    //mu2: this->coeff_frt	   alpha2: this->restitution
				
				Vecteur x3(bille.position()-position());
				Vecteur n(x3*(1.0/x3.norme_vecteur()));
				double alpha(bille.restitution*restitution);
				double mu(bille.coeff_frt*coeff_frt);
				double lambda((1.0 + alpha)*(masse/(bille.masse + masse)));
				Vecteur delta_vit(3);
				Vecteur delta_vit_ang(3);
				
                //test pour un choc entre deux boules
				if (distance(bille).norme_vecteur() <= (rayon + bille.getRayon())){
					
					//mise à jour des forces (facultatif)
					//vitesse v*
					Vecteur v3(vitesse()-(bille.vitesse()));
					double v_etoile(v3*n);
					//vitesse de contact
					Vecteur v_c((-v3)+(v_etoile*n)+(n^((bille.getRayon()*bille.vitesse_angulaire())+(rayon*vitesse_angulaire()))));
					//condition sur mu alpha et v_c
					if ((7.0*mu*v_etoile*(1.0 + alpha)) >= 2.0* v_c.norme_vecteur()){
						delta_vit = ((lambda*v_etoile)*n) - (((2.0*masse)/(7.0*(bille.masse + masse)))*(v_c));
						delta_vit_ang = ((5.0*masse)/(7.0*bille.rayon*(bille.masse + masse)))*(n^v_c);
					} else {
						delta_vit = (lambda*v_etoile)*(n -(mu*(v_c*(1.0/v_c.norme_vecteur()))));
						delta_vit_ang = ((5.0*mu*lambda*v_etoile)/(2.0*bille.rayon))*(n^(v_c*(1.0/v_c.norme_vecteur())));
					}
					//mise à jour  
					Vecteur vect_vit1(bille.vitesse()+delta_vit);
					Vecteur vect_vit_angu1(bille.vitesse_angulaire() + delta_vit_ang);
					Vecteur vect_vit2(vitesse() - (bille.masse/masse)*delta_vit);
					Vecteur vect_vit_angu2(vitesse_angulaire() + ((bille.masse*bille.getRayon())/(masse*rayon))*delta_vit_ang);
					for(size_t i(0); i<3;++i){
						vect_vit1.augmente(vect_vit_angu1.getvecteur()[i]);
						vect_vit2.augmente(vect_vit_angu2.getvecteur()[i]);
						}
					bille.setEtat_dt(vect_vit1);
					setEtat_dt(vect_vit2);
				}
				
			}
		
//////////////// Définition opérateur <<  ////////////////////////////////////////////////////////////////////////////
		ostream& Boule:: affiche(ostream& sortieboule) const{
			    sortieboule<<masse<<" # masse"<<endl;
				sortieboule<<rayon<<" # rayon"<<endl;
				sortieboule<<massevolumique()<<" # masse volumique"<<endl;
				sortieboule<<position()<<" # position"<<endl;
				sortieboule<<angle()<<" # angles"<<endl;
				sortieboule<<vitesse()<<" # vitesse"<<endl;
				sortieboule<<vitesse_angulaire()<<" # vitesse angulaire"<<endl;
				sortieboule<<force<<" # force"<<endl;
				sortieboule<<restitution<<" # restitution"<<endl;
				sortieboule<<coeff_frt<<" # coef_frt"<<endl;
				sortieboule<<frt_glis<<" # fr_glis"<<endl;
				sortieboule<<frt_roul<<" # fr_roul"<<endl;
				
			return sortieboule;
			}
	    ostream& operator<<(ostream& sortieboule, Boule const& zboule){
			return zboule.affiche(sortieboule) ;
			}
