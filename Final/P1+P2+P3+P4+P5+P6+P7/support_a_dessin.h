#ifndef PRJ_SUPPORT_A_DESSIN_H
#define PRJ_SUPPORT_A_DESSIN_H


class Systeme;
class Boule ;
class Paroi;
class Sol;


class SupportADessin{
 public:
	  //Méthodes virtuelles pures de dessin
	  virtual void dessine(Systeme const& systeme) = 0;
	  virtual void dessine(Boule const& balle) = 0;
	  virtual void dessine(Paroi const& paroi) = 0;
	  virtual void dessine(Sol   const& sol) = 0;
	  
	  //Destructeur virtuel
	  virtual ~SupportADessin() {}
    
};

#endif




