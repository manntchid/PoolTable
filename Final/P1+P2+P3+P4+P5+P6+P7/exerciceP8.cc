#include <iostream>
#include <vector>
#include <memory>
#include "systeme.h"
#include "text_viewer.h"
#include "Boule.h"

using namespace std;

int main(){

//Déclaration et Initialisation d'un TextViewer
TextViewer text(cout);

//Initialisation de trois boules
Boule b1(0.127,0.02625, 0.2, 0.99,{-1.0,0.0,0.02625,0.0,0.0,0.0},{2.0,0.0,0.0,0.0,76.1905,0.0}, new TextViewer(text));

Boule b2(0.127,0.02625, 0.2, 0.99,{0.5525,0.0,0.02625,0.0,0.0,0.0},{0.0,0.0,0.0,0.0,0.0,0.0}, new TextViewer(text));

Boule b3(0.127,0.02625, 0.2, 0.99,{0.5, 0.0 , 0.02625,0.0,0.0,0.0},{0.0,0.0,0.0,0.0,0.0,0.0}, new TextViewer(text));

//Création d'un système
Systeme premier(3.569, 1.778, new TextViewer(text)) ;

//Ajout des trois boules dans le système
premier.ajouter(new Boule(b1));
premier.ajouter(new Boule(b2));
premier.ajouter(new Boule(b3));

//Dessin du système
premier.dessine();

return 0;
}
