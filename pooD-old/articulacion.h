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

#include "Conjunto.h"

class Articulacion : public Conjunto {
public:
    Articulacion();
    Articulacion(const Articulacion& orig);
    virtual ~Articulacion();
    int mover(float movimiento, float vel, int tipo_vinc);
    void set_posicion_relativa(float nueva_posicion); //posicion que va de 0 a 360 para los rotadores y de 0 a 100 para el desplazador
    float get_posicion_relativa();
    void set_velocidad_mov(float nueva_velocidad);
    float get_velocidad_mov();
private:
    float posicion_relativa;
    float coordenadas[3];
    float velocidad_mov;
    float cota_pos[2];
    float cota_vel = 50;
    




};

#endif /* ARTICULACION_H */

