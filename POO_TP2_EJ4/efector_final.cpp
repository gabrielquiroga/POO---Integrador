/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   efector_final.cpp
 * Author: gabrielq
 * 
 * Created on 8 de octubre de 2018, 09:57
 */

#include "efector_final.h"


#include <iostream>
using namespace std;
#include <string>


void efector_final::pintar() {
    this->set_peso(20);
    this->actividad = "Pintar";
}

void efector_final::sostener() {
    this->set_peso(15);
    this->actividad = "Sostener";
}

void efector_final::soltar() {
    this->set_peso(10);
    this->actividad = "Soltar";
}

void efector_final::rotar() {
    this->set_peso(30);
    this->actividad = "Rotar";
}

void efector_final::set_velocidad(float nueva_velocidad) {
    this->set_peso(5);
    this->actividad = "Cambiar Velocidad";
    velocidad_giro = nueva_velocidad;
}


//Bloque para obtener los datos
int efector_final::get_estado() {
    return this->estado;
}
string efector_final::get_actividad() {
    return this->actividad;
}
int efector_final::get_ciclo_actual() {
    return this->ciclo_actual;
}
int efector_final::get_ciclos_prefijados() {
    return this->ciclos_prefijados;
}
float efector_final::get_velocidad_giro() {
    return this->velocidad_giro;
}


void efector_final::cambiar_estado(bool nuevo_estado) {
    this->estado = nuevo_estado;
}


void efector_final::set_ciclos_prefijados(int ciclos) {
    this->ciclos_prefijados = ciclos;
}

void efector_final::aumentar_ciclo() {
    this->ciclo_actual = ciclo_actual + 1;
}

void efector_final::set_ciclo_actual(int nuevo_ciclo_actual) {
    this->ciclo_actual = nuevo_ciclo_actual;
}
