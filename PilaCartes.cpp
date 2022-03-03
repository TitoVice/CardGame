#include "PilaCartes.h"
#include <iostream>
#include <string>
#include "Carta.h"

using namespace std;

// CONSTRUCTORS I DESTRUCTOR ----------------------------------
PilaCartes::PilaCartes(){
    a_cim = NULL;
}

PilaCartes::PilaCartes(const PilaCartes& o){

    a_cim = NULL;
    copia(o);
}

PilaCartes::~PilaCartes(){

    allibera();
}

// CONSULTORS -------------------------------------------------
bool PilaCartes::buida() const{

    return a_cim == NULL;
}

Carta PilaCartes::cim() const{

    return a_cim->valor;
}

void PilaCartes::mostrar() const{

    int contador = 0;
    Node *aux = a_cim;

    while(aux != NULL and contador < 10){
        aux->valor.mostrar();
        contador++;
        aux = aux->seg;
    }
    cout<<endl;
}

// MODIFICADORS -----------------------------------------------
void PilaCartes::empila(const Carta& s){

    Node* nou = new Node;
    nou->valor = s;
    nou->seg = a_cim;
    a_cim = nou;
}

void PilaCartes::empilarVector(const Carta* vectorCartes, int quantitat){

    for(int i = 0; i < quantitat; i++){
        empila(vectorCartes[i]);
    }
}

void PilaCartes::desempila(){

    Node* aux = a_cim;
    a_cim = a_cim->seg;
    delete aux;
}

// OPERADORS ---------------------------------------
PilaCartes& PilaCartes::operator=(const PilaCartes& o){

    if (this != &o){
        allibera();
        copia(o);
    }
    return *this;
}

// MÉTODES PRIVATS -------------------------------------------------
void PilaCartes::copia(const PilaCartes& o) {

    if(!o.buida()){
        Node *p, *q, *aux;
        p = new Node; a_cim = p;
        aux = o.a_cim; p->valor = aux->valor; p->seg = NULL;
        q = p;
        while (aux->seg!=NULL) {
            aux = aux->seg;
            p = new Node; q->seg = p;
            p->valor = aux->valor; p->seg = NULL;
            q = p;
        }
    }
}

void PilaCartes::allibera(){

    while (!buida()) {
        Node* aux = a_cim;
        a_cim = a_cim->seg;
        delete aux;
    }
}
