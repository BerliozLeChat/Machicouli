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

class ReleveMeteo;

typedef int (* CompReleveMeteo)(const ReleveMeteo& rm1, const ReleveMeteo& rm2);

typedef bool (*PredicatReleveMeteo)(const ReleveMeteo& rm);


class ReleveMeteo {
        private:
          int station;
          DateMeteo date;
          double temperature;

        public:
          ~ReleveMeteo(void);
          ReleveMeteo();
          void initialiserReleveMeteo(int,DateMeteo,double);
          void initialiserReleveMeteo(int,int, int ,int ,double);
          int comparaisonReleveMeteo(int(* CompReleveMeteo));
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

int ReleveMeteo::comparaison(*CompReleveMeteo fonctionComparaison,ReleveMeteo releve2){
    return fonctionComparaison(this,releve2);
}

bool ReleveMeteo::predicat(*PredicatReleveMeteo *predicat()){
    return predicat(this);
}

void ReleveMeteo::afficher(){
    cout << "[ station : ".this.station." ]".this.date.toString()." [ temperature : ".this->temperature." ]" <<endl;
}



//fonctions pouvant etre appelé par la fonction de comparaison ou de predicat de la classe
int CompTempDateStation(const ReleveMeteo& rm1, const ReleveMeteo& rm2){
    int retour=1;
    if(rm1.temperature<rm2.temperature){
        retour=-1;
    }
    else if(rm1.temperature==rm2.temperature){
        if(rm1.date.comparerDateMeteo(rm2.date)==0){
            if(rm1.station>rm2.station){
                retour=-1
            }
           else if(rm1.station==rm2.station){
                retour=0
            }
        }
        else{
            retour=rm1.date.comparerDateMeteo(rm2.date);
        }
    }
}

int CompTempDateStationInverse(const ReleveMeteo& rm1, const ReleveMeteo& rm2){
    int resultat=CompTempDateStation(rm1,rm2);
    if(resultat==0)
        return 0
    else
        return -resultat;
}

bool PredicatTemp(const ReleveMeteo& rm){
    if(rm->temperature<=0)
        return true;
    else
        return false;

}






