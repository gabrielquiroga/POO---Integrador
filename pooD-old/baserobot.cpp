/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   baserobot.cpp
 * Author: gabrielq
 * 
 * Created on 28 de septiembre de 2018, 11:27
 */

#include "baserobot.h"
#include "efectorfinal.h"
#include "Conjunto.h"

#include <iostream>
using namespace std;
#include <string>
#include <sstream>

//----------------------------GET/SET-------------------------------------------


int BaseRobot::get_vel(int tipo_vinc){
    return vinculo[tipo_vinc].get_velocidad_mov();
}
void BaseRobot::set_vel(int tipo_vinc,int vel){
     vinculo[tipo_vinc].set_velocidad_mov(vel);
}

string BaseRobot::get_estado() {
    return this->estado;
}
void BaseRobot::set_estado(string nuevo_estado) {
    this->estado = nuevo_estado;
    if (this->estado == "Activo") {
        for (int i=1; i<=3; i++) {
            vinculo[i].set_posicion_relativa(0);
        }
    }
}

string BaseRobot::get_IP() {
    return this->IP;
}
void BaseRobot::set_IP(string nueva_IP) {
    this->IP = nueva_IP;
}

//-----------------------------------INICIAR_MOVIMIENTO-------------------------------------------

string BaseRobot::iniciar_movimiento(int tipo_vinc,/* int direccion,*/ int cantidad, int vel_mov) {
    string aux;
    string err;
    /*
    if (direccion == 2) {
        cantidad = -cantidad;
    }*/
    if (tipo_vinc == 0) {
        vinculo[tipo_vinc].set_tipoPieza("Vínculo de rotación xy");
    }
    else if (tipo_vinc == 1) {
        vinculo[tipo_vinc].set_tipoPieza("Vínculo de rotación yz");
    }
    else if (tipo_vinc == 2) {
        vinculo[tipo_vinc].set_tipoPieza("Vínculo de desplazamiento y");
    }
    if(0==vinculo[tipo_vinc].mover(cantidad, vel_mov, tipo_vinc)){

    aux = this->toString2(tipo_vinc);
    if (vel_mov != 0) {
    vinculo[tipo_vinc].set_VEL(vel_mov);
    vinculo[tipo_vinc].set_TIME(cantidad/((double)(vel_mov)));

    }
    return aux;

    }
    else{
    err="Fuera de los límites";
        return err;
    }


}
string BaseRobot::toString2(int tipo_vinc) {
    
    string aux="INFORME DEL CONJUNTO\nEstado: ";
    stringstream ss1, ss2, ss3, ss4;
    ss1 << this->estado;
    aux += ss1.str();
    aux += string("\nArticulacion: ");
    ss2 << vinculo[tipo_vinc].get_tipoPieza();
    aux += ss2.str();
    aux += string("\nNueva posición: ");
    ss3 << vinculo[tipo_vinc].get_posicion_relativa();
    aux += ss3.str();
    aux += string("\nVelocidad del movimiento: ");
    ss4 << vinculo[tipo_vinc].get_velocidad_mov();
    aux += ss4.str();
    aux += string("\n");
    return aux;
}

//---------------------------------FOTO-----------------------------------
string BaseRobot::foto(){
    camara.foto();
    string aux=string("Se tomaron ");
    stringstream ss1, ss2;
    ss1 << to_string(camara.get_numero());
    aux += ss1.str();
    ss2 << string(" fotos.");
    aux += ss2.str();

    return aux;
}

void BaseRobot::setN(int N){
    camara.set_numero(N);
}

//------------------------------------VIDEO---------------------------------------
string BaseRobot::video(bool on_off){
    if (on_off){
        camara.startVideo();
    return "Grabando";
    }
    else{
        camara.stopVideo();
        string aux=string("Se grabaron ");
        stringstream ss1, ss2;
        ss1 << to_string(camara.get_dt());
        aux += ss1.str();
        ss2 << string(" segundos.");
        aux += ss2.str();

        return aux;
    }
}


//------------------------CARGAR_DATOS_DEL_ARCHIVO_EN_LA_BASE-------------------

void BaseRobot::leer_comando(){

    archivo.open("comandos.txt", ios::in);
    if (archivo.is_open()){
        string linea;
        while (getline(archivo, linea)) {
            this->datos.push_back(linea);
        }
    }
    else {
        cout << "No se encontró el archivo..." << endl;
    }
    archivo.close();
}

//------------------GET/SET_DEL_VECTOR_DATOS-------------------------------------

vector <string> BaseRobot::get_datos(){
        return this->datos;
}

void BaseRobot::set_datos(int tam){
    int i;
    for (i=0;i<tam-3;i++){
        //this->datos[i] = this->datos[i+3];
    }
}
//-----------------CANTIDAD_DE_LINEAS_DEL_ARCHIVO--------------------------

int BaseRobot::get_tam_archivo() {
    int tam=1;
    archivo.open("comandos.txt", ios::in);
    while (!archivo.eof()) {
        if (archivo.get() == '\n') {
            tam++;
        }
    }
    archivo.close();
    return tam;
}

//--------------------------------GUARDAR_ACCIONES_EN_UN_TXT---------------------------------

void BaseRobot::guardar_archivo(int pos1, int pos2, int pos3, int vel1, int vel2, int vel3) {
    archivo.open("historial.txt", ios::app); //app es para añadir texto al final del archivo
    if (archivo.is_open()) {
        string texto;
        archivo << "0 " << pos1 << " " << vel1 << "\n"
                << "1 " << pos2 << " " << vel2 << "\n"
                << "2 " << pos3 << " " << vel3 << "\n";
    }
    else {
        cout << "No se encontró el archivo..." << endl;
    }
    archivo.close();
}

void BaseRobot::borrar_historial() {
    archivo.open("historial.txt", ios::out);
    archivo << "";
    archivo.close();
}

bool BaseRobot::get_rec(){
    return this->rec;
}
void BaseRobot::set_rec(bool rec){
    this->rec = rec;
}

vector<double> BaseRobot::get_VEL() {
    return vinculo[0].get_VEL();
}
vector<double> BaseRobot::get_TIME() {
    return vinculo[0].get_TIME();
}
















