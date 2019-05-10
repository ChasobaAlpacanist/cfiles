#include <stdio.h>

int fact(int a){
  int result = 1;
  for(int i = 1; i < a + 1; i++){
    result *= i;
  }

  return result;
}

int fact_rec(int a){
  if(a < 2){
    return 1;
  } else {
    return a * fact_rec(a - 1);
  }

}

int main(void){
  int num = 0;

  printf("整数値を入力：");
  scanf("%d", &num);

  printf("%dの階乗は%d\n", num, fact(num));
  printf("%dの階乗を再帰で表すと%d\n", num, fact_rec(num));

  return 0;
}
