#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 10

void print_array(char str[MAX_SIZE], int max_size){
  for(int i = 0; i < max_size - 1; i++){ //print without null
    printf("%c", str[i]);
  }
  printf("\n");
}

int main(void){
  char str[MAX_SIZE] = "ABCDEFG";
  print_array(str, MAX_SIZE);
}
