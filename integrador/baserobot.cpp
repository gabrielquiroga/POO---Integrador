#include "baserobot.h"
#include "efectorfinal.h"
#include "conjunto.h"

#include <iostream>
using namespace std;
#include <string>
#include <sstream>

BaseRobot::BaseRobot()
{

}


string BaseRobot::get_estado() {
    return this->estado;
}
void BaseRobot::set_estado(string nuevo_estado) {
    this->estado = nuevo_estado;
}

string BaseRobot::get_IP() {
    return this->IP;
}
void BaseRobot::set_IP(string nueva_IP) {
    this->IP = nueva_IP;
}

string BaseRobot::iniciar(int accion, int ciclos, float velocidad) {
    this->set_estado("Activo");
    this->set_peso(100);

    if(accion == PINTAR) {
        herramienta.pintar();
    }else if(accion == SOSTENER) {
        herramienta.sostener();
    }else if(accion == SOLTAR) {
        herramienta.soltar();
    }else if(accion == ROTAR) {
        herramienta.rotar();
    }else if(accion == CAMBIAR_VELOCIDAD) {
        herramienta.set_velocidad(velocidad);
    }
    if (accion != CAMBIAR_VELOCIDAD) {
        herramienta.set_ciclos_prefijados(ciclos);
    }
    equipo.set_peso(this->get_peso() + herramienta.get_peso());
    herramienta.set_velocidad(velocidad);



    return 0;
}

string BaseRobot::toString() {
    stringstream ss;
    ss << "Estado: " << this->get_estado() << endl
            << "Actividad en progreso: " << herramienta.get_actividad() << endl
            << "Número de ciclos: " << herramienta.get_ciclo_actual() << endl
            << "Ciclos prefijados: " << herramienta.get_ciclos_prefijados() << endl
            << "Velocidad de giro: " << herramienta.get_velocidad_giro() << endl
            << "Peso del conjunto: " << equipo.get_peso() << endl;
    return ss.str();
}
