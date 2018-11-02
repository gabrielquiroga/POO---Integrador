#include "mainwindow.h"
#include <QApplication>

#include <iostream>
using namespace std;
#include <unistd.h>
#include <string>
#include <sstream>


#include "efectorfinal.h"
#include "conjunto.h"
#include "baserobot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    BaseRobot *base;
    base = new BaseRobot;


    char respuesta;
    int accion=0, ciclos, n=0;
    float velocidad;

    cout << "Desea iniciar el equipo? y/n" << endl;
    cin >> respuesta;
    while (accion != 0) {
        n++;
        if (respuesta == 'y') {
            cout << "Seleccione las actividades a realizar" << endl
                    << "1. Pintar" << endl
                    << "2. Sostener" << endl
                    << "3. Soltar" << endl
                    << "4. Rotar" << endl
                    << "5. Cambiar velocidad" << endl
                    << "0. Iniciar el programa" << endl;
            cin >> accion;
            cout << "Ingrese número de ciclos" << endl;
            cin >> ciclos;
            cout << "Ingrese velocidad de giro" << endl;
            cin >> velocidad;
            base->iniciar(accion, ciclos, velocidad);

        }

        else {
            base->set_estado("Inactivo");
            cout << "Estado de la base: " << base->get_estado() << endl;
        }
    }

    return a.exec();
}
