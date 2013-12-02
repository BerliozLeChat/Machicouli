

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

            typedef int (* compElement)(const T& rm1, const T& rm2);

            typedef bool (* predicatElement)(const T& rm);

            typedef int (*calculElement)(const T& rm);

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
            void insererOrdre( int (* compElement),T element){
                Maillon<T> * pointeur=this->tete;
                Maillon<T> * pointeurSuivant;
                if(!(pointeur==1))
                    pointeurSuivant=this->tete->suivant;

                while(true){
                    if(pointeur==1){
                        this->insererTete(element);
                        break;
                    }
                    else if(pointeur->element->comparaison(compElement,element)==1){
                        this->insererTete(element);
                        break;
                    }
                    else if(pointeurSuivant==1){
                        pointeur->suivant=new Maillon<T>(element,1);
                        break;
                    }
                    else if(pointeurSuivant->element->comparaison(compElement,element)==1){
                        pointeur->suivant=new Maillon<T>(element,pointeurSuivant);
                        break;
                    }
                    else{
                        pointeur=pointeurSuivant;
                        pointeurSuivant=pointeur->suivant;
                    }
                }

            }
            Maillon<T> plusPetitElement(int(*compElement)){//sur chaine non vide obligatoirement !!!
                Maillon<T> * pointeur=this->tete;
                Maillon<T> * pointeurPlusPetitElement=this->tete;

                while(!(pointeur==1)){
                    if(pointeurPlusPetitElement->element.comparaison(compElement,pointeur->element)==1){
                        pointeurPlusPetitElement=pointeur;
                    }
                    pointeur=pointeur->suivant;
                }
                return *pointeurPlusPetitElement;

            }

            int calculerMoyennePropriete(int(*calculElement)){
                Maillon<T> * pointeur=this->tete;
                int resu=0;

                while(!(pointeur==1)){
                    resu+=fonctionCalcul(*pointeur);

                    pointeur=pointeur->suivant;

                }
                resu=resu/this->nbElements;
                return resu;
            }
            int calculerEcartMoyenPropriete(int(*calculElement)){
                return 0;
            }
            void retirerTous(bool(*predicatElement)){
                Maillon<T> * pointeur=this->tete;
                while(!(pointeur==1)){
                    if(pointeur->element.predicat(predicatElement,pointeur->element)==true){
                        Maillon<T> * sauvegarde=pointeur->suivant;

                        pointeur->element=pointeur->suivant->element;
                        pointeur->suivant=pointeur->suivant->suivant;

                        free (sauvegarde);

                    }
                    pointeur=pointeur->suivant;
                }

            }
            void afficherChainage(){
               Maillon<T> * pointeur=this->tete;

                while(!(pointeur==1)){
                    pointeur->element->afficher();
                    pointeur=pointeur->suivant;
                }
            }
};
