#ifndef EVENTOS_H_INCLUDED
#define EVENTOS_H_INCLUDED

// Evalua y aplica deposito de garantia, paritarias, aguinaldo y suba de alquiler
void aplicarEventosFijos(int mes, float &sueldo, float &saldo_pesos, float &gastos_alquiler, float &gastos_fijos, float gastos_servicios, float gastos_transporte, float gastos_comida);

// Calcula entre 0 y 3 imprevistos al azar y los descuenta del fondo de emergencia o del saldo
void procesarImprevistos(float &saldo_pesos, float &fondo_emergencia, int &meses_sin_fondo);

#endif // EVENTOS_H_INCLUDED
