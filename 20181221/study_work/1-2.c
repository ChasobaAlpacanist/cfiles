#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Constants
#define DIMENSION2 2
#define DIMENSION3 3

//2DELEMENTS R -> Row, C -> Column
#define D2R1 0
#define D2R2 1
#define D2C1 0
#define D2C2 1

//3DELEMENTS
#define D3R1 0
#define D3R2 1
#define D3R3 2
#define D3C1 0
#define D3C2 1
#define D3C3 2

//Task
#define SUM 1
#define PRODUCT 2
#define TRANSPOSE 3
#define INVERSE 4

//Prototypes
int **init_matrix(int matrix_size);
double **init_matrix_double(int matrix_size);
void input_matrix(int **matrix, int matrix_size);
void print_matrix(int **matrix, int matrix_size);
void print_matrix_double(double **matrix, int matrix_size);
int det(int **matrix, int matrix_size);

int **matrix_sum(int **dt1, int **dt2, int matrix_size);
int **matrix_pro(int **dt1, int **dt2, int matrix_size);
int **matrix_trans(int **dt1, int matrix_size);
double **matrix_inv(int **dt1, int matrix_size);

void free_all(int **matrix, int matrix_size);
void free_all_double(double **matrix, int matrix_size);

int main(void){
  int task = 0;
  int matrix_size = 0;
  int **dt1 = NULL;
  int **dt2 = NULL;
  int **dt3 = NULL;
  double **dt4 = NULL;

  printf("Choose your task from here.\n");
  printf("Calculate the sum of two matrices -> 1\n");
  printf("Calculate the product of two matrices -> 2\n");
  printf("Calculate the transpose matrix -> 3\n");
  printf("Calculate the inverse matrix -> 4\n");
  scanf("%d", &task);
  assert(SUM <= task && task <= INVERSE);

  switch(task){
    case SUM:
      printf("Input matrix size:");
      scanf("%d", &matrix_size);

      dt1 = init_matrix(matrix_size);
      dt2 = init_matrix(matrix_size);

      printf("dt1:\n");
      input_matrix(dt1, matrix_size);
      printf("dt2:\n");
      input_matrix(dt2, matrix_size);

      dt3 = matrix_sum(dt1, dt2, matrix_size);

      printf("dt1 is\n");
      print_matrix(dt1, matrix_size);
      printf("dt2 is\n");
      print_matrix(dt2, matrix_size);
      printf("The sum of dt1 and dt2 is\n");
      print_matrix(dt3, matrix_size);

      free_all(dt1, matrix_size);
      free_all(dt2, matrix_size);
      free_all(dt3, matrix_size);
      break;
    case PRODUCT:
      printf("Input matrix size:");
      scanf("%d", &matrix_size);

      dt1 = init_matrix(matrix_size);
      dt2 = init_matrix(matrix_size);

      printf("dt1:\n");
      input_matrix(dt1, matrix_size);
      printf("dt2:\n");
      input_matrix(dt2, matrix_size);

      dt3 = matrix_pro(dt1, dt2, matrix_size);

      printf("dt1 is\n");
      print_matrix(dt1, matrix_size);
      printf("dt2 is\n");
      print_matrix(dt2, matrix_size);
      printf("The product of dt1 and dt2 is\n");
      print_matrix(dt3, matrix_size);

      free_all(dt1, matrix_size);
      free_all(dt2, matrix_size);
      free_all(dt3, matrix_size);
      break;
    case TRANSPOSE:
      printf("Input matrix size:");
      scanf("%d", &matrix_size);

      dt1 = init_matrix(matrix_size);

      printf("dt1:\n");
      input_matrix(dt1, matrix_size);

      dt2 = matrix_trans(dt1, matrix_size);

      printf("dt1 is\n");
      print_matrix(dt1, matrix_size);
      printf("The transpose matrix of dt1 is\n");
      print_matrix(dt2, matrix_size);

      free_all(dt1, matrix_size);
      free_all(dt2, matrix_size);
      break;
    case INVERSE:
      printf("Input matrix size(2 or 3):");
      scanf("%d", &matrix_size);
      assert(matrix_size == DIMENSION2 || matrix_size == DIMENSION3);

      dt1 = init_matrix(matrix_size);

      printf("dt1:\n");
      input_matrix(dt1, matrix_size);

      dt4 = matrix_inv(dt1, matrix_size);

      printf("dt1 is\n");
      print_matrix(dt1, matrix_size);
      printf("The inverse matrix of dt1 is\n");
      print_matrix_double(dt4, matrix_size);

      free_all(dt1, matrix_size);
      free_all_double(dt4, matrix_size);
      break;
  }
  return 0;
}

int **init_matrix(int matrix_size){ //初期化
  int **matrix = NULL;
  matrix = (int **)calloc(matrix_size, sizeof(int *));
  for(int i = 0; i < matrix_size * matrix_size; i++){
    matrix[i] = (int *)calloc(matrix_size, sizeof(int));
  }

  for(int i = 0; i < matrix_size; i++){
    for(int j = 0; j < matrix_size; j++){
      matrix[i][j] = 0;
    }
  }
  return  matrix;
}
double **init_matrix_double(int matrix_size){
  double **matrix = NULL;
  matrix = (double **)calloc(matrix_size, sizeof(double *));

  for(int i = 0; i < matrix_size * matrix_size; i++){
    matrix[i] = (double *)calloc(matrix_size, sizeof(double));
  }

  for(int i = 0; i < matrix_size; i++){
    for(int j = 0; j < matrix_size; j++){
      matrix[i][j] = 0;
    }
  }
  return  matrix;
}
void input_matrix(int **matrix, int matrix_size){ //入力
  for(int i = 0; i < matrix_size; i++){
    for(int j = 0; j < matrix_size; j++){
      printf("Input integer into the %d,%d element:", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  }
}
void print_matrix(int **matrix, int matrix_size){ //表示
  for(int i = 0; i < matrix_size; i++){
    for(int j = 0; j < matrix_size; j++){
      printf("%d　", matrix[i][j]);
    }
    printf("\n");
  }
}
void print_matrix_double(double **matrix, int matrix_size){
  for(int i = 0; i < matrix_size; i++){
    for(int j = 0; j < matrix_size; j++){
      printf("%.4lf　", matrix[i][j]);
    }
    printf("\n");
  }
}
int det(int **matrix, int matrix_size){
  if(matrix_size == DIMENSION2){
    int detplus = matrix[D2R1][D2C1] * matrix[D2R2][D2C2];

    int detminus = matrix[D2R1][D2C2] * matrix[D2R2][D2C1];
    return detplus - detminus;
  } else {
    int detplus = ((matrix[D3R1][D3C1] * matrix[D3R2][D3C2] * matrix[D3R3][D3C3]) +
                  (matrix[D3R1][D3C2] * matrix[D3R2][D3C3] * matrix[D3R3][D3C1]) +
                  (matrix[D3R2][D3C1] * matrix[D3R3][D3C2] * matrix[D3R1][D3C3]));

    int detminus = ((matrix[D3R1][D3C1] * matrix[D3R2][D3C3] * matrix[D3R3][D3C2]) +
                   (matrix[D3R1][D3C2] * matrix[D3R2][D3C1] * matrix[D3R3][D3C3]) +
                   (matrix[D3R1][D3C3] * matrix[D3R2][D3C2] * matrix[D3R3][D3C1]));

    return detplus - detminus;
  }
}

int **matrix_sum(int **dt1, int **dt2, int matrix_size){
  int **dt3 = NULL;
  dt3 = init_matrix(matrix_size);

  for(int i = 0; i < matrix_size; i++){ //calculate
    for(int j = 0; j < matrix_size; j++){
      dt3[i][j] = dt1[i][j] + dt2[i][j];
    }
  }
  return dt3;
}
int **matrix_pro(int **dt1, int **dt2, int matrix_size){
  int **dt3 = NULL;
  dt3 = init_matrix(matrix_size);

  for(int row = 0; row < matrix_size; row++){ //calculate
    for(int col = 0; col < matrix_size; col++){
      for(int k = 0; k < matrix_size; k++){
        dt3[row][col] += (dt1[row][k] * dt2[k][col]);
      }
    }
  }
  return dt3;
}
int **matrix_trans(int **dt1, int matrix_size){
  int **dt2 = NULL;

  dt2 = init_matrix(matrix_size);
  for(int i = 0; i < matrix_size; i++){
    for(int j = 0; j < matrix_size; j++){
      dt2[i][j] = dt1[j][i];
    }
  }
  return dt2;
}
double **matrix_inv(int **dt1, int matrix_size){
  assert(matrix_size == DIMENSION2 || matrix_size == DIMENSION3);

  int det_matrix = det(dt1, matrix_size);
  assert(det_matrix != 0);

  double **dt2 = NULL;

  dt2 = init_matrix_double(matrix_size);

  if(matrix_size == DIMENSION2){ //calculate
    dt2[D2R1][D2C1] = (double)dt1[D2R2][D2C2] / det_matrix;
    dt2[D2R1][D2C2] = (double)(-1 * dt1[D2R1][D2C2]) / det_matrix;
    dt2[D2R2][D2C1] = (double)(-1 * dt1[D2R2][D2C1]) / det_matrix;
    dt2[D2R2][D2C2] = (double)dt1[D2R1][D2C1] / det_matrix;
  } else { //3Dmatrix
    dt2[D3R1][D3C1] = (double)(dt1[D3R2][D3C2] * dt1[D3R3][D3C3] - dt1[D3R2][D3C3] * dt1[D3R3][D3C2]) / det_matrix;
    dt2[D3R2][D3C1] = (double)(-1 * (dt1[D3R2][D3C1] * dt1[D3R3][D3C3] - dt1[D3R2][D3C3] * dt1[D3R3][D3C1])) / det_matrix;
    dt2[D3R3][D3C1] = (double)(dt1[D3R2][D3C1] * dt1[D3R3][D3C2] - dt1[D3R2][D3C2] * dt1[D3R3][D3C1]) / det_matrix;
    dt2[D3R1][D3C2] = (double)(-1 * (dt1[D3R1][D3C2] * dt1[D3R3][D3C3] - dt1[D3R1][D3C3] * dt1[D3R3][D3C2])) / det_matrix;
    dt2[D3R2][D3C2] = (double)(dt1[D3R1][D3C1] * dt1[D3R3][D3C3] - dt1[D3R1][D3C3] * dt1[D3R3][D3C1]) / det_matrix;
    dt2[D3R3][D3C2] = (double)(-1 * (dt1[D3R1][D3C1] * dt1[D3R3][D3C2] - dt1[D3R1][D3C2] * dt1[D3R3][D3C1])) / det_matrix;
    dt2[D3R1][D3C3] = (double)(dt1[D3R1][D3C2] * dt1[D3R2][D3C3] - dt1[D3R1][D3C3] * dt1[D3R2][D3C2]) / det_matrix;
    dt2[D3R2][D3C3] = (double)(-1 * (dt1[D3R1][D3C1] * dt1[D3R2][D3C3] - dt1[D3R1][D3C3] * dt1[D3R2][D3C1])) / det_matrix;
    dt2[D3R3][D3C3] = (double)(dt1[D3R1][D3C1] * dt1[D3R2][D3C2] - dt1[D3R1][D3C2] * dt1[D3R2][D3C1]) / det_matrix;
  }
  return dt2;
}
void free_all(int **matrix, int matrix_size){ //配列のメモリ解放
  for(int i = 0; i < matrix_size; i++){
    free(matrix[i]);
  }
  free(matrix);
}
void free_all_double(double **matrix, int matrix_size){
  for(int i = 0; i < matrix_size; i++){
    free(matrix[i]);
  }
  free(matrix);
}
