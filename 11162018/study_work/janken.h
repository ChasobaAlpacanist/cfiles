#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define result
#define WIN 0
#define TIE 1
#define LOSE 2

//define hand
#define ROCK 1
#define SCISSORS 2
#define PAPER 3

/* int janken_result(int)
  じゃんけんにおいて手を比較して勝ち負けを決める関数
  int player_hand : プレイヤーの手を表す数字
  int cpu_hand : cpuの手を表す数字
  返り値 : じゃんけんの結果を表す数字
  注意 : 1 <= player_hand <= 3, 1 <= cpu_hand <= 3
*/
int janken_result(int player_hand, int cpu_hand);

/* void print_result(int)
  じゃんけんの結果に応じた出力を行う関数
  int result : 結果を表す数字
  返り値 : なし
  注意 : 0 <= result <= 2
*/
void print_result(int result);

/* int get_number(void)
  cpuの手を決めるための1から3までの乱数を返す関数
  返り値 : cpuの手を表す数字
*/
int get_number(void);

/* void print_cpu_hand(int)
  cpuの手を表示する関数
  int cpu_hand : cpuの手を表す数字
  返り値 : なし
  注意 : 1 <= cpu_hand <= 3
*/
void print_cpu_hand(int cpu_hand);

/* int janken(void)
  じゃんけんを勝敗がつくまで行い、結果を出力し返す関数
  返り値 : じゃんけんの結果を表す数字
  注意 : 結果は勝ちか負けであるため 0 or 2
*/
int janken(void);
