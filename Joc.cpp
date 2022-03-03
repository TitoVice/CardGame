#include "Joc.h"
#include <iostream>
#include <string>
#include "Carta.h"
#include "ConjuntCartes.h"
#include "PilaCartes.h"
#include "Jugador.h"

const int Joc::N_CARTES_PAL = 12;
const int Joc::N_PALS = 4;

using namespace std;

// CONSTRUCTORS -------------------------------------------------
Joc::Joc(){

    _nJugadors = _llavor = _nBaralles = 0;
    _llistaJugadors = new Jugador[2];           //el mínim de jugadors
    _baralla = new Carta[N_CARTES_PAL * N_PALS];//el mínim de cartes
}

// CONSULTORS -------------------------------------------------
void Joc::mostrarClassificacio() const{

    for(int i = 0; i < _nJugadors; i++){
        if(i == 0){
            cout<<"REI: "; _llistaJugadors[i].getNom(); cout<<endl;
        }
        else if(i == _nJugadors - 1){
            cout<<"ESCLAU: "; _llistaJugadors[i].getNom(); cout<<endl;
        }
        else if(_nJugadors % 2 != 0 and i == _nJugadors / 2){
            cout<<"BURGES: "; _llistaJugadors[i].getNom(); cout<<endl;
        }
        else if(i <= _nJugadors / 2 - 1){
            cout<<"NOBLE: "; _llistaJugadors[i].getNom(); cout<<endl;
        }
        else{
            cout<<"VASSALL: "; _llistaJugadors[i].getNom(); cout<<endl;
        }
    }
}

// MODIFICADORS -------------------------------------------------
void Joc::inicialitzar(){

    cout<<"*** JOC DE L'ESCLAU ***"<<endl
        <<"ENTRA LA LLAVOR:"<<endl;
    cin>>_llavor;
    do{
        cout<<"ENTRA EL NOMBRE DE JUGADORS:"<<endl;
        cin>>_nJugadors;
    }while(_nJugadors < 2 or _nJugadors > 12);
    delete[] _llistaJugadors;
    _llistaJugadors = new Jugador[_nJugadors];

    for(int i = 0; i < _nJugadors; i++){
        cout<<"ENTRA EL NOM DEL JUGADOR/A "<<i + 1<<":"<<endl;
        _llistaJugadors[i].llegirNom();
    }
    do{
        cout<<"ENTRA EL NOMBRE DE BARALLES:"<<endl;
        cin>>_nBaralles;
    }while(_nBaralles < 1 or _nBaralles > 3);
    delete[] _baralla;
    _baralla = new Carta[_nBaralles * N_PALS * N_CARTES_PAL];
}

void Joc::inicialitzarRonda(){

    PilaCartes nova;
    _descartades = nova;
    _llistaJugadors[_nJugadors - 1].buidar();   //es treuen les cartes de l'esclau, ja que es l'unic que encara en tenia
}

void Joc::generarIRepartirCartes(){

    generarCartes();
    barrejar();
    repartirCartes();
}

void Joc::ronda(){

    Jugador* classificacio = new Jugador[_nJugadors]; //taula on es posen els jugadors classificats
    int jugadorsActius = _nJugadors, quantCartes = 0, passa = 0, ultimJugador, posicio = 0;
    //num. de jugadors actius; quantitat de cartes de la jugada; jugadors que passen; ultim jugador en fer jugada; posicio de la classificacio
    bool acabat = false;

    while (jugadorsActius > 1){
        while(passa < _nJugadors - 1 and !acabat and jugadorsActius > 1){   //fins que guanyi un jugador la tirada
            int i = 0;
            while(i < _nJugadors and passa < _nJugadors - 1 and !acabat and jugadorsActius > 1){
                if(_llistaJugadors[i].esActiu()){
                    int numCarta;
                    if(_llistaJugadors[i].tirada(quantCartes, numCarta, passa, _descartades)){
                        cout<<"TIRADA: ";
                        passa = 0;
                        ultimJugador = i;
                        _descartades.empilarVector(_llistaJugadors[i].treureCartes(quantCartes, numCarta), quantCartes);
                        if(numCarta == 2) acabat = true;
                        if(_llistaJugadors[i].noTeCartes()){
                            _llistaJugadors[i].canviarActiu(false);
                            jugadorsActius--;
                            classificacio[posicio] = _llistaJugadors[i];
                            posicio++;
                            cout<<"EL JUGADOR/A "; _llistaJugadors[i].getNom(); cout<<" HA FINALITZAT EN LA POSICIO "<<posicio<<"."<<endl;
                        }
                    }
                }
                else passa++;
                i++;
            }
        }
        primerTirador(ultimJugador);
        quantCartes = 0;
        acabat = false;
        passa = 0;
    }
    int ultim = 0;
    bool trobat = false;
    while(ultim < _nJugadors and !trobat){    //per col·locar l'ultim jugador a la classificacio
        if(_llistaJugadors[ultim].esActiu()){
            classificacio[posicio] = _llistaJugadors[ultim];
            trobat = true;
        }
        ultim++;
    }
    _llistaJugadors = classificacio;
    for(int j = 0; j < _nJugadors; j++) _llistaJugadors[j].canviarActiu(true);      //posar tots els juugadors com a actius
}

void Joc::intercanviarCartes(){

    int beneficiat = 0, perjudicat = _nJugadors - 1, intercanvis = _nJugadors / 2;

    while(beneficiat < perjudicat){
        Carta* elegides = new Carta[intercanvis];
        Carta* lesMillors = new Carta[intercanvis];
        cout<<"EL JUGADOR/A "; _llistaJugadors[beneficiat].getNom();
        cout<<" I EL JUGADOR/A "; _llistaJugadors[perjudicat].getNom();
        cout<<" INTERCANVIEN "<<intercanvis<<" CARTES"<<endl
            <<"- JUGADOR/A "; _llistaJugadors[beneficiat].getNom(); cout<<" -"<<endl;

        lesMillors = _llistaJugadors[perjudicat].treureMillors(intercanvis);
        _llistaJugadors[beneficiat].afegirVectorCartes(lesMillors, intercanvis);
        _llistaJugadors[beneficiat].mostrar();

        cout<<"QUINES CARTES VOLS INTERCANVIAR?"<<endl;
        elegides = _llistaJugadors[beneficiat].treureElegides(intercanvis);
        _llistaJugadors[perjudicat].afegirVectorCartes(elegides, intercanvis);

        beneficiat++;
        perjudicat--;
        intercanvis--;
    }
}

// MÉTODES PRIVATS -------------------------------------------------
void Joc::primerTirador(int jugador){

    Jugador* novaTaula = new Jugador[_nJugadors];
    int pos = 0;

    for(int i = jugador; i < _nJugadors; i++){
        novaTaula[pos] = _llistaJugadors[i];
        pos++;
    }
    for(int i = 0; i < jugador; i++){
        novaTaula[pos] = _llistaJugadors[i];
        pos++;
    }
    _llistaJugadors = novaTaula;
}

void Joc::generarCartes(){

    int posicio = 0;

    for(int i = 0; i < _nBaralles; i++){
        for(int pal = 0; pal < N_PALS; pal++){
            for(int num = 1; num <= N_CARTES_PAL; num++){
                Carta _carta(num, pal);
                _baralla[posicio] = _carta;
                posicio++;
            }
        }
    }
}

void Joc::barrejar(){

    int _nCartes = _nBaralles * N_PALS * N_CARTES_PAL;
    for(int i = _nCartes - 1; i > 0; i--){
        int pos = aleatori(i + 1);
        intercanvi(_baralla[pos], _baralla[i]);
    }
}

void Joc::repartirCartes(){

    int num_jugadors = _nJugadors - 1;

    for(int num_carta = 0; num_carta < (_nBaralles * N_PALS * N_CARTES_PAL); num_carta++){
        _llistaJugadors[num_jugadors].afegirCarta(_baralla[num_carta]);
        if(num_jugadors == 0) num_jugadors =  _nJugadors - 1;
        else num_jugadors--;
    }
}

int Joc::aleatori(int maxim){

    _llavor = _llavor * 1103515245 + 12345;
    int res = (_llavor/32) % 32768;
	return res % maxim;
}

void Joc::intercanvi(Carta &x, Carta &y){

    Carta aux;
    aux = x;
    x = y;
    y = aux;
}
