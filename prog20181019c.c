#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

int main(void){
  int hp, strength, defence;

  sndPlaySound((LPCSTR)"n78.wav", SND_ASYNC);
	printf("      *         ***             *         *      \n");
	printf("     **            *            *         *      \n");
	printf("    **                     **********      *     \n");
	printf("   **          ******           *          *  ** \n");
	printf("  *               **          ***          ***   \n");
	printf("  **              *          *  *         *      \n");
	printf("   **            ***         *  *       **       \n");
	printf("    **          *  *          ***       *        \n");
	printf("     **        *   *            *       **       \n");
	printf("      **      *    ****       **         ********\n");
	printf("                              *                  \n");
  //waiting for key input
  _getch();
  system("cls");

  printf("ようこそ。\n");
  _getch();
  printf("あなたは選ばれし勇者さんらしいです。\n")
  _getch();
  printf("ステータスを入力してください。\n");
  _getch();

  printf("たいりょく:\n");
  scanf("%d", &hp);

  printf("ちから:\n");
  scanf("%d", &strength);

  printf("ぼうぎょ:\n");
  scanf("%d", &defence);

  printf("ステータスの振り方は自由だからって振りすぎてませんよね？\n");
  _getch();
  printf("...まあいいですけど。こちらは私どもからのささやかなプレゼントです。\n")
  _getch();
  printf("ロトのよろいを手に入れた。\n");
  defence = defence + 45; //45はロトのよろいの守備力
  _getch();
  printf("ロトのたてを手に入れた。\n");
  defence += defence + 20;
  _getch();
  printf("ひのきのぼうを手に入れた。\n");
  strength += 2;
  _getch();
  printf("もうしわけございません。ぶきは今これしかなくて...\n");
  _getch();
  printf("まあきっと大丈夫です、最初は。\n");
  _getch();
  printf("それではステータスをお伝えしますね。\n");
  _getch();
  printf("こうげき:%d\n", strength);
  _getch();
  printf("ぼうぎょ:%d\n", defence);
  _getch();
  printf("たいりょく:%d\n", (int)defence * 0.5 + hp);
  _getch();
  printf("ほんじゃもう寝るからあとはそっちで頑張ってくださいね。\n");
  _getch();
  printf("...目が覚めると目の前にはドラゴンがいた。\n");
  _getch();
  printf("ドラゴンがあらわれた。\n"); //ドラゴンの攻撃力は150, 防御力は40、体力は200
  _getch();
  printf("ドラゴンのこうげきは危険だ!%d発食らうと死んでしまう!\n", (int)(hp / (150 - defence)));
  _getch();
  printf("ドラゴンはタフだ!%d回攻撃しないと倒れなさそうだ!\n", (int)(200 / (strength - 40)));
  _getch();

  return 0;
}
