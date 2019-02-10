#include <stdio.h>
#include <assert.h>

// f(n + 1) = f(n) + f(n - 1)
int fibo_loop(int index){
  if(index < 2){
    return 1;
  } else {
    int value = 1, value_before = 1; //define f(0) and f(1)
    int tmp = 0;
    while(index > 1){
      tmp = value;
      value += value_before;
      value_before = tmp;
      index--;
    }
    return value;
  }
}

int fibo_rec(int index, int a, int b){
  if(index < 2){
    return a;
  } else {
    return fibo_rec(index - 1, a + b, a);
  }
}

int main(void){
  int index = 0;
  printf("Input the index?:");
  scanf("%d", &index);
  assert(index >= 0);

  printf("(loop) f(%d) = %d\n", index, fibo_loop(index));
  printf("(recursion) f(%d) = %d\n", index, fibo_rec(index, 1, 1));

  return 0;
}
