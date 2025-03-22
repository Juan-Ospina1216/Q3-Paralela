#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char*argv[]){
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    vector<vector<int>> matriz(row, vector<int>(col));
    vector<int> vec(col);
    vector<int> resultado(row);
    srand(time(0));
    printf("Matriz\n");
    //Generar valores
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matriz[i][j] = rand()%1000;
            if (i == 0){
                vec[j] = rand()%1000;
            }
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Vector\n");
    for(int i = 0; i < col; i++){
        printf("%d ", vec[i]);
    }

    printf("\nResultado\n");
    //Calcular multiplicacion
    for(int i = 0; i < row; i++){
        int suma = 0;
        for(int j = 0; j < col; j++){
            suma += matriz[i][j] * vec[j];
        }
        resultado[i] = suma;
        printf("%d ", resultado[i]);
    }
}