#include "hotplateb.h"
#include <iomanip>
using namespace std;

void initialize(float arr[MAXROW][MAXCOL], int row, int col){
  int a = (rand()%1000)/100.0;
  int b = (rand()%1000)/100.0;
  int c = (rand()%1000)/100.0;
  int d = (rand()%1000)/100.0;
  int e = (rand()%1000)/100.0;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      if (i == 0 || j == 0 || j == (col - 1)){
        arr[i][j] = a;
      } else if (i == (row - 1)){
        arr[i][j] = b;
      } else if (i == (row/4) && j < (col/3)){
        arr[i][j] = c;
      } else if (i == (row/2) && j == (col/2)){
        arr[i][j] = d;
      } else {
        arr[i][j] = e;
      }
    }
  }
}

/*
 *     @param arr2
 *         @param arr1
 *         */

void new_values(float arr2[][MAXCOL], float arr1[][MAXCOL], int row, int col){
  for(int i = 0; i < row; i++){
    //cout << "i " << i << "     lim " << MAXROW << endl;
    for(int j = 0; j < col; j++){
      //cout << "j " << i << "     lim " << MAXCOL << endl;
      if (i == 0 || j == 0 || i == (row - 1) || (i == (row/4) && j < (col/3)) || (i == (row/2) && j == (col/2))){
        // Skip
      } else {
        arr2[i][j] = ((arr1[i][j+1] + arr1[i][j-1] + arr1[i-1][j] + arr1[i+1][j]) + (4.0*(arr1[i][j])))/ 8.0;
        //cout << "arr[" << i <<"][" << j <<"] = " << arr2[i][j] << endl;
      }
    }
}
}

int check_convergence(float arr[][MAXCOL], int row, int col){
    float convergence;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (i == 0 || j == 0 || i == (row - 1) || (i == (row/4) && j < (col/3)) || (i == (row/2) && j == (col/2))){
            // Skip
            } else {
                convergence = arr[i][j] - ((arr[i][j-1] + arr[i][j+1] + arr[i+1][j] + arr[i-1][j]) / 4.0);
            if (fabs(convergence) > 0.1){
                return 1; // status
            }
            }
        }
    }
    return 0; // status
}
/*
Step
*/
double step(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return ((double) tp.tv_sec + (double) tp.tv_usec * 1e-6);
}

int main(int argc, char*argv[]){
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    float arr1[row][col];
    float arr2[row][col];
    srand(time(0));
    initialize(arr1, row, col);
    initialize(arr2, row, col);
    int it = 0;
    const int MAX_IT = 1000;
    int maxHeat = 30;
    int hotCells;
    double start_time = step();


    while(check_convergence(arr1, row, col) && it < MAX_IT){
  
  
      /*
        cout << "MATRIZ "<<it << endl;
        for(int i = 0; i < MAXROW; i++){
          for(int j = 0; j < MAXCOL; j++){
            cout << setprecision(2) << arr1[i][j] << " ";
          }
          cout << endl;
        }
        cout << endl;
      */
        hotCells = 0;
        new_values(arr2, arr1, row, col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                arr1[i][j] = arr2[i][j];
                if(arr1[i][j] >= maxHeat) hotCells++;
            }
        }
        it++;
    }
    /*
     * cout << "MATRIZ FINAL" << endl;
     * for(int i = 0; i < MAXROW; i++){
     *   for(int j = 0; j < MAXCOL; j++){
     *     cout << setprecision(2) << arr1[i][j] << " ";
     *   }
     *   cout << endl;
     * }
     * */
    double end_time = step();
    cout << "Número de celdas con temp mayor a " << maxHeat << "°: " <<hotCells << "/" << col*row<<endl << endl;
    cout << "Tiempo de ejecucion: " << end_time - start_time << "s" << endl;
    return 0;
}