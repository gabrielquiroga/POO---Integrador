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


#include "efector_final.h"
#include "Conjunto.h"
#include "baserobot.h"

/*
 * 
 */
int main() {

    baserobot *base;
    base = new baserobot;

    
    char respuesta;
    int accion, ciclos, n;
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
    
    return 0;
}

