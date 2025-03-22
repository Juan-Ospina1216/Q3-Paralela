#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  int row = atoi(argv[1]);
  int col = atoi(argv[2]);

  vector<vector<int>> matriz(row, vector<int>(col));
  vector<int> vec(col);
  vector<int> result(row, 0);

  cout << "Matriz:" << endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      matriz[i][j] = rand() % 100;
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Vector:" << endl;
  for (int i = 0; i < col; i++) {
    vec[i] = rand() % 100;
    cout << vec[i] << " ";
  }
  cout << endl;

  #pragma omp parallel for
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      result[i] += matriz[i][j] * vec[j];
    }
  }
  cout << "\nResultado:" << endl;
  for (int i = 0; i < row; i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}