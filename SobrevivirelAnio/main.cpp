#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "menu.h"
#include "portada.h"

using namespace std;

int main() {
    // Inicializa la semilla para los imprevistos aleatorios y eventos de BTC
    SetConsoleOutputCP(1252);
    srand(time(NULL));
    mostrarportada();
    ejecutarMenuPrincipal();

    return 0;
}
