/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conjunto.h
 * Author: gabrielq
 *
 * Created on 30 de septiembre de 2018, 20:46
 */

#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
using namespace std;
#include <string>



class Conjunto {
public:
    string get_tipoPieza(); 
    void set_tipoPieza(string nueva_pieza);
    string get_identificacion();
    void set_identificacion(string nueva_identificacion);
    string get_descripcion();
    void set_descripcion(string nueva_descripcion);
    float get_peso();
    void set_peso(float nuevo_peso);
    
private:
    
    string tipoPieza;
    string identificacion;
    string descripcion;
    float peso;

};

#endif /* CONJUNTO_H */

