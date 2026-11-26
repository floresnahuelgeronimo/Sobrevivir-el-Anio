#include <iostream>

#include "rlutil.h"
#include "Interfaz.h"

using namespace std;

void mostrarportada()
    {

    int x = calcularMargenX(54); // El recuadro mide 44 caracteres de ancho
    int y = 8;                   // Margen superior (empieza en la fila 5)

        imprimirEnBloqueColor(x,y,"==========================================================",5);
        imprimirEnBloqueColor(x,y,"                                                          ",5);
        imprimirEnBloqueColor(x,y,"              SOBREVIVIR EL AÑO                           ",5);
        imprimirEnBloqueColor(x,y,"                                                          ",5);
        imprimirEnBloqueColor(x,y,"       Simulador de Finanzas Personales                   ",5);
        imprimirEnBloqueColor(x,y,"                                                          ",5);
        imprimirEnBloqueColor(x,y,"==========================================================",5);
        imprimirEnBloqueColor(x,y,"              Los precios no frenan.                             ",5);
        imprimirEnBloqueColor(x,y,"              La vida se complica.                             ",5);
        imprimirEnBloqueColor(x,y,"              Tus decisiones pesan.                           ",5);
        imprimirEnBloqueColor(x,y,"==========================================================",5);

    ubicarCursor(x, y);
    cout << " Presione ENTER para comenzar..." << endl;
    cin.get();
}

