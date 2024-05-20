#include "Game.h"

//글씨 색 바꾸기

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

	do {
		x = 1, y = 1;
		start = start_screen();
		s_c = game_start(map, start, &x, &y);
	} while (s_c);
	
	return 0;
}
