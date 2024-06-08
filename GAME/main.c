#include "Game.h"

void init(int visible) // Ŀ�� ���̱� ����
{
    //���콺 Ŀ�� ����
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = visible; // 1 �� �� ����, 0 �ݴ�, visible �߰�
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

int main(void)
{
    int start, s_c;
    int x = 1, y = 1; //����� ��ġ
    int map[MAP_SIZE_H][MAP_SIZE_W]; //�⺻ map
    char playName[NAMESIZE] = { NULL }; //����� �̸�

    init(0);

    //�õ尪 ����
    srand(time(NULL));

    //�� ó�� ������ �����Ҷ� ���丮 �ֱ� (skip �ǵ���) -> ��༭�� �̸� �ֱ� ����
    char* str = "�к�� ��Ȱ�� ����ϱ� ���� ������ �˹ٸ� �����ϰ� �Ǵµ�...";
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
    printf("���� ����");
    printf("\n\n\n\n\n\n");
    return 0;
}

void slow_print(const char* str, int delay)   //���� ����ϴ� �ӵ� �����ϴ� �Լ�
{
    while (*str)
    {  //���� ���ڿ����� �Ǵ�
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == ENTER)
            {  //EnterŰ�� ������ skip
                fflush(stdout);
                break;
            }
        }
        putchar(*str++);  //���ڿ��� �ϳ��� �����
        Sleep(delay);
    }
    if (delay == 30)
        skip(); //skip�� ��ü �������
    else
        skip_f();
}

void slow_print_money(const char* str, int delay)   //���� ����ϴ� �ӵ� �����ϴ� �Լ�
{
    while (*str)
    {
        putchar(*str++);  //���ڿ��� �ϳ��� �����
        Sleep(delay);
    }
}