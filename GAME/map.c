#include "Game.h"

int boss_speed_array[] = { 20, 15, 12, 10, 6, 5, 3 };   //*//
int boss_speed_level = 0;   //*//

int boss_y = 26;
int boss_x = 58;

void gotoxy(int x, int y)
{
    COORD Cur = { x,y };
    // Ŀ���� �̵����ִ� �Լ�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//���� ȭ��
int start_screen(char pn[], int n)
{
    int x = M_W;
    int y = M_H;
    system("cls");
    printf("  ######     ######      ######     ######            \n");
    printf("  #               #      #               #            \n");
    printf("  ######          #      ######          #            \n");
    printf("            ########               ########           \n");
    printf(" #######    #           #######    #                  \n");
    printf("    #       #              #       #                  \n");
    printf("    #       #######        #       #######            \n\n");
    printf(" ######   #     ##    #   #####   #         ##    #    #   #   #\n");
    printf("  #  #   ##   #    #  #     #    ##       #    #  ##   #####   #\n");
    printf(" ######  ##     ##    #   #   #   #         ##    #    #   #   ###\n");
    printf("          #           #    ########         #######    #####   #\n");
    printf("  #           ####### #    #      #         #######            #\n");
    printf("  ########            #    ########         #######            #");

    gotoxy(x - 2, y);
    printf("> ���� ����");
    gotoxy(x, y + 1);
    printf("���� ����");
    gotoxy(x, y + 2);
    printf("���� ����");
    gotoxy(24, 20);
    printf("���� player: %s", pn);


    do {
        int ch = _getch();
        if (ch == ENTER || ch == SPACE)
            return y - M_H;
        if (ch == 224) {
            ch = _getch();
            printf(" \b");
            switch (ch) {
                //y��ǥ�� �ִ� M_H���� M_H++2
            case UP: //Ű���� UP
                if (y > M_H) {
                    gotoxy(x - 2, y);
                    printf(" ");
                    gotoxy(x - 2, --y);
                    printf(">");
                }
                break;
            case DOWN: //Ű���� DOWN
                if (y < M_H + 2) {
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

//�� ����
int menu(void)
{
    int x = M_W;
    int y = M_H;
    system("cls");
    gotoxy(0, y - 8);
    printf("                      [���̵� ����]\n\n");

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
            return y - M_H;
        if (ch == 224) {
            ch = _getch();
            printf(" \b");
            switch (ch) {
                //y��ǥ�� �ִ� M_H���� M_H+3
            case UP: //Ű���� UP
                if (y > M_H) {
                    gotoxy(x - 2, y);
                    printf(" ");
                    gotoxy(x - 2, --y);
                    printf(">");
                }
                break;
            case DOWN: //Ű���� DOWN
                if (y < M_H + 3) {
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

//���� ��
int rule(void)
{
    int contract[MAP_SIZE_H][MAP_SIZE_W];
    generate_map(contract);
    drawMap(contract);

    gotoxy(1, 0);
    printf("��༭(���� ����)");
    gotoxy(2, 3);
    printf("1. �ð� �ȿ� ������ ������ ã�ƶ�.");
    gotoxy(2, 6);
    printf("2. 3������ �̴ϰ���");
    gotoxy(2, 7);
    printf("\t- ��ǥ ���� �̻� ȹ�� ����: ���� 10���� ����");
    gotoxy(2, 8);
    printf("\t- ��ǥ ���� �̻� ȹ�� ����: ���� 10���� ����");
    gotoxy(2, 9);
    printf("\t\t\t\t    ����� �ӵ� ����");
    gotoxy(2, 11);
    printf("2-1. ��ǰ����: A, S, DŰ�� ����Ͽ� ��ǰ�� �˸��� ĭ��");
    gotoxy(2, 12);
    printf("               �־��.");
    gotoxy(2, 14);
    printf("2-2. �մ�    : 1, 2, 3Ű�� ����Ͽ� ��ǰ�� ĭ�� ������");
    gotoxy(2, 15);
    printf("               �˸��� Ű�� ������.(������� ����)");
    gotoxy(2, 17);
    printf("2-3. �ù�����: ����Ű�� ����Ͽ� ���ѽð� �ȿ� �ù� D��");
    gotoxy(2, 18);
    printf("               �޾ƶ�.");

    int x = M_W;
    int y = M_H + 7;
    gotoxy(x - 2, y);
    printf("> back");  //return -1
    gotoxy(x, y + 1);
    printf("���� ����"); //return -2

    do {
        int ch = _getch();
        if (ch == ENTER || ch == SPACE)
            return y - M_H - 7;
        if (ch == 224) {
            ch = _getch();
            printf(" \b");
            switch (ch) {
                //y��ǥ�� �ִ� M_H���� M_H+1
            case UP: //Ű���� UP
                if (y > M_H + 7) {
                    gotoxy(x - 2, y);
                    printf(" ");
                    gotoxy(x - 2, --y);
                    printf(">");
                }
                break;
            case DOWN: //Ű���� DOWN
                if (y < M_H + 8) {
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

//�⺻ �� ����
void generate_map(int(*map)[MAP_SIZE_W])
{
    for (int i = 0; i < MAP_SIZE_H; i++)
    {
        for (int j = 0; j < MAP_SIZE_W; j++)
        {
            if (i == 0 || i == MAP_SIZE_H - 1 || j == 0 || j == MAP_SIZE_W - 1)
                map[i][j] = WALL; //�� ����
            else
                map[i][j] = CLEARSPACE; //�����
        }
    }
}

//�� ���� �� ����
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

//level���� �� ����
void level_map(int(*map)[MAP_SIZE_W], int level)
{
    int h, w;

    if (level == 0) //EASY(5) ����
    {
        //�� ���� ���(��) ����
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
    else if (level == 1) //NOMAL(7) ����
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
    else if (level == 2) //HARD(9) ����
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
    gotoxy(0, 0);
    //map �׸���
    for (int i = 0; i < MAP_SIZE_H; i++)
    {
        for (int j = 0; j < MAP_SIZE_W; j++)
        {
            char temp = map[i][j];
            if (temp == CLEARSPACE)
                printf(" ");
            else if (temp == WALL) //-1�� ��
                printf("#");
            else if (temp == BLOCK)
            {
                textcolor(DARKRED);
                printf("#");
                textcolor(WHITE);
            }
            else //-1�� -2 ������ ���� ���
                printf("O");
        }
        printf("\n");
    }
    gotoxy(61, 19);
    printf("Boss Speed %d", boss_speed_level + 1);
    gotoxy(61, 20);
    printf("");
    for (int i = 0; i < boss_speed_level + 1; i++) {
        printf("�� ");
    }
    if (boss_speed_level == 6) {
        printf("!!MAX!!");
    }
}

int pause(void)
{
    int x = M_W;
    int y = M_H;
    system("cls");
    gotoxy(0, y - 8);
    printf("                         [�Ͻ� ����]\n\n");

    gotoxy(x - 2, y);
    printf("> �̾� �ϱ�");  //return -1
    gotoxy(x, y + 1);
    printf("���� �޴�"); //return -2
    gotoxy(x, y + 2);
    printf("���� ����"); //return -3

    do {
        int ch = _getch();
        if (ch == ENTER || ch == SPACE)
            return y - M_H;
        if (ch == 224) {
            ch = _getch();
            printf(" \b");
            switch (ch) {
                //y��ǥ�� �ִ� M_H���� M_H+2
            case UP: //Ű���� UP
                if (y > M_H) {
                    gotoxy(x - 2, y);
                    printf(" ");
                    gotoxy(x - 2, --y);
                    printf(">");
                }
                break;
            case DOWN: //Ű���� DOWN
                if (y < M_H + 2) {
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

void first_show(char name[])
{
    char* str = "��༭(���� ����)        EnterŰ�� ������ skip\n\n\n \\
        1. �ð� �ȿ� ������ ������ ã�ƶ�.\n\n\n \\
        2. 3������ �̴ϰ���\n   \\
        - ��ǥ ���� �̻� ȹ�� ���� : ���� 10���� ����\n \\
        - ��ǥ ���� �̻� ȹ�� ���� : ���� 10���� ����, ����� �ӵ� ����\n\n\\
        2 - 1. ��ǰ����: A, S, DŰ�� ����Ͽ� ��ǰ�� �˸��� ĭ��\n\\
        \t\t �־��.\n\n\\
        2 - 2. �մ�    : 1, 2, 3Ű�� ����Ͽ� ��ǰ�� ĭ�� ������\n\\
        \t\t �˸��� Ű�� ������.(������� ����)\n\n\\
        2 - 3. �ù�����: ����Ű�� ����Ͽ� ���ѽð� �ȿ� �ù� D��\n\\
        \t\t �޾ƶ�.\n\n\\
        Ȯ���� �Ŀ� �����ϼ���.\n\\
        player ���� : ";
        slow_print(str, 30);
    init(1); //Ŀ�� �� ���̱�
    fgets(name, NAMESIZE, stdin);
    name[strcspn(name, "\n")] = '\0';
    init(0);
}

void skip()
{
    system("cls");   //skip�� ��ü �������
    printf("��༭(���� ����)\n\n\n\\
        1. �ð� �ȿ� ������ ������ ã�ƶ�.\n\n\n\\
        2. 3������ �̴ϰ���\n\\
        - ��ǥ ���� �̻� ȹ�� ���� : ���� 10���� ����\n\\
        - ��ǥ ���� �̻� ȹ�� ���� : ���� 10���� ����, ����� �ӵ� ����\n\n\\
        2 - 1. ��ǰ����: A, S, DŰ�� ����Ͽ� ��ǰ�� �˸��� ĭ��\n\\
        \t\t �־��.\n\n\\
        2 - 2. �մ�    : 1, 2, 3Ű�� ����Ͽ� ��ǰ�� ĭ�� ������\n\\
        \t\t �˸��� Ű�� ������.(������� ����)\n\n\\
        2 - 3. �ù�����: ����Ű�� ����Ͽ� ���ѽð� �ȿ� �ù� D��\n\\
        \t\t �޾ƶ�.\n\n\\
        Ȯ���� �Ŀ� �����ϼ���.\n\\
        player ���� : ");
}

void skip_f()
{
    system("cls");   //skip�� ��ü �������
    printf("�к�� ��Ȱ�� ����ϱ� ���� ������ �˹ٸ� �����ϰ� �Ǵµ�...");
}

//�� �ȿ��� �����̱�
int move_key(int(*map)[MAP_SIZE_W], int* x, int* y, int level, int* money, char playName[])
{
    Sleep(1000 / FRAME);  // ȭ���� 1�ʸ��� 60�� ������Ʈ �ȴ�.
    int ch, f, stop;

    gotoxy(*x, *y);
    textcolor(YELLOW);
    printf("p\b");
    textcolor(WHITE);
    if (_kbhit())
    {
        ch = _getch();
        //ESC �������� �Ͻ�����
        if (ch == ESC)
        {
            stop = pause();
            //�̾��ϱ�
            if (stop == 0)
                return stop - 1; //return -1
            //���θ޴���
            else if (stop == 1)
                return stop - 3; //return -2
            //��������
            else if (stop == 2)
                return stop - 5; //return -3
        }
        if (ch == 224) {
            ch = _getch();
            printf(" \b");
            switch (ch) {
            case UP:
                if (map[(*y) - 1][*x] == CLEARSPACE)
                {
                    (*y)--;
                    return GARBAGE;
                }
                else if (map[(*y) - 1][*x] == WALL || map[(*y) - 1][*x] == BLOCK) //��
                    return GARBAGE;
                else
                {
                    (*y)--;
                    f = flag(map, x, y, level, money, playName);
                    (*y)++;
                    return f;
                }
                break;
            case DOWN:
                if (map[(*y) + 1][*x] == CLEARSPACE)
                {
                    (*y)++;
                    return GARBAGE;
                }
                else if (map[(*y) + 1][*x] == WALL || map[(*y) + 1][*x] == BLOCK)
                    return GARBAGE;
                else
                {
                    (*y)++;
                    f = flag(map, x, y, level, money, playName);
                    (*y)--;
                    return f;
                }
                break;
            case LEFT:
                if (map[*y][(*x) - 1] == CLEARSPACE)
                {
                    (*x)--;
                    return GARBAGE;
                }
                else if (map[*y][(*x) - 1] == WALL || map[*y][(*x) - 1] == BLOCK)
                    return GARBAGE;
                else
                {
                    (*x)--;
                    f = flag(map, x, y, level, money, playName);
                    (*x)++;
                    return f;
                }
                break;
            case RIGHT:
                if (map[*y][(*x) + 1] == CLEARSPACE)
                {
                    (*x)++;
                    return GARBAGE;
                }
                else if (map[*y][(*x) + 1] == WALL || map[*y][(*x) + 1] == BLOCK)
                    return GARBAGE;
                else
                {
                    (*x)++;
                    f = flag(map, x, y, level, money, playName);
                    (*x)--;
                    return f;
                }
                break;
            }
        }
        return GARBAGE;
    }
    return GARBAGE;
}

int game_start(int(*map)[MAP_SIZE_W], int start, int* x, int* y, char playName[])
{
    int item, level, ch;
    int money = 100; //�ʱ� ����
    int frame_cnt = 0;
    int time_taken = 0;
    boss_speed_level = 0;

    if (start == 0)
    {
        level = menu();

        if (level == 3)
            return 1; //��ȯ�� 1�̸� ����ȭ������

        generate_map(map);
        system("cls");
        level_map(map, level);
        draw_map(map);

        while (1) {
            item = move_key(map, x, y, level, &money, playName);

            frame_cnt++;
            if (frame_cnt == 61) {   // TODO:not sure if it iterates 60 time and resetted
                frame_cnt = 1;
                time_taken++;
            }
            // how boss moves
            if (frame_cnt % boss_speed_array[boss_speed_level] == 0) {
                draw_boss(map, y, x);
            }
            if (check_caught(y, x) == PLAYER_CAUGHT) {
                draw_map(map);
            }
            //Ÿ�̸�
            gotoxy(61, 1);
            printf("�����ð�");
            gotoxy(62, 2);   //*//
            gotoxy(62, 2);   //*//
            printf("%4d", TIME_LIMIT - time_taken);   //*//
            if (TIME_LIMIT - time_taken <= 0) {   //*//   �ð� �ʰ��� ����
                //printf�� �ð� ���� �˷��ֱ�
                system("cls");
                gotoxy(9, 8);
                printf("######   ######   ##   ##  #######             ###    ##   ##  #######  ######\n");
                gotoxy(9, 9);
                printf("  ##       ##     ##   ##  ##                 ## ##   ##   ##  ##       ##   ##\n");
                gotoxy(9, 10);
                printf("  ##       ##     ### ###  ##                ##   ##  ##   ##  ##       ##   ##\n");
                gotoxy(9, 11);
                printf("  ##       ##     ## # ##  #####             ##   ##   ## ##   #####    ######\n");
                gotoxy(9, 12);
                printf("  ##       ##     ## # ##  ##                ##   ##   ## ##   ##       ## ##\n");
                gotoxy(9, 13);
                printf("  ##       ##     ##   ##  ##                 ## ##     ###    ##       ##  ##\n");
                gotoxy(9, 14);
                printf("  ##     ######   ##   ##  #######             ###      ###    #######  ##   ##\n");
                Sleep(2000);
                return 1;   //*//
            }   //*//

            if (money >= 0)
            {
                gotoxy(61, 22);
                printf("����: %4d����", money);
            }
            else
                money = 0;

            //ESC ������ �� �Ͻ�����
            //return -1: �̾��ϱ�
            if (item == -1)
            {
                system("cls");
                draw_map(map);
            }
            //return -2: ���θ޴���
            else if (item == -2)
            {
                return 1;
            }
            //return -3: ���� ����
            else if (item == -3)
            {
                return 0;
            }


            if (item == 1)
            {
                if (level == 2)
                {
                    system("cls");
                    gotoxy(25, 10);
                    printf("######  ##   ##  #####");
                    gotoxy(25, 11);
                    printf("##      ###  ##  ##  ##");
                    gotoxy(25, 12);
                    printf("##      #### ##  ##   ##");
                    gotoxy(25, 13);
                    printf("#####   #######  ##   ##");
                    gotoxy(25, 14);
                    printf("##      ## ####  ##   ##");
                    gotoxy(25, 15);
                    printf("##      ##  ###  ##  ##");
                    gotoxy(25, 16);
                    printf("######  ##   ##  #####");

                    Sleep(2000);
                    return 1; //��ȯ�� 1�̸� ����ȭ������
                }
                else if (level == 0 || level == 1)
                {
                    system("cls");
                    gotoxy(9, 8);
                    printf("##       ######  ##   ##   ######   ##           ##   ##  ######   ");
                    gotoxy(9, 9);
                    printf("##       ##      ##   ##   ##       ##           ##   ##  ##   ##");
                    gotoxy(9, 10);
                    printf("##       ##      ##   ##   ##       ##           ##   ##  ##   ##");
                    gotoxy(9, 11);
                    printf("##       #####   ### ###   #####    ##           ##   ##  ##   ##");
                    gotoxy(9, 12);
                    printf("##       ##       #####    ##       ##           ##   ##  ######");
                    gotoxy(9, 13);
                    printf("##       ##        ###     ##       ##           ##   ##  ##");
                    gotoxy(9, 14);
                    printf("######   ######     #      ######   ######        #####   ##");

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
        //���� �� ����(��༭)
        system("cls");
        int r;
        r = rule();
        if (r == 0)
        {
            return 1; //���� �޴���(�ڷ� ����)
        }
        else
            return 2; //���� ����

    }
    else
    {
        return 0; //��ȯ�� 0�̸� ����
    }
}

void move_boss(int(*map)[MAP_SIZE_W], int* player_y, int* player_x) {
    // based on player
    int diff_y = *player_y - boss_y;
    int diff_x = *player_x - boss_x;

    int abs_diff_y = abs(diff_y);
    int abs_diff_x = abs(diff_x);

    // ���̰� ũ�� ���� ���� ���� �����ϲ���
    if (abs_diff_y > abs_diff_x) {
        if (diff_y > 0) {
            boss_y++;
        }
        else {
            boss_y--;
        }
    }
    else {
        if (diff_x > 0) {
            boss_x++;
        }
        else {
            boss_x--;
        }
    }
}

void draw_boss(int(*map)[MAP_SIZE_W], int* player_y, int* player_x) {
    gotoxy(boss_x, boss_y);
    if (map[boss_y][boss_x] != -2) {
        gotoxy(0, 0);
        draw_map(map);
    }
    printf(" \b");
    move_boss(map, player_y, player_x);
    gotoxy(boss_x, boss_y);
    printf("B\b");
}

int check_caught(int* y, int* x) {   // not yet added to where it supposed to be
    if (*x == boss_x && *y == boss_y) {   //*//
        if (boss_x == 1 && boss_y == 1) {   //*//
            *x = 58;   //*//
            *y = 26;
        }   //*//
        else {   //*//
            *x = 1;   //*//
            *y = 1;   //*//
        }   //*//
        system("cls");
        gotoxy(25, 8);
        printf("     .-""""""-.");
        gotoxy(25, 9);
        printf("   .'����   / / '.");
        gotoxy(25, 10);
        printf("  /   O      O   ��");
        gotoxy(25, 11);
        printf(" :                :");
        gotoxy(25, 12);
        printf(" |                |  ");
        gotoxy(25, 13);
        printf(" :       __       :");
        gotoxy(25, 14);
        printf(" ��  .-\"\`  `\"-.  /");
        gotoxy(25, 15);
        printf("   '.          .'");
        gotoxy(25, 16);
        printf("     '-......-'");


        Sleep(1500);
        return PLAYER_CAUGHT;////////////////////
    }
    //*//
}