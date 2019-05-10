#include "myheader.h"

void say_hello(void){
  for(int i = 0; i < 10; i++){
    printf("Hello\n");
  }
}

void say_hello_rec(void){
  static int i = 0;
  if(i < 10){
    i++;
    say_hello_rec();
    printf("Hello\n");
  }
}
