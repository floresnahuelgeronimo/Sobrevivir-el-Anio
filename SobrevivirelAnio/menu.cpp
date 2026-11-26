#include <iostream>
#include <cstdlib>

#include "rlutil.h"
#include "menu.h"
#include "juego.h"
#include "Creditos.h"
#include "Interfaz.h"
using namespace std;

char pedirOpcionMenu()
{
int opcion;
    int x = 34; // Margen superior (empieza en la Columna 34)
    int y = 9;  // Margen superior (empieza en la fila 9)

    limpiarPantalla();
    imprimirEnBloqueColor(x, y, "============================================",5);
    imprimirEnBloqueColor(x, y, "             SOBREVIVIR EL AÑO              ",5);
    imprimirEnBloqueColor(x, y, "       Simulador de Finanzas en Argentina   ",5);
    imprimirEnBloqueColor(x, y, "============================================",5);
    imprimirEnBloqueColor(x, y, "  1. Nueva Partida                          ",5);
    imprimirEnBloqueColor(x, y, "  2. Highscore de la sesion                 ",5);
    imprimirEnBloqueColor(x, y, "  3. Glosario Financiero                    ",5);
    imprimirEnBloqueColor(x, y, "  4. Creditos                               ",5);
    imprimirEnBloqueColor(x, y, "  0. Salir                                  ",5);
    imprimirEnBloqueColor(x, y, "============================================",5);
    ubicarCursor(x, y);
    cout << "  Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}
void ejecutarMenuPrincipal()
{
    // Variables de sesion (locales a esta funcion)
    int    sesion_cantidad_partidas = 0;
    float  sesion_mejor_patrimonio  = 0.0;
    string sesion_mejor_jugador     = "";

    bool salir = false;

    while (!salir)
    {
        int opcion_menu = pedirOpcionMenu();

        switch (opcion_menu)
        {
        case 1:
            iniciarNuevaPartida(sesion_cantidad_partidas, sesion_mejor_patrimonio, sesion_mejor_jugador);
            break;

        case 2:
            mostrarHighscore(sesion_cantidad_partidas, sesion_mejor_patrimonio, sesion_mejor_jugador);
            break;

        case 3:
            mostrarGlosario();
            break;
        case 4:
            mostrarcreditos();
            break;

        case 0:
            salir = confirmarSalida();
            break;

        default:
            cout << endl << "  Opcion invalida. Intenta de nuevo." << endl;
            pausarPantalla();
            break;
        }
    }
}



void mostrarHighscore(int sesion_cantidad_partidas, float sesion_mejor_patrimonio, string sesion_mejor_jugador)
{
limpiarPantalla();
    cout << "============================================" << endl;
    cout << "         HIGHSCORE DE LA SESION             " << endl;
    cout << "============================================" << endl;
    cout << endl;

    if (sesion_cantidad_partidas == 0)
    {
        cout << "  Todavia no se jugo ninguna partida." << endl;
        cout << "  Inicia una partida para ver el ranking!" << endl;
    }
    else
    {
        cout << "  Partidas jugadas:      " << sesion_cantidad_partidas << endl;
        cout << "  Mejor jugador/a:       " << sesion_mejor_jugador     << endl;
        cout << "  Mejor patrimonio real: $" << sesion_mejor_patrimonio << endl;
    }

    pausarPantalla();
}



bool confirmarSalida()
{
    char respuesta;
    cout << endl << "  Seguro que deseas salir del juego? (S/N): ";
    cin  >> respuesta;
    cin.ignore();

    if (respuesta == 'S' || respuesta == 's')
    {
        system("cls");
        cout << "============================================" << endl;
        cout << "  Hasta la proxima!" << endl;
        cout << "  Recorda: la inflacion no descansa." << endl;
        cout << "============================================" << endl;
        return true;
    }
    return false;
}


int pedirOpcionEntera() {
    int opcion;
    cin >> opcion;

    if (cin.fail()) { // Solo entra si falló cin (por ej. una letra), NO si pusiste 0
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }

    cin.ignore(10000, '\n');
    return opcion;
}
