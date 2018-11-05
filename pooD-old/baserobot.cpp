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
#include "Conjunto.h"

#include <iostream>
using namespace std;
#include <string>
#include <sstream>



string BaseRobot::get_estado() {
    return this->estado;
}
void BaseRobot::set_estado(string nuevo_estado) {
    this->estado = nuevo_estado;
    if (this->estado == "Activo") {
        for (int i=1; i<=3; i++) {
            vinculo[i].set_posicion_relativa(0);
        }
    }
}

string BaseRobot::get_IP() {
    return this->IP;
}
void BaseRobot::set_IP(string nueva_IP) {
    this->IP = nueva_IP;
}

string BaseRobot::iniciar_actividad(int accion, int ciclos, float velocidad) {
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
    this->set_peso(this->get_peso() + herramienta.get_peso());
    herramienta.set_velocidad(velocidad);
    
    aux = this->toString();     
    return aux;
}
string BaseRobot::toString() {

    string aux="INFORME DEL CONJUNTO\nEstado: ";   
    stringstream ss1, ss2, ss3, ss4, ss5, ss6;
    ss1 << this->estado;
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
    ss6 << this->get_peso();
    aux += ss6.str();
    aux += string("\n");
    return aux;
}

string BaseRobot::iniciar_movimiento(int tipo_vinc,/* int direccion,*/ float cantidad, float vel_mov) {
    string aux;
    string err;
    /*
    if (direccion == 2) {
        cantidad = -cantidad;
    }*/
    if (tipo_vinc == 1) {
        vinculo[tipo_vinc].set_tipoPieza("Vínculo de rotación xy");
    }
    else if (tipo_vinc == 2) {
        vinculo[tipo_vinc].set_tipoPieza("Vínculo de rotación yz");
    }
    else if (tipo_vinc == 3) {
        vinculo[tipo_vinc].set_tipoPieza("Vínculo de desplazamiento y");
    }
    if(0==vinculo[tipo_vinc].mover(cantidad, vel_mov, tipo_vinc)){

    aux = this->toString2(tipo_vinc);
    return aux;
    }
    else{
    err="Fuera de los límites";
        return err;
    }
    }
string BaseRobot::toString2(int tipo_vinc) {
    
    string aux="INFORME DEL CONJUNTO\nEstado: ";
    stringstream ss1, ss2, ss3, ss4;
    ss1 << this->estado;
    aux += ss1.str();
    aux += string("\nArticulacion: ");
    ss2 << vinculo[tipo_vinc].get_tipoPieza();
    aux += ss2.str();
    aux += string("\nNueva posición: ");
    ss3 << vinculo[tipo_vinc].get_posicion_relativa();
    aux += ss3.str();
    aux += string("\nVelocidad del movimiento: ");
    ss4 << vinculo[tipo_vinc].get_velocidad_mov();
    aux += ss4.str();
    aux += string("\n");
    return aux;
}

float BaseRobot::get_vel(int tipo_vinc){
    return vinculo[tipo_vinc].get_velocidad_mov();
}
void BaseRobot::set_vel(int tipo_vinc,float vel){
     vinculo[tipo_vinc].set_velocidad_mov(vel);
}
