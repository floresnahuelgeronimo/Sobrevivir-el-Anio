#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
using namespace std;

// Coordina el menu principal y conserva en alcance local el Highscore de la sesion
void ejecutarMenuPrincipal();

// Muestra el mejor resultado registrado durante la ejecucion actual del programa
void mostrarHighscore(int sesion_cantidad_partidas, float sesion_mejor_patrimonio, string sesion_mejor_jugador);

// Muestra las definiciones del Glosario Financiero (consultable desde el menu o durante la partida)
void mostrarGlosario();

// Solicita confirmacion S/N antes de cerrar el programa
bool confirmarSalida();

#endif // MENU_H_INCLUDED
