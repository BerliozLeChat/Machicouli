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
		void initialiserDateMeteo(int,int,int);
		bool equals(DateMeteo);
		int comparerDateMeteo(DateMeteo);
		void afficherDateMeteo()

		
		
	
};

DateMeteo::DateMeteo(){
		this->annee=0;
		this->jour=0;
		this->heure=0;
}

void DateMeteo::initialiserDateMeteo(int annee,int jour,int heure){	
		this->annee=annee;
		this->jour=jour;
		this->heure=heure;
}

bool DateMeteo::equals(DateMeteo date){
	bool res = false;
	if(this->annee == date->annee){
		if(this->jour == date->jour){
			if(this.heure == date.heure)
				res=true;
		}
	}
}

int DateMeteo::comparerDateMeteo(DateMeteo date){
	int compare=0;
	if(!this->equals(date)){
		if(this->annee<date->annee){
			compare=-1
		}
		else if(this->annee>date->annee){
			compare=1;	
		}
		else{
			if(this->jour<date->jour){
				compare=-1
			}
			else if(this->jour>date->jour){
				compare=1;	
			}
			else{
				if(this->heure<date->heure){
					compare=-1
				}
				else{
					compare=1;	
				}				
			}
		}
	}
	return compare;
}

