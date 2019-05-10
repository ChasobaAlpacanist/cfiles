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

//Prototypes
int det(int **matrix, int matrix_size);
int **init_matrix(int matrix_size);

int main(void){
  //変数の初期化
  int matrix_size = 0;
  int **matrix = NULL;

  printf("Input matrix size(2 or 3):");
  scanf("%d", &matrix_size);
  assert(matrix_size == DIMENSION2 || matrix_size ==  DIMENSION3);

  matrix = init_matrix(matrix_size);

  printf("The matrix you input is ->\n");
  for(int i = 0; i < matrix_size; i++){
    for(int j = 0; j < matrix_size; j++){
      printf("%d　", matrix[i][j]);
    }
    printf("\n");
  }

  printf("The determinant of this matrix is -> %d\n", det(matrix, matrix_size));

  for(int i = 0; i < matrix_size; i++){  //メモリ解放
    free(matrix[i]);
  }
  free(matrix);

  return 0;
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

int **init_matrix(int matrix_size){
  int **matrix = NULL;
  matrix = (int **)calloc(matrix_size, sizeof(int *));

  for(int i = 0; i < matrix_size * matrix_size; i++){
    matrix[i] = (int *)calloc(matrix_size, sizeof(int));
  }

  for(int i = 0; i < matrix_size; i++){  //初期化
    for(int j = 0; j < matrix_size; j++){
      matrix[i][j] = 0;
    }
  }

  for(int i = 0; i < matrix_size; i++){ //入力
    for(int j = 0; j < matrix_size; j++){
      printf("Input integer into the %d,%d element:", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  }
  return  matrix;
}
