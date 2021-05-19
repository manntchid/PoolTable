CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
CXXFLAGS += -g                    # pour debugger
# CXXFLAGS += -pg                 # pour profiler
# LDFLAGS  += -pg                 # pour profiler
# CXXFLAGS += -O2                 # pour optimiser la vitesse






all:: testp11 testVecteur

Vecteur.o: Vecteur.cc Vecteur.h
testVecteur : Vecteur.o

Boule.o: Boule.cc Boule.h 

testBoule1.o: testBoule1.cc Vecteur.h Boule.h
testBoule1 : testBoule1.o Vecteur.o Boule.o Integrateur.o IntegrateurEuler.o

Integrateur.o: Integrateur.cc Integrateur.h

IntegrateurEuler.o: IntegrateurEuler.cc IntegrateurEuler.h

testIntegrateur.o: testIntegrateur.cc Vecteur.h Boule.h Integrateur.h IntegrateurEuler.h
testIntegrateur : testIntegrateur.o Vecteur.o Boule.o Integrateur.o IntegrateurEuler.o

IntegrateurNewmark.o: IntegrateurNewmark.cc IntegrateurNewmark.h

testintegrateurNewmark.o: testintegrateurNewmark.cc IntegrateurNewmark.h Vecteur.h Boule.h Integrateur.h IntegrateurEuler.h
testintegrateurNewmark : testintegrateurNewmark.o IntegrateurNewmark.o Vecteur.o Boule.o Integrateur.o IntegrateurEuler.o

Objet.o: Objet.cc Objet.h

testChocs.o: testChocs.cc Boule.h  
testChocs: testChocs.o Vecteur.o Boule.o Objet.o Integrateur.o IntegrateurEuler.o

testChocs2.o: testChocs2.cc Boule.h 
testChocs2: testChocs2.o Vecteur.o Boule.o Objet.o Integrateur.o IntegrateurEuler.o

Paroi.o : Paroi.cc Paroi.h
Sol.o : Sol.h
systeme.o : systeme.cc systeme.h 

exerciceP8.o : exerciceP8.cc systeme.h text_viewer.h 
exerciceP8 : exerciceP8.o systeme.o Paroi.o Sol.o Boule.o IntegrateurEuler.o Integrateur.o Vecteur.o text_viewer.o

exerciceP9.o : exerciceP9.cc systeme.h text_viewer.h 
exerciceP9 : exerciceP9.o systeme.o Paroi.o Sol.o Boule.o IntegrateurEuler.o Integrateur.o Vecteur.o text_viewer.o

text_viewer.o : text_viewer.cc text_viewer.h

testp11.o : testp11.cc 
testp11 : testp11.o systeme.o Paroi.o Sol.o Boule.o IntegrateurEuler.o Integrateur.o Vecteur.o

