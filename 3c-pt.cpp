#include <iostream>
#include <pthread.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void*sumar(void*arg);
void*mult(void*arg);
void*transpuesta(void*arg);

struct matrices{
  vector<vector<int>>* A;
  vector<vector<int>>* B;
  int size;
};

int main(int argc, char*argv[]){
  int size = atoi(argv[1]);
  vector<vector<int>> a(size, vector<int>(size));
  vector<vector<int>> b(size, vector<int>(size));
  pthread_t hilo_suma, hilo_mult, hilo_transp;
  srand(time(0));
  printf("MATRIZ A:\n");
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      a[i][j] = rand()%100;
      printf("%d ", a[i][j]);
      b[i][j] = rand()%100;
    }
    printf("\n");
  }
  printf("MATRIZ B:\n");
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  matrices datos = {&a, &b, size};
  pthread_create(&hilo_suma, NULL, sumar, &datos);
  pthread_create(&hilo_mult, NULL, mult, &datos);
  pthread_create(&hilo_transp, NULL, transpuesta, &datos);

  pthread_join(hilo_suma, NULL);
  pthread_join(hilo_mult, NULL);
  pthread_join(hilo_transp, NULL);
}

void*sumar(void*arg){
  matrices* dato = (matrices*) arg;
  printf("SUMA:\n");
  for(int i = 0; i < dato->size; i++){
    for(int j = 0; j < dato->size; j++){
        printf("%d ", (*(dato->A))[i][j] + (*(dato->B))[i][j]);
    }
    printf("\n");
  }
  return NULL;
}

void*mult(void*arg){
  matrices* dato = (matrices*) arg;
  printf("MULTIPLICACION:\n");
  for(int i = 0; i < dato->size; i++){
    for(int j = 0; j < dato->size; j++){
      int result = 0;
      for(int k = 0; k < dato->size; k++){
        result += (*(dato->A))[i][k] * (*(dato->B))[i][k];
      }
      printf("%d ", result);
    }
    printf("\n");
  }
  return NULL;
}

void*transpuesta(void*arg){
  matrices* dato = (matrices*) arg;
  printf("TRANSPUESTA:\n");
  for(int i = 0; i < dato->size; i++){
    for(int j = 0; j < dato->size; j++){
      printf("%d ", (*(dato->A))[j][i]);
    }
    printf("\n");
  }
  return NULL;
}