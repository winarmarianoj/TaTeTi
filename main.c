/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mariano
 *
 * Created on 17 de septiembre de 2019, 16:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funcionesTateti.h"

int main(int argc, char** argv) {
    char *tateti=NULL;
    if ((tateti=(char*)malloc(sizeof(char*)*9))==NULL){
        printf("No tenes memoria");
        exit(EXIT_FAILURE);
    }
    memset(tateti,'\0',9);
    
    initialize (tateti);
         
    JUGADOR jug1;
    jug1.jugador = 1;
    jug1.tipo = 'X';
    jug1.turno = 1;
    jug1.gano = 0;
    
    JUGADOR jug2;
    jug2.jugador = 2;
    jug2.tipo = 'O';
    jug2.turno = 0;
    jug2.gano = 0;
    
       
    char seguir;
    int i=0;
    char basura;
    
    do{
        
        while (i<9 && !jug1.gano && !jug2.gano){
            
            if (jug1.turno){
                draw(tateti);
                printf("Turno del Jugador %d  con la opción  (%c) \t", jug1.jugador, jug1.tipo);                
                elegir(tateti,jug1);
                jug1.turno=0;
                jug2.turno=1;
                gano(tateti,&jug1);
                system("clear");
            }else{
                draw(tateti);
                printf("Turno del Jugador %d  con la opción  (%c) \t", jug2.jugador, jug2.tipo);                
                elegir(tateti,jug2);
                jug2.turno=0;
                jug1.turno=1;
                gano(tateti,&jug2);
                system("clear");
            }
            i++;
        }
        draw(tateti);
        
        if(jug1.gano){
            printf("\nFelicidades!!! Ganaste el Juego Jugador %d!!!!!\n\n", jug1.jugador);
        }else if (jug2.gano){
            printf("\nFelicidades!!! Ganaste el Juego Jugador %d!!!!!\n", jug2.jugador);
        }else{
            printf("\nNadie Ganor.\n");
        }        
        
        printf("¿Desea jugar una nueva partida?\n");
        scanf(" %c", &seguir);
        basura=getchar();       
        
        jug1.gano=false;
        jug2.gano=false;        
        i=0;
        system("clear");
    }while (seguir=='Y' || seguir=='y');
    
    exit(EXIT_SUCCESS);
}