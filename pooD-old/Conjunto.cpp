/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conjunto.cpp
 * Author: gabrielq
 * 
 * Created on 30 de septiembre de 2018, 20:46
 */

#include "conjunto.h"

#include <iostream>
using namespace std;
#include <string>

string Conjunto::get_tipoPieza(){
    return this->tipoPieza;
}
void Conjunto::set_tipoPieza(string nueva_pieza){
    this->tipoPieza = nueva_pieza;
}

string Conjunto::get_identificacion(){
    return this->identificacion;
}
void Conjunto::set_identificacion(string nueva_identificacion){
    this->identificacion = nueva_identificacion;
}

string Conjunto::get_descripcion(){
    return this->descripcion;
}
void Conjunto::set_descripcion(string nueva_descripcion){
    this->descripcion = nueva_descripcion;
}

float Conjunto::get_peso(){
    return this->peso;
}
void Conjunto::set_peso(float nuevo_peso){
    this->peso = nuevo_peso;
}