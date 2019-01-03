#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OUTCOME 6
#define ROLL_TIMES 100

int dice(void){
  int outcome = (rand() % MAX_OUTCOME) + 1;
  return outcome;
}

int main(void){
  int outcome_counter[MAX_OUTCOME] = {0};
  srand((unsigned)time(NULL)); //define the seed of random number
  for(int i = 0; i < ROLL_TIMES; i++){
    outcome_counter[dice() - 1] += 1;
  }
  for(int i = 1; i < MAX_OUTCOME + 1; i++){
    printf("%dの目は%d回出ました！\n", i, outcome_counter[i - 1]);
  }

  return 0;
}
