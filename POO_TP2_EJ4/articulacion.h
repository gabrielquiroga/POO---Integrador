/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Articulacion.h
 * Author: GABI
 *
 * Created on 2 de noviembre de 2018, 19:57
 */

#ifndef ARTICULACION_H
#define ARTICULACION_H

#include "conjunto.h"

class Articulacion : public Conjunto {
public:
    Articulacion();
    Articulacion(const Articulacion& orig);
    virtual ~Articulacion();
    void mover();
private:
    float coordenadas[3];
    float cotas_pos_x[2];
    float cotas_pos_y[2];
    float cotas_pos_z[2];
    float cotas_vel_x[2];
    float cotas_vel_y[2];
    float cotas_vel_z[2];
    




};

#endif /* ARTICULACION_H */

