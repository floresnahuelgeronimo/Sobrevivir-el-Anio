#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <string>

using namespace std;

// Reemplaza a system("cls") usando rlutil
void limpiarPantalla();

void pausarPantalla();

// Calcula la columna X donde debe empezar un bloque de cierto ancho para quedar centrado
int calcularMargenX(int ancho_bloque);

// Posiciona el cursor en (x, y) - util cuando tenes que imprimir texto mezclado con variables numericas
void ubicarCursor(int x, int y);

// Imprime una linea en (x, y) y baja automaticamente a la fila siguiente (y++)
void imprimirEnBloque(int x, int &y, string texto);

// Centra una sola linea de texto segun su propio largo y baja a la fila siguiente
void imprimirTextoCentrado(int &y, string texto);

// Reemplaza a pausarPantalla() ubicando el mensaje centrado
void pausarCentrado(int x, int &y, string mensaje);



// --- Funciones de color ---
void cambiarColor(int color);
void cambiarFondo(int color);
void restaurarColor();
void imprimirEnBloqueColor(int x, int &y, string texto, int color);

#endif // INTERFAZ_H_INCLUDED
