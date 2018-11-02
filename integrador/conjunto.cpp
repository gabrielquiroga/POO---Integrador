#include "conjunto.h"

#include <iostream>
using namespace std;
#include <string>


Conjunto::Conjunto()
{

}

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
