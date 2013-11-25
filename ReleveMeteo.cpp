/*
Licence Informatique
Université de Nantes

X3I0010   TP n◦ 3 : chainage et météo

Auteurs : François Hallereau & Sébastien Vallée
Groupe : 301B
Date :
*/



#include <iostream> // pour les entrées/sorties
#include <fstream>
#include <cmath>
#include <string>
#include <cassert>
#include "DateMeteo.cpp"
using namespace std; // afin d'éviter d'avoir à préfixer par "std::"

typedef int (* CompReleveMeteo)
        (const ReleveMeteo& rm1, const ReleveMeteo& rm2);


class ReleveMeteo {
        private:
          int station;
          DateMeteo date;
          double temperature;

        public:
          ~ReleveMeteo(void);
          void ReleveMeteo();
          void initialiserReleveMeteo(int,DateMeteo,double);
          void initialiserReleveMeteo(int,int, int ,int ,double);
          int comparaisonReleveMeteo(fonctionComparaison);
          void afficherReleveMeteo();

}

void ReleveMeteo::ReleveMeteo(){
    this->station=0;
    this->DateMeteo= new DateMeteo().initialiserDateMeteo();
    this->temperature = -273,15;
}
void ReleveMeteo::initialiserReleveMeteo(int station ,DateMeteo date, int temperature){
    this->station = station;
    this->date = date;
    this->temperature = temperature;

}

void ReleveMeteo::initialiserReleveMeteo(int station , int annee , int jour , int heure , int temperature){
    this->station = station;
    this->date = new DateMeteo.initialiserDateMeteo(annee,jour,heure);
    this->temperature = temperature;

}

int ReleveMeteo::comparaisonReleveMeteo(fonctionComparaison){
    return fonctionComparaison(this);
}

void ReleveMeteo::afficherReleveMeteo(){
    cout << "[ station : ".this.station." ]".this.date.afficherDateMeteo()." [ temperature : ".this->temperature." ]" <<endl;
}
