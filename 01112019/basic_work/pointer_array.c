#include <stdio.h>
#include <stdlib.h>


//動的2次元配列の実装方法
//1. 1次元配列の要素を分割
//実装が比較的楽
int main(void){
    int *dtNew = NULL;
    int size = 3;
    dtNew = (int *)calloc(size*size, sizeof(int));
    dtNew[(size * 0) + 0] = 10; //1行1列を左のようにする。
    printf("%d\n", dtNew[0]);
    free(dtNew);
}

//2. 各行のデータを保持する配列と各行のポインタを保持する配列に分ける
//行ごとの長さを変更できる。free処理がやや煩雑
int main(void){
    int **matrix = NULL;
    int size = 3;
    matrix = (int *)calloc(size, sizeof(int *));
    for(int i = 0; i < size; i++){
        matrix[i] = (int *)calloc(size, sizeof(int));
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d　", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

//2a. 各行のポインタを保持する配列を作る。ポインタからできるデータは連続している。
//2に比べ作る作るポインタの数が少なく、ループが少ないため、処理が2よりも早い。
int main(void){
    int **matrix = NULL;
    int *base_matrix = NULL;
    int row_size = 3;
    int col_size = 3;

    matrix = (int *)calloc(row_size, sizeof(int *));
    base_matrix = (int *)calloc(row_size * col_size, sizeof(int));
    for(int i = 0; i < row_size; i++){//初期化
        matrix[i] = base_matrix + (i * col_size);
    }

    for(int i = 0; i < row_size; i++){//入力
        for(int j = 0; j < col_size; j++){
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    for(int i = 0; i < row_size; i++){//表示
        for(int j = 0; j < col_size; j++){
            printf("%d　", matrix[i][j]);
        }
        printf("\n");
    }
    free(base_matrix);
    free(matrix);
}
