#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

//Constants
#define INCREMENT 1
#define DECREMENT 2

void inc_date(int *year, int *month, int *day);
void dec_date(int *year, int *month, int *day);

int main(void){
  //初期化
  int year[2] = {0}, month[2] = {0}, day[2] = {0};
  int task = 0;

  printf("Input the year:");
  scanf("%d", &year[0]);
  printf("Input the month:");
  scanf("%d", &month[0]);
  printf("Input the day:");
  scanf("%d", &day[0]);

  printf("Choose the task from here\n");
  printf("Increment the date -> 1\n");
  printf("Decrement the date -> 2\n");
  scanf("%d", &task);
  assert(task == INCREMENT || task == DECREMENT);

  if(task == INCREMENT){
    inc_date(year, month, day);
    printf("%d年%d月%d日の翌日は%d年%d月%d日\n", year[0], month[0], day[0], year[1], month[1], day[1]);
  } else {
    dec_date(year, month, day);
    printf("%d年%d月%d日の前日は%d年%d月%d日\n", year[0], month[0], day[0], year[1], month[1], day[1]);
  }

  return 0;
}

void inc_date(int *year, int *month, int *day){
  time_t time; //1970年1月1日0時0分0秒(UTC)からの経過秒数
  struct tm date;
  struct tm *fixed_date; //適正な表記に直した後の構造体
  date.tm_sec = 0;
  date.tm_min = 0;
  date.tm_hour = 0;
  date.tm_mday = day[0] + 1; //翌日を表すために1を加える。
  date.tm_mon = month[0] - 1; //monthは1月からの経過月数(0~11)で表される。
  date.tm_year = year[0] - 1900; //yearは1900年からの経過年数で表される。
  date.tm_isdst = -1; //夏時間無効を表す。

  time = mktime(&date);
  fixed_date = localtime(&time);

  day[1] = fixed_date->tm_mday;
  month[1] = fixed_date->tm_mon + 1;
  year[1] = fixed_date->tm_year + 1900;
}

void dec_date(int *year, int *month, int *day){
  time_t time;
  struct tm date;
  struct tm *fixed_date;
  date.tm_sec = 0;
  date.tm_min = 0;
  date.tm_hour = 0;
  date.tm_mday = day[0] - 1; //前日を表すために1を引く。
  date.tm_mon = month[0] - 1;
  date.tm_year = year[0] - 1900;
  date.tm_isdst = -1;

  time = mktime(&date);
  fixed_date = localtime(&time);

  day[1] = fixed_date->tm_mday;
  month[1] = fixed_date->tm_mon + 1;
  year[1] = fixed_date->tm_year + 1900;
}
