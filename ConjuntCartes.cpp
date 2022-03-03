#include "ConjuntCartes.h"
#include "Carta.h"
#include <iostream>

using namespace std;

// CONSTRUCTORS -------------------------------------------------
ConjuntCartes::ConjuntCartes()
{
    _nCartes = 0;
    _maxCartes = 5;
    _taula = new Carta[_maxCartes];
}

// CONSULTORS -------------------------------------------------
void ConjuntCartes::mostrar() const{

    for(int i = 0; i < _nCartes; i++){
        _taula[i].mostrar();
    }
}

bool ConjuntCartes::esApte(int quantitat, int numCarta) const{

    bool apte = false, passat = false;
    int pos = 0, enTe = 0;

    while(pos < _nCartes and !apte and !passat){
        if(_taula[pos].numIgual(numCarta)) enTe++;          //per veure si te el suficient numero de cartes amb el mateix numero demanat
        else if(_taula[pos].numMesGranOIgual(numCarta)) passat = true;
        pos++;
        if(enTe == quantitat) apte = true;
    }
    return apte;
}

bool ConjuntCartes::esBuida() const{

    return _nCartes == 0;
}

// MODIFICADORS -------------------------------------------------
void ConjuntCartes::buidar(){

    _nCartes = 0;
}

void ConjuntCartes::afegir(const Carta &_carta){

    int pos = 0;
    bool trobat = false;

    if(_nCartes == _maxCartes) expandir();

    while(pos < _nCartes and !trobat){
        if(_taula[pos] < _carta) pos++;
        else trobat = true;
    }

    if(!trobat) _taula[_nCartes] = _carta;
    else{
        for(int j = _nCartes; j > pos; j--){
            _taula[j] = _taula[j-1];
        }
        _taula[pos] = _carta;
    }
    _nCartes++;
}

Carta* ConjuntCartes::treure(int quantitat, int numCarta, bool mostrar){

    int pos = 0, posTretes = 0;
    bool trobat = false;
    Carta* tretes = new Carta[quantitat];

    while(pos < _nCartes and !trobat){
        if(_taula[pos].numIgual(numCarta)) trobat = true;
        else pos++;
    }

    if(trobat){
        for(int i = 0; i < quantitat; i++){
            if(mostrar) _taula[pos].mostrar();
            tretes[posTretes] = _taula[pos];
            posTretes++;
            for(int j = pos; j < _nCartes; j++){
                _taula[j] = _taula[j + 1];
            }
            _nCartes--;
        }
        if(mostrar) cout<<endl;
    }
    return tretes;
}

Carta* ConjuntCartes::treureMillors(int nCartes){

    Carta* tretes = new Carta[nCartes];
    int pos = _nCartes - 1, posTretes = 0;

    for(int i = 0; i < nCartes; i++){
        tretes[posTretes] = _taula[pos];
        posTretes++;
        pos--;
        _nCartes--;
    }
    return tretes;
}

// MÉTODES PRIVATS -------------------------------------------------
void ConjuntCartes::expandir(){

    _maxCartes = 2*_maxCartes;
    Carta *aux = new Carta[_maxCartes];
    for(int i=0; i<_nCartes; i++) aux[i] = _taula[i];
    delete[] _taula;
    _taula = aux;
}
