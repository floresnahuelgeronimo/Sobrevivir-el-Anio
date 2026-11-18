#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <string>

using namespace std;

// Coordina la partida completa y actualiza las estadisticas de la sesion
void iniciarNuevaPartida(int &sesion_cantidad_partidas, float &sesion_mejor_patrimonio, string &sesion_mejor_jugador);

// Pide nombre del jugador y cantidad de rondas (1 a 12)
void pedirDatosIniciales(string &nombre_jugador, int &cantidad_meses);

// Devuelve el nombre del mes usando un vector
string obtenerNombreMes(int mes);

// Limpia la pantalla y dibuja arriba el panel de estado fijo
void mostrarPanelEstado(int mes, int cantidad_meses, string nombre_jugador, float saldo_pesos, float fondo_emergencia, int dolares, float btc, float sp500, float sueldo, float gastos_fijos);

// Descuenta gastos fijos, controla meses en rojo y devuelve true si hubo Game Over
bool pagarGastosYVerificarGameOver(int mes, float gastos_fijos, float fondo_emergencia, float &saldo_pesos, int &meses_en_rojo);

// Registra el mes de mayor ahorro y el de mayor gasto/menor sobrante
void registrarMejorYPeorMes(int mes, float monto_evaluado, float &ahorro_maximo, int &mes_mejor, float &ahorro_minimo, int &mes_peor);

// Muestra el consejo educativo correspondiente al mes usando un vector
void mostrarTipDelMes(int mes);

// Muestra las estadisticas finales y actualiza el highscore de la sesion
void mostrarResumenFinal(bool game_over, string nombre_jugador, float patrimonio_inicial, float saldo_pesos, float fondo_emergencia, int dolares, float btc, float sp500, float precio_dolar, float precio_btc, float precio_sp500, float inflacion_acumulada, int mes_mejor, float ahorro_maximo, int mes_peor, float ahorro_minimo, int meses_sin_fondo, float &sesion_mejor_patrimonio, string &sesion_mejor_jugador);
#endif // JUEGO_H_INCLUDED
