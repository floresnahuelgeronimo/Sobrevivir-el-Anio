#include <iostream>
#include <cstdlib>

#include "juego.h"
#include "menu.h"
#include "eventos.h"
#include "inversiones.h"
#include "Interfaz.h"

using namespace std;

void iniciarNuevaPartida(int &sesion_cantidad_partidas, float &sesion_mejor_patrimonio, string &sesion_mejor_jugador)
{
    string nombre_jugador = "";
    int    cantidad_meses = 12;

    const float PATRIMONIO_INICIAL = 150000.0;
    float sueldo                   = 500000.0;
    float saldo_pesos              = PATRIMONIO_INICIAL;
    float fondo_emergencia         = 0.0;

    int   dolares = 0;
    float btc     = 0.0;
    float sp500   = 0.0;

    float precio_dolar = 1100.0;
    float precio_btc   = 65000.0;
    float precio_sp500 = 500.0;

    const float INFLACION   = 0.07;
    float gastos_alquiler   = 180000.0;
    float gastos_servicios  = 45000.0;
    float gastos_transporte = 30000.0;
    float gastos_comida     = 80000.0;
    float gastos_fijos      = gastos_alquiler + gastos_servicios + gastos_transporte + gastos_comida;

    int   meses_en_rojo       = 0;
    int   meses_sin_fondo     = 0;
    float ahorro_maximo       = 0.0;
    float ahorro_minimo       = 0.0;
    int   mes_mejor           = 1;
    int   mes_peor            = 1;
    float inflacion_acumulada = 1.0;
    bool  game_over           = false;

    pedirDatosIniciales(nombre_jugador, cantidad_meses);

    for (int mes = 1; mes <= cantidad_meses && !game_over; mes++)
    {
        // SECCION 1: Eventos fijos y cobro de sueldo
        mostrarPanelEstado(mes, cantidad_meses, nombre_jugador, saldo_pesos, fondo_emergencia, dolares, btc, sp500, sueldo, gastos_fijos);
        aplicarEventosFijos(mes, sueldo, saldo_pesos, gastos_alquiler, gastos_fijos, gastos_servicios, gastos_transporte, gastos_comida);

        saldo_pesos += sueldo;
        cout << "  >> Sueldo acreditado: +$" << sueldo << endl;
        cout << "  >> Nuevo disponible en pesos: $" << saldo_pesos << endl;
            pausarPantalla();

        // SECCION 2: Imprevistos y descuento de gastos fijos
        mostrarPanelEstado(mes, cantidad_meses, nombre_jugador, saldo_pesos, fondo_emergencia, dolares, btc, sp500, sueldo, gastos_fijos);
        procesarImprevistos(saldo_pesos, fondo_emergencia, meses_sin_fondo);

        game_over = pagarGastosYVerificarGameOver(mes, gastos_fijos, fondo_emergencia, saldo_pesos, meses_en_rojo);
        if (game_over)
        {
            registrarMejorYPeorMes(mes, saldo_pesos, ahorro_maximo, mes_mejor, ahorro_minimo, mes_peor);
            pausarPantalla();
            break;
        }

        if (saldo_pesos <= 0)
        {
            cout << "  Sin sobrante disponible para ahorrar o invertir este mes." << endl;
            registrarMejorYPeorMes(mes, saldo_pesos, ahorro_maximo, mes_mejor, ahorro_minimo, mes_peor);
            actualizarPreciosEInflacion(mes, INFLACION, precio_dolar, precio_btc, precio_sp500, inflacion_acumulada, gastos_fijos, gastos_alquiler, gastos_servicios, gastos_transporte, gastos_comida);
            pausarPantalla();

            mostrarPanelEstado(mes, cantidad_meses, nombre_jugador, saldo_pesos, fondo_emergencia, dolares, btc, sp500, sueldo, gastos_fijos);
            mostrarTipDelMes(mes);
            pausarPantalla();
            continue;
        }

            pausarPantalla();

        // SECCION 3: Distribucion del sobrante
        mostrarPanelEstado(mes, cantidad_meses, nombre_jugador, saldo_pesos, fondo_emergencia, dolares, btc, sp500, sueldo, gastos_fijos);
        float sobrante           = saldo_pesos;
        float capital_a_invertir = 0.0;
        float capital_a_fondo    = 0.0;
        decidirDistribucionSobrante(sobrante, capital_a_invertir, capital_a_fondo, fondo_emergencia, saldo_pesos);
            pausarPantalla();

        // SECCION 4: Eleccion del instrumento
        if (capital_a_invertir > 0)
        {
            mostrarPanelEstado(mes, cantidad_meses, nombre_jugador, saldo_pesos, fondo_emergencia, dolares, btc, sp500, sueldo, gastos_fijos);
            decidirInstrumentoInversion(capital_a_invertir, precio_dolar, precio_btc, precio_sp500, saldo_pesos, dolares, btc, sp500);
            pausarPantalla();
        }

        // Actualizacion de precios y estadisticas del mes
        actualizarPreciosEInflacion(mes, INFLACION, precio_dolar, precio_btc, precio_sp500, inflacion_acumulada, gastos_fijos, gastos_alquiler, gastos_servicios, gastos_transporte, gastos_comida);
        registrarMejorYPeorMes(mes, sobrante, ahorro_maximo, mes_mejor, ahorro_minimo, mes_peor);

        // SECCION 5: Tip educativo
        mostrarPanelEstado(mes, cantidad_meses, nombre_jugador, saldo_pesos, fondo_emergencia, dolares, btc, sp500, sueldo, gastos_fijos);
        mostrarTipDelMes(mes);
        pausarPantalla();
    }

    sesion_cantidad_partidas++;
    mostrarResumenFinal(game_over, nombre_jugador, PATRIMONIO_INICIAL, saldo_pesos, fondo_emergencia, dolares, btc, sp500, precio_dolar, precio_btc, precio_sp500, inflacion_acumulada, mes_mejor, ahorro_maximo, mes_peor, ahorro_minimo, meses_sin_fondo, sesion_mejor_patrimonio, sesion_mejor_jugador);

        pausarPantalla();
}

void pedirDatosIniciales(string &nombre_jugador, int &cantidad_meses)
{
    limpiarPantalla();

    cout << "============================================" << endl;
    cout << "          NUEVA PARTIDA                     " << endl;
    cout << "============================================" << endl;
    cout << endl;
    cout << "  Ingresa tu nombre: ";
    cin  >> nombre_jugador;
    cin.ignore();

    cout << "  Cuantos meses deseas jugar? (1 a 12): ";
    cin  >> cantidad_meses;
    cin.ignore();

    while (cantidad_meses < 1 || cantidad_meses > 12)
    {
        cout << "  Cantidad invalida. Ingresa un valor entre 1 y 12: ";
        cin  >> cantidad_meses;
        cin.ignore();
    }

    system("cls");
    cout << "============================================" << endl;
    cout << "  Bienvenido/a, " << nombre_jugador << "!" << endl;
    cout << "============================================" << endl;
    cout << endl;
    cout << "  Es enero. Acabas de conseguir tu primer" << endl;
    cout << "  trabajo como recien recibido/a." << endl;
    cout << "  Patrimonio inicial: $150.000" << endl;
    cout << "  Sueldo inicial:     $500.000" << endl;
    cout << "  Objetivo: sobrevivir " << cantidad_meses << " mes(es) sin que" << endl;
    cout << "  la inflacion destruya tu poder adquisitivo." << endl;

        pausarPantalla();
}

string obtenerNombreMes(int mes)
{
    string nombres_meses[12] = {
        "ENERO", "FEBRERO", "MARZO", "ABRIL",
        "MAYO", "JUNIO", "JULIO", "AGOSTO",
        "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"
    };

    if (mes >= 1 && mes <= 12)
    {
        return nombres_meses[mes - 1];
    }
    return "";
}

void mostrarPanelEstado(int mes, int cantidad_meses, string nombre_jugador, float saldo_pesos, float fondo_emergencia, int dolares, float btc, float sp500, float sueldo, float gastos_fijos)
{
    system("cls");
    cout << "============================================================" << endl;
    cout << "  MES " << mes << "/" << cantidad_meses << " " << obtenerNombreMes(mes)
         << " | Jugador: " << nombre_jugador << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "  TENENCIAS ACTUALES" << endl;
    cout << "  Disponible en pesos:  $ " << saldo_pesos      << endl;
    cout << "  Fondo de emergencia:  $ " << fondo_emergencia << endl;
    cout << "  Dolares:              "   << dolares          << " USD" << endl;
    cout << "  BTC:                  "   << btc              << " BTC" << endl;
    cout << "  S&P 500:              "   << sp500            << " cuotas" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "  Sueldo del mes:       $ " << sueldo           << endl;
    cout << "  Gastos fijos:         $ " << gastos_fijos     << endl;
    cout << "============================================================" << endl;
    cout << endl;
}

bool pagarGastosYVerificarGameOver(int mes, float gastos_fijos, float fondo_emergencia, float &saldo_pesos, int &meses_en_rojo)
{
    saldo_pesos -= gastos_fijos;

    cout << "  [ PAGO DE GASTOS FIJOS (-$" << gastos_fijos << ") ]" << endl;
    if (saldo_pesos < 0)
    {
        cout << "  >> SALDO TRAS GASTOS FIJOS: -$" << (saldo_pesos * -1) << " (EN ROJO!)" << endl;
        meses_en_rojo++;
        cout << "  >> Meses consecutivos en rojo: " << meses_en_rojo << "/3" << endl;
    }
    else
    {
        cout << "  >> SOBRANTE DISPONIBLE DEL MES: $" << saldo_pesos << endl;
        meses_en_rojo = 0;
    }
    cout << endl;

    if (meses_en_rojo >= 3)
    {
        cout << "============================================================" << endl;
        cout << "                        GAME OVER                           " << endl;
        cout << "  Estuviste 3 meses consecutivos en rojo." << endl;
        cout << "  Te fuiste a vivir a lo de tus viejos." << endl;
        cout << "============================================================" << endl;
        return true;
    }
    return false;
}

void registrarMejorYPeorMes(int mes, float monto_evaluado, float &ahorro_maximo, int &mes_mejor, float &ahorro_minimo, int &mes_peor)
{
if (mes == 1)
    {
        // En el primer mes, ese monto es automaticamente el mejor y el peor hasta ahora
        ahorro_maximo = monto_evaluado;
        mes_mejor     = mes;
        ahorro_minimo = monto_evaluado;
        mes_peor      = mes;
    }
    else if (monto_evaluado > ahorro_maximo)
    {
        ahorro_maximo = monto_evaluado;
        mes_mejor     = mes;
    }
    if (monto_evaluado < ahorro_minimo)
    {
        ahorro_minimo = monto_evaluado;
        mes_peor      = mes;
    }
}

void mostrarTipDelMes(int mes)
{
    string tips[12] = {
        "La INFLACION es el aumento sostenido de los precios.\n  Aunque tu sueldo nominal parezca igual, cada mes compra menos.",
        "El FONDO DE EMERGENCIA cubre imprevistos sin vender inversiones\n  a perdida. Se recomienda tener de 3 a 6 meses de gastos cubiertos.",
        "El COSTO DE OPORTUNIDAD es lo que resignas al elegir. Dejar\n  pesos quietos en la cuenta pierde un 7% de poder de compra al mes.",
        "Tu sueldo subio 15% por paritarias, pero la inflacion acumulada\n  fue mayor. Eso explica la caida del SALARIO REAL.",
        "DIVERSIFICAR es repartir tus ahorros en distintos instrumentos\n  para reducir el riesgo. No pongas todos los huevos en una canasta.",
        "El AGUINALDO (SAC) es medio sueldo extra en junio y diciembre.\n  Aprovechalo para reforzar tu fondo o tus inversiones.",
        "La VOLATILIDAD mide cuanto salta el precio de un activo.\n  Activos como Bitcoin pueden darte grandes subas o fuertes caidas.",
        "La LIQUIDEZ es la rapidez para convertir un activo en efectivo.\n  El fondo de emergencia siempre debe ser liquido.",
        "La INDEXACION actualiza contratos como el alquiler siguiendo\n  la inflacion acumulada. Preve estos saltos en tu presupuesto.",
        "Un ETF del S&P 500 te permite invertir en las 500 empresas mas\n  grandes de EE.UU. con crecimiento historico estable.",
        "Los eventos extremos del mercado ocurren sin avisar. Una\n  cartera diversificada resiste mejor las caidas bruscas.",
        "El PATRIMONIO REAL mide cuanto vale tu dinero descontando\n  la inflacion. El verdadero objetivo es conservar poder de compra."
    };

    cout << "  [ TIP EDUCATIVO DEL MES ]" << endl;
    if (mes >= 1 && mes <= 12)
    {
        cout << "  " << tips[mes - 1] << endl;
    }
}

void mostrarResumenFinal(bool game_over, string nombre_jugador, float patrimonio_inicial, float saldo_pesos, float fondo_emergencia, int dolares, float btc, float sp500, float precio_dolar, float precio_btc, float precio_sp500, float inflacion_acumulada, int mes_mejor, float ahorro_maximo, int mes_peor, float ahorro_minimo, int meses_sin_fondo, float &sesion_mejor_patrimonio, string &sesion_mejor_jugador)
{
    system("cls");
    cout << "============================================================" << endl;
    cout << "             RESUMEN FINAL DE LA PARTIDA                    " << endl;
    cout << "  Jugador: " << nombre_jugador << endl;
    cout << "============================================================" << endl;
    cout << endl;

    float patrimonio_dolares = dolares * precio_dolar;
    float patrimonio_btc     = btc * precio_btc * precio_dolar;
    float patrimonio_sp500   = sp500 * precio_sp500 * precio_dolar;
    float patrimonio_nominal = saldo_pesos + fondo_emergencia + patrimonio_dolares + patrimonio_btc + patrimonio_sp500;
    float patrimonio_real    = patrimonio_nominal / inflacion_acumulada;

    cout << "  DESGLOSE DE PATRIMONIO FINAL (EN PESOS):" << endl;
    cout << "  - Disponible en pesos:      $" << saldo_pesos        << endl;
    cout << "  - Fondo de emergencia:      $" << fondo_emergencia   << endl;
    cout << "  - Dolares (" << dolares << " USD):          $" << patrimonio_dolares << endl;
    cout << "  - Bitcoin (" << btc << " BTC):        $" << patrimonio_btc     << endl;
    cout << "  - S&P 500 (" << sp500 << " cuotas):   $" << patrimonio_sp500   << endl;
    cout << "  ----------------------------------------------------------" << endl;
    cout << "  PATRIMONIO NOMINAL FINAL:   $" << patrimonio_nominal << endl;
    cout << "  PATRIMONIO REAL (Ajustado): $" << patrimonio_real    << endl;
    cout << "  PATRIMONIO INICIAL:         $" << patrimonio_inicial << endl;
    cout << endl;

    cout << "  ESTADISTICAS DE LA PARTIDA:" << endl;
    cout << "  - Mes con mayor ahorro:            Mes " << mes_mejor << " ($" << ahorro_maximo << ")" << endl;
    cout << "  - Mes con mayor gasto / menor sob: Mes " << mes_peor  << " ($" << ahorro_minimo << ")" << endl;
    cout << "  - Meses sin fondo de emergencia:   "     << meses_sin_fondo << endl;
    cout << "  - Inflacion acumulada:             "     << (inflacion_acumulada - 1.0) * 100.0 << "%" << endl;
    cout << endl;

    cout << "============================================================" << endl;
    if (game_over)
    {
        cout << "  FINAL: Game Over" << endl;
        cout << "  Mensaje: Te fuiste a vivir a lo de tus viejos (3 meses en rojo)." << endl;
    }
    else if (patrimonio_real > patrimonio_inicial * 1.10)
    {
        cout << "  FINAL: Sobreviviste el anio con dignidad!" << endl;
        cout << "  Mensaje: Lograste vencer a la inflacion." << endl;
    }
    else if (patrimonio_real >= patrimonio_inicial * 0.90)
    {
        cout << "  FINAL: Empataste con la inflacion" << endl;
        cout << "  Mensaje: No perdiste, pero tampoco ganaste." << endl;
    }
    else
    {
        cout << "  FINAL: La inflacion te comio" << endl;
        cout << "  Mensaje: Tu dinero vale menos que en enero." << endl;
    }
    cout << "============================================================" << endl;

    if (patrimonio_real > sesion_mejor_patrimonio)
    {
        sesion_mejor_patrimonio = patrimonio_real;
        sesion_mejor_jugador    = nombre_jugador;
    }
}

