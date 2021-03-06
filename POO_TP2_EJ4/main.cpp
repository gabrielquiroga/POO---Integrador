/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabrielq
 *
 * Created on 24 de septiembre de 2018, 14:08
 */
#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <fstream>
#include <stdlib.h>

#include "efectorfinal.h"
#include "conjunto.h"
#include "baserobot.h"

/*
 * 
 */
int main() {

    BaseRobot *base;
    base = new BaseRobot;
    
    fstream archivo("registro.txt");    
    if(!archivo.is_open()) {
        archivo.open("registro.txt", ios::out);
    }
    archivo << "Comandos ingresados, separados por un espacio:\n";
    
    char respuesta;
    int accion=1, ciclos, n=0, i, tipo_vinc, direccion, ans;
    float velocidad, cantidad, vel_mov;
    //string informe[10];
    list <string> informe;
    list <string>::iterator iter;
    
    cout << "Desea iniciar el equipo? y/n" << endl;
    cin >> respuesta;
    archivo << " " << respuesta;
    while (accion != 0) {
        n++;
        if (respuesta == 'y') {
            cout << "Seleccione qué desea realizar en este ciclo: " << endl
                    << "1. Actividad"<< endl
                    << "2. Movimiento" << endl;
            cin >> ans;
            archivo << " " << ans;
            
            if (ans == 1) {
                cout << "Seleccione las actividades a realizar" << endl
                        << "1. Pintar" << endl
                        << "2. Sostener" << endl
                        << "3. Soltar" << endl
                        << "4. Rotar" << endl
                        << "5. Cambiar velocidad" << endl
                        << "0. Iniciar el programa" << endl;
                cin >> accion;
                archivo << " " << accion;
                if (accion != 0 ) {
                    if (accion != 5) {
                    cout << "Ingrese número de ciclos" << endl;
                    cin >> ciclos;
                    archivo << " " << ciclos;
                    }
                    cout << "Ingrese velocidad de giro" << endl;
                    cin >> velocidad;
                    archivo << " " << velocidad;
                }
                informe.insert(informe.end(), base->iniciar_actividad(accion, ciclos, velocidad));
            }
            else if (ans == 2) {
                cout << "Ingrese el vinculo que desea mover:" << endl
                        << "1. Rotación en plano xy" << endl
                        << "2. Rotación en plano yz" << endl
                        << "3. Desplazamiento en eje y" << endl;
                cin >> tipo_vinc;
                archivo << " " << tipo_vinc;
                cout << "Ingrese el sentido de movimiento: " << endl
                        << "1. Derecha u horario" << endl
                        << "2. Izquierda o antihorario" << endl;
                cin >> direccion;
                archivo << " " << direccion;
                cout << "Ingrese la cantidad del movimiento, en milímetros o grados" << endl;
                cin >> cantidad;
                archivo << " " << cantidad;
                cout << "Ingrese la velocidad del movimiento" << endl;
                cin >> vel_mov;
                archivo << " " << vel_mov;
                
                informe.insert(informe.end(), base->iniciar_movimiento(tipo_vinc, direccion, cantidad, vel_mov));
            }
        }
        else {
            base->set_estado("Inactivo");
            cout << "Estado de la base: " << base->get_estado() << endl;
        }
        
        if (accion != 0) {
            cout << "Desea agregar otro ciclo? y/n" << endl;
            cin >> respuesta;
            archivo << " " << respuesta;
            if (respuesta == 'n') {
                accion = 0;
            }
        }
    }
    /*for (i=0; i<=n; i++) {
        cout << informe[i];
    }*/
    for (i=1;i<=n;i++) {
        cout << informe.front() << endl;
        informe.pop_front();
    }
    
    archivo.close();
    return 0;
}

