#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>

using namespace std;

void ejecutarMenuPrincipal();
int pedirOpcionMenu();
void mostrarHighscore(int sesion_cantidad_partidas, float sesion_mejor_patrimonio, string sesion_mejor_jugador);
bool confirmarSalida();

#endif // MENU_H_INCLUDED
