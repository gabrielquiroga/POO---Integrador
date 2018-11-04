/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Articulacion.cpp
 * Author: GABI
 * 
 * Created on 2 de noviembre de 2018, 19:57
 */

#include "articulacion.h"

Articulacion::Articulacion() {
}

Articulacion::Articulacion(const Articulacion& orig) {
}

Articulacion::~Articulacion() {
}

void Articulacion::mover(float movimiento, float vel, int tipo_vinc) {
    this->velocidad_mov = vel;
    this->posicion_relativa = this->posicion_relativa + movimiento;
    this->cota_pos[1] = 0;
    if (tipo_vinc == 1 || tipo_vinc == 2) {
        this->cota_pos[2] = 360;
    } else if (tipo_vinc == 3) {
        this->cota_pos[2] = 100;
    }
    //Esto supongo que lo debería hacer con excepciones
    if (this->posicion_relativa < this->cota_pos[1] || this->posicion_relativa > this->cota_pos[2]) {
        cout << "El movimiento excede alguna de las cotas" << endl;
    }
    if (this->velocidad_mov > this->cota_vel) {
        cout << "La velocidad excede la cota" << endl;
    }
}
void Articulacion::set_posicion_relativa(float nueva_posicion) {
    this->posicion_relativa = nueva_posicion;
}
float Articulacion::get_posicion_relativa() {
    return this->posicion_relativa;
}
void Articulacion::set_velocidad_mov(float nueva_velocidad) {
    this->velocidad_mov = nueva_velocidad;
}
float Articulacion::get_velocidad_mov() {
    return this->velocidad_mov;
}
