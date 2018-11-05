/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Eslabon.h
 * Author: GABI
 *
 * Created on 2 de noviembre de 2018, 19:38
 */

#ifndef ESLABON_H
#define ESLABON_H

#include "conjunto.h"

class Eslabon : public Conjunto {
public:
    Eslabon();
    Eslabon(const Eslabon& orig);
    virtual ~Eslabon();
    
private:
    float dim_l; //largo
    float dim_h; //alto
    float dim_w; //ancho
    

};

#endif /* ESLABON_H */

