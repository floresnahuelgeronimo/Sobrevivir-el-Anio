#include <iostream>
#include <iomanip>
#include "rlutil.h"
#include "menu.h"
#include "juego.h"

using namespace std;

void ejecutarMenuPrincipal() {
    int sesion_cantidad_partidas = 0;
    float sesion_mejor_patrimonio = 0.0;
    string sesion_mejor_jugador = "Ninguno";

 int opcion = -1;
    bool salirConfirmado = false;

    do {
        rlutil::cls();
        rlutil::setColor(rlutil::CYAN);
        cout << "========================================" << endl;
        cout << "           SOBREVIVIR EL ANIO           " << endl;
        cout << "========================================" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "1. Nueva Partida" << endl;
        cout << "2. Highscore de la sesion" << endl;
        cout << "3. Glosario Financiero" << endl;
        cout << "0. Salir" << endl;
        rlutil::setColor(rlutil::CYAN);
        cout << "========================================" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                iniciarNuevaPartida(sesion_cantidad_partidas, sesion_mejor_patrimonio, sesion_mejor_jugador);
                break;
            case 2:
                mostrarHighscore(sesion_cantidad_partidas, sesion_mejor_patrimonio, sesion_mejor_jugador);
                break;
            case 3:
                mostrarGlosario();
                break;
            case 0:
                salirConfirmado = confirmarSalida();
                break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\nOpcion invalida. Presione una tecla para reintentar..." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                break;
        }
    } while (!salirConfirmado);
}

void mostrarHighscore(int sesion_cantidad_partidas, float sesion_mejor_patrimonio, string sesion_mejor_jugador) {
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    cout << "========================================" << endl;
    cout << "         HIGHSCORE DE LA SESION         " << endl;
    cout << "========================================" << endl;
    rlutil::setColor(rlutil::WHITE);

    if (sesion_cantidad_partidas == 0) {
        cout << "Todavia no se registraron partidas finalizadas en esta sesion." << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << "Partidas jugadas en la sesion : " << sesion_cantidad_partidas << endl;
        cout << "Mejor jugador                 : " << sesion_mejor_jugador << endl;
        cout << "Mejor patrimonio real final   : $ " << sesion_mejor_patrimonio << endl;
    }

    rlutil::setColor(rlutil::YELLOW);
    cout << "========================================" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "Presione cualquier tecla para volver...";
    rlutil::anykey();
}

void mostrarGlosario() {
    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "======================================================================" << endl;
    cout << "                         GLOSARIO FINANCIERO                          " << endl;
    cout << "======================================================================" << endl;
    rlutil::setColor(rlutil::WHITE);

    cout << "1. Inflacion: Aumento generalizado y sostenido de los precios de bienes" << endl;
    cout << "   y servicios. Hace que el dinero valga menos con el tiempo." << endl;

    cout << "2. Poder adquisitivo: Cantidad de bienes y servicios que se pueden" << endl;
    cout << "   comprar con una suma de dinero. Disminuye cuando hay inflacion." << endl;

    cout << "3. Salario real vs. nominal: El nominal es el numero del recibo. El real" << endl;
    cout << "   mide cuanto se puede comprar. Si la inflacion supera al sueldo, cae." << endl;

    cout << "4. Fondo de emergencia: Reserva de dinero liquido para cubrir imprevistos" << endl;
    cout << "   sin necesidad de endeudarse ni vender inversiones." << endl;

    cout << "5. Diversificacion: Estrategia de distribuir el dinero entre distintos" << endl;
    cout << "   instrumentos para reducir el riesgo ('no poner todo en una canasta')." << endl;

    cout << "6. Costo de oportunidad: Valor de la mejor alternativa que se resigna" << endl;
    cout << "   al tomar una decision (ej. dejar pesos quietos sin invertir)." << endl;

    cout << "7. Volatilidad: Medida de cuanto varia el precio de un activo (como BTC)." << endl;

    cout << "8. Liquidez: Facilidad con la que un activo se convierte en efectivo." << endl;

    cout << "9. Indexacion: Ajuste periodico de un contrato (ej. alquiler) segun un" << endl;
    cout << "   indice de precios para mantener su valor real." << endl;

    cout << "10. ETF (Exchange-Traded Fund): Fondo que cotiza en bolsa y replica un" << endl;
    cout << "    indice como el S&P 500, invirtiendo en muchas empresas a bajo costo." << endl;

    cout << "11. Patrimonio real: Disponible en pesos + Fondo de emergencia +" << endl;
    cout << "    Inversiones pesificadas, ajustado por la inflacion acumulada." << endl;

    cout << "12. Patrimonio inicial: Dinero con el que se comienza el juego ($150.000)." << endl;

    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "======================================================================" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "Presione cualquier tecla para continuar...";
    rlutil::anykey();
}

bool confirmarSalida() {
    char respuesta;
    do {
        cout << "Esta seguro que desea salir del juego? (S/N): ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            cout << "Gracias por jugar a Sobrevivir el Anio. Hasta pronto!" << endl;
            return true;
        } else if (respuesta == 'N' || respuesta == 'n') {
            return false;
        } else {
            cout << "Ingreso invalido. Responda con S o N." << endl;
        }
    } while (true);
}
