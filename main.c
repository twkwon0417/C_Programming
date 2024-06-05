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


int main(void)
{
    int start, s_c;
    int x = 1, y = 1; //사용자 위치
    int map[MAP_SIZE_H][MAP_SIZE_W]; //기본 map
    char playName[NAMESIZE] = { NULL }; //사용자 이름

    init(0);

    //시드값 변경
    srand(time(NULL));

    //맨 처음 게임을 시작할때 스토리 넣기 (skip 되도록) -> 계약서에 이름 넣기 구현
    char* str = "학비와 생활비를 충당하기 위해 편의점 알바를 시작하게 되는데...";
    slow_print(str, 20);
    Sleep(1000);
    system("cls");
    first_show(playName);

    do {
        x = 1, y = 1;
        start = start_screen(playName, NAMESIZE);
        s_c = game_start(map, start, &x, &y, playName);
        if (s_c == 2)
        {
            s_c = game_start(map, 0, &x, &y, playName);
        }
    } while (s_c);
    system("cls");
    printf("\n\n\n");
    return 0;
}

void slow_print(const char* str, int delay)   //글자 출력하는 속도 제어하는 함수
{
    while (*str)
    {  //공백 문자열인지 판단
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == ENTER)
            {  //Enter키를 누르면 skip
                fflush(stdout);
                break;
            }
        }
        putchar(*str++);  //문자열을 하나씩 출력함
        Sleep(delay);
    }
    if (delay == 30)
        skip(); //skip후 전체 내용출력
    else
        skip_f();
}

void slow_print_money(const char* str, int delay)   //글자 출력하는 속도 제어하는 함수
{
    while (*str)
    {
        putchar(*str++);  //문자열을 하나씩 출력함
        Sleep(delay);
    }
}
