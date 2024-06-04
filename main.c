#include "Game.h"

void init(int visible) // 커서 보이기 설정
{
    //마우스 커서 숨김
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = visible; // 1 볼 수 있음, 0 반대, visible 추가
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void slow_print(const char* str, int delay)   //글자 출력하는 속도 제어하는 함수
{
    while (*str)
    {  //공백 문자열인지 판단
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == '\r')
            {  //Enter키를 누르면 skip
                break;
            }
        }
        putchar(*str++);  //문자열을 하나씩 출력함
        Sleep(delay);
    }

    skip(); //skip후 전체 내용출력
}

int main(void)
{
    int start, s_c;
    int x = 1, y = 1; //사용자 위치
    int map[MAP_SIZE_H][MAP_SIZE_W]; //map
    char playName[NAMESIZE] = { NULL }; //사용자 이름

    init(0);

    //시드값 변경
    srand(time(NULL));

    //맨 처음 게임을 시작할때 스토리 넣기 (skip 되도록) -> 계약서에 이름 넣기 구현
    first_show(playName);

    do {
        x = 1, y = 1;
        start = start_screen(playName, NAMESIZE); //배열 인수 전달 추가
        s_c = game_start(map, start, &x, &y);
        if (s_c == 2)
        {
            s_c = game_start(map, 0, &x, &y);
        }
    } while (s_c);

    printf("\n\n\n");
    return 0;
}
