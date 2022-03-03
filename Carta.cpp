#include "Carta.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const char Carta::nomPal[] = {'O','C','E','B'};
const int Carta::valorCarta[] = {13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

// CONSTRUCTORS -------------------------------------------------
Carta::Carta(){

    _num = _pal = _valor = 0;
}

Carta::Carta(int num, int pal){

    _num = num;
    _pal = pal;
    _valor = valorCarta[_num - 1];
}

// CONSULTORS -------------------------------------------------
void Carta::mostrar() const{

    cout<<"["<<_num<<nomPal[_pal]<<"]";
}

bool Carta::numIgual(int numero) const{

    return _num == numero;
}

bool Carta::numMesGranOIgual(int numero) const{

    return _valor >= valorCarta[numero - 1];
}

// OPERADORS -------------------------------------------------
bool Carta::operator <(const Carta &_carta) const{

    if(_valor < _carta._valor) return true;
    else if(_valor == _carta._valor and _pal < _carta._pal) return true;
    else return false;
}

void Carta::operator =(const Carta &_carta){

    _num = _carta._num;
    _pal = _carta._pal;
    _valor = _carta._valor;
}
