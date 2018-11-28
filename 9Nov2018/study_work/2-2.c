#include <stdio.h>
#include <assert.h>

int gcc(int a, int b){
  if(a % b == 0){
    return b;
  } else {
    return gcc(b, a % b);
  }
}


int main(void){
  int u = 0, v = 0;
  printf("uの値を入力：");
  scanf("%d", &u);

  printf("vの値を入力：");
  scanf("%d", &v);
  assert(u > v);


  printf("%dと%dの最大公約数は%dです。\n", u, v, gcc(u, v));

  return 0;
}
