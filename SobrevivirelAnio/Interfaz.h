#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <string>

using namespace std;

void limpiarPantalla();
void pausarPantalla();
void ubicarCursor(int x, int y);
void imprimirEnBloque(int x, int &y, string texto);
void pausarCentrado(int x, int &y, string mensaje);

// Lee un entero de forma segura (evita bucle infinito si escriben letras)
int pedirOpcionEntera();

// --- Funciones de color ---
void cambiarColor(int color);
void cambiarFondo(int color);
void restaurarColor();
void imprimirEnBloqueColor(int x, int &y, string texto, int color);

#endif // INTERFAZ_H_INCLUDED
