#include <iostream>
#include "Vecteur.h"
#include <string>


using namespace std ;

int main (){

//Initialisation des vecteurs utilisés
Vecteur vect1(1.0, 2.0, -0.1);	//premier vecteur
Vecteur vect2(2.6, 3.5,  4.1);	//deuxième vecteur
Vecteur vect3(vect1);  			//copie de V1
Vecteur vect4(3);      			//le vecteur nul

cout << "Vecteur 1 : " << vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (vect1 != vect3) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;

cout << "( " << vect1 << ") + ( " << vect2 << ") = " << "( " << vect1+vect2 << ")" << endl;
cout << "( " << vect2 << ") + ( " << vect1 << ") = " << "( " << vect2+vect1 << ")" << endl;
cout << "( " << vect1 << ") + ( " << vect4 << ") = " << "( " << vect1+vect4 << ")" << endl;
cout << "( " << vect4 << ") + ( " << vect1 << ") = " << "( " << vect4+vect1 << ")" << endl;
cout << "( " << vect1 << ") - ( " << vect2 << ") = " << "( " << vect1-vect2 << ")" << endl;
cout << "( " << vect2 << ") - ( " << vect2 << ") = " << "( " << vect2-vect2 << ")" << endl;
cout << "- ( " << vect1 << ") " << " = " << "( " << -vect1 << ")" << endl;
cout << "- ( " << vect2 << ") + ( " << vect1 << ") = " << "( " << -vect2+vect1 << ")" << endl;
cout << "3*( " << vect1 << ") = " << "( " << 3*vect1 << ")" << endl;
cout << "( " << vect1 << ") * ( " << vect2 << ") = " << "( " << vect1*vect2 << ")" << endl;
cout << "( " << vect2 << ") * ( " << vect1 << ") = " << "( " << vect2*vect1 << ")" << endl;
cout << "( " << vect1 << ") ^ ( " << vect2 << ") = " << "( " << (vect1^vect2) << ")" << endl;
cout << "|| " << vect1 << "||^2 = " << vect1.carre_norme()  << endl;
cout << "|| " << vect1 << "|| = " << vect1.norme_vecteur()  << endl;
cout << "|| " << vect2 << "||^2 = " << vect2.carre_norme()  << endl;
cout << "|| " << vect2 << "|| = " << vect2.norme_vecteur()  << endl;


return 0;
}
