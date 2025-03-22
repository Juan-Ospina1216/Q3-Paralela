#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>
using namespace std;
#define ROW 5
#define COL 5


int main(){
    int matriz[ROW][COL];
    int vector[COL];
    int resultado[ROW];
    srand(time(0));
    printf("Matriz\n");
    //Generar valores
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            matriz[i][j] = rand()%1000;
            if (i == 0){
                vector[j] = rand()%1000;
            }
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Vector\n");
    for(int i = 0; i < COL; i++){
        printf("%d ", vector[i]);
    }

    printf("\nResultado\n");
    //Calcular multiplicacion
    for(int i = 0; i < ROW; i++){
        int suma = 0;
        for(int j = 0; j < COL; j++){
            suma += matriz[i][j] * vector[j];
        }
        resultado[i] = suma;
        printf("%d ", resultado[i]);
    }
}