#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "janken.h"

int janken_result(int player_hand, int cpu_hand){ //0がかち、1があいこ、2がまけ
  if(player_hand == ROCK){ //プレイヤーがグー
    switch(cpu_hand){
      case ROCK:
        return TIE;
        break;
      case SCISSORS:
        return WIN;
        break;
      case PAPER:
        return LOSE;
        break;
    }
  } else {
    if(player_hand == SCISSORS){ //プレイヤーがチョキ
      switch(cpu_hand){
        case ROCK:
          return LOSE;
          break;
        case SCISSORS:
          return TIE;
          break;
        case PAPER:
          return WIN;
      }
    } else { //プレイヤーがパー
      switch(cpu_hand){
        case ROCK:
          return WIN;
          break;
        case SCISSORS:
          return LOSE;
          break;
        case PAPER:
          return TIE;
      }
    }
  }
  return 0;
}

void print_result(int result){ //結果をprint
  switch(result){
    case WIN:
      printf("かち！\n");
      break;
    case TIE:
      printf("あいこ！もう一回！\n");
      break;
    case LOSE:
      printf("まけ！\n");
      break;
  }
}

int get_number(void){
  srand((unsigned)time(NULL));
  int rand_num = (rand() % 3) + 1; //random number from 1 to 3
  return rand_num;
}

void print_cpu_hand(int cpu_hand){
  switch(cpu_hand){
    case ROCK:
      printf("コンピューターの手はグーです。\n");
      break;
    case SCISSORS:
      printf("コンピューターの手はチョキです。\n");
      break;
    case PAPER:
      printf("コンピューターの手はパーです。\n");
      break;
  }
}

int janken(void){
  int hand = 0;
  int result = 0;

  srand((unsigned)time(NULL)); //define the seed of random number

  do{
    printf("手を決めてください（1 -> グー、2 -> チョキ、 3 -> パー）\n");
    scanf("%d", &hand);
    assert(hand >= 1 && hand <= 3);
    int cpu_hand = get_number(); //cpuの手を確定
    print_cpu_hand(cpu_hand);

    result = janken_result(hand, cpu_hand); //結果を数字に変換して代入
    print_result(result);
  } while(result == 1);

  return result;
}
