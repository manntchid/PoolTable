#include <iostream>
#include <vector>
#include "Vecteur.h"
#include "Boule.h"
#include <initializer_list>
#include <cmath>

using namespace std ;

int main (){

//Initialisation des boules
Boule b1(0.127,0.02625, 0.2, 0.99,{-1.0,0.0,0.02625,0.0,0.0,0.0},{2.0,0.0,0.0,0.0,76.1905,0.0});
Boule b2(0.127,0.02625, 0.2, 0.99,{0.5525,0.0,0.02625,0.0,0.0,0.0},{0.0,0.0,0.0,0.0,0.0,0.0});
Boule b3(0.127,0.02625, 0.2, 0.99,{0.5, 0.0 , 0.02625,0.0,0.0,0.0},{0.0,0.0,0.0,0.0,0.0,0.0});

//Affichage des boules
cout<<"Boule 1 : "<<endl<<b1<<endl;
cout<<"Boule 2 : "<<endl<<b2<<endl;
cout<<"Boule 3 : "<<endl<<b3<<endl;

return 0;
}
