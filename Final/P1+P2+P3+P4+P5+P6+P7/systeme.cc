#include <iostream>
#include "systeme.h"
#include <memory>
#include <vector>
#include <cmath>
#include <limits>
using namespace std ;
/*
 * Par rapport à notre convention cf paroi.h pour que le point (0.0,0.0,0.0) soit au centre de la table, 
 * l'origine du sol doit être au point (longueur_/2.0,-largeur_/2,0.0)																								
*/

//////////////////// Définition du Constructeur //////////////////////////////////////////// 
Systeme::Systeme(double longueur_, double largeur_,SupportADessin* vue)
  :Dessinable(vue),
   sol_billard(0.05,0.4,0.1,0.05,{0.0,largeur_,0.0},{-longueur_,0.0,0.0},{longueur_/2.0,-largeur_/2.0,0.0},vue),
   paroi1(0.15,0.9,{0.0,0.0,-hauteur},{0.0,largeur_,0.0},{-longueur_/2.0,-largeur_/2.0,hauteur}, vue),
   paroi2(0.15,0.9,{0.0,0.0,-hauteur},{longueur_,0.0,0.0},{-longueur_/2.0,largeur_/2.0,hauteur}, vue),
   paroi3(0.15,0.9,{0.0,0.0,-hauteur},{0.0,-largeur_,0.0},{longueur_/2.0,largeur_/2.0,hauteur}, vue),
   paroi4(0.15,0.9,{0.0,0.0,-hauteur},{-longueur_,0.0,0.0},{longueur_/2.0,-largeur_/2.0,hauteur}, vue)
  {
	  collisionable.push_back(&sol_billard);
	  collisionable.push_back(&paroi1);
	  collisionable.push_back(&paroi2);
	  collisionable.push_back(&paroi3);
	  collisionable.push_back(&paroi4);
	  }

////////////////////// Définition des Méthodes ////////////////////////////////////////////
void Systeme :: ajouter(Boule* const& boule1){
	if(boule1 != nullptr){
	   mobile.push_back(boule1);
	   collisionable.push_back(boule1);
	   }
	}
	
vector<Boule*> const& Systeme::getMobile() const{
	return mobile ;
	}
	
vector<Objet*> const& Systeme::getcollisionable() const {
   return collisionable;
}

void Systeme :: interpenetration(){
	Vecteur dx(3);
	double e(0.0);
	double eps(numeric_limits<double>::epsilon());
	double lambda(0.0);
	for(size_t i(0); i < mobile.size(); ++i){
		for(size_t j=i+1; j < mobile.size(); ++j){
			dx=mobile[i]->position()-mobile[j]->position();
			e=dx.norme_vecteur()-mobile[i]->getRayon()-mobile[j]->getRayon();
			if(e<0.0){
				cout<<"Les boules s'interpénetrent"<<endl;
				if(-eps*mobile[i]->position().norme_vecteur() < e){
					e=-eps*mobile[i]->position().norme_vecteur();
					}
				if(-eps*mobile[j]->position().norme_vecteur() < e){
					e=-eps*mobile[j]->position().norme_vecteur();
					}
				lambda = (1.0+eps)*e/(2.0*dx.norme_vecteur());
				//Il faut que dx soit de dimension 6
				for(size_t i(0) ; i < 3 ;++i){
					dx.augmente(0.0);
				}
				mobile[i]->setEtat(Vecteur(mobile[i]->getEtat()-lambda*dx));
				mobile[j]->setEtat(Vecteur(mobile[j]->getEtat()+lambda*dx));
				}
			}
		}
	}

void Systeme :: evolue(double pas_de_temps){
	
	//1) arrêter les boules quasi immobiles
	for(auto const& boule : mobile){
		if(boule->vitesse().norme_vecteur() < 1e-2 and boule->vitesse_angulaire().norme_vecteur() < 1e-1 and boule->getForce().norme_vecteur() < 1e-10){
			boule->setEtat_dt(Vecteur(6));
			}
		//2) calculer les forces qui s'appliquent à chaque boule 
		if(boule->getForce() != Vecteur(3)){
			boule->ajoute_force(-boule->getForce());
			}
		boule->ajoute_force(Vecteur(0.0,0.0,-boule->poids()));
		sol_billard.reaction(*boule); 
		}
	
	// 3)gérer toutes les collisions
	double dt_effectue(0.0);
	double ecart_collision(0.0);
	double temps_collision_proche(0.0);
	Boule* boule_collision(nullptr) ;
	Objet* objet_collision(nullptr) ;
	vector<Objet*> implique;
	if(mobile.size() != 0 and collisionable.size() != 0){
		//Tant qu'il y a une collision
		do{
			
			temps_collision_proche=pas_de_temps;
			IntegrateurEuler p1(pas_de_temps-dt_effectue, 0.0);
			for(auto const& boule : mobile){
				for(auto const& objet : collisionable){
					if(objet != boule){
					ecart_collision= objet->t_collision(*boule,0.0,pas_de_temps-dt_effectue,p1);
						if(ecart_collision >= 0.0 and ecart_collision < temps_collision_proche){
						//Noter la boule et l'objet collisionné
						boule_collision = boule;
						objet_collision = objet;
						temps_collision_proche = ecart_collision;			
						}
					}
				}
			}
			
			if(temps_collision_proche != -1 and temps_collision_proche < pas_de_temps){
				cout<<"Temps collision : t + " <<temps_collision_proche+dt_effectue<<endl;	
				if(temps_collision_proche != 0.0){
				//On intègre sur le sous-pasdetemps
				IntegrateurEuler p2(temps_collision_proche,0.0);
				*boule_collision = p2.integre(*boule_collision,temps_collision_proche);
				cout<<"Boule : "<<endl<<*boule_collision<<endl;
				cout<<"Avec : "<<endl;
					for(auto const& boule2 : mobile){
					 if(boule2==boule_collision){
						//On insère dans le tableau "implique" les boules impliquées dans la collision
						implique.push_back(boule2);
					   }
					 if(boule2==objet_collision){
						//On intégre l'objet en collision si celui-ci est une boule
						*boule2=p2.integre(*boule2,temps_collision_proche);
						//On insère dans le tableau "implique" les boules impliquées dans la collision
						implique.push_back(boule2);	
					   }  
					}
			    }
			    //On gère la collision
				objet_collision -> collision(*boule_collision);
				implique.push_back(boule_collision);
				implique.push_back(objet_collision);
				dt_effectue+=temps_collision_proche;
				
				}
						
		}while(temps_collision_proche < pas_de_temps);
		
   
	//4) Finir le pasdetemps
		
		bool sous(false) ;
		size_t count(0);
		for(auto const& boule : mobile){
			//On vérifie si la boule qui se trouve dans le tableau "mobile" se trouve dans le tableau "implique"
			while(sous==false and count < implique.size()){
				if(boule==implique[count]){
					sous = true ;
					}
					++count;
				}
			if(dt_effectue >= 0.0 and sous==true){
			    IntegrateurEuler p3(pas_de_temps-dt_effectue, 0.0);
			    *boule=p3.integre(*boule,pas_de_temps-dt_effectue);
				}
			else{
				
				IntegrateurEuler p(pas_de_temps, 0.0);
				*boule=p.integre(*boule,pas_de_temps);
				}
			 sous=false ;
			 count=0;
		    }
		    
	//5) corriger les boules qui s'interpénètrent
         interpenetration();
		
  }
}


  
