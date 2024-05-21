#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
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

void gotoxy(int x, int y);
int move_key(int(*map)[MAP_SIZE_W], int* x, int* y, int level);
int menu(void);
void generate_map(int(*map)[MAP_SIZE_W]);
void level_map(int(*map)[MAP_SIZE_W], int level);
int start_screen(void);
int flag(int(*map)[MAP_SIZE_W], int* x, int* y, int level);
void draw_map(int(*map)[MAP_SIZE_W]);
int game_start(int(*map)[MAP_SIZE_W], int start, int* x, int* y);
int pause(void);
void creation_block(int(*map)[MAP_SIZE_W], int level);

void textcolor(int colorNum);
void article(int level);

void move_boss(int* player_y, int* player_x);
