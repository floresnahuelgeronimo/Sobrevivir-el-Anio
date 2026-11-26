#include <iostream>
#include <cstdlib>

#include "Creditos.h"
#include "Interfaz.h"

using namespace std;

void mostrarcreditos()
{
    limpiarPantalla();

    int x = calcularMargenX(44);
    int y = 5;

 imprimirEnBloqueColor(x, y, "============================================",14);
 imprimirEnBloqueColor(x, y, "                CRÉDITOS                    ",14);
 imprimirEnBloqueColor(x, y, "============================================",14);
 imprimirEnBloqueColor(x, y, "                                             ",14);
 imprimirEnBloqueColor(x, y, "  TRABAJO FINAL INTEGRADOR DE PROGRAMACIÓN   ",14);
 imprimirEnBloqueColor(x, y, "              Programación I                 ",14);
 imprimirEnBloqueColor(x, y, "                                             ",14);
 imprimirEnBloqueColor(x, y, "                Proyecto:                    ",14);
 imprimirEnBloqueColor(x, y, "  Sobrevivir el Año - Simulador de Finanzas  ",14);
 imprimirEnBloqueColor(x, y, "                                             ",14);
 imprimirEnBloqueColor(x, y, "              Integrantes:                   ",14);
 imprimirEnBloqueColor(x, y, "         Geronimo Nahuel Flores              ",14);
 imprimirEnBloqueColor(x, y, "               Mateo Sauret                  ",14);
 imprimirEnBloqueColor(x, y, "           Tobias Uriel Vera                 ",14);
 imprimirEnBloqueColor(x, y, "         Francisco Roman Martinez            ",14);
 imprimirEnBloqueColor(x, y, "               Comisión:13                   ",14);
 imprimirEnBloqueColor(x, y, "                Año: 2026                    ",14);
 imprimirEnBloqueColor(x, y, "                                             ",14);
 imprimirEnBloqueColor(x, y, "            Gracias por jugar!               ",14);
 imprimirEnBloqueColor(x, y, "============================================",14);

   ubicarCursor(x, y);
    pausarPantalla();
    cin.get();

}
