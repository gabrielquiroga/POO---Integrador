#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H

#include "conjunto.h"

#include <string>
using namespace std;

enum {
    NADA, PINTAR, SOSTENER, SOLTAR, ROTAR, CAMBIAR_VELOCIDAD
};

class EfectorFinal : public Conjunto
{
public:
    EfectorFinal();
    void pintar();
    void sostener();
    void soltar();
    void rotar();
    void set_velocidad(float nueva_velocidad);
    float get_velocidad_giro();
    void cambiar_estado(bool nuevo_estado);
    int get_estado();
    string get_actividad();
    void set_ciclo_actual(int nuevo_ciclo_actual);
    int get_ciclo_actual();
    void aumentar_ciclo();
    void set_ciclos_prefijados(int ciclos);
    int get_ciclos_prefijados();

private:
    bool estado;
    int ciclo_actual;
    int ciclos_prefijados;
    float velocidad_giro;
    string actividad;
    float peso;

};


#endif // EFECTORFINAL_H
