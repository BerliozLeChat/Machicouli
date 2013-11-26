template <class T>Maillon{
        private:
           T element;
           Maillon<T> * suivant;
        public:
            void Maillon(T,Maillon*);
            ~Maillon(void);

}

void Maillon<T>::Maillon(T element, Maillon * maillon){
    this->element=element;
    this->suivant=maillon;
}

template <class T> Chaine {
        private:

          int nbElements;
          Maillon<T> &tete;

        public:
            ~Chaine(void);
            void initialiserChainage() : //initialise un chaˆınage;
            bool estVide() : //teste si un chaˆınage est vide, i.e., ne contenant aucun ´el´ement ;
            void reinitialiser() : //r´einitialise un chaˆınage en retirant tous ses ´el´ements ;
            void insererTete(...) : //ins`ere un ´el´ement en tˆete du chaˆınage;
            void insererQueue(T) : //ins`ere un ´el´ement en queue du chaˆınage;
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
bool estVide(){
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

void insererTete(T element){
       this->tete=new Maillon(element,this->tete);
       this->nbElements=this->nbElements+1;

}
void insererQueue(T element){
    Maillon<T> mama=new Maillon(element,0);

    if(this->tete==0){
        this->tete=&mama;
    }
    else{
        Maillon *p = this->tete;
        while(!(p->suivant==0){
            p=p->suivant;
        }

        this->nbElements = this->nbElements+1;
        p->suivant=&mama;
    }
    this->nbElements=this->nbElements+1;

}
void retirerTete(){
    if(!(this->tete==0){
        ptrTete=this->tete;
        this->tete=this->tete.suivant;
        free(ptrTete);
        this->nbElements=this->nbElements-1;
    }

}
void retirerQueue(){
    if(!(this->tete==0) && !(this->tete->suivant==0)){
        Maillon *p = this->tete;
        while(!(p->suivant->suivant==0)){
            p=p->suivant;
        }
        free(p->suivant);
        p->suivant=0;
        this->nbElements=this->nbElements-1;
    }
}
void insererOrdre(...){

}
Maillon plusPetitElement(...){

}
?? retirerTous(...){

}
void afficherChainage(...){

}
