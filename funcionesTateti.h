/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionesTateti.h
 * Author: mariano
 *
 * Created on 18 de septiembre de 2019, 13:04
 */

#ifndef FUNCIONESTATETI_H
#define FUNCIONESTATETI_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct{
        int jugador;
        char tipo;
        int turno;
        bool gano;
    }JUGADOR;

    void initialize (char *t);
    void draw (char *t);
    bool revisar (char *t, int n);
    void elegir (char * t, JUGADOR j);
    void gano (char * t, JUGADOR * j);


#ifdef __cplusplus
}
#endif

#endif /* FUNCIONESTATETI_H */

