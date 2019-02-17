#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//Constants
#define STR_MAX 256
#define WEAPON 1
#define ARMOR 2
#define SHIELD 3
#define HELMET 4
#define NOEQUIP 0
#define POWER_RAND_RANGE 5  //ちから、身のまもりの乱数生成のための範囲
#define G_RATE_RAND_RANGE 8  //成長率の乱数生成のための範囲
#define NUMBER_OF_ITEMS 4 //持ち物の数

typedef struct equip{ //装備
  int type;   //タイプ（なしの場合はNOEQUIP）
  char name[STR_MAX];;  //武器名
  int point;   //武器によるステータスの修正値
} equip_t;

typedef struct player{  //プレイヤー構造体
  int id;               //プレイヤーID（一意特定可能）
  char name[STR_MAX];   //プレイヤー名
  int level;            //レベル
  int power;            //ちから
  int protec;           //みのまもり
  int speed;            //すばやさ
  int attack;           //こうげき
  int defense;          //ぼうぎょ
  double g_rate;        //成長率
  equip_t weapon;       //ぶき
  equip_t armor;        //アーマー
  equip_t shield;       //たて
  equip_t helmet;       //かぶと
  struct player *prev;  //前のキャラクタ
  struct player *next;  //次のキャラクタ
} player_t;

//Prototypes
char *print_equipment(equip_t item);
void print_chara_all(player_t *player);  //1-1.1
player_t gen_player(char name[STR_MAX]);  //1-1.2
void print_all_party(player_t *player);  //1-1.3

player_t *get_chara_pointer(player_t *party, int id); //1-1.5
void join_party(player_t *party, player_t *join_player);  //1-1/4
void remove_party(player_t *party, int id); //1-1.6
void print_member_data(player_t *party, int id); //1-1.7
void swap_member(player_t *party, int id1, int id2);  //1-1.8

equip_t equip(player_t *chara, equip_t equipment);  //1-1.9

void export_party(char filename[STR_MAX], player_t *party);  //保存ファイル名、パーティーの情報を引数とする 1-1.10
void import_party(char filename[STR_MAX], player_t *new_party);  //ファイルからパーティーを作成引数はパーティーのポインタ 1-1.11

//main
int main(void){
  srand((unsigned) time(NULL));

  //characters
  player_t chara1 = gen_player("Yuusya");
  player_t chara2 = gen_player("Sensi");
  player_t chara3 = gen_player("Kenja");
  player_t chara4 = gen_player("Souryo");
  player_t chara5 = gen_player("Budouka");
  //characters pointer
  player_t *chara1_p = &chara1;
  player_t *chara2_p = &chara2;
  player_t *chara3_p = &chara3;
  player_t *chara4_p = &chara4;
  player_t *chara5_p = &chara5;
  //party
  player_t *party = chara1_p;


  //equipment
  equip_t item1 = {1, "Tsuyoiken", 10};

  print_chara_all(chara1_p); //1-1.1, 1-1.2の確認
  printf("\n");

  join_party(party, chara2_p);
  join_party(party, chara3_p);
  join_party(party, chara4_p);

  print_all_party(party); //1-1.3の確認
  printf("\n");
  print_all_party(chara3_p);
  printf("\n");

  join_party(party, chara5_p);
  print_all_party(party); //1-1.4, 1-1.5の確認
  printf("\n");

  remove_party(party, 4); //4番目に作られたキャラchara4をパーティーから削除。
  print_all_party(party); //1-1.6の確認
  printf("\n");

  print_member_data(party, 2); //2番目に作られたキャラchara2のデータを表示 1-1.7の確認
  printf("\n");

  swap_member(party, 1, 5); //chara1とchara5の順番を入れ替え。
  print_all_party(party); //1-1.8の確認。
  printf("\n");

  print_member_data(chara1_p, chara1_p->id);
  printf("\n");
  printf("%sは%sを装備した！\n", chara1_p->name, equip(chara1_p, item1).name);

  print_member_data(chara1_p, chara1_p->id); //chara1のデータを確認 1-1.9の確認。

  char filename[STR_MAX] = "text.txt";
  export_party(filename, party); //1-1.10の確認

}

//functions
char *print_equipment(equip_t item){
  static char message[STR_MAX];
  if(item.type == NOEQUIP){
    sprintf(message, "何も装備していません。\n");
    return message;
  } else {
    sprintf(message, "%sです。\n", item.name);
    return message;
  }
}

void print_chara_all(player_t *player){
  printf("プレイヤーIDは%d\n", player->id);
  printf("プレイヤー名は%s\n", player->name);
  printf("%sのレベルは%d\n", player->name, player->level);
  printf("%sのちからは%d\n", player->name, player->power);
  printf("%sのみのまもりは%d\n", player->name, player->protec);
  printf("%sのすばやさは%d\n", player->name, player->speed);
  printf("%sの攻撃力は%d\n", player->name, player->attack);
  printf("%sの防御力は%d\n", player->name, player->defense);
  printf("%sの成長率は%.1lf\n", player->name, player->g_rate);
  printf("武器は%s", print_equipment(player->weapon));
  printf("アーマーは%s", print_equipment(player->armor));
  printf("盾は%s", print_equipment(player->shield));
  printf("かぶとは%s", print_equipment(player->helmet));
}

player_t gen_player(char name[STR_MAX]){
  static int id_maker = 1; //IDに一意性を与えるための変数

  player_t character = {id_maker};
  sprintf(character.name, "%s", name);
  character.level = 1;
  character.power = 5 + rand()%(POWER_RAND_RANGE + 1);
  character.protec = 5 + rand()%(POWER_RAND_RANGE + 1);
  character.speed = 10;
  character.attack = character.power;
  character.defense = character.protec;
  character.g_rate = 1.1 + ((rand()%G_RATE_RAND_RANGE + 1) / 10.0); //1.1 ~ 1.9
  character.weapon.type = NOEQUIP;
  sprintf(character.weapon.name, "%s", "None");
  character.armor.type = NOEQUIP;
  sprintf(character.armor.name, "%s", "None");
  character.shield.type = NOEQUIP;
  sprintf(character.shield.name, "%s", "None");
  character.helmet.type = NOEQUIP;
  sprintf(character.helmet.name, "%s", "None");
  character.prev = NULL;
  character.next = NULL;

  id_maker++; //次にキャラを作るためにIDを更新

  return character;
}

void print_all_party(player_t *player){
  if(player->prev != NULL){
    print_all_party(player->prev);
  } else {
    int index = 1;
    player_t *now_player = player;

    do{
      printf("%d人目:%s\n", index, now_player->name);
      index++;
      now_player = now_player->next;
    } while(now_player != NULL);
  }
}

player_t *get_chara_pointer(player_t *party, int id){
  player_t *member = party;
  if(member->id == id){
    return member;
  } else {
    while(member->prev != NULL){  //指定されたところからパーティーの先頭までを探す
      member = member->prev;
      if(member->id == id){
        return member;
      } else {

      }
    }
    while(member != NULL){ //指定されたところからパーティーの最後までを探す。
      member = member->next;
      if(member->id == id){
        return member;
      } else {

      }
    }
  }
  printf("探しているキャラが見つかりませんでした。");
  return NULL;
}

void join_party(player_t *party, player_t *join_player){
  player_t *last_member = party; //最後尾のメンバーを探す。
  while(last_member->next != NULL){
    last_member = last_member->next;
  }
  last_member->next = join_player;
  join_player->prev = last_member;
}

void remove_party(player_t *party, int id){
  player_t *remove_player = get_chara_pointer(party, id);
  player_t *prev_player = remove_player->prev;
  player_t *next_player = remove_player->next;
  prev_player->next = next_player;
  next_player->prev = prev_player; //前後関係の整合
}

void print_member_data(player_t *party, int id){
  player_t *member = get_chara_pointer(party, id);
  assert(member != NULL);
  print_chara_all(member);
}

void swap_member(player_t *party, int id1, int id2){ //prev, next以外の全てのデータを入れ替える。
  player_t *member1 = get_chara_pointer(party, id1);
  player_t *member2 = get_chara_pointer(party, id2);
  player_t tmp;

  tmp.id = member1->id;
  sprintf(tmp.name, "%s", member1->name);
  tmp.level = member1->level;
  tmp.power = member1->power;
  tmp.protec = member1->protec;
  tmp.speed = member1->speed;
  tmp.attack = member1->attack;
  tmp.defense = member1->defense;
  tmp.g_rate = member1->g_rate;
  tmp.weapon = member1->weapon;
  tmp.armor = member1->armor;
  tmp.shield = member1->shield;
  tmp.helmet = member1->helmet;

  member1->id = member2->id;
  sprintf(member1->name, "%s", member2->name);
  member1->level = member2->level;
  member1->power = member2->power;
  member1->protec = member2->protec;
  member1->speed = member2->speed;
  member1->attack = member2->attack;
  member1->defense = member2->defense;
  member1->g_rate = member2->g_rate;
  member1->weapon = member2->weapon;
  member1->armor = member2->armor;
  member1->shield = member2->shield;
  member1->helmet = member2->helmet;

  member2->id = tmp.id;
  sprintf(member2->name, "%s", tmp.name);
  member2->level = tmp.level;
  member2->power = tmp.power;
  member2->protec = tmp.protec;
  member2->speed = tmp.speed;
  member2->attack = tmp.attack;
  member2->defense = tmp.defense;
  member2->g_rate = tmp.g_rate;
  member2->weapon = tmp.weapon;
  member2->armor = tmp.armor;
  member2->shield = tmp.shield;
  member2->helmet = tmp.helmet;
}

equip_t equip(player_t *chara, equip_t equipment){
  assert(equipment.type >= WEAPON && equipment.type <= HELMET);
  switch(equipment.type){
    case WEAPON:
      chara->weapon = equipment;
      chara->attack += (equipment.point);
      break;
    case ARMOR:
      chara->armor = equipment;
      chara->defense += (equipment.point);
      break;
    case SHIELD:
      chara->shield = equipment;
      chara->defense += (equipment.point);
      break;
    case HELMET:
      chara->helmet = equipment;
      chara->defense += (equipment.point);
      break;
  }
  return equipment;
}

void export_party(char filename[STR_MAX], player_t *party){
  FILE *fp = NULL;
  fp = fopen(filename, "w");

  player_t *first_player = party;
  while(party->prev != NULL){ //find first player
    first_player = party->prev;
  }

  do {
    fprintf(fp, "%d %s %d %d %d %d %d %d %.2lf\n", first_player->id,
      first_player->name, first_player->level, first_player->power,
      first_player->protec, first_player->speed, first_player->attack,
      first_player->defense, first_player->g_rate); //print status

    //print items
    fprintf(fp, "%d %s %d\n", first_player->weapon.type, first_player->weapon.name,
                            first_player->weapon.point);
    fprintf(fp, "%d %s %d\n", first_player->armor.type, first_player->armor.name,
                            first_player->armor.point);
    fprintf(fp, "%d %s %d\n", first_player->shield.type, first_player->shield.name,
                            first_player->shield.point);
    fprintf(fp, "%d %s %d\n", first_player->helmet.type, first_player->helmet.name,
                            first_player->helmet.point);

    first_player = first_player->next;
  } while(first_player != NULL);
  fclose(fp);
}

/* void import_party(char filename[STR_MAX], player_t *new_party){
  FILE *fp = NULL;
  fp = fopen(filename, "r");
  assert(fp != NULL);
  int num_lines = 0; //得られたファイルの行数を数える

  char str[STR_MAX];
  while(fgets(str, STR_MAX, fp) != NULL){
    num_lines++;
  }
  fclose(fp);
  int num_members = num_lines / 5; //1人あたり5行使うため

  new_party = (int *)calloc(num_members, sizeof(player_t));

  fp = fopen(filename, "r");
  for(int i = 0; i < num_members; i++){

  }
} */
