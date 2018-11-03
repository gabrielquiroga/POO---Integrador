/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   baserobot.h
 * Author: gabrielq
 *
 * Created on 28 de septiembre de 2018, 11:27
 */

#ifndef BASEROBOT_H
#define BASEROBOT_H
#include "conjunto.h"
#include "efectorfinal.h"
#include "articulacion.h"


#include <iostream>
using namespace std;
#include <string>
#include <sstream>



class BaseRobot : public Conjunto {
    EfectorFinal herramienta;
    Conjunto equipo;
    Articulacion vinculo[3];

public:
    string get_estado();
    void set_estado(string nuevo_estado);
    string get_IP();
    void set_IP(string nueva_IP);
    string iniciar_actividad(int accion, int ciclos, float velocidad);
    string toString();
    string iniciar_movimiento(int tipo_vinc, int direccion, float cantidad, float vel_mov);

private:
    string estado;
    string IP;
    
};

#endif /* BASEROBOT_H */

