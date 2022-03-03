#ifndef CARTA_H
#define CARTA_H
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Carta
{
    public:
            // CONSTRUCTORS -------------------------------------------------
            Carta();
            //Pre: --
            //Post: costructor base

            Carta(int num, int pal);
            //Pre: -1 < pal < 5, -1 < num < 13
            //Post: constructor per defecte

            // CONSULTORS -------------------------------------------------
            void mostrar() const;
            //Pre: --
            //Post: mostra la carta

            bool numIgual(int numero) const;
            //Pre: --
            //Post: retorna cert si _num == numero, fals altrament

            bool numMesGranOIgual(int numero) const;
            //Pre: --
            //Post: retorna cert si _valor >= valor, fals altrament

            // OPERADORS -------------------------------------------------
            bool operator <(const Carta &_carta) const;
            //Pre: --
            //Post: operador menor que

            void operator =(const Carta &_carta);
            //Pre: --
            //Post: operador igual

    private:
        int _num, _pal, _valor;

        static const char nomPal[];
        static const int valorCarta[];
};

#endif // CARTA_H
