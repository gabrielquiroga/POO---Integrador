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
#include <vector>

class Articulacion : public Conjunto {
public:
    Articulacion();
    Articulacion(const Articulacion& orig);
    virtual ~Articulacion();
    int mover(float movimiento, int vel, int tipo_vinc);
    void set_posicion_relativa(float nueva_posicion); //posicion que va de 0 a 360 para los rotadores y de 0 a 100 para el desplazador
    float get_posicion_relativa();
    void set_velocidad_mov(int nueva_velocidad);
    int get_velocidad_mov();
    void set_VEL(double vel);
    vector <double> get_VEL();
    void set_TIME(double time);
    vector <double> get_TIME();
private:
    float posicion_relativa;
    float coordenadas[3];
    int velocidad_mov;
    float cota_pos[2];
    float cota_vel = 50;
    vector <double> VEL;
    vector <double> TIME;
    




};

#endif /* ARTICULACION_H */

