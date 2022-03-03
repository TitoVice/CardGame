#include "Jugador.h"
#include <iostream>
#include <string>
#include "ConjuntCartes.h"
#include "PilaCartes.h"

using namespace std;

// CONSTRUCTORS -------------------------------------------------
Jugador::Jugador()
{
    _nom = "";
    _actiu = true;
}
// CONSULTORS -------------------------------------------------
void Jugador::mostrar() const{

    _ma.mostrar();
    cout<<endl;
}

void Jugador::getNom() const{

    cout<<_nom;
}

bool Jugador::esActiu() const{

    return _actiu;
}

bool Jugador::noTeCartes() const{

    return _ma.esBuida();
}

// MODIFICADORS -------------------------------------------------
void Jugador::llegirNom(){

    cin>>_nom;
}

void Jugador::canviarActiu(bool estat){

    _actiu = estat;
}

void Jugador::buidar(){

    _ma.buidar();
}

void Jugador::afegirCarta(const Carta &afegida){

    _ma.afegir(afegida);
}

void Jugador::afegirVectorCartes(const Carta* baralla, int quantitat){

    for(int i = 0; i < quantitat; i++){
        _ma.afegir(baralla[i]);
    }
}

Carta* Jugador::treureCartes(int nCartes, int numCarta){

    return _ma.treure(nCartes, numCarta, true);
}

Carta* Jugador::treureElegides(int nCartes){

    Carta* tretes = new Carta[nCartes];
    int numero;

    for(int i = 0; i < nCartes; i++){
        cin>>numero;
        Carta* perTreure = _ma.treure(1, numero ,false);
        tretes[i] = perTreure[0];
    }
    return tretes;
}

Carta* Jugador::treureMillors(int nCartes){

    return _ma.treureMillors(nCartes);
}

bool Jugador::tirada(int &quantCartes, int &numCarta, int &passa, const PilaCartes &_descartades){

    bool correcte = false, tirar = false;
    int nCartes;
    cout<<"- TORN DEL JUGADOR/A "<<_nom<<" -"<<endl;
    if(quantCartes == 0 and !_descartades.buida()) cout<<"EL JUGADOR/A "<<_nom<<" INICIA TORN."<<endl;
    cout<<"MA:"<<endl;
    mostrar();
    while(!correcte){
        cout<<"QUINES CARTES VOLS TIRAR?"<<endl;
        cin>>nCartes>>numCarta;
        if(nCartes == 0 and numCarta == 0){
            cout<<"EL JUGADOR/A "<<_nom<<" PASSA."<<endl;
            passa++;
            correcte = true;
        }
        else{
            if(nCartes == -1 and numCarta == -1){
                cout<<"DARRERES CARTES TIRADES:"<<endl;
                _descartades.mostrar();
            }
            else{
                if(!_ma.esApte(nCartes, numCarta)) cout<<"ERROR. EL JUGADOR NO TE AQUESTES CARTES"<<endl;
                else{
                    correcte = true; tirar = true;
                    if(quantCartes != 0){
                        if(nCartes != quantCartes or _descartades.cim().numMesGranOIgual(numCarta)){
                            cout<<"ERROR. AMB AQUESTA TIRADA NO SUPERES LES CARTES ACTUALS"<<endl;
                            correcte = false;
                            tirar = false;
                        }
                    }
                    else quantCartes = nCartes;
                }
            }
        }
    }
    return tirar;
}
