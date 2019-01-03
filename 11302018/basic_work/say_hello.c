#include <stdio.h>
#include "myheader.h"

int main(void){
  printf("ループ\n");
  say_hello();
  printf("再帰\n");
  say_hello_rec();

  return 0;
}
