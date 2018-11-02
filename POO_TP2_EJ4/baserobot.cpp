/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   baserobot.cpp
 * Author: gabrielq
 * 
 * Created on 28 de septiembre de 2018, 11:27
 */

#include "baserobot.h"
#include "efector_final.h"
#include "Conjunto.h"

#include <iostream>
using namespace std;
#include <string>
#include <sstream>



string baserobot::get_estado() {
    return this->estado;
}
void baserobot::set_estado(string nuevo_estado) {
    this->estado = nuevo_estado;
}

string baserobot::get_IP() {
    return this->IP;
}
void baserobot::set_IP(string nueva_IP) {
    this->IP = nueva_IP;
}

string baserobot::iniciar(int accion, int ciclos, float velocidad) {
    this->set_estado("Activo");
    this->set_peso(100);
        
    if(accion == PINTAR) {
        herramienta.pintar();
    }else if(accion == SOSTENER) {
        herramienta.sostener();
    }else if(accion == SOLTAR) {
        herramienta.soltar();
    }else if(accion == ROTAR) {
        herramienta.rotar();
    }else if(accion == CAMBIAR_VELOCIDAD) {
        herramienta.set_velocidad(velocidad);
    }
    if (accion != CAMBIAR_VELOCIDAD) {
        herramienta.set_ciclos_prefijados(ciclos);
    }
    equipo.set_peso(this->get_peso() + herramienta.get_peso());
    herramienta.set_velocidad(velocidad);
    
    
    
    return 0;
}

string baserobot::toString() {
    stringstream ss;
    ss << "Estado: " << this->get_estado() << endl 
            << "Actividad en progreso: " << herramienta.get_actividad() << endl
            << "Número de ciclos: " << herramienta.get_ciclo_actual() << endl
            << "Ciclos prefijados: " << herramienta.get_ciclos_prefijados() << endl
            << "Velocidad de giro: " << herramienta.get_velocidad_giro() << endl
            << "Peso del conjunto: " << equipo.get_peso() << endl;
    return ss.str();
}

