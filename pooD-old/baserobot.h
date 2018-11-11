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
#include "efectorfinal.h"
#include "articulacion.h"


#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>



class BaseRobot : public Conjunto {
    EfectorFinal camara;
    Articulacion vinculo[3];
    fstream archivo;

public:
    string get_estado();
    void set_estado(string nuevo_estado);
    string get_IP();
    void set_IP(string nueva_IP);
    string iniciar_actividad(int accion, int ciclos, float velocidad);
    string toString();
    string iniciar_movimiento(int tipo_vinc,/* int direccion,*/ int cantidad, int vel_mov);
    string toString2(int tipo_vinc);
    void set_vel(int tipo_vinc,int vel);
    int get_vel(int tipo_vinc);
    void leer_comando();
    int get_tam_archivo();
    void guardar_archivo(int pos1, int pos2, int pos3, int vel1, int vel2, int vel3);
    void borrar_historial();
    vector <string> get_datos();
    void set_datos(int tam);
    string foto();
    void setN(int N);
    string video(bool on_off);
    bool get_rec();
    void set_rec(bool rec);
    vector<double> get_VEL();
    vector<double> get_TIME();
private:
    string estado;
    string IP;
    vector <string> datos;    //comandos en archivo de texto
    bool rec=0;
};

#endif /* BASEROBOT_H */

