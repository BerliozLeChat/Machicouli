#include "ReleveMeteo.cpp"

int main(int argc, char *argv[]){
    DateMeteo *date = new DateMeteo();
	date->initialiserDateMeteo(2001,01,22);

	DateMeteo *date2 = new DateMeteo();
	date2->initialiserDateMeteo(2001,01,22);

	DateMeteo *date3 = new DateMeteo();
	date3->initialiserDateMeteo(2002,01,22);

	DateMeteo *date4 = new DateMeteo();
	if(date4->initialiserDateMeteo(2000,01,22))
        cout<<"ok"<<endl;

    DateMeteo *date5 = new DateMeteo();
	if(date5->initialiserDateMeteo(2016,366,22)) //annee bisextile
        cout<<"ok"<<endl;
    else
        cout<<"erreur"<<endl;

    DateMeteo *date6 = new DateMeteo();
	if(date6->initialiserDateMeteo(2013,366,22)) //annee non bisextile
        cout<<"ok"<<endl;
    else
        cout<<"erreur"<<endl;

	cout<<date->serializeDateMeteo()<<endl;
	cout<<date->comparerDateMeteo(date2)<<endl<<date->comparerDateMeteo(date3)<<endl<<date->comparerDateMeteo(date4);
}
