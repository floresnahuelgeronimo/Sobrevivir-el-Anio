#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>

using namespace std;

// Controla el ciclo del menu principal y aloja las variables de la sesion
void ejecutarMenuPrincipal();

// Muestra el menu principal y devuelve la opcion ingresada
char pedirOpcionMenu();

// Muestra el ranking de la sesion actual
void mostrarHighscore(int sesion_cantidad_partidas, float sesion_mejor_patrimonio, string sesion_mejor_jugador);

// Controla el submenu del glosario financiero (12 definiciones)
void mostrarGlosario();

// Imprime la definicion elegida en el glosario usando vectores
void mostrarDefinicionGlosario(int opcion_glosario);

// Pide confirmacion antes de cerrar el programa
bool confirmarSalida();

// Pausa la ejecucion esperando que el usuario presione ENTER
void pausarPantalla();

int pedirOpcionEntera();
#endif // MENU_H_INCLUDED
