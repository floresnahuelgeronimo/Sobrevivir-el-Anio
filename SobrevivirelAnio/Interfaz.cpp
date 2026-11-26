#include <iostream>
#include "rlutil.h"
#include "interfaz.h"

using namespace std;

void limpiarPantalla()
{
    rlutil::cls();
}

void pausarPantalla()
{
rlutil::anykey("Presione una tecla para continuar...");

}

int calcularMargenX(int ancho_bloque)
{
    int x = (rlutil::tcols() - ancho_bloque) / 2;

    // Seguridad: si la ventana es muy angosta, arranca en la columna 1
    if (x < 1)
    {
        x = 1;
    }
    return x;
}

void ubicarCursor(int x, int y)
{
    rlutil::locate(x, y);
}

void imprimirEnBloque(int x, int &y, string texto)
{
    rlutil::locate(x, y);
    cout << texto;
    y++;
}

void imprimirTextoCentrado(int &y, string texto)
{
    int x = calcularMargenX(texto.length());
    rlutil::locate(x, y);
    cout << texto;
    y++;
}

void pausarCentrado(int x, int &y, string mensaje)
{
    y++;
    rlutil::locate(x, y);
    cout << mensaje;
    rlutil::anykey(); // Espera cualquier tecla sin depender del buffer de cin
}

// --- Funciones de color ---

void cambiarColor(int color)
{
    rlutil::setColor(color);
}

void cambiarFondo(int color)
{
    rlutil::setBackgroundColor(color);
}

void restaurarColor()
{
    rlutil::setColor(15);
    rlutil::setBackgroundColor(0);
}

void imprimirEnBloqueColor(int x, int &y, string texto, int color)
{
    rlutil::setColor(color);
    rlutil::locate(x, y);
    cout << texto;
    rlutil::setColor(15); // Restaura el color automaticamente
    y++;
}


