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
using namespace std; // afin d'éviter d'avoir à préfixer par "std::"


class DateMeteo {
	private:
	int annee;
	int jour;
	int heure;

	public :
		DateMeteo(void);
		~DateMeteo(void);
		bool initialiserDateMeteo(int,int,int);
		int serializeDateMeteo();
		bool equals(DateMeteo*);
		int comparerDateMeteo(DateMeteo*);
		void afficherDateMeteo();




};

DateMeteo::DateMeteo(){
		this->annee=0;
		this->jour=0;
		this->heure=0;
}

bool DateMeteo::initialiserDateMeteo(int annee,int jour,int heure){
	if(heure>23 || heure<0)
		return false;
	if((annee%4==0 && annee%100!=0)||annee%400==0){
		if(jour>366)
			return false;
	}
	else{
		if(jour>365)
			return false;
	}

	this->annee=annee;
	this->jour=jour;
	this->heure=heure;

	return true;
}

int DateMeteo::serializeDateMeteo(){
	return this->heure+this->jour*100+this->annee*100000;
}


bool DateMeteo::equals(DateMeteo *date){
	bool res = false;
	if(this->serializeDateMeteo()==date->serializeDateMeteo()){
		res=true;
	}
	return res;
}

int DateMeteo::comparerDateMeteo(DateMeteo *date){
	int compare;

	if(this->equals(date)){
		compare=0;
	}
	else if(this->serializeDateMeteo()>date->serializeDateMeteo()){
		compare=1;
	}
	else{
		compare=-1;
	}
	return compare;
}

void DateMeteo::afficherDateMeteo(){
	cout<<"[ annee : "<<this->annee<<" ; jour : "<<this->jour<<" ; heure : "<<this->heure<<" ]" <<endl;
}

