#include <stdio.h>

#define MAX_SIZE 1024

void print_array(char str[MAX_SIZE], int max_size){
  for(int i = 0; i < max_size - 1; i++){ //print without null
    printf("%c", str[i]);
  }
  printf("\n");
}

int main(void){
  char str[MAX_SIZE] = {""};
  printf("Input the string:");
  scanf("%s", str);

  printf("The string you input is -> ");
  print_array(str, MAX_SIZE);
}
