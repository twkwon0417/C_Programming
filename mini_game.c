#include "Game.h"

extern int boss_frame;	//*//
int boss_frame_array[] = { 20, 15, 12, 10, 6, 5, 3 };	//*//
extern int boss_speed_level;	//*//

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

int flag(int(*map)[MAP_SIZE_W], int* x, int* y, int level, int* money)
{
	int check;
	system("cls");

	if (map[*y][*x] == 0)
	{
		gotoxy(10, 7);
		printf("  ######    ##   ##########       ####    ##     ########  ");
		gotoxy(10, 8);
		printf("  #    #    ##           ##     ########  ##     #         ");
		gotoxy(10, 9);
		printf("  #    #    ##           ##      ######   ##     #         ");
		gotoxy(10, 10);
		printf("  ######    ##           ##      #    #   ##     ########  ");
		gotoxy(10, 11);
		printf("##########  ##           #       ######   ##               ");
		gotoxy(10, 12);
		printf("      # #######  ############       ##     ##              ");
		gotoxy(10, 13);
		printf("     #      ##                  ############   ############");
		gotoxy(10, 14);
		printf("   #########      #      ##                                ");
		gotoxy(10, 15);
		printf("          ##      #      ##      ###########    #########  ");
		gotoxy(10, 16);
		printf("   #########      #########               #             #  ");
		gotoxy(10, 17);
		printf("   ##             #      ##               #             #  ");
		gotoxy(10, 18);
		printf("   ##########     #########               #             #  ");
		Sleep(2000);
		system("cls");
		map[*y][*x] = CLEARSPACE;

		//인터넷 뱅킹으로 돈 들어오는 아스키 아트 함수로 만들어 넣기

		return 1; //월급 획득 성공
	}
	else
	{
		switch (map[*y][*x] % 5 + 1)
		{
		case 1:
			printf("월급 감소");
			*money = *money - 10;
			Sleep(2000);
			system("cls");
			break;
		case 2:
			printf("월급 증가");
			*money = *money + 10;
			Sleep(2000);
			system("cls");
			break;
		case 3:
			gotoxy(10, 7);
			printf("     ##         #         #");
			gotoxy(10, 8);
			printf("     ##         #         #");
			gotoxy(10, 9);
			printf("    ####        #         #");
			gotoxy(10, 10);
			printf(" ###    ###     #         #");
			gotoxy(10, 11);
			printf("##   ##   ##    #         #");
			gotoxy(10, 12);
			printf("     ##         ########  #");
			gotoxy(10, 13);
			printf("############              #");
			gotoxy(10, 14);
			printf("  #              ##########");
			gotoxy(10, 15);
			printf("  ##             #        #");
			gotoxy(10, 16);
			printf("  ##             #        #");
			gotoxy(10, 17);
			printf("  ##             #        #");
			gotoxy(10, 18);
			printf("  #########      ##########");
			Sleep(2000);
			system("cls");

			break;
		case 4:
			gotoxy(10, 7);
			printf("#######    #  #   ##    ##  #  #");
			gotoxy(10, 8);
			printf("##         #  #   ##    ##  #  #");
			gotoxy(10, 9);
			printf("##         #  #   ##    ##  #  #");
			gotoxy(10, 10);
			printf("######     ####   ########  #  #");
			gotoxy(10, 11);
			printf("##         #  #   ##    ##  ####");
			gotoxy(10, 12);
			printf("##         #  #   ##    ##  #  #");
			gotoxy(10, 13);
			printf("########   #  #   ##    ##  #  #");
			gotoxy(10, 14);
			printf("                  ########  #  #");
			gotoxy(10, 15);
			printf("   ###########              #  #");
			gotoxy(10, 16);
			printf("            ##              #  #");
			gotoxy(10, 17);
			printf("            ##                 #");
			gotoxy(10, 18);
			printf("            ##                 ");
			Sleep(2000);
			system("cls");
			check = delivery();
			if (check == 1)
				*money = *money + 10;
			else {
				*money = *money - 10;
				mini_game_fail_penalty();	// 보스의 속도 증가 여부에따라 ...(IM)POSSIBLE 반환 Header 참고
			}
			break;
		case 5:
			gotoxy(10, 7);
			printf("  ########    #########     ######  #  #######   #");
			gotoxy(10, 8);
			printf("  #      #      #   #          #     #  ######   #");
			gotoxy(10, 9);
			printf("  #      #      #   #          #     #       #   #");
			gotoxy(10, 10);
			printf("  ########    #########       ### ####       #   #");
			gotoxy(10, 11);
			printf("                             #####   #  ######   #");
			gotoxy(10, 12);
			printf("########################    ### ###  #  #        #");
			gotoxy(10, 13);
			printf("     ■■           #        ##     #  #  #        #");
			gotoxy(10, 14);
			printf("  ########        #            ######   #        #");
			gotoxy(10, 15);
			printf("         #    #########       ###  ###  ######## #");
			gotoxy(10, 16);
			printf("  ########    ##     ##       #      #           #");
			gotoxy(10, 17);
			printf("  #           ##     ##       ##    ##           #");
			gotoxy(10, 18);
			printf("  #########   #########        #######           #");
			Sleep(2000);
			system("cls");
			check = article(level);
			if (check == 1)
				*money = *money + 10;
			else {	//*//
				*money = *money - 10;	//*//
				mini_game_fail_penalty();	// 보스의 속도 증가 여부에따라 ...(IM)POSSIBLE 반환 Header 참고
			}	//*//
			break;
		}
		system("cls");
		map[*y][*x] = CLEARSPACE;
		draw_map(map);
		return 0; //월급 획득 실패
	}
}
//return 값  -> 1이면 성공, 0이면 실패
int article(int level)
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
		gotoxy(10, 7);
		printf("   ■■     ■   ■■■■■■■■■ ");
		gotoxy(10, 8);
		printf("   ■■     ■          ■■ ");
		gotoxy(10, 9);
		printf("   ■■  ■■■■      ■   ■■ ");
		gotoxy(10, 10);
		printf("   ■■■    ■      ■   ■■ ");
		gotoxy(10, 11);
		printf("  ■■■■■   ■      ■   ■  ");
		gotoxy(10, 12);
		printf("■■■  ■■■  ■ ■■■■■■■■■■■■");
		gotoxy(10, 13);
		printf("■■        ■             ");
		gotoxy(10, 14);
		printf("    ■■■■■■     ■■■■■■   ");
		gotoxy(10, 15);
		printf("   ■■■  ■■■   ■■■■■■■■  ");
		gotoxy(10, 16);
		printf("   ■      ■   ■■     ■■ ");
		gotoxy(10, 17);
		printf("   ■■    ■■   ■■    ■■  ");
		gotoxy(10, 18);
		printf("   ■■■■■■■■    ■■■■■■■  ");
		Sleep(1000);
		return 1;
	}
	//목표 실패
	else
	{
		system("cls");
		gotoxy(10, 7);
		printf("    ■     ■          ■  ■");
		gotoxy(10, 8);
		printf("    ■     ■  ■■■■■■■ ■  ■");
		gotoxy(10, 9);
		printf("   ■■■    ■    ■  ■  ■  ■");
		gotoxy(10, 10);
		printf("  ■■■■■   ■    ■  ■  ■  ■");
		gotoxy(10, 11);
		printf(" ■■  ■■■  ■    ■  ■  ■■■■");
		gotoxy(10, 12);
		printf("■■     ■  ■    ■  ■  ■  ■");
		gotoxy(10, 13);
		printf("  ■■■■■■■■■    ■  ■  ■  ■");
		gotoxy(10, 14);
		printf("          ■   ■■■■■■■■  ■");
		gotoxy(10, 15);
		printf("          ■  ■■■■■■■■■  ■");
		gotoxy(10, 16);
		printf("   ■■■■■■■■          ■  ■");
		gotoxy(10, 17);
		printf("   ■                 ■  ■");
		gotoxy(10, 18);
		printf("   ■■■■■■■■          ■  ■");
		Sleep(1000);
		return 0;
	}
}

int delivery(void)
{
	int g_map[MAP_SIZE_H][MAP_SIZE_W] = { 0 };
	int num, numX, numY;  //택배 위치
	int playerX = 25, playerY = 26; //사용자 위치
	int score = 0;  // 점 기록
	int targetScore = 6; //목표 점
	int timer = TIMER;

	init(0);
	printf("택배 정리\n");
	printf("규정한 시간에 택배를 받아야 합니다.");
	Sleep(3000);
	gameMap(g_map);

	while (score < targetScore)
	{
		setNumber(g_map, &num, &numX, &numY);

		DWORD start_time = GetTickCount();  //시간 기록
		DWORD current_time;
		drawMap(g_map, score);

		//drawMap(g_map, r_time, score); 

		while (GetTickCount() - start_time < timer)  //출력하는 택배 유지하는 시간
		{
			current_time = GetTickCount();
			int r_time = timer - (current_time - start_time);
			if (r_time % 1000 == 0)
			{
				gotoxy(29, MAP_SIZE_H);
				printf("                    "); // Clear previous time display
				gotoxy(29, MAP_SIZE_H);
				printf("/남은 시간: %2d s", r_time / 1000);
			}

			moveKey(g_map, &playerX, &playerY, &score, num);
			gotoxy(20, MAP_SIZE_H);
			printf("Score: %2d\n", score);

			if (playerX == numX && playerY == numY)
			{
				score++;
				g_map[numY][numX] = -2;  //찾았은 택배를 지우기

				break;
			}
		}

		if (GetTickCount() - start_time >= timer) {
			break;
		}

		g_map[numY][numX] = -2;  // 찾았은 택배를 지우기

		if (score % 2 == 0 && score != 0)
		{
			timer -= 2000;
		}
	}

	system("cls");
	if (score == targetScore)
	{
		printf("택배 정리 완성.");
		Sleep(1000);
		return 1;
	}
	else
	{
		printf("택배 정리 실패.");
		Sleep(1000);
		return 0;
	}

}

void gameMap(int(*map)[MAP_SIZE_W])
{
	for (int i = 0; i < MAP_SIZE_H; i++)
	{
		for (int j = 0; j < MAP_SIZE_W; j++)
		{
			if (i == 0 || j == MAP_SIZE_W - 1 || j == 0 || i == MAP_SIZE_H - 1)
				map[i][j] = -1;
			else
				map[i][j] = -2;
		}
	}
}

void drawMap(int(*map)[MAP_SIZE_W], int remaining_time)
{
	gotoxy(0, 0);  // MAP위치 초시화
	for (int i = 0; i < MAP_SIZE_H; i++)
	{
		for (int j = 0; j < MAP_SIZE_W; j++)
		{
			if (map[i][j] == -2)
				printf(" ");
			else if (map[i][j] == -1)
				printf("#");
			else
				printf("□"); //택배 출력
		}
		printf("\n");
	}
}

void setNumber(int(*map)[MAP_SIZE_W], int* num, int* x, int* y)
{
	*num = rand() % 9;  //택배 위치 설정(원래 숫자 출력)
	*x = rand() % (MAP_SIZE_W - 2) + 1;
	*y = rand() % (MAP_SIZE_H - 2) + 1;

	map[*y][*x] = *num;
}

void moveKey(int(*map)[MAP_SIZE_W], int* x, int* y)
{
	int ch;

	gotoxy(*x, *y);
	printf("◆\b");

	if (_kbhit())
	{
		ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			printf(" \b");
			switch (ch)
			{
			case UP:
				if (*y > 1 && map[*y - 1][*x] != -1)
					(*y)--;
				break;
			case DOWN:
				if (*y < MAP_SIZE_H - 2 && map[*y + 1][*x] != -1)
					(*y)++;
				break;
			case LEFT:
				if (*x > 1 && map[*y][*x - 1] != -1)
					(*x)--;
				break;
			case RIGHT:
				if (*x < MAP_SIZE_W - 2 && map[*y][*x + 1] != -1)
					(*x)++;
				break;
			default:
				break;
			}
		}
	}
}

int mini_game_fail_penalty() {	//*//
	if (boss_speed_level < MAX_BOSS_SPEED_LEVEL) {	//*//
		boss_speed_level++;	//*//
		boss_frame = *(boss_frame_array + boss_speed_level);	//*//
		return BOSS_SPEED_UP_POSSIBLE;	//*//
	}	//*//
	return BOSS_SPEED_UP_IMPOSSIBLE;	//*//
}	//*//
