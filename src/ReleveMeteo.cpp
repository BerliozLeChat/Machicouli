/*
Licence Informatique
Université de Nantes

X3I0010   TP n◦ 3 : chainage et météo

Auteurs : François Hallereau & Sébastien Vallée
Groupe : 301B
Date :
*/

#include "DateMeteo.cpp"
#include "chainage.cpp"


#include <iostream> // pour les entrées/sorties
#include <fstream>
#include <cmath>
#include <string>
#include <cassert>
using namespace std; // afin d'éviter d'avoir à préfixer par "std::"

class ReleveMeteo;

typedef int (* CompReleveMeteo)(const ReleveMeteo& rm1, const ReleveMeteo& rm2);

typedef bool (*PredicatReleveMeteo)(const ReleveMeteo& rm);


class ReleveMeteo {
        private:
          int station;
          DateMeteo * date;
          double temperature;

        public:
          ~ReleveMeteo(void);
          ReleveMeteo(void);
          void initialiserReleveMeteo(int,DateMeteo *,double);
          void initialiserReleveMeteo(int,int, int ,int ,double);
          int getStation();
          DateMeteo* getDate();
          double getTemperature();
          int comparaison(int(* CompReleveMeteo),ReleveMeteo);
          bool predicat(bool (*PredicatReleveMeteo));
          void afficher();

};

ReleveMeteo::ReleveMeteo(){
    this->station=0;
    this->date= new DateMeteo();
    this->temperature = -273.15;
}
void ReleveMeteo::initialiserReleveMeteo(int station ,DateMeteo * date, double temperature){
    this->station = station;
    this->date = date;
    this->temperature = temperature;

}

void ReleveMeteo::initialiserReleveMeteo(int station , int annee , int jour , int heure , double temperature){
    this->station = station;
    this->date = new DateMeteo();
    this->date->initialiserDateMeteo(annee,jour,heure);
    this->temperature = temperature;

}
int ReleveMeteo::getStation(){
    return this->station;
}
DateMeteo* ReleveMeteo::getDate(){
    return this->date;
}
double ReleveMeteo::getTemperature(){
    return this->temperature;
}

int ReleveMeteo::comparaison(int(*CompReleveMeteo),ReleveMeteo releve2){
    return CompReleveMeteo(this,releve2);
}

bool ReleveMeteo::predicat(bool (*PredicatReleveMeteo)){
    return PredicatReleveMeteo(this);
}

void ReleveMeteo::afficher(){
    ostringstream convert;
    convert << this->station;
    string buff = convert.str();

    convert << this->temperature;
    string buff2 = convert.str();
    cout << "[ station : "<<buff<<" ]"<<this->date->toString()<<" [ temperature : "<<buff2<<" ]" <<endl;
}



//fonctions pouvant etre appelé par la fonction de comparaison ou de predicat de la classe
int CompTempDateStation(const ReleveMeteo& rm1, const ReleveMeteo& rm2){
    int retour=1;
    if(rm1.getTemperature()<rm2.getTemperature()){
        retour=-1;
    }
    else if(rm1.getTemperature()==rm2.getTemperature()){
        if(rm1.getDate().comparerDateMeteo(rm2.getDate())==0){
            if(rm1.getStation()>rm2.getStation()){
                retour=-1;
            }
           else if(rm1.getStation()==rm2.getStation()){
                retour=0;
            }
        }
        else{
            retour=rm1.getDate().comparerDateMeteo(*(rm2.getDate()));
        }
    }
}

int CompTempDateStationInverse(const ReleveMeteo& rm1, const ReleveMeteo& rm2){
    int resultat=CompTempDateStation(rm1,rm2);
    if(resultat==0)
        return 0;
    else
        return -resultat;
}

bool PredicatTemp(const ReleveMeteo& rm){
    if(rm.getTemperature()<=0)
        return true;
    else
        return false;

}


//fonction pour lire les relevés dans un fichier texte

 void lectureReleves(Chainage& chaine,char* monTableau){

    int station, annee, jour, heure;
    double temperature;
    std::ifstream ifs ("..\res\releves\releve_s3_2007.txt", std::ifstream::in); // filename est le nom du ficher de releves
    if (ifs) {
        while (getline(ifs, ligne)) {
            std::istringstream iss(ligne);
            iss >> station;
            iss >> annee;
            iss >> jour;
            iss >> heure;
            iss >> temperature;// ici traitement du relev´e qui vient d’e^tre lu dans le fichier }

            chaine.insererOrdre(&CompTempDateStation,new Maillon<ReleveMeteo>().initialiserReleveMeteo(station ,new DateMeteo().initialiserDateMeteo(annee,jour,heure),temperature));  // on l'affiche

}






