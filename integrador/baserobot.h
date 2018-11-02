#ifndef BASEROBOT_H
#define BASEROBOT_H


#include "conjunto.h"
#include "efectorfinal.h"


#include <iostream>
using namespace std;
#include <string>
#include <sstream>



class BaseRobot : public Conjunto {
    EfectorFinal herramienta;
    Conjunto equipo;

public:
    BaseRobot();
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


#endif // BASEROBOT_H
