#include <omp.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void sumar(vector<vector<int>> A, vector<vector<int>> B, int size);
void mult(vector<vector<int>> A, vector<vector<int>> B, int size);
void transpuesta(vector<vector<int>> A, int size);

int main(int argc, char*argv[]){
  int size = atoi(argv[1]);
  vector<vector<int>> a(size, vector<int>(size));
  vector<vector<int>> b(size, vector<int>(size));
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

  #pragma omp parallel sections
  {
    #pragma omp section
    {sumar(a, b, size);}

    #pragma omp section
    {mult(a, b, size);}

    #pragma omp section
    {transpuesta(a, size);}
  }
  return 0;

}

void sumar(vector<vector<int>> A, vector<vector<int>> B, int size){
  printf("SUMA:\n");
  #pragma omp parallel for
  for(int i = 0; i < size; i++){
    #pragma omp critical
    for(int j = 0; j < size; j++){
        printf("%d ", A[i][j] + B[i][j]);
    }
    printf("\n");
  }
}

void mult(vector<vector<int>> A, vector<vector<int>> B, int size){
  printf("MULTIPLICACION:\n");
  #pragma omp parallel for
  for(int i = 0; i < size; i++){
    #pragma omp critical
    for(int j = 0; j < size; j++){
      int result = 0;
      for(int k = 0; k < size; k++){
        result += A[i][k] * B[i][k];
      }
      printf("%d ", result);
    }
    printf("\n");
  }
}

void transpuesta(vector<vector<int>> A, int size){

  printf("TRANSPUESTA:\n");
  #pragma omp parallel for
  for(int i = 0; i < size; i++){
    #pragma omp critical
    for(int j = 0; j < size; j++){
      printf("%d ", A[j][i]);
    }
    printf("\n");
  }
}