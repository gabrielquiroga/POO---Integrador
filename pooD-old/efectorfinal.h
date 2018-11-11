/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   efector_final.h
 * Author: gabrielq
 *
 * Created on 8 de octubre de 2018, 09:57
 */

#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H

#include "Conjunto.h"

#include <string>
#include <time.h>
using namespace std;

enum {
    NADA, PINTAR, SOSTENER, SOLTAR, ROTAR, CAMBIAR_VELOCIDAD
};

class EfectorFinal : public Conjunto {
public:
    void set_estado(bool nuevo_estado);
    int get_estado();
    void startVideo();
    void stopVideo();
    void foto();
    int get_numero();
    void set_numero(int N);
    double get_dt();
private:
    bool estado;
    time_t t0;
    time_t tf;
    double dt;
    int numero;


};

#endif /* EFECTOR_FINAL_H */


