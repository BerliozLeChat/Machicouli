

template <class T> class Maillon{
        public:
           T element;
           Maillon<T> * suivant;


            Maillon(T element, Maillon<T> * maillon){
                this->element=element;
                this->suivant=maillon;
            }
};

template <class T> class Chaine {
        private:

          int nbElements;
          Maillon<T> &tete;

        public:

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
                if(!(this->nbElements==0)){
                    Maillon<T> * suivant;
                    Maillon<T> * ptr = this->tete;

                    while(!(this->ptr==0)){
                        suivant=this->ptr->suivant;
                        free(this->ptr);
                        ptr=suivant;
                    }
                    this->tete=0;
                    this->nbElements=0;
                }
            }

            void insererTete(T element){
                   this->tete=new Maillon<T>(element,this->tete);
                   this->nbElements=this->nbElements+1;

            }
            void insererQueue(T element){
                Maillon<T> mama=new Maillon<T>(element,0);

                if(this->tete==0){
                    this->tete=&mama;
                }
                else{
                    Maillon<T>* p = this->tete;
                    while(!(p->suivant==0)){
                        p=p->suivant;
                    }

                    this->nbElements = this->nbElements+1;
                    p->suivant=&mama;
                }
                this->nbElements=this->nbElements+1;

            }
            void retirerTete(){
                if(!(this->nbElements==0)){
                    Maillon<T> * ptrTete=this->tete;
                    this->tete=this->tete.suivant;
                    free(ptrTete);
                    this->nbElements=this->nbElements-1;
                }

            }
            void retirerQueue(){
                if(!(this->tete==0) && !(this->tete->suivant==0)){
                    Maillon<T> *p = this->tete;
                    while(!(p->suivant->suivant==0)){
                        p=p->suivant;
                    }
                    free(p->suivant);
                    p->suivant=0;
                    this->nbElements=this->nbElements-1;
                }
            }
            void insererOrdre(T element){

            }
            Maillon<T> plusPetitElement(){

            }
            void retirerTous(){

            }
            void afficherChainage(){

            }
};
