#include <stdio.h>

//最大公約数を求める関数（再帰）
int gcc(int a, int b){
  if(a > b){
    if(a % b == 0){
      return b;
    } else {
      return gcc(b, a % b);
    }
  } else {
    if(b % a == 0){
      return a;
    } else {
      return gcc(a, b % a);
    }
  }
}

int main(void){
  int u = 0, v = 0;
  printf("uの値を入力：");
  scanf("%d", &u);

  printf("vの値を入力：");
  scanf("%d", &v);

  printf("%dと%dの最大公約数は%dです。\n", u, v, gcc(u, v));

  return 0;
}
