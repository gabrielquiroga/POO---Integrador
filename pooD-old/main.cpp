#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include <unistd.h>
#include <string>
#include <sstream>


#include "efectorfinal.h"
#include "Conjunto.h"
#include "baserobot.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    BaseRobot *base;
    base = new BaseRobot;

    //int *datos;
    //datos = base->leer_comando();
    //cout << datos[0] <<endl << datos[1] << endl << datos[2] << endl;
    //delete datos;


//        char respuesta;
//        int accion, ciclos, n=0, i, tipo_vinc, direccion, ans;
//        float velocidad, cantidad, vel_mov;
//        string informe[10];

//        cout << "Desea iniciar el equipo? y/n" << endl;
//        cin >> respuesta;
//        while (accion != 0) {
//            n++;
//            if (respuesta == 'y') {
//                cout << "Seleccione qué desea realizar en este ciclo: " << endl
//                        << "1. Actividad"<< endl
//                        << "2. Movimiento" << endl;
//                cin >> ans;

//                if (ans == 1) {
//                    cout << "Seleccione las actividades a realizar" << endl
//                            << "1. Pintar" << endl
//                            << "2. Sostener" << endl
//                            << "3. Soltar" << endl
//                            << "4. Rotar" << endl
//                            << "5. Cambiar velocidad" << endl
//                            << "0. Iniciar el programa" << endl;
//                    cin >> accion;
//                    if (accion != 0 ) {
//                        if (accion != 5) {
//                        cout << "Ingrese número de ciclos" << endl;
//                        cin >> ciclos;
//                        }
//                        cout << "Ingrese velocidad de giro" << endl;
//                        cin >> velocidad;
//                    }
//                    informe[n] = base->iniciar_actividad(accion, ciclos, velocidad);
//                }
//                else if (ans == 2) {
//                    cout << "Ingrese el vinculo que desea mover:" << endl
//                            << "1. Rotación en plano xy" << endl
//                            << "2. Rotación en plano yz" << endl
//                            << "3. Desplazamiento en eje y" << endl;
//                    cin >> tipo_vinc;
//                    cout << "Ingrese el sentido de movimiento: " << endl
//                            << "1. Derecha u horario" << endl
//                            << "2. Izquierda o antihorario" << endl;
//                    cin >> direccion;
//                    cout << "Ingrese la cantidad del movimiento, en milímetros o grados" << endl;
//                    cin >> cantidad;
//                    cout << "Ingrese la velocidad del movimiento" << endl;
//                    cin >> vel_mov;

//                    informe[n] = base->iniciar_movimiento(tipo_vinc, direccion, cantidad, vel_mov);
//                }
//            }
//            else {
//                base->set_estado("Inactivo");
//                cout << "Estado de la base: " << base->get_estado() << endl;
//            }

//            if (accion != 0) {
//                cout << "Desea agregar otro ciclo? y/n" << endl;
//                cin >> respuesta;
//                if (respuesta == 'n') {
//                    accion = 0;
//                }
//            }
//        }
//        for (i=0; i<=n; i++) {
//            cout << informe[i];
//        }








    return a.exec();
};
