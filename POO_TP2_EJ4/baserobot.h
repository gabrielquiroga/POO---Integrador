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
#include "Conjunto.h"
#include "efector_final.h"


#include <iostream>
using namespace std;
#include <string>
#include <sstream>



class baserobot : public Conjunto {
    efector_final *herramienta;
    Conjunto *equipo;

public:
    string get_estado();
    void set_estado(string nuevo_estado);
    string get_IP();
    void set_IP(string nueva_IP);
    string iniciar(int accion, int ciclos, float velocidad);
    string toString();

private:
    string estado;
    string IP;
    
};

#endif /* BASEROBOT_H */

