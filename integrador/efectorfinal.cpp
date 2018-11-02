#include "efectorfinal.h"

#include <iostream>
using namespace std;
#include <string>

EfectorFinal::EfectorFinal()
{

}

void EfectorFinal::pintar() {
    this->set_peso(20);
    this->actividad = "Pintar";
}

void EfectorFinal::sostener() {
    this->set_peso(15);
    this->actividad = "Sostener";
}

void EfectorFinal::soltar() {
    this->set_peso(10);
    this->actividad = "Soltar";
}

void EfectorFinal::rotar() {
    this->set_peso(30);
    this->actividad = "Rotar";
}

void EfectorFinal::set_velocidad(float nueva_velocidad) {
    this->set_peso(5);
    this->actividad = "Cambiar Velocidad";
    velocidad_giro = nueva_velocidad;
}

//Bloque para obtener los datos
int EfectorFinal::get_estado() {
    return this->estado;
}
string EfectorFinal::get_actividad() {
    return this->actividad;
}
int EfectorFinal::get_ciclo_actual() {
    return this->ciclo_actual;
}
int EfectorFinal::get_ciclos_prefijados() {
    return this->ciclos_prefijados;
}
float EfectorFinal::get_velocidad_giro() {
    return this->velocidad_giro;
}


void EfectorFinal::cambiar_estado(bool nuevo_estado) {
    this->estado = nuevo_estado;
}


void EfectorFinal::set_ciclos_prefijados(int ciclos) {
    this->ciclos_prefijados = ciclos;
}

void EfectorFinal::aumentar_ciclo() {
    this->ciclo_actual = ciclo_actual + 1;
}

void EfectorFinal::set_ciclo_actual(int nuevo_ciclo_actual) {
    this->ciclo_actual = nuevo_ciclo_actual;
}


