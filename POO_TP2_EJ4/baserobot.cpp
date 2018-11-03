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
#include "efectorfinal.h"
#include "conjunto.h"

#include <iostream>
using namespace std;
#include <string>
#include <sstream>



string BaseRobot::get_estado() {
    return this->estado;
}
void BaseRobot::set_estado(string nuevo_estado) {
    this->estado = nuevo_estado;
}

string BaseRobot::get_IP() {
    return this->IP;
}
void BaseRobot::set_IP(string nueva_IP) {
    this->IP = nueva_IP;
}

string BaseRobot::iniciar(int accion, int ciclos, float velocidad) {
    this->set_estado("Activo");
    this->set_peso(100);
    string aux;
        
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
    
    aux = this->toString();  
    
    
    return aux;
}

string BaseRobot::toString() {

    string aux="INFORME DEL CONJUNTO\nEstado: ";   
    stringstream ss1, ss2, ss3, ss4, ss5, ss6;
    ss1 << this->get_estado();
    aux += ss1.str();
    aux += string("\nActividad en progreso: ");
    ss2 << herramienta.get_actividad();
    aux += ss2.str();
    aux += string("\nCiclos realizados: ");
    ss3 << herramienta.get_ciclo_actual();
    aux += ss3.str();
    aux += string("\nCiclos prefijados: ");
    ss4 << herramienta.get_ciclos_prefijados();
    aux += ss4.str();
    aux += string("\nVelocidad de giro: ");
    ss5 << herramienta.get_velocidad_giro();
    aux += ss5.str();
    aux += string("\nPeso del conjunto: ");
    ss6 << equipo.get_peso();
    aux += ss6.str();
    aux += string("\n");
    return aux;
}

