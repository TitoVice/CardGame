#ifndef PILACARTES_H
#define PILACARTES_H
#include <string>
#include "Carta.h"

using namespace std;

class PilaCartes
{
    public:
        // CONSTRUCTORS I DESTRUCTOR ----------------------------------
        PilaCartes();
        //Pre: --;
        //Post: pila buida

        PilaCartes(const PilaCartes& o);  // const. de copia
        //Pre: --;
        //Post: aquesta pila es copia de la pila o

        ~PilaCartes();
        //Pre: --;
        //Post: memoria alliberada

        // CONSULTORS -------------------------------------------------
        bool buida() const;
        //Pre: -- ;
        //Post: retorna cert si la pila es buida; fals en c.c.

        Carta cim() const;
        //Pre: pila no buida;
        //Post: retorna el valor del cim de la pila

        void mostrar() const;
        //Pre: --
        //Post: mostra les 10 primeres cartes

        // MODIFICADORS -----------------------------------------------
        void empila(const Carta &s);
        //Pre: --;
        //Post: ha afegit s a dalt de la pila

        void empilarVector(const Carta* vectorCartes, int quantitat);
        //Pre: --
        //Post: ha afegit el vector a la pila

        void desempila();
        //Pre: pila no buida;
        //Post: ha eliminat element de dalt de la pila

        // OPERADORS ---------------------------------------
        PilaCartes& operator=(const PilaCartes& o);
        //Pre: -- ;
        //Post: aquesta pila es copia de la pila o

        private:
            struct Node{
                Carta valor;
                Node* seg;
            };

            Node* a_cim; // punter al cim de la pila

            // MÉTODES PRIVATS -------------------------------------------------
            void copia(const PilaCartes& o);
            //Pre: pila buida;
            //Post: aquesta pila es copia de o

            void allibera();
            //Pre: --;
            //Post: memoria alliberada
};
#endif // PILACARTES_H

