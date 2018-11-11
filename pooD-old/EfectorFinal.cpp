/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   efector_final.cpp
 * Author: gabrielq
 * 
 * Created on 8 de octubre de 2018, 09:57
 */

#include "efectorfinal.h"


#include <iostream>
using namespace std;
#include <string>


void EfectorFinal::startVideo() {
     time(&t0);
}

void EfectorFinal::stopVideo() {
    time(&tf);
    this->dt=difftime(tf,t0); //para obtener la diferencia en milisegundos, usar gettimeofday()
}

void EfectorFinal::foto() {

}


//Bloque para obtener los datos
int EfectorFinal::get_estado() {
    return this->estado;
}


void EfectorFinal::set_estado(bool nuevo_estado) {
    this->estado = nuevo_estado;
}
int EfectorFinal::get_numero() {
    return this->numero;
}
void EfectorFinal::set_numero(int N) {
     this->numero=N;
}

double EfectorFinal::get_dt() {
    return this->dt;
}
