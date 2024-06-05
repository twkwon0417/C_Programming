#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAP_SIZE_W 60
#define MAP_SIZE_H 28
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define SPACE 32
#define ESC 27
#define BLOCK 99
#define M_H 16
#define M_W 26

#define GARBAGE -4
#define WALL -1
#define CLEARSPACE -2

#define EASY 5
#define NOMAL 7
#define HARD 9

#define RED 12
#define DARKRED 4
#define BLUE 9
#define WHITE 15
#define YELLOW 6

#define FRAME 60
#define TIMER 10000
#define TIME_LIMIT 90   //*//
#define MAX_BOSS_SPEED_LEVEL 6   //*//
#define BOSS_SPEED_UP_POSSIBLE -10   //*//
#define BOSS_SPEED_UP_IMPOSSIBLE -11   //*//
#define NAMESIZE 20

#define WIDTH 3 // 피아노 키의 개수
#define HEIGHT 26 // 노트가 떨어지는 높이
#define GAME_DURATION 30000 // 게임 지속 시간 (밀리초)

//main.c
void init(int visible);
void slow_print(const char* str, int delay);
void slow_print_money(const char* str, int delay);


//map.c
void gotoxy(int x, int y);
int start_screen(char pn[], int n);
int menu(void);
int rule(void);
void generate_map(int(*map)[MAP_SIZE_W]);
void creation_block(int(*map)[MAP_SIZE_W], int level);
void level_map(int(*map)[MAP_SIZE_W], int level);
void draw_map(int(*map)[MAP_SIZE_W]);
int pause(void);
void first_show(char name[]);
void skip();
void skip_f();



//mini_game.c
typedef struct {
    int active;
    int position;
} Note;
void textcolor(int colorNum);
int flag(int(*map)[MAP_SIZE_W], int* x, int* y, int level, int* money, char playName[]);
int article(int level);
void setNumber(int(*map)[MAP_SIZE_W], int* num, int* x, int* y);
void drawMap(int(*map)[MAP_SIZE_W]);
void moveKey(int(*map)[MAP_SIZE_W], int* x, int* y);
int delivery(void);
void draw_board();
void draw_customer_map(Note notes[WIDTH][HEIGHT], int score);
void generate_note(Note notes[WIDTH][HEIGHT]);
void update_notes(Note notes[WIDTH][HEIGHT]);
int customer(int level);
int mini_game_fail_penalty();





int move_key(int(*map)[MAP_SIZE_W], int* x, int* y, int level, int* money, char playName[]);

void move_boss(int(*map)[MAP_SIZE_W], int* player_y, int* player_x);
int game_start(int(*map)[MAP_SIZE_W], int start, int* x, int* y, char playName[]);
