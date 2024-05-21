#include "Game.h"

int frame_cnt = 0;  // which frame are we in, In 60frames   // could
int player_frame = 20;
int evil_frame = 20;

struct opponent {
	int y;
	int x;
} boss;

void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	// 커서를 이동해주는 함수
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//맵 안에서 움직이기
int move_key(int(*map)[MAP_SIZE_W], int* x, int* y, int level)
{
	Sleep(1000 / FRAME);  // 화면은 1초마다 60번 업데이트 된다.
	printf("     %d \n", frame_cnt);
	frame_cnt++;
	if (frame_cnt == 61) {   // TODO:not sure if it iterates 60 time and resetted
		frame_cnt = 1;
	}

	int ch, f, stop;

	gotoxy(*x, *y);
	textcolor(YELLOW);
	printf("◆\b");  // where the new point is drawn
	textcolor(WHITE);

	if (frame_cnt % player_frame == 0) {
		if (_kbhit()) {
			while (_kbhit()) {
				ch = _getch();
				printf("\n input %d", ch);
				break;
			}
			
			//ESC 눌렀을때 일시정지
			if (ch == ESC) {
				stop = pause();
				//이어하기
				if (stop == 0)
					return stop - 1; //return -1
				//메인메뉴로
				else if (stop == 1)
					return stop - 3; //return -2
				//게임종료
				else if (stop == 2)
					return stop - 5; //return -3
			}
			if (ch == 224) {
			ch = _getch();
				printf(" \b");
				switch (ch) {
				case UP:
					if (map[(*y) - 1][*x] == CLEARSPACE) {
						(*y)--;
						return GARBAGE;
					}
					else if (map[(*y) - 1][*x] == WALL || map[(*y) - 1][*x] == BLOCK) //벽
						return GARBAGE;
					else {
						(*y)--;
						f = flag(map, x, y, level);
						(*y)++;
						return f;
					}
					break;
				case DOWN:
					if (map[(*y) + 1][*x] == CLEARSPACE) {
						(*y)++;
						return GARBAGE;
					}
					else if (map[(*y) + 1][*x] == WALL || map[(*y) + 1][*x] == BLOCK)
						return GARBAGE;
					else {
						(*y)++;
						f = flag(map, x, y, level);
						(*y)--;
						return f;
					}
					break;
				case LEFT:
					if (map[*y][(*x) - 1] == CLEARSPACE) {
						(*x)--;
						return GARBAGE;
					}
					else if (map[*y][(*x) - 1] == WALL || map[*y][(*x) - 1] == BLOCK)
						return GARBAGE;
					else {
						(*x)--;
						f = flag(map, x, y, level);
						(*x)++;
						return f;
					}
					break;
				case RIGHT:
					if (map[*y][(*x) + 1] == CLEARSPACE) {
						(*x)++;
						return GARBAGE;
					}
					else if (map[*y][(*x) + 1] == WALL || map[*y][(*x) + 1] == BLOCK)
						return GARBAGE;
					else {
						(*x)++;
						f = flag(map, x, y, level);
						(*x)--;
						return f;
					}
					break;
				}
			}
		}
	}

}

//맵 선택
int menu(void)
{
	int x = 24;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("                      [맵 선택]\n\n");

	gotoxy(x - 2, y);
	printf("> EASY ");
	gotoxy(x, y + 1);
	printf("NOMAL");
	gotoxy(x, y + 2);
	printf("HARD");
	gotoxy(x, y + 3);
	printf("back");

	do {
		int ch = _getch();
		if (ch == ENTER || ch == SPACE)
			return y - 6;
		if (ch == 224) {
			ch = _getch();
			printf(" \b");
			switch (ch) {
				//y좌표는 최대 6에서 9
			case UP: //키보드 UP
				if (y > 6) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}
				break;
			case DOWN: //키보드 DOWN
				if (y < 9) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
		}
	} while (1);
}

//기본 맵 생성
void generate_map(int(*map)[MAP_SIZE_W])
{
	for (int i = 0; i < MAP_SIZE_H; i++)
	{
		for (int j = 0; j < MAP_SIZE_W; j++)
		{
			if (i == 0 || i == MAP_SIZE_H - 1 || j == 0 || j == MAP_SIZE_W - 1)
				map[i][j] = WALL; //벽 생성
			else
				map[i][j] = CLEARSPACE; //빈공간
		}
	}
}

//level별로 맵 생성
void level_map(int(*map)[MAP_SIZE_W], int level)
{
	int h, w;

	if (level == 0) //EASY(5) 선택
	{
		//맵 안의 블록(벽) 생성
		creation_block(map, level);

		for (int i = 0; i < EASY; i++)
		{
			h = rand() % (MAP_SIZE_H - 2) + 1;
			w = rand() % (MAP_SIZE_W - 2) + 1;
			if (h == 1 && w == 1)
			{
				i--;
				continue;
			}
			if (map[h][w] == BLOCK)
			{
				i--;
				continue;
			}
			map[h][w] = i;
		}
	}
	else if (level == 1) //NOMAL(7) 선택
	{
		creation_block(map, level);
		for (int i = 0; i < NOMAL; i++)
		{
			h = rand() % (MAP_SIZE_H - 2) + 1;
			w = rand() % (MAP_SIZE_W - 2) + 1;
			if (h == 1 && w == 1)
			{
				i--;
				continue;
			}
			if (map[h][w] == BLOCK)
			{
				i--;
				continue;
			}
			map[h][w] = i;
		}
	}
	else if (level == 2) //HARD(9) 선택
	{
		creation_block(map, level);
		for (int i = 0; i < HARD; i++)
		{
			h = rand() % (MAP_SIZE_H - 2) + 1;
			w = rand() % (MAP_SIZE_W - 2) + 1;
			if (h == 1 && w == 1)
			{
				i--;
				continue;
			}
			if (map[h][w] == BLOCK)
			{
				i--;
				continue;
			}
			map[h][w] = i;
		}
	}
}

void draw_map(int(*map)[MAP_SIZE_W])
{
	//map 그리기
	for (int i = 0; i < MAP_SIZE_H; i++)
	{
		for (int j = 0; j < MAP_SIZE_W; j++)
		{
			char temp = map[i][j];
			if (temp == CLEARSPACE)
				printf(" ");
			else if (temp == WALL) //-1은 벽
				printf("#");
			else if (temp == BLOCK)
			{
				textcolor(DARKRED);
				printf("⣿");
				textcolor(WHITE);
			}
			else //-1과 -2 제외한 숫자 깃발
				printf("▶");
		}
		printf("\n");
	}
}

//시작 화면
int start_screen(void)
{
	int x = 24;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("                      게임 제목\n\n");

	gotoxy(x - 2, y);
	printf("> 게임 시작");
	gotoxy(x, y + 1);
	printf("게임 설명");
	gotoxy(x, y + 2);
	printf("게임 종료");

	do {
		int ch = _getch();
		if (ch == ENTER || ch == SPACE)
			return y - 6;
		if (ch == 224) {
			ch = _getch();
			printf(" \b");
			switch (ch) {
				//y좌표는 최대 6에서 8
			case UP: //키보드 UP
				if (y > 6) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}
				break;
			case DOWN: //키보드 DOWN
				if (y < 8) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
		}
	} while (1);

}
int game_start(int(*map)[MAP_SIZE_W], int start, int* x, int* y)
{
	int item, level, ch;

	if (start == 0)
	{
		level = menu();

		if (level == 3)
			return 1; //반환이 1이면 시작화면으로

		generate_map(map);
		system("cls");
		level_map(map, level);
		draw_map(map);


		while (1) {
			item = move_key(map, x, y, level);

			//ESC 눌렀을 때 일시정지
			//return -1: 이어하기
			if (item == -1)
			{
				system("cls");
				draw_map(map);
			}
			//return -2: 메인메뉴로
			else if (item == -2)
			{
				return 1;
			}
			//return -3: 게임 종료
			else if (item == -3)
			{
				return 0;
			}


			if (item == -99)	// code that allow not to go to next level
			{
				if (level == 2)
				{
					printf("게임 완료");
					Sleep(2000);
					return 1; //반환이 1이면 시작화면으로
				}
				else if (level == 0 || level == 1)
				{
					printf("다음 레벨로");
					Sleep(2000);
					system("cls");
					level = level + 1;
					*x = 1;
					*y = 1;
					generate_map(map);
					level_map(map, level);
					draw_map(map);
				}
			}
		}
	}
	else if (start == 1)
	{
		//게임 룰 설명(계약서)
	}
	else
	{
		return 0; //반환이 0이면 종료
	}
}
int pause(void)
{
	int x = 24;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("                     일시정지\n\n");

	gotoxy(x - 2, y);
	printf("> 이어 하기");  //return -1
	gotoxy(x, y + 1);
	printf("메인 메뉴로"); //return -2
	gotoxy(x, y + 2);
	printf("게임 종료"); //return -3

	do {
		int ch = _getch();
		if (ch == ENTER || ch == SPACE)
			return y - 6;
		if (ch == 224) {
			ch = _getch();
			printf(" \b");
			switch (ch) {
				//y좌표는 최대 6에서 8
			case UP: //키보드 UP
				if (y > 6) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}
				break;
			case DOWN: //키보드 DOWN
				if (y < 8) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
		}
	} while (1);
}

void creation_block(int(*map)[MAP_SIZE_W], int level)
{
	int b_h, b_w;

	if (level == 0)
		level = EASY;
	else if (level == 1)
		level = NOMAL;
	else if (level == 2)
		level = HARD;

	for (int i = 0; i < level * 2; i++)
	{
		b_h = rand() % (MAP_SIZE_H - 2) + 1;
		b_w = rand() % (MAP_SIZE_W - 2) + 1;
		if (b_h == 1 && b_w == 1)
		{
			i--;
			continue;
		}
		switch (i % 3)
		{
		case 0:
			if (map[b_h + 1][b_w] != CLEARSPACE || map[b_h + 2][b_w] != CLEARSPACE || map[b_h + 3][b_w] != CLEARSPACE)
			{
				i--;
				break;
			}
			map[b_h][b_w] = BLOCK;
			map[b_h + 1][b_w] = BLOCK;
			map[b_h + 2][b_w] = BLOCK;
			map[b_h + 3][b_w] = BLOCK;
			break;
		case 1:
			if (map[b_h][b_w + 1] != CLEARSPACE || map[b_h][b_w + 2] != CLEARSPACE || map[b_h][b_w + 3] != CLEARSPACE || map[b_h][b_w + 4] != CLEARSPACE || map[b_h][b_w + 5] != CLEARSPACE)
			{
				i--;
				break;
			}
			map[b_h][b_w] = BLOCK;
			map[b_h][b_w + 1] = BLOCK;
			map[b_h][b_w + 2] = BLOCK;
			map[b_h][b_w + 3] = BLOCK;
			map[b_h][b_w + 4] = BLOCK;
			map[b_h][b_w + 5] = BLOCK;
			break;
		case 2:
			if (map[b_h][b_w + 1] != CLEARSPACE || map[b_h][b_w + 2] != CLEARSPACE || map[b_h + 1][b_w + 3] != CLEARSPACE || map[b_h + 1][b_w + 4] != CLEARSPACE || map[b_h + 1][b_w + 2] != CLEARSPACE)
			{
				i--;
				break;
			}
			map[b_h][b_w] = BLOCK;
			map[b_h][b_w + 1] = BLOCK;
			map[b_h][b_w + 2] = BLOCK;
			map[b_h + 1][b_w + 2] = BLOCK;
			map[b_h + 1][b_w + 3] = BLOCK;
			map[b_h + 1][b_w + 4] = BLOCK;
			break;
		}
	}
}
