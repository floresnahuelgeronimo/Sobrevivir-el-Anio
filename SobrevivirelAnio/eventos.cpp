#include <iostream>
#include <cstdlib>
#include <string>
#include "eventos.h"

using namespace std;

void aplicarEventosFijos(int mes, float &sueldo, float &saldo_pesos, float &gastos_alquiler, float &gastos_fijos, float gastos_servicios, float gastos_transporte, float gastos_comida)
{
    cout << "  [ EVENTOS DEL MES ]" << endl;
    bool hubo_evento = false;

    if (mes == 1)
    {
        cout << "  ** DEPOSITO DE GARANTIA **" << endl;
        cout << "  Gasto inicial al mudarse al departamento: -$180.000" << endl;
        saldo_pesos -= 180000.0;
        hubo_evento = true;
    }

    if (mes == 4 || mes == 7 || mes == 10)
    {
        float aumento = sueldo * 0.15;
        sueldo += aumento;
        cout << "  ** AUMENTO PARITARIO (+15%) **" << endl;
        cout << "  Tu sueldo se actualizo a: $" << sueldo << endl;
        hubo_evento = true;
    }

    if (mes == 6 || mes == 12)
    {
        float aguinaldo = sueldo * 0.5;
        saldo_pesos += aguinaldo;
        cout << "  ** AGUINALDO (SAC) **" << endl;
        cout << "  Cobras medio sueldo adicional obligatorio por ley: +$" << aguinaldo << endl;
        hubo_evento = true;
    }

    if (mes == 9)
    {
        gastos_alquiler *= 1.4;
        gastos_fijos = gastos_alquiler + gastos_servicios + gastos_transporte + gastos_comida;
        cout << "  ** ACTUALIZACION DEL ALQUILER **" << endl;
        cout << "  Ajuste por inflacion acumulada (x 1.4). Nuevo alquiler: $" << gastos_alquiler << endl;
        hubo_evento = true;
    }

    if (!hubo_evento)
    {
        cout << "  Sin eventos fijos programados para este mes." << endl;
    }
    cout << endl;
}

void procesarImprevistos(float &saldo_pesos, float &fondo_emergencia, int &meses_sin_fondo)
{
    string imprevisto_nombre[12] = {
        "Se rompe el lavarropas (Reparacion urgente)",
        "Visita medica inesperada (Consulta + medicamentos)",
        "Multa de transito (Infraccion)",
        "Tecnico de internet (Se corto el servicio)",
        "Regalo de cumpleanios obligado",
        "Rompiste un vidrio del gimnasio (Te toca hacerte cargo)",
        "Cena o salida social ineludible",
        "Se rompe la pantalla del celular (Reparacion urgente)",
        "Sube la expensa del edificio (Ajuste en el edificio)",
        "Mini escapada de ultimo momento",
        "Black Friday - una oferta irresistible",
        "Regalos de fin de anio (Navidad y anio nuevo)"
    };

    float imprevisto_costo[12] = {
        70000, 45000, 30000, 25000, 35000, 55000,
        50000, 80000, 20000, 90000, 60000, 55000
    };

    int   cantidad_imprevistos = 0;
    float total_imprevistos    = 0.0;

    cout << "  [ IMPREVISTOS DEL MES ]" << endl;

    int probabilidades[3] = {70, 15, 10};
    bool seguir_tirando   = true;

    for (int i = 0; i < 3 && seguir_tirando; i++)
    {
        int dado = rand() % 100;
        if (dado < probabilidades[i])
        {
            int idx = rand() % 12;
            cout << "  [!] " << imprevisto_nombre[idx] << " (-$" << imprevisto_costo[idx] << ")" << endl;

            if (idx == 10)
            {
                char comprar;
                cout << "      Es una decision optativa. Compras la oferta? (S/N): ";
                cin  >> comprar;
                cin.ignore();
                if (comprar == 'S' || comprar == 's')
                {
                    total_imprevistos += imprevisto_costo[idx];
                    cantidad_imprevistos++;
                }
                else
                {
                    cout << "      Dejaste pasar la oferta. Gasto evitado!" << endl;
                }
            }
            else
            {
                total_imprevistos += imprevisto_costo[idx];
                cantidad_imprevistos++;
            }
        }
        else
        {
            seguir_tirando = false;
        }
    }

    if (cantidad_imprevistos == 0)
    {
        cout << "  [ok] Sin gastos imprevistos este mes!" << endl;
    }
    else
    {
        cout << "  Total imprevistos a cubrir: -$" << total_imprevistos << endl;

        if (fondo_emergencia >= total_imprevistos)
        {
            fondo_emergencia -= total_imprevistos;
            cout << "  >> Cubierto totalmente con tu fondo de emergencia." << endl;
        }
        else if (fondo_emergencia > 0)
        {
            float resto = total_imprevistos - fondo_emergencia;
            cout << "  >> [ALERTA] Fondo de emergencia insuficiente!" << endl;
            cout << "     Se usaron $" << fondo_emergencia << " del fondo y -$" << resto << " de tu saldo en pesos." << endl;
            fondo_emergencia = 0;
            saldo_pesos -= resto;
        }
        else
        {
            saldo_pesos -= total_imprevistos;
            meses_sin_fondo++;
            cout << "  >> [ALERTA] No tenes fondo de emergencia!" << endl;
            cout << "     Se desconto -$" << total_imprevistos << " directamente de tu saldo en pesos." << endl;
        }
    }
    cout << endl;
}
