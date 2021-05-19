#include <iostream>
#include <memory>
#include <cmath>
#include "systeme.h"
#include "text_viewer.h"


using namespace std ;


int main(){
Systeme premier(3.569,1.778);
Boule b1(0.127 ,0.02625, 0.2 , 0.99,{0.3, 0, 1.065, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
Boule b2(0.127 ,0.02625, 0.2 , 0.99,{0.0, 0.0, 1.0, 0.0, 0.0, 0.0}, {1.0, 0.0, 2.0, 0.0, 0.0, 0.0});
Boule b3(0.127 ,0.02625, 0.2 , 0.99,{0.08, 0.0, 1.16, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 5.0, 0.0});
Boule b4(0.127 ,0.02625, 0.2 , 0.99,{-1.0, 0.0, 0.02625, 0.0, 0.0, 0.0}, {2.0, 0.0, 0.0, 0.0, 76.1905, 0.0});
Boule b5(0.127 ,0.02625, 0.2 , 0.99,{0.5, 0.0, 0.02625, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
Boule b6(0.127 ,0.02625, 0.2 , 0.99,{0.5525, 0.0, 0.02625, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
Boule b7(0.127 ,0.02625, 0.2 , 0.99,{-1.0, 0.0, 0.02625, 0.0, 0.0, 0.0}, {0.85, 0.0, 0.0, 0.0, -100.0, 0.0});
//===============Test du P11.4.1 Chute Simple==================================================================	


/*premier.ajouter(&b1);
for(int i(0); i<100;++i){
cout<<"=================================="<<endl;
cout<<"t = "<<i*0.01<<endl;
cout<<"=================================="<<endl;
for(auto const& boule : premier.getMobile()){
	  //Affichage des boules
	  cout<<"Boule : "<<endl<<*boule<<endl;             
    } 
premier.evolue(0.01);
}*/

//===============Test du P11.4.2 "Chute du second exemple P7"===================================================

/*premier.ajouter(&b2);
premier.ajouter(&b3);
for(int i(0); i<684;++i){
cout<<"=================================="<<endl;
cout<<"t = "<<i*0.01<<endl;
cout<<"=================================="<<endl;
for(auto const& boule : premier.getMobile()){
	  //Affichage des boules
	  cout<<"Boule : "<<endl<<*boule<<endl;             
    } 
premier.evolue(0.01);
}*/
//===============Test du P11.4.3 "Une balle roule"==============================================================

/*premier.ajouter(&b4);
for(int i(0); i<1157;++i){ 
cout<<"=================================="<<endl;
cout<<"t = "<<i*0.01<<endl;
cout<<"=================================="<<endl;
for(auto const& boule : premier.getMobile()){
	  //Affichage des boules
	  cout<<"Boule : "<<endl<<*boule<<endl;             
    } 
premier.evolue(0.01);
}*/

//===============Test du P11.4.4 "Balle roulant, choc une balle"================================================

/*premier.ajouter(&b4);
premier.ajouter(&b5);

for(int i(0); i<1105;++i){
cout<<"=================================="<<endl;
cout<<"t = "<<i*0.01<<endl;
cout<<"=================================="<<endl;
for(auto const& boule : premier.getMobile()){
	  //Affichage des boules
	  cout<<"Boule : "<<endl<<*boule<<endl;             
    }  
premier.evolue(0.01);
}*/

//===============Test du P11.4.5 "Balle roulant, choc 2 balles"===============================================

/*premier.ajouter(&b4);
premier.ajouter(&b6);
premier.ajouter(&b5);

for(int i(0); i<1088;++i){ //Les valeurs sont justes jusqu'à t = 0.73 
cout<<"=================================="<<endl;
cout<<"t = "<<i*0.01<<endl;
cout<<"=================================="<<endl;
for(auto const& boule : premier.getMobile()){
	  //Affichage des boules
	  cout<<"Boule : "<<endl<<*boule<<endl;             
    } 
premier.evolue(0.01);
}*/

//===============Test du P11.4.6 "Effet rétro"=================================================================

/*premier.ajouter(&b7);
for(int i(0); i<601;++i){ 
cout<<"=================================="<<endl;
cout<<"t = "<<i*0.01<<endl;
cout<<"=================================="<<endl;
for(auto const& boule : premier.getMobile()){
	  //Affichage des boules
	  cout<<"Boule : "<<endl<<*boule<<endl;             
    } 
premier.evolue(0.01);
}*/

//===============Test du P11.4.7 "Effet rétro avec choc"=======================================================

/*premier.ajouter(&b7);
premier.ajouter(&b5);
for(int i(0); i<786;++i){ 
cout<<"=================================="<<endl;
cout<<"t = "<<i*0.01<<endl;
cout<<"=================================="<<endl;
for(auto const& boule : premier.getMobile()){
	  //Affichage des boules
	  cout<<"Boule : "<<endl<<*boule<<endl;             
    } 
premier.evolue(0.01);
}*/

return 0;
}
