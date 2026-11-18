#ifndef INVERSIONES_H_INCLUDED
#define INVERSIONES_H_INCLUDED

/// Paso 1: Solicita el porcentaje a invertir vs fondo de emergencia
void decidirDistribucionSobrante(float sobrante, float &capital_a_invertir, float &capital_a_fondo, float &fondo_emergencia, float &saldo_pesos);

/// Paso 2: Solicita el instrumento financiero y realiza la compra
void decidirInstrumentoInversion(float capital_a_invertir, float precio_dolar, float precio_btc, float precio_sp500, float &saldo_pesos, int &dolares, float &btc, float &sp500);

/// Actualiza cotizaciones (USD, BTC, S&P500), inflacion acumulada y gastos fijos
void actualizarPreciosEInflacion(int mes, float inflacion, float &precio_dolar, float &precio_btc, float &precio_sp500, float &inflacion_acumulada, float &gastos_fijos, float gastos_alquiler, float &gastos_servicios, float &gastos_transporte, float &gastos_comida);

#endif // INVERSIONES_H_INCLUDED
