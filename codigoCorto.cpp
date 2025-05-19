#include <iostream>
using namespace std;

int main() {
    int edad, tipo_cliente, opcion;
    double saldo = 7.0;
    double precio_original = 0.0;
    double precio_descuento = 0.0;
    int codigo_plato = 0;

    cout << "ingrese su edad: ";
    cin >> edad;

    if (edad < 12) {
        cout << "no puede realizar la compra por ser menor de edad." << endl;
    } else {
        cout << "tipo de cliente:" << endl;
        cout << "1. estudiante" << endl;
        cout << "2. adulto mayor" << endl;
        cout << "3. ver todo" << endl;
        cout << "ingrese una opcion: ";
        cin >> tipo_cliente;

        if (tipo_cliente == 1 || tipo_cliente == 3) {
            cout << "menu estudiante (25% descuento):" << endl;
            cout << "1. combo hamburguesa ($8)" << endl;
            cout << "2. combo pizza personal ($7)" << endl;
            cout << "3. almuerzo ejecutivo ($10)" << endl;
            cout << "seleccione una opcion: ";
            cin >> opcion;

            switch(opcion) {
                case 1:
                    precio_original = 8;
                    codigo_plato = 1;
                    break;
                case 2:
                    precio_original = 7;
                    codigo_plato = 2;
                    break;
                case 3:
                    precio_original = 10;
                    codigo_plato = 3;
                    break;
                default:
                    cout << "opcion invalida" << endl;
                    return 0;
            }

            precio_descuento = precio_original * 0.75;
        }

        if (tipo_cliente == 2 || tipo_cliente == 3) {
            if (tipo_cliente == 2) {
                cout << "menu adulto mayor (30% descuento):" << endl;
            } else {
                cout << "menu adulto mayor (30% descuento): (opcional)" << endl;
            }

            cout << "4. sopa nutritiva ($6)" << endl;
            cout << "5. plato casero ($9)" << endl;
            cout << "6. postre + cafe ($5)" << endl;
            if (tipo_cliente == 2) {
                cout << "seleccione una opcion: ";
                cin >> opcion;
            }

            if (tipo_cliente == 2 || (tipo_cliente == 3 && opcion >= 4)) {
                switch(opcion) {
                    case 4:
                        precio_original = 6;
                        codigo_plato = 4;
                        break;
                    case 5:
                        precio_original = 9;
                        codigo_plato = 5;
                        break;
                    case 6:
                        precio_original = 5;
                        codigo_plato = 6;
                        break;
                    default:
                        cout << "opcion invalida" << endl;
                        return 0;
                }

                precio_descuento = precio_original * 0.70;
            }
        }

        if (precio_descuento > 0) {
            if (precio_descuento > saldo) {
                double falta = precio_descuento - saldo;
                cout << "no tiene suficiente saldo para comprar el plato codigo " << codigo_plato << "." << endl;
                cout << "le faltan $" << falta << endl;
            } else {
                double restante = saldo - precio_descuento;
                cout << "compra realizada con exito!" << endl;
                cout << "codigo del plato: " << codigo_plato << endl;
                cout << "saldo restante: $" << restante << endl;
            }
        } else {
            cout << "no se selecciono ningun plato valido." << endl;
        }
    }

    return 0;
}
