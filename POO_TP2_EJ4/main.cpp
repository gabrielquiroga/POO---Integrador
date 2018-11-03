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
#include <unistd.h>
#include <string>
#include <sstream>


#include "efectorfinal.h"
#include "conjunto.h"
#include "baserobot.h"

/*
 * 
 */
int main() {

    BaseRobot *base;
    base = new BaseRobot;

    
    char respuesta;
    int accion, ciclos, n=0, i;
    float velocidad;
    string informe, proceso[5];
    
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
            if (accion != 0 ) {
                if (accion != 5) {
                cout << "Ingrese número de ciclos" << endl;
                cin >> ciclos;
                }
                cout << "Ingrese velocidad de giro" << endl;
                cin >> velocidad;
            }
            informe = base->iniciar(accion, ciclos, velocidad);
            proceso[n] = informe;

        }
        else {
            base->set_estado("Inactivo");
            cout << "Estado de la base: " << base->get_estado() << endl;
        }
        
        cout << "Desea agregar otra actividad? y/n" << endl;
        cin >> respuesta;
        if (respuesta == 'n') {
            accion = 0;
        }
    }
    for (i=0; i<=n; i++) {
        cout << proceso[i];
    }
    
    return 0;
}

