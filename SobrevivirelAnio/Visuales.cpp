#include <iostream>


#include "menu.h"
#include "Interfaz.h"


using namespace std;

void mostrarGlosario()
{
    int opcion_glosario=-1;

    while (opcion_glosario != 0)
    {
    int x=34;
    int y=5;

    limpiarPantalla();
    imprimirEnBloqueColor(x, y, "============================================",10);
    imprimirEnBloqueColor(x, y,"          GLOSARIO FINANCIERO                ",10);
    imprimirEnBloqueColor(x, y, "============================================",10);
    imprimirEnBloqueColor(x, y,"  1.  Inflacion",10);
    imprimirEnBloqueColor(x, y,"  2.  Poder adquisitivo",10);
    imprimirEnBloqueColor(x, y,"  3.  Salario real vs nominal",10);
    imprimirEnBloqueColor(x, y,"  4.  Fondo de emergencia",10);
    imprimirEnBloqueColor(x, y,"  5.  Diversificacion",10);
    imprimirEnBloqueColor(x, y,"  6.  Costo de oportunidad",10);
    imprimirEnBloqueColor(x, y,"  7.  Volatilidad",10);
    imprimirEnBloqueColor(x, y,"  8.  Liquidez",10);
    imprimirEnBloqueColor(x, y,"  9.  Indexacion",10);
    imprimirEnBloqueColor(x, y,"  10. ETF (Exchange-Traded Fund)",10);
    imprimirEnBloqueColor(x, y,"  11. Patrimonio real",10);
    imprimirEnBloqueColor(x, y,"  12. Patrimonio inicial",10);
    imprimirEnBloqueColor(x, y,"  0.  Volver al menu principal",10);
    imprimirEnBloqueColor(x, y,"============================================",10);
    imprimirEnBloqueColor(x, y,"      Opcion:",15);

        opcion_glosario = pedirOpcionEntera();

        if (opcion_glosario != 0)
        {
            mostrarDefinicionGlosario(opcion_glosario);
            pausarPantalla();
            }else if (opcion_glosario == 0){
            return;
            }

        }
    }


void mostrarDefinicionGlosario(int opcion_glosario)
{
    string titulos[12] = {
        "INFLACION",
        "PODER ADQUISITIVO",
        "SALARIO REAL vs SALARIO NOMINAL",
        "FONDO DE EMERGENCIA",
        "DIVERSIFICACION",
        "COSTO DE OPORTUNIDAD",
        "VOLATILIDAD",
        "LIQUIDEZ",
        "INDEXACION",
        "ETF (Exchange-Traded Fund)",
        "PATRIMONIO REAL",
        "PATRIMONIO INICIAL"
    };

    string definiciones[12] = {
        "Aumento generalizado y sostenido de los\n  precios de bienes y servicios. Hace que\n  el dinero valga menos con el tiempo.",
        "Cantidad de bienes y servicios que se\n  pueden comprar con una suma de dinero.\n  Disminuye cuando hay inflacion.",
        "Nominal: el numero en el recibo de sueldo.\n  Real: cuanto se puede comprar con ese dinero.\n  Si la inflacion supera al aumento del sueldo,\n  el salario real cae.",
        "Reserva de dinero liquido disponible para\n  cubrir gastos imprevistos sin necesidad de\n  endeudarse ni vender inversiones a perdida.",
        "Estrategia de distribuir el dinero entre\n  distintos instrumentos para reducir el\n  riesgo total. 'No poner todos los huevos\n  en la misma canasta.'",
        "El valor de la mejor alternativa que se\n  resigna al tomar una decision. Guardar\n  plata en pesos tiene el costo de oportunidad\n  de no invertirla.",
        "Medida de cuanto varia el precio de un\n  activo. Un instrumento muy volatil (como\n  Bitcoin) puede subir o bajar mucho en\n  poco tiempo.",
        "Facilidad con la que un activo se puede\n  convertir en dinero disponible. El efectivo\n  es el mas liquido; los inmuebles, el menos.",
        "Mecanismo por el cual el valor de un\n  contrato (como un alquiler) se ajusta\n  periodicamente segun un indice de precios.",
        "Fondo de inversion que cotiza en bolsa y\n  replica el comportamiento de un indice,\n  como el S&P 500. Permite invertir en muchas\n  empresas a la vez con bajo costo.",
        "Saldo disponible en pesos + Fondo de\n  emergencia + Inversiones (pesificadas),\n  ajustado por la inflacion acumulada.",
        "Dinero con el que se comienza el juego\n  ($150.000 pesos)."
    };

    limpiarPantalla();
    cout << "============================================" << endl;
    if (opcion_glosario >= 1 && opcion_glosario <= 12)
    {
        cout << "  " << titulos[opcion_glosario - 1] << endl;
        cout << "--------------------------------------------" << endl;
        cout << "  " << definiciones[opcion_glosario - 1] << endl;
    }
else if (opcion_glosario != 0) {
    cout << "Opcion invalida." << endl;}
    cout << "============================================" << endl;
}
