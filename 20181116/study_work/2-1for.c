#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int janken_result(int player_hand, int cpu_hand){ //0がかち、1があいこ、2がまけ
  if(player_hand == 1){ //プレイヤーがグー
    switch(cpu_hand){
      case 1:
        return 1;
        break;
      case 2:
        return 0;
        break;
      case 3:
        return 2;
        break;
    }
  } else {
    if(player_hand == 2){ //プレイヤーがチョキ
      switch(cpu_hand){
        case 1:
          return 2;
          break;
        case 2:
          return 1;
          break;
        case 3:
          return 0;
      }
    } else { //プレイヤーがパー
      switch(cpu_hand){
        case 1:
          return 0;
          break;
        case 2:
          return 2;
          break;
        case 3:
          return 1;
      }
    }
  }
  return 0;
}

void print_result(int result){ //結果をprint
  switch(result){
    case 0:
      printf("かち！\n");
      break;
    case 1:
      printf("あいこ！もう一回！\n");
      break;
    case 2:
      printf("まけ！\n");
      break;
  }
}

void print_cpu_hand(int cpu_hand){
  switch(cpu_hand){
    case 1:
      printf("コンピューターの手はグーです。\n");
      break;
    case 2:
      printf("コンピューターの手はチョキです。\n");
      break;
    case 3:
      printf("コンピューターの手はパーです。\n");
      break;
  }
}

int get_number(void){
  int rand_num = (rand() % 3) + 1; //random number from 1 to 3
  return rand_num;
}

int main(void){
  int hand = 0;

  srand((unsigned)time(NULL)); //define the seed of random number

  for(int i = 1; i == 1;){
    printf("手を決めてください（1 -> グー、2 -> チョキ、 3 -> パー）\n");
    scanf("%d", &hand);
    assert(hand >= 1 && hand <= 3);
    int cpu_hand = get_number(); //cpuの手を確定
    print_cpu_hand(cpu_hand); //cpuの手を表示

    i = janken_result(hand, cpu_hand); //結果を数字に変換して代入
    print_result(i);
  }

  return 0;
}
