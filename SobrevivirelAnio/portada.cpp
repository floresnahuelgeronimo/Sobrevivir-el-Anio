#include <iostream>

#include "rlutil.h"
#include "Interfaz.h"

using namespace std;

void mostrarportada()
    {

    int x = calcularMargenX(54); // El recuadro mide 44 caracteres de ancho
    int y = 8;                   // Margen superior (empieza en la fila 5)

        imprimirEnBloqueColor(x,y,"==========================================================",9);
        imprimirEnBloqueColor(x,y,"                                                          ",9);
        imprimirEnBloqueColor(x,y,"              SOBREVIVIR EL AÑO                           ",9);
        imprimirEnBloqueColor(x,y,"                                                          ",9);
        imprimirEnBloqueColor(x,y,"       Simulador de Finanzas Personales                   ",9);
        imprimirEnBloqueColor(x,y,"                                                          ",9);
        imprimirEnBloqueColor(x,y,"==========================================================",9);
        imprimirEnBloqueColor(x,y,"                La inflación avanza.                             ",9);
        imprimirEnBloqueColor(x,y,"                Los gastos aumentan.                             ",9);
        imprimirEnBloqueColor(x,y,"              Tus decisiones importan.                           ",9);
        imprimirEnBloqueColor(x,y,"==========================================================",9);

    ubicarCursor(x, y);
    cout << " Presione ENTER para comenzar..." << endl;
    cin.get();
}

