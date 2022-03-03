 #ifndef CONJUNTCARTES_H
#define CONJUNTCARTES_H
#include <iostream>
#include "Carta.h"

using namespace std;

class ConjuntCartes
{
    public:
        // CONSTRUCTORS -------------------------------------------------
        ConjuntCartes();
        //Pre: --
        //Post: constructor per defecte

        // CONSULTORS -------------------------------------------------
        void mostrar() const;
        //Pre: --
        //Post: mostra la taula

        bool esApte(int quantitat, int numCarta) const;
        //Pre: quantitat i numCarta != 0
        //Post: retorna cert si hi ha quantitat de numCarta en la taula, fals altrament

        bool esBuida() const;
        //Pre: --
        //Post: cert si no hi ha cartes, fals altrament

        // MODIFICADORS -------------------------------------------------
        void buidar();
        //Pre: --
        //Post: treu totes les cartes de _taula

        void afegir(const Carta &_carta);
        //Pre: --
        //Post: s'afegeix una carta a la taula

        Carta* treure(int quantitat, int numCarta, bool mostrar);
        //Pre: hi ha tantes cartes de numCarta com quantitat (minim)
        //Post: es treuen les quantitat primeres cartes de numCarta i es mostren

        Carta* treureMillors(int nCartes);
        //Pre: _taula ha de tenir nCartes
        //Post: es treuen les millors nCartes de _taula, i es retornen

    private:
        int _nCartes;
        int _maxCartes;
        Carta *_taula;

        // MÉTODES PRIVATS -------------------------------------------------
        void expandir();
        //Pre: --
        //Post: expandeix al doble la _taula
};

#endif // ConjuntCartes_H
