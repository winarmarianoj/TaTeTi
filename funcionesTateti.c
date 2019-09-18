/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funcionesTateti.h"

void initialize (char *t){
    
    for (int i=1; i<=9; i++){
        *t='0'+i;
        t++;
    }
}

void draw (char *t){
    
    printf(" %c | %c | %c \n", *(t+0), *(t+1), *(t+2));
    printf("...........\n");
    printf(" %c | %c | %c \n", *(t+3), *(t+4), *(t+5));
    printf("...........\n");
    printf(" %c | %c | %c \n", *(t+6), *(t+7), *(t+8));
    printf("...........\n");
}

bool revisar (char *t, int n){
    if (n<0){
        return false;
    }
    if (n>9){
        return false;
    }
    if (*(t+n)=='X'){
        return false;
    }
    if (*(t+n)=='O'){
        return false;
    }
    return true;
}

void elegir (char * t, JUGADOR j){
    int n=0;
    char basura;
    printf("\nIndique la posición a jugar:\t");
    scanf(" %d", &n);
    basura=getchar();
    n--;
    system("clear");
    
    /*supervisa si el nro ingresado es correcto 
      y si la posicion fue o no utilizada */
    while (!revisar(t,n)){
        printf("\nNúmero no válido. Pulse otra opción\n");
        scanf(" %d", &n);
        n--;
    }
    
    *(t+n)=j.tipo;    
}

void gano (char * t, JUGADOR * j){
    
    //Verifica posibles ganadores por filas
    if ( (*(t+0)==j->tipo && *(t+1)==j->tipo && *(t+2)==j->tipo) || 
         (*(t+3)==j->tipo && *(t+4)==j->tipo && *(t+5)==j->tipo) || 
         (*(t+6)==j->tipo && *(t+7)==j->tipo && *(t+8)==j->tipo) ){
        j->gano=true;
    }
    //Verifica posibles ganadores por columnas
    if ( (*(t+0)==j->tipo && *(t+3)==j->tipo && *(t+6)==j->tipo) || 
         (*(t+1)==j->tipo && *(t+4)==j->tipo && *(t+7)==j->tipo) || 
         (*(t+2)==j->tipo && *(t+5)==j->tipo && *(t+8)==j->tipo) ){    
        j->gano=true;
    }
    //Verifica posibles ganadores por diagonales
    if ( (*(t+0)==j->tipo && *(t+4)==j->tipo && *(t+8)==j->tipo) ||
         (*(t+6)==j->tipo && *(t+4)==j->tipo && *(t+2)==j->tipo) ){
        j->gano=true;
    }    
}

