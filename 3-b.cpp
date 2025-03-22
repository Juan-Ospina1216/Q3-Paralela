#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void suma(vector<vector<int>> A, vector<vector<int>> B, int size);
void multiplicacion(vector<vector<int>> A, vector<vector<int>> B, int size);
void transpuesta(vector<vector<int>> A, int size);

int main(int argc, char*argv[]){
    int size = atoi(argv[1]);
    vector<vector<int>> A(size, vector<int>(size));
    vector<vector<int>> B(size, vector<int>(size));
    srand(time(0));
    printf("Matriz A: \n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            A[i][j] = rand() % 100;
            printf("%d ", A[i][j]);
            B[i][j] = rand() % 100;
        }
        printf("\n");
    }
    printf("Matriz B:\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    cout << "SUMA: " << endl;
    suma(A, B, size);
    cout << "MULTIPLICACION: " << endl;
    multiplicacion(A, B, size);
    cout << "TRANSPUESTA: " << endl;
    transpuesta(A, size);

    return 0;
}

void suma(vector<vector<int>> A, vector<vector<int>> B, int size){
    vector<vector<int>> resultado(size, vector<int>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            resultado[i][j] = A[i][j] + B[i][j];
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

}

void multiplicacion(vector<vector<int>> A, vector<vector<int>> B, int size){
    vector<vector<int>> resultado(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
}

void transpuesta(vector<vector<int>> A, int size){
    vector<vector<int>> resultado(size, vector<int>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }
}