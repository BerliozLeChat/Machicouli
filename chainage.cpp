class Maillon<class T>{
        private:
           T element;
           Maillon * suivant;
        public:
            void Maillon(T,Maillon*);
            ~Maillon(void);

}

class Chaine {
        private:

          int nbElements;
          Maillon * tete;

        public:
            ~Chaine(void);
            void initialiserChainage() : //initialise un chaˆınage;
            bool estVide(...) : //teste si un chaˆınage est vide, i.e., ne contenant aucun ´el´ement ;
            void reinitialiser(...) : //r´einitialise un chaˆınage en retirant tous ses ´el´ements ;
            void insererTete(...) : //ins`ere un ´el´ement en tˆete du chaˆınage;
            void insererQueue(...) : //ins`ere un ´el´ement en queue du chaˆınage;
            void retirerTete(...) : //retire l’´el´ement de tˆete d’un chaˆınage;
            void retirerQueue(...) : //retire l’´el´ement de queue d’un chaˆınage;
            void insererOrdre(...) : //ins`ere un ´el´ement dans un chaˆınage dans l’ordre donn´e par une fonction de comparaison de type CompReleveMeteo (pass´ee en param`etre);
            Maillon plusPetitElement(...) : //retourne l’´el´ement le plus petit selon l’ordre donn´e par une fonction de comparaison de type CompReleveMeteo (pass´ee en param`etre);
            ?? retirerTous(...) : //retire tous les ´el´ements d’un chaˆınage v´eriﬁant une propri´et´e donn´ee par un pr´edicat de type PredicatReleveMeteo (pass´e en param`etre);
            void afficherChainage(...) : //ecrit les ´el´ements d’un chaˆınage sur un ﬂot de sortie.

}

void initialiserChainage(){
    this->nbElements=0;
    this->tete=0;
}
bool estVide(...){
    if(this->nbElements)
        return true;
    else
        return false;
}
void reinitialiser(){
    if(!(this->tete==0)){
        Maillon * suivant;
        Maillon * ptr = this->tete;

        while(!(this->ptr==0)){
            suivant=this->ptr->suivant;
            free(this->ptr);
            ptr=suivant;
        }
        this->tete=0;this->nbElements=0;
    }
}

void insererTete(){

}
void insererQueue(...){

}
void retirerTete(...){

}
void retirerQueue(...){

}
void insererOrdre(...){

}
Maillon plusPetitElement(...){

}
?? retirerTous(...){

}
void afficherChainage(...){

}
