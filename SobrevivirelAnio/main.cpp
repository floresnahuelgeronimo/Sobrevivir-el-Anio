#include <iostream>
#include <ctime>
#include <cstdlib>
#include "menu.h"

using namespace std;

int main() {
    // Inicializa la semilla para los imprevistos aleatorios y eventos de BTC
    srand(time(NULL));

    // Ejecuta el menu principal manteniendo el estado de la sesion sin variables globales
    ejecutarMenuPrincipal();

    return 0;
}
