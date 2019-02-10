#include <stdio.h>
#include <assert.h>

void print_binary(int num){
  int binary[32] = {0};
  int i = 0; //Initialize index

  if(num >= 0){
    //Converting to binary
    do{
      binary[i] = num % 2;
      num /= 2;
      i++;
    } while(num > 0);
  } else {
    //Change MSB into "1"(means negative number)
    binary[31] = 1;
    //Converting to two`s complement
    num = 2147483648 + num;

    //Converting to binary
    do{
      binary[i] = num % 2;
      num /= 2;
      i++;
    } while(num > 0);
  }

  //printing binary
  for(int i = 31; i >= 0; i--){
    printf("%d", binary[i]);
  }
}

int main(void){
  int num = 0;

  printf("Input the integer(-2147483648~2147483647):");
  scanf("%d", &num);
  assert(num > -2147483648);
  assert(num < 2147483647);

  printf("The binary scale of %d is ", num);
  print_binary(num);
  printf(".\n");

  return 0;
}
