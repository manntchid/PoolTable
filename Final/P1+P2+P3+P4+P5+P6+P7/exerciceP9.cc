#include <iostream>
#include "systeme.h"
#include "text_viewer.h"


using namespace std;


int main(){

//Déclaration et Initialisation d'un TextViewer
TextViewer ecran(cout);

//Initialisation de deux boules
Boule a(0.127, 0.02625, 0.2, 0.99,{0.0, 0.0, 1.0, 0.0, 0.0, 0.0},{1.0, 0.0, 2.0, 0.0, 0.0, 0.0}, new TextViewer(ecran));

Boule b(0.127, 0.02625, 0.2, 0.99,{0.08, 0.0, 1.16, 0.0, 0.0, 0.0},{0.0, 0.0, 0.0, 0.0, 5.0, 0.0},new TextViewer(ecran));

//Création d'un système
Systeme premier(3.569, 1.778,new TextViewer(ecran));

//Ajout des deux boules dans le système
premier.ajouter(new Boule(a));
premier.ajouter(new Boule(b));

//Dessin du système dans l'état initial
premier.dessine();
cout<<"------"<<endl;
//Evolution du systeme dans le temps
premier.evolue(0.1);

//Dessin du système après son évolution dans le temps
premier.dessine();
return 0;
}
