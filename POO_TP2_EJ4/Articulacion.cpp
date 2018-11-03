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

void Articulacion::mover(float movimiento, float vel) {
    this->velocidad_mov = vel;
    
    
}

