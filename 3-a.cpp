#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define SIZE 5

using namespace std;

void suma(vector<vector<int>> A, vector<vector<int>> B);
void multiplicacion(vector<vector<int>> A, vector<vector<int>> B);
void transpuesta(vector<vector<int>> A);

int main(){
    vector<vector<int>> A(SIZE, vector<int>(SIZE));
    vector<vector<int>> B(SIZE, vector<int>(SIZE));
    srand(time(0));
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }
    cout << "SUMA: " << endl;
    suma(A, B);
    cout << "MULTIPLICACION: " << endl;
    multiplicacion(A, B);
    cout << "TRANSPUESTA: " << endl;
    transpuesta(A);

    return 0;
}

void suma(vector<vector<int>> A, vector<vector<int>> B){
    vector<vector<int>> resultado(SIZE, vector<int>(SIZE));
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            resultado[i][j] = A[i][j] + B[i][j];
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

}

void multiplicacion(vector<vector<int>> A, vector<vector<int>> B){
    vector<vector<int>> resultado(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
}

void transpuesta(vector<vector<int>> A){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }
}