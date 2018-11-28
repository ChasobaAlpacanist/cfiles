#include <stdio.h>

int main(void){
  for(int i = 1; i < 10; i++){
    for (int j = 1; j < 10; j++){
      if(i * j > 24){
        break;
      } else {
        if(i * j == 24){
          printf("%d %d\n", i, j);
          break;
        }
      }
    }
  }
  return 0;
}
