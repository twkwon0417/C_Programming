#include "Game.h"

void init(void)
{
	//마우스 커서 숨김
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

int main(void)
{
	int start, s_c;
	int x = 1, y = 1; //사용자 위치
	int map[MAP_SIZE_H][MAP_SIZE_W]; //map

	init();
	
	//시드값 변경
	srand(time(NULL));

	//맨 처음 게임을 시작할때 스토리 넣기 (skip 되도록) -> 계약서에 이름 넣기 구현

	do {
		x = 1, y = 1;
		start = start_screen();
		s_c = game_start(map, start, &x, &y);
		if (s_c == 2)
		{
			s_c = game_start(map, 0, &x, &y);
		}
	} while (s_c);
	
	printf("\n\n\n");
	return 0;
}
