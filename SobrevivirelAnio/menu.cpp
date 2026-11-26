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
    int x = calcularMargenX(44); // El recuadro mide 44 caracteres de ancho
    int y = 5;                   // Margen superior (empieza en la fila 5)

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
    // Variables de sesion (locales a esta funcion, respetan los nombres del PDF)
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

void mostrarGlosario()
{
    int opcion_glosario=-1;
    while (opcion_glosario != 0)
    {
        system("cls");
        cout << "============================================" << endl;
        cout << "          GLOSARIO FINANCIERO               " << endl;
        cout << "============================================" << endl;
        cout << "  1.  Inflacion"                    << endl;
        cout << "  2.  Poder adquisitivo"            << endl;
        cout << "  3.  Salario real vs nominal"      << endl;
        cout << "  4.  Fondo de emergencia"          << endl;
        cout << "  5.  Diversificacion"              << endl;
        cout << "  6.  Costo de oportunidad"         << endl;
        cout << "  7.  Volatilidad"                  << endl;
        cout << "  8.  Liquidez"                     << endl;
        cout << "  9.  Indexacion"                   << endl;
        cout << "  10. ETF (Exchange-Traded Fund)"   << endl;
        cout << "  11. Patrimonio real"              << endl;
        cout << "  12. Patrimonio inicial"           << endl;
        cout << "  0.  Volver al menu principal"     << endl;
        cout << "============================================" << endl;
        cout << "  Opcion: ";
        opcion_glosario = pedirOpcionEntera();

        if (opcion_glosario != 0)
        {
            mostrarDefinicionGlosario(opcion_glosario);
            pausarPantalla();
            }else if (opcion_glosario == 0){
            return;
            }

        }
    }


void mostrarDefinicionGlosario(int opcion_glosario)
{
    string titulos[12] = {
        "INFLACION",
        "PODER ADQUISITIVO",
        "SALARIO REAL vs SALARIO NOMINAL",
        "FONDO DE EMERGENCIA",
        "DIVERSIFICACION",
        "COSTO DE OPORTUNIDAD",
        "VOLATILIDAD",
        "LIQUIDEZ",
        "INDEXACION",
        "ETF (Exchange-Traded Fund)",
        "PATRIMONIO REAL",
        "PATRIMONIO INICIAL"
    };

    string definiciones[12] = {
        "Aumento generalizado y sostenido de los\n  precios de bienes y servicios. Hace que\n  el dinero valga menos con el tiempo.",
        "Cantidad de bienes y servicios que se\n  pueden comprar con una suma de dinero.\n  Disminuye cuando hay inflacion.",
        "Nominal: el numero en el recibo de sueldo.\n  Real: cuanto se puede comprar con ese dinero.\n  Si la inflacion supera al aumento del sueldo,\n  el salario real cae.",
        "Reserva de dinero liquido disponible para\n  cubrir gastos imprevistos sin necesidad de\n  endeudarse ni vender inversiones a perdida.",
        "Estrategia de distribuir el dinero entre\n  distintos instrumentos para reducir el\n  riesgo total. 'No poner todos los huevos\n  en la misma canasta.'",
        "El valor de la mejor alternativa que se\n  resigna al tomar una decision. Guardar\n  plata en pesos tiene el costo de oportunidad\n  de no invertirla.",
        "Medida de cuanto varia el precio de un\n  activo. Un instrumento muy volatil (como\n  Bitcoin) puede subir o bajar mucho en\n  poco tiempo.",
        "Facilidad con la que un activo se puede\n  convertir en dinero disponible. El efectivo\n  es el mas liquido; los inmuebles, el menos.",
        "Mecanismo por el cual el valor de un\n  contrato (como un alquiler) se ajusta\n  periodicamente segun un indice de precios.",
        "Fondo de inversion que cotiza en bolsa y\n  replica el comportamiento de un indice,\n  como el S&P 500. Permite invertir en muchas\n  empresas a la vez con bajo costo.",
        "Saldo disponible en pesos + Fondo de\n  emergencia + Inversiones (pesificadas),\n  ajustado por la inflacion acumulada.",
        "Dinero con el que se comienza el juego\n  ($150.000 pesos)."
    };

    system("cls");
    cout << "============================================" << endl;
    if (opcion_glosario >= 1 && opcion_glosario <= 12)
    {
        cout << "  " << titulos[opcion_glosario - 1] << endl;
        cout << "--------------------------------------------" << endl;
        cout << "  " << definiciones[opcion_glosario - 1] << endl;
    }
else if (opcion_glosario != 0) {
    cout << "Opcion invalida." << endl;
    pausarPantalla();
}
    cout << "============================================" << endl;
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
    if (!opcion) {
        cin.clear();             // Destraba cin para no romper el menú principal
        cin.ignore(10000, '\n'); // Limpia las letras que quedaron en el buffer
        return -1;               // Fuerza opción inválida para tu else/default
    }
    cin.ignore(10000, '\n');     // Limpia el Enter o texto sobrante
    return opcion;
}
