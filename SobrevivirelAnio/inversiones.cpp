#include <iostream>
#include <iomanip>
#include "inversiones.h"

using namespace std;

void decidirDistribucionSobrante(float sobrante, float &capital_a_invertir, float &capital_a_fondo, float &fondo_emergencia, float &saldo_pesos)
{
    int opcion_dist = 0;
    cout << "  [ PASO 1: DISTRIBUCION DEL SOBRANTE ]" << endl;
    cout << "  Sobrante disponible: $" << sobrante << endl << endl;
    cout << "  Como distribuis tu sobrante del mes?" << endl;
    cout << "  1. 25% inversion  | 75% fondo emerg." << endl;
    cout << "  2. 50% inversion  | 50% fondo emerg." << endl;
    cout << "  3. 75% inversion  | 25% fondo emerg." << endl;
    cout << "  4. 100% inversion |  0% fondo emerg." << endl;
    cout << "  Opcion: ";
    cin  >> opcion_dist;
    cin.ignore();

    float porcentaje_inversion = 0.50;
    switch (opcion_dist)
    {
    case 1: porcentaje_inversion = 0.25; break;
    case 2: porcentaje_inversion = 0.50; break;
    case 3: porcentaje_inversion = 0.75; break;
    case 4: porcentaje_inversion = 1.00; break;
    default: porcentaje_inversion = 0.50; break;
    }

    capital_a_invertir = sobrante * porcentaje_inversion;
    capital_a_fondo    = sobrante - capital_a_invertir;

    fondo_emergencia += capital_a_fondo;
    saldo_pesos       = 0.0;

    cout << endl;
    cout << "  >> Destinado a inversion:        $" << capital_a_invertir << endl;
    cout << "  >> Sumado al fondo emergencia:   $" << capital_a_fondo    << endl;
}

void decidirInstrumentoInversion(float capital_a_invertir, float precio_dolar, float precio_btc, float precio_sp500, float &saldo_pesos, int &dolares, float &btc, float &sp500)
{
    int opcion_instr = 0;
    cout << "  [ PASO 2: ELECCION DEL INSTRUMENTO DE INVERSION ]" << endl;
    cout << "  Capital a invertir: $" << capital_a_invertir << endl << endl;
    cout << "  1. Pesos en cuenta" << endl;
    cout << "     + A favor: Liquidez inmediata, sin riesgo." << endl;
    cout << "     - En contra: Pierde valor con la inflacion (7% mensual)." << endl << endl;
    cout << "  2. Dolares (USD) - Cotizacion: $" << precio_dolar << endl;
    cout << "     + A favor: Reserva de valor historica." << endl;
    cout << "     - En contra: Este anio el peso le gano al dolar en algunos periodos." << endl << endl;
    cout << "  3. Bitcoin (BTC) - Cotizacion: USD " << precio_btc << endl;
    cout << "     + A favor: Alto potencial de ganancia (+25% en meses pares)." << endl;
    cout << "     - En contra: Alto riesgo, puede caer drasticamente (-20% impares)." << endl << endl;
    cout << "  4. S&P 500 (ETF) - Cotizacion: USD " << precio_sp500 << endl;
    cout << "     + A favor: Crecimiento estable historico (+1% mensual promedio)." << endl;
    cout << "     - En contra: Requiere pensar en largo plazo, no es inmediato." << endl << endl;
    cout << "  Opcion: ";
    cin  >> opcion_instr;
    cin.ignore();

    cout << endl;
    switch (opcion_instr)
    {
    case 1:
        saldo_pesos += capital_a_invertir;
        cout << "  >> Dejaste $" << capital_a_invertir << " disponibles en tu cuenta en pesos." << endl;
        break;

    case 2:
    {
        int usd_comprados = (int)(capital_a_invertir / precio_dolar);
        float vuelto_pesos = capital_a_invertir - (usd_comprados * precio_dolar);
        dolares     += usd_comprados;
        saldo_pesos += vuelto_pesos;
        cout << "  >> Compraste " << usd_comprados << " USD (Sobro $" << vuelto_pesos << " en cuenta)." << endl;
        break;
    }
    case 3:
    {
        float usd_disponibles = capital_a_invertir / precio_dolar;
        float btc_comprado    = usd_disponibles / precio_btc;
        btc += btc_comprado;
        cout << "  >> Compraste " << setprecision(6) << btc_comprado << setprecision(2) << " BTC." << endl;
        break;


    }
    case 4:
    {
        float usd_disponibles  = capital_a_invertir / precio_dolar;
        float cuotas_compradas = usd_disponibles / precio_sp500;
        sp500 += cuotas_compradas;
        cout << "  >> Compraste " << cuotas_compradas << " cuotas del ETF S&P 500." << endl;
        break;
    }
    default:
        saldo_pesos += capital_a_invertir;
        cout << "  >> Opcion no valida. El capital quedo en tu cuenta en pesos." << endl;
        break;
    }
}

void actualizarPreciosEInflacion(int mes, float inflacion, float &precio_dolar, float &precio_btc, float &precio_sp500, float &inflacion_acumulada, float &gastos_fijos, float gastos_alquiler, float &gastos_servicios, float &gastos_transporte, float &gastos_comida)
{
    precio_dolar *= 1.05;

    if (mes == 6)
        precio_btc *= 1.60;
    else if (mes == 11)
        precio_btc *= 0.50;
    else if (mes % 2 == 0)
        precio_btc *= 1.25;
    else
        precio_btc *= 0.80;

    precio_sp500 *= 1.01;
    inflacion_acumulada *= (1.0 + inflacion);

    // El alquiler solo se actualiza en septiembre; el resto sube por inflacion mensual
    gastos_servicios  *= (1.0 + inflacion);
    gastos_transporte *= (1.0 + inflacion);
    gastos_comida     *= (1.0 + inflacion);
    gastos_fijos       = gastos_alquiler + gastos_servicios + gastos_transporte + gastos_comida;
}
