#ifndef JOC_H
#define JOC_H
#include <iostream>
#include <string>
#include "Carta.h"
#include "ConjuntCartes.h"
#include "PilaCartes.h"
#include "Jugador.h"

using namespace std;

class Joc
{
    public:
        // CONSTRUCTORS -------------------------------------------------
        Joc();
        //Pre: --
        //Post: constructor per defecte

        // CONSULTORS -------------------------------------------------
        void mostrarClassificacio() const;
        //Pre: s'ha jugat una ronda
        //Post: mostra la classificacio dels jugadors

        // MODIFICADORS -------------------------------------------------
        void inicialitzar();
        //Pre: --
        //Post: dades principals agafades: _nJugadors, _llavor, _nBaralles

        void inicialitzarRonda();
        //Pre: s'ha jugat una ronda
        //Post: es prepara tot per a la següent ronda

        void generarIRepartirCartes();
        //Pre: --
        //Post: genera i reparteix les cartes entre els jugadors

        void ronda();
        //Pre: --
        //Post: duu a terme una ronda de joc

        void intercanviarCartes();
        //Pre: s'ha jugat una ronda
        //Post: es canvien cartes entre els jugadors

    private:
        int _nJugadors, _nBaralles;
        unsigned _llavor;
        PilaCartes _descartades;
        Jugador *_llistaJugadors;
        Carta *_baralla;

        static const int N_PALS;
        static const int N_CARTES_PAL;

        // MÉTODES PRIVATS -------------------------------------------------
        void primerTirador(int jugador);
        //Pre: 0 <= jugador < _nJugadors
        //Post: coloca primer al jugador en la _llistaJugadors

        void generarCartes();
        //Pre: --
        //Post: genera les cartes a la baralla

        void barrejar();
        //Pre: --
        //Post: barreja la _baralla

        void repartirCartes();
        //Pre: --
        //Post: dona les cartes de la baralla als jugadors

        int aleatori(int maxim);
        //Pre: --
        //Post: genera un numero aleatori entre 0 i max-1

        static void intercanvi(Carta &x, Carta &y);
        //Pre: --
        //Post: intercanvia els dos elements
};

#endif // JOC_H
