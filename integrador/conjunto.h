#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
using namespace std;
#include <string>


class Conjunto
{
public:
    Conjunto();
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


#endif // CONJUNTO_H
