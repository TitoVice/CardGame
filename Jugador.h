#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <string>
#include "ConjuntCartes.h"
#include "PilaCartes.h"

using namespace std;

class Jugador
{
    public:
        // CONSTRUCTOR -------------------------------------------------
        Jugador();
        //Pre: --
        //Post: constructor per defecte

        // CONSULTORS -------------------------------------------------
        void mostrar() const;
        //Pre: --
        //Post: mostra la ma

        void getNom() const;
        //Pre: --
        //Post: escriu el nom per pantalla

        bool esActiu() const;
        //Pre: --
        //Post: cert si _actiu es true, fals altrament

        bool noTeCartes() const;
        //Pre: --
        //Post: cert si no te cartes a la ma, fals altrament

        // MODIFICADORS -------------------------------------------------
        void llegirNom();
        //Pre: --
        //Post: llegeix el _nom

        void canviarActiu(bool estat);
        //Pre: --
        //Post: passa _actiu a estat

        void buidar();
        //Pre: --
        //Post: treu totes les cartes de _ma

        void afegirCarta(const Carta &afegida);
        //Pre: --
        //Post: afegeix una carta a la _ma

        void afegirVectorCartes(const Carta* baralla, int quantitat);
        //Pre: --
        //Post: s'afegeixen totes les cartes de baralla a _ma

        Carta* treureCartes(int nCartes, int numCarta);
        //Pre: el jugador ha de tenir les cartes demanades
        //Post: es treuen les cartes de la _ma i es posen en un vector

        Carta* treureElegides(int nCartes);
        //Pre: el jugador ha de tenir nCartes
        //Post: es treuen les nCartes que elegeixi el jugador, i es retornen

        Carta* treureMillors(int nCartes);
        //Pre: el jugador ha de tenir nCartes
        //Post: es treuen les millors nCartes del jugador, i es retornen

        bool tirada(int &quantCartes, int &numCarta, int &passa, const PilaCartes &_descartades);
        //Pre: --
        //Post: fa una tirada

    private:
        string _nom;
        bool _actiu;
        ConjuntCartes _ma;
};

#endif // JUGADOR_H
