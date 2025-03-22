#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <pthread.h>

using namespace std;

struct datos{
  const vector<int>* matriz;
  const vector<int>* vec;
  vector<int>* result;
  int id;
  int row;
  int col;
};

void* multiplicar_fila(void* arg);

int main(int argc, char* argv[]){
  int row = atoi(argv[1]);
  int col = atoi(argv[2]);

  vector<pthread_t> hilos(row);
  vector<vector<int>> matriz(row, vector<int>(col));
  vector<int> vec(col);
  vector<int> result(row);
  vector<datos> datos_hilos(row);

  printf("Matriz:\n");
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      matriz[i][j] = rand() % 100;
      if(i == 0){
        vec[j] = rand() % 100;
      }
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  } 
  printf("Vector:\n");
  for(int i = 0; i < col; i++){
    printf("%d ", vec[i]);
  }
  printf("\n");

  for(int i = 0; i < row; i++){
    datos_hilos[i] = {&matriz[i], &vec, &result, i, row, col};
    pthread_create(&hilos[i], NULL, multiplicar_fila, &datos_hilos[i]);
  }

  for(int i = 0; i < row; i++){
    pthread_join(hilos[i], NULL);
  }

  printf("\nResultado:\n");
  for(int j = 0; j < row; j++){
    printf("%d ", result[j]);
  }
  printf("\n");
  return 0;
}

void* multiplicar_fila(void* arg){
  datos* dato = (datos*) arg;
  int suma = 0;

  for(int i = 0; i < dato->col; i++){
    suma += (*(dato->matriz))[i] * (*(dato->vec))[i];
  }
  (*(dato->result))[dato->id] = suma;

  return NULL;
}