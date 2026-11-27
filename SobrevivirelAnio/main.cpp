#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "menu.h"
#include "Visuales.h"
using namespace std;

int main() {

    SetConsoleOutputCP(1252);
    cout << fixed << setprecision(2);

    // Inicializa la semilla para los imprevistos aleatorios y eventos de BTC
    srand(time(NULL));
    mostrarportada();
    ejecutarMenuPrincipal();

    return 0;
}
