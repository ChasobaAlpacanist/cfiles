#include <stdio.h>
#include <assert.h>

int main(void){
  int x = 0, y = 0;
  printf("x?:");
  scanf("%d", &x);
  printf("y?:");
  scanf("%d", &y);

  assert(y >= 0);

  int pow = 1;

  for(int i = 0; i < y; i++){
    pow *= x;
  }

  printf("x^y = %d\n", pow);

  return 0;
}
