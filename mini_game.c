#include "Game.h"

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

int flag(int(*map)[MAP_SIZE_W], int* x, int* y, int level)
{
	system("cls");

	if (map[*y][*x] == 0)
	{
		gotoxy(0, 7);
		printf("              ■■■■■■    ■■   ■■■■■■■■■■       ■■■■    ■■     ■■■■■■■■  \n");
		printf("              ■    ■    ■■           ■■     ■■■■■■■■  ■■     ■         \n");
		printf("              ■    ■    ■■           ■■      ■■■■■■   ■■     ■         \n");
		printf("              ■■■■■■    ■■           ■■      ■    ■   ■■     ■■■■■■■■  \n");
		printf("            ■■■■■■■■■■  ■■           ■       ■■■■■■   ■■               \n");
		printf("                 ■ ■■■■■■■  ■■■■■■■■■■■■       ■■     ■■              \n");
		printf("                 ■      ■■                  ■■■■■■■■■■■■   ■■■■■■■■■■■■\n");
		printf("               ■■■■■■■■■      ■      ■■                                \n");
		printf("                      ■■      ■      ■■      ■■■■■■■■■■■    ■■■■■■■■■  \n");
		printf("               ■■■■■■■■■      ■■■■■■■■■               ■             ■  \n");
		printf("               ■■             ■      ■■               ■             ■  \n");
		printf("               ■■■■■■■■■■     ■■■■■■■■■               ■             ■  ");
		Sleep(2000);
		system("cls");
		map[*y][*x] = -2;
		return 1; //월급 획득 성공
	}
	else
	{
		switch (map[*y][*x] % 4 + 1)
		{
		case 1:
			printf("깃발 위치");
			gotoxy(0, 7);
			Sleep(2000);
			system("cls");
			
			break;
		case 2:
			gotoxy(0, 7);
			printf("                        ■■         ■         ■\n");
			printf("                        ■■         ■         ■\n");
			printf("                       ■■■■        ■         ■\n");
			printf("                    ■■■    ■■■     ■         ■\n");
			printf("                   ■■   ■■   ■■    ■         ■\n");
			printf("                        ■■         ■■■■■■■■  ■\n");
			printf("                   ■■■■■■■■■■■■              ■\n");
			printf("                     ■              ■■■■■■■■■■\n");
			printf("                     ■■             ■        ■\n");
			printf("                     ■■             ■        ■\n");
			printf("                     ■■             ■        ■\n");
			printf("                     ■■■■■■■■■      ■■■■■■■■■■");
			Sleep(2000);
			system("cls");
			
			break;
		case 3:
			gotoxy(0, 7);
			printf("               ■■■■■■■    ■  ■   ■■    ■■  ■  ■\n");
			printf("               ■■         ■  ■   ■■    ■■  ■  ■\n");
			printf("               ■■         ■  ■   ■■    ■■  ■  ■\n");
			printf("               ■■■■■■     ■■■■   ■■■■■■■■  ■  ■\n");
			printf("               ■■         ■  ■   ■■    ■■  ■■■■\n");
			printf("               ■■         ■  ■   ■■    ■■  ■  ■\n");
			printf("               ■■■■■■■■   ■  ■   ■■    ■■  ■  ■\n");
			printf("                                 ■■■■■■■■  ■  ■\n");
			printf("                  ■■■■■■■■■■■              ■  ■\n");
			printf("                           ■■              ■  ■\n");
			printf("                           ■■                 ■\n");
			printf("                           ■■                 ");
			Sleep(2000);
			system("cls");
			
			break;
		case 4:
			gotoxy(0, 7);
			printf("            ■■■■■■■■    ■■■■■■■■■     ■■■■■■■  ■  ■■■■■■   ■\n");
			printf("            ■      ■      ■   ■          ■     ■  ■■■■■■   ■\n");
			printf("            ■      ■      ■   ■          ■     ■       ■   ■\n");
			printf("            ■■■■■■■■    ■■■■■■■■■       ■■■ ■■■■       ■   ■\n");
			printf("                                       ■■■■■   ■  ■■■■■■   ■\n");
			printf("          ■■■■■■■■■■■■■■■■■■■■■■■■    ■■■ ■■■  ■  ■        ■\n");
			printf("               ■■           ■        ■■     ■  ■  ■        ■\n");
			printf("            ■■■■■■■■        ■            ■■■■■■   ■        ■\n");
			printf("                   ■    ■■■■■■■■■       ■■■  ■■■  ■■■■■■■■ ■\n");
			printf("            ■■■■■■■■    ■■     ■■       ■      ■           ■\n");
			printf("            ■           ■■     ■■       ■■    ■■           ■\n");
			printf("            ■■■■■■■■■   ■■■■■■■■■        ■■■■■■■           ■");
			Sleep(2000);
			system("cls");
			article(level);
			break;
		}
		system("cls");
		map[*y][*x] = CLEARSPACE;
		draw_map(map);
		return 0; //월급 획득 실패
	}
}
//return 값 수정 -> 1이면 성공, 0이면 실패
void article(int level)
{
	int mini_game_map[MAP_SIZE_H][MAP_SIZE_W];
	//미니게임 맵 생성
	for (int i = 0; i < MAP_SIZE_H; i++)
	{
		for (int j = 0; j < MAP_SIZE_W; j++)
		{
			if (i == 0 || i == MAP_SIZE_H - 1 || j == 0 || j == MAP_SIZE_W - 1)
				mini_game_map[i][j] = WALL;
			else if (i % 9 == 0)
				mini_game_map[i][j] = WALL;
			else
				mini_game_map[i][j] = CLEARSPACE;
		}
	}
	//map 그리기
	draw_map(mini_game_map);
	gotoxy(61, 1);
	printf("--------------");
	gotoxy(61, 8);
	printf("--------------");
	gotoxy(61, 10);
	printf("--------------");
	gotoxy(1, 0);
	printf("음료 ");
	textcolor(YELLOW);
	printf("(A키)");
	textcolor(WHITE);
	gotoxy(1, 9);
	printf("라면 ");
	textcolor(YELLOW);
	printf("(S키)");
	textcolor(WHITE);
	gotoxy(1, 18);
	printf("과자 ");
	textcolor(YELLOW);
	printf("(D키)");
	textcolor(WHITE);

	//game 시작
	char item;
	int ch, goal, score = 0;
	int a1 = 2, a2 = 3, a_c = 0;
	int b1 = 2, b2 = 11, b_c = 0;
	int c1 = 2, c2 = 20, c_c = 0;

	//level별 목표
	if (level == 0)
		goal = 5;
	else if (level == 1)
		goal = 7;
	else
		goal = 9;

	gotoxy(61, 22);
	printf("목표 점수: %2d", goal);
	gotoxy(61, 24);
	printf("현재 점수: %2d", score);
	gotoxy(61, 0);
	printf("남은 물품: %2d", 10);

	for (int i = 1; i <= 10; i++)
	{
		//10개 물품 랜덤으로 나오기
		item = rand() % 3;
		gotoxy(66, 2);
		switch (item)
		{
		case 0:
			printf("음료");
			gotoxy(64, 4);
			printf("        ");
			gotoxy(65, 4);
			printf(" ⢔⢆⡢⣢⠀");
			gotoxy(64, 5);
			printf("        ");
			gotoxy(65, 5);
			printf(" ⠑⡊⢞⢑⠀");
			gotoxy(64, 6);
			printf("        ");
			gotoxy(65, 6);
			printf(" ⡪⡣⣫⢗⠀");
			gotoxy(64, 7);
			printf("        ");
			gotoxy(65, 7);
			printf(" ⠨⠪⠎⠏⠀");
			break;
		case 1:
			printf("라면");
			gotoxy(64, 4);
			printf("        ");
			gotoxy(65, 4);
			printf("⢠⢰⡴⣖⢤⠄");
			gotoxy(64, 5);
			printf("        ");
			gotoxy(65, 5);
			printf(" ⢷⣻⡺⡷⠁");
			gotoxy(64, 6);
			printf("        ");
			gotoxy(65, 6);
			printf("⠀⢽⡳⣕⢟⠀");
			gotoxy(64, 7);
			printf("        ");
			gotoxy(65, 7);
			printf(" ⠘⠵⠭⠂⠀");
			break;
		case 2:
			printf("과자");
			gotoxy(64, 4);
			printf("⢀⡀⡀⡀⠀⠀⠀⠀");
			gotoxy(64, 5);
			printf("⢸⡍⡏⡯⢫⣏⢯⡁");
			gotoxy(64, 6);
			printf("⢸⣺⢒⡚⡜⣎⢷⡁");
			gotoxy(64, 7);
			printf("  ⠁⠉⠁⠃⠛⠀");
			break;
		}
		//키보드 a, s, d키 눌렀을 때
		do {
			ch = _getch();
			switch (ch) {
			case 'a':
				if (item == 0)
				{
					score++;
					gotoxy(a1 + a_c * 6, a2);
					printf(" ⢔⢆⡢⣢⠀");
					gotoxy(a1 + a_c * 6, a2 + 1);
					printf(" ⠑⡊⢞⢑⠀");
					gotoxy(a1 + a_c * 6, a2 + 2);
					printf(" ⡪⡣⣫⢗⠀");
					gotoxy(a1 + a_c * 6, a2 + 3);
					printf(" ⠨⠪⠎⠏⠀");
					gotoxy(a1 + a_c * 6 + 1, a2 + 4);
					printf("음료");
					gotoxy(62 + i, 9);
					textcolor(BLUE); //파란색 text
					printf("O ");
					a_c++;
				}
				else
				{
					gotoxy(62 + i, 9);
					textcolor(RED); //빨간색 text
					printf("X ");
				}
				break;
			case 's':
				if (item == 1)
				{
					score++;
					gotoxy(b1 + b_c * 6, b2);
					printf("⢠⢰⡴⣖⢤⠄");
					gotoxy(b1 + b_c * 6, b2 + 1);
					printf(" ⢷⣻⡺⡷⠁");
					gotoxy(b1 + b_c * 6, b2 + 2);
					printf("⠀⢽⡳⣕⢟⠀");
					gotoxy(b1 + b_c * 6, b2 + 3);
					printf(" ⠘⠵⠭⠂⠀");
					gotoxy(b1 + b_c * 6 + 1, b2 + 4);
					printf("라면");
					gotoxy(62 + i, 9);
					textcolor(BLUE); //파란색 text
					printf("O ");
					b_c++;
				}
				else
				{
					gotoxy(62 + i, 9);
					textcolor(RED); //빨간색 text
					printf("X ");
				}
				break;
			case 'd':
				if (item == 2)
				{
					score++;
					gotoxy(c1 + c_c * 6, c2);
					printf("⢀⡀⡀⡀⠀⠀⠀⠀");
					gotoxy(c1 + c_c * 6, c2 + 1);
					printf("⢸⡍⡏⡯⢫⣏⢯⡁");
					gotoxy(c1 + c_c * 6, c2 + 2);
					printf("⢸⣺⢒⡚⡜⣎⢷⡁");
					gotoxy(c1 + c_c * 6, c2 + 3);
					printf("  ⠁⠉⠁⠃⠛⠀");
					gotoxy(c1 + c_c * 6 + 1, c2 + 4);
					printf("과자");
					gotoxy(62 + i, 9);
					textcolor(BLUE); //파란색 text
					printf("O ");
					c_c++;
				}
				else
				{
					gotoxy(62 + i, 9);
					textcolor(RED); //빨간색 text
					printf("X ");
				}
				break;
			}
		} while (ch != 'a' && ch != 's' && ch != 'd');
		
		textcolor(WHITE); //흰색 text
		gotoxy(61, 22);
		printf("목표 점수: %2d", goal);
		gotoxy(61, 24);
		printf("현재 점수: %2d", score);
		gotoxy(61, 0);
		printf("남은 물품: %2d", 10 - i);
	}

	//지우기
	gotoxy(65, 2);
	printf("    ");
	gotoxy(64, 4);
	printf("        ");
	gotoxy(64, 5);
	printf("        ");
	gotoxy(64, 6);
	printf("        ");
	gotoxy(64, 7);
	printf("        ");
	
	Sleep(1500);
	//목표 성공
	if (goal <= score)
	{
		system("cls");
		printf("성공");
		Sleep(1000);
	}
	//목표 실패
	else
	{
		system("cls");
		printf("실패");
		Sleep(1000);
	}
}