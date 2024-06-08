#include "Game.h"

extern int boss_speed_level;   //*//

void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

int flag(int(*map)[MAP_SIZE_W], int* x, int* y, int level, int* money, char playName[])
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

        system("cls");
        int Money[MAP_SIZE_H][MAP_SIZE_W];
        //����
        for (int i = 0; i < MAP_SIZE_H; i++)
        {
            for (int j = 0; j < MAP_SIZE_W; j++)
            {
                if (i == 0 || i == MAP_SIZE_H - 1 || j == 0 || j == MAP_SIZE_W - 1)
                    Money[i][j] = WALL;
                else
                    Money[i][j] = CLEARSPACE;
            }
        }
        drawMap(Money);
        gotoxy(20, 2);
        printf("%10s�� ����", playName);
        gotoxy(23, 4);
        printf("1234-56-*******");
        gotoxy(22, 13);
        printf("���ѤѤѤѤѤѤѦ�\n");
        gotoxy(22, 14);
        printf("����������  ������\n");
        gotoxy(22, 15);
        printf("������  $$  ��  ��\n");
        gotoxy(22, 16);
        printf("�� ���� �� ���� ��\n");
        gotoxy(22, 17);
        printf("���ѤѤѤѤѤѤѦ�\n");
        gotoxy(18, 22);
        printf("%4d", *money);
        slow_print_money("������ �Աݵǿ����ϴ�", 30);
        Sleep(2000);
        system("cls");
        return 1; //���� ȹ�� ����
    }
    else
    {
        switch (map[*y][*x] % 5 + 1)
        {
        case 1:
            printf("���� ����");
            *money = *money - 10;
            Sleep(2000);
            system("cls");
            break;
        case 2:
            printf("���� ����");
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
            check = customer(level);
            if (check == 1)
                *money = *money + 10;
            else {
                *money = *money - 10;
                mini_game_fail_penalty();   // ������ �ӵ� ���� ���ο����� ...(IM)POSSIBLE ��ȯ Header ����
            }
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
                mini_game_fail_penalty();   // ������ �ӵ� ���� ���ο����� ...(IM)POSSIBLE ��ȯ Header ����
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
            printf("     ##           #        ##     #  #  #        #");
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
            else {   //*//
                *money = *money - 10;   //*//
                mini_game_fail_penalty();   // ������ �ӵ� ���� ���ο����� ...(IM)POSSIBLE ��ȯ Header ����
            }   //*//
            break;
        }
        system("cls");
        map[*y][*x] = CLEARSPACE;
        draw_map(map);
        return 0; //���� ȹ�� ����
    }
}

//return ��  -> 1�̸� ����, 0�̸� ����
int article(int level)
{
    int mini_game_map[MAP_SIZE_H][MAP_SIZE_W];
    //�̴ϰ��� �� ����
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
    //map �׸���
    drawMap(mini_game_map);
    gotoxy(61, 1);
    printf("--------------");
    gotoxy(61, 8);
    printf("--------------");
    gotoxy(61, 10);
    printf("--------------");
    gotoxy(1, 0);
    printf("Drink ");
    textcolor(YELLOW);
    printf("(A key)");
    textcolor(WHITE);
    gotoxy(1, 9);
    printf("Ramen ");
    textcolor(YELLOW);
    printf("(S key)");
    textcolor(WHITE);
    gotoxy(1, 18);
    printf("Snack ");
    textcolor(YELLOW);
    printf("(D key)");
    textcolor(WHITE);

    //game ����
    char item;
    int ch, goal, score = 0;
    int a1 = 2, a2 = 3, a_c = 0;
    int b1 = 2, b2 = 11, b_c = 0;
    int c1 = 2, c2 = 20, c_c = 0;

    //level�� ��ǥ
    if (level == 0)
        goal = 5;
    else if (level == 1)
        goal = 7;
    else
        goal = 9;

    gotoxy(61, 22);
    printf("��ǥ ����: %2d", goal);
    gotoxy(61, 24);
    printf("���� ����: %2d", score);
    gotoxy(61, 0);
    printf("���� ��ǰ: %2d", 10);

    for (int i = 1; i <= 10; i++)
    {
        //10�� ��ǰ �������� ������
        item = rand() % 3;
        gotoxy(66, 2);
        switch (item)
        {
        case 0:
            printf("Drink");
            gotoxy(64, 4);
            printf("        ");
            gotoxy(65, 4);
            printf(" ##### ");
            gotoxy(64, 5);
            printf("        ");
            gotoxy(65, 5);
            printf(" ##### ");
            gotoxy(64, 6);
            printf("        ");
            gotoxy(65, 6);
            printf(" ##### ");
            gotoxy(64, 7);
            printf("        ");
            gotoxy(65, 7);
            printf(" ##### ");
            break;
        case 1:
            printf("Ramen");
            gotoxy(64, 4);
            printf("        ");
            gotoxy(65, 4);
            printf("######");
            gotoxy(64, 5);
            printf("        ");
            gotoxy(65, 5);
            printf(" #### ");
            gotoxy(64, 6);
            printf("        ");
            gotoxy(65, 6);
            printf(" #### ");
            gotoxy(64, 7);
            printf("        ");
            gotoxy(65, 7);
            printf(" #### ");
            break;
        case 2:
            printf("Snack");
            gotoxy(64, 4);
            printf("####    ");
            gotoxy(64, 5);
            printf("########");
            gotoxy(64, 6);
            printf("########");
            gotoxy(64, 7);
            printf("   #####");
            break;
        }
        //Ű���� a, s, dŰ ������ ��
        do {
            ch = _getch();
            switch (ch) {
            case 'a':
                if (item == 0)
                {
                    score++;
                    gotoxy(a1 + a_c * 6, a2);
                    printf(" ##### ");
                    gotoxy(a1 + a_c * 6, a2 + 1);
                    printf(" ##### ");
                    gotoxy(a1 + a_c * 6, a2 + 2);
                    printf(" ##### ");
                    gotoxy(a1 + a_c * 6, a2 + 3);
                    printf(" ##### ");
                    gotoxy(a1 + a_c * 6 + 1, a2 + 4);
                    printf("Drink");
                    gotoxy(62 + i, 9);
                    textcolor(BLUE); //�Ķ��� text
                    printf("O ");
                    a_c++;
                }
                else
                {
                    gotoxy(62 + i, 9);
                    textcolor(RED); //������ text
                    printf("X ");
                }
                break;
            case 's':
                if (item == 1)
                {
                    score++;
                    gotoxy(b1 + b_c * 6, b2);
                    printf("######");
                    gotoxy(b1 + b_c * 6, b2 + 1);
                    printf(" #### ");
                    gotoxy(b1 + b_c * 6, b2 + 2);
                    printf(" #### ");
                    gotoxy(b1 + b_c * 6, b2 + 3);
                    printf(" #### ");
                    gotoxy(b1 + b_c * 6 + 1, b2 + 4);
                    printf("Ramen");
                    gotoxy(62 + i, 9);
                    textcolor(BLUE); //�Ķ��� text
                    printf("O ");
                    b_c++;
                }
                else
                {
                    gotoxy(62 + i, 9);
                    textcolor(RED); //������ text
                    printf("X ");
                }
                break;
            case 'd':
                if (item == 2)
                {
                    score++;
                    gotoxy(c1 + c_c * 6, c2);
                    printf("####    ");
                    gotoxy(c1 + c_c * 6, c2 + 1);
                    printf("########");
                    gotoxy(c1 + c_c * 6, c2 + 2);
                    printf("########");
                    gotoxy(c1 + c_c * 6, c2 + 3);
                    printf("   #####");
                    gotoxy(c1 + c_c * 6 + 1, c2 + 4);
                    printf("Snack");
                    gotoxy(62 + i, 9);
                    textcolor(BLUE); //�Ķ��� text
                    printf("O ");
                    c_c++;
                }
                else
                {
                    gotoxy(62 + i, 9);
                    textcolor(RED); //������ text
                    printf("X ");
                }
                break;
            }
        } while (ch != 'a' && ch != 's' && ch != 'd');

        textcolor(WHITE); //��� text
        gotoxy(61, 22);
        printf("��ǥ ����: %2d", goal);
        gotoxy(61, 24);
        printf("���� ����: %2d", score);
        gotoxy(61, 0);
        printf("���� ��ǰ: %2d", 10 - i);
    }

    //�����
    gotoxy(65, 2);
    printf("        ");
    gotoxy(64, 4);
    printf("        ");
    gotoxy(64, 5);
    printf("        ");
    gotoxy(64, 6);
    printf("        ");
    gotoxy(64, 7);
    printf("        ");

    Sleep(1500);
    //��ǥ ����
    if (goal <= score)
    {
        system("cls");
        gotoxy(10, 7);
        printf("   ##     #   ######### ");
        gotoxy(10, 8);
        printf("   ##     #          ## ");
        gotoxy(10, 9);
        printf("   ##  ####      #   ## ");
        gotoxy(10, 10);
        printf("   ###    #      #   ## ");
        gotoxy(10, 11);
        printf("  #####   #      #   #  ");
        gotoxy(10, 12);
        printf("###  ###  # ############");
        gotoxy(10, 13);
        printf("##        #             ");
        gotoxy(10, 14);
        printf("    ######     ######   ");
        gotoxy(10, 15);
        printf("   ###  ###   ########  ");
        gotoxy(10, 16);
        printf("   #      #   ##     ## ");
        gotoxy(10, 17);
        printf("   ##    ##   ##    ##  ");
        gotoxy(10, 18);
        printf("   ########    #######  ");
        Sleep(1000);
        return 1;
    }
    //��ǥ ����
    else
    {
        system("cls");
        gotoxy(10, 7);
        printf("    #     #          #  #");
        gotoxy(10, 8);
        printf("    #     #  ####### #  #");
        gotoxy(10, 9);
        printf("   ###    #    #  #  #  #");
        gotoxy(10, 10);
        printf("  #####   #    #  #  #  #");
        gotoxy(10, 11);
        printf(" ##  ###  #    #  #  ####");
        gotoxy(10, 12);
        printf("##     #  #    #  #  #  #");
        gotoxy(10, 13);
        printf("  #########    #  #  #  #");
        gotoxy(10, 14);
        printf("          #   ########  #");
        gotoxy(10, 15);
        printf("          #  #########  #");
        gotoxy(10, 16);
        printf("   ########          #  #");
        gotoxy(10, 17);
        printf("   #                 #  #");
        gotoxy(10, 18);
        printf("   ########          #  #");
        Sleep(1000);
        return 0;
    }
}

void setNumber(int(*map)[MAP_SIZE_W], int* num, int* x, int* y)
{
    *num = rand() % 9;  //�ù� ��ġ ����(���� ���� ���)
    *x = rand() % (MAP_SIZE_W - 2) + 1;
    *y = rand() % (MAP_SIZE_H - 2) + 1;

    map[*y][*x] = *num;
}

void drawMap(int(*map)[MAP_SIZE_W])
{
    gotoxy(0, 0);  // MAP��ġ �ʽ�ȭ
    for (int i = 0; i < MAP_SIZE_H; i++)
    {
        for (int j = 0; j < MAP_SIZE_W; j++)
        {
            if (map[i][j] == CLEARSPACE)
                printf(" ");
            else if (map[i][j] == WALL)
                printf("#");
            else
                printf("D"); //�ù� ���
        }
        printf("\n");
    }
}

void moveKey(int(*map)[MAP_SIZE_W], int* x, int* y)
{
    int ch;

    gotoxy(*x, *y);
    textcolor(YELLOW);
    printf("p\b");
    textcolor(WHITE);

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

int delivery(void)
{
    int g_map[MAP_SIZE_H][MAP_SIZE_W] = { 0 };
    int num, numX, numY;  //�ù� ��ġ
    int playerX = 25, playerY = 26; //����� ��ġ
    int score = 0;  // �� ���
    int targetScore = 6; //��ǥ ��
    int timer = TIMER;

    init(0);
    printf("�ù� ����\n");
    printf("������ �ð��� �ù踦 �޾ƾ� �մϴ�.");
    Sleep(3000);
    generate_map(g_map);

    while (score < targetScore)
    {
        setNumber(g_map, &num, &numX, &numY);

        DWORD start_time = GetTickCount();  //�ð� ���
        DWORD current_time;
        drawMap(g_map);

        gotoxy(MAP_SIZE_W + 1, 1);
        printf("���� �ð�");
        gotoxy(MAP_SIZE_W + 1, 2);
        printf("1~2��° �ù�: 9��");
        gotoxy(MAP_SIZE_W + 1, 3);
        printf("3~4��° �ù�: 7��");
        gotoxy(MAP_SIZE_W + 1, 4);
        printf("5~6��° �ù�: 5��");

        while (GetTickCount() - start_time < timer)  //����ϴ� �ù� �����ϴ� �ð�
        {
            current_time = GetTickCount();
            int r_time = timer - (current_time - start_time);
            if (r_time % 1000 == 0)
            {
                gotoxy(29, MAP_SIZE_H);
                printf("                    "); // Clear previous time display
                gotoxy(29, MAP_SIZE_H);
                printf("/���� �ð�: %2d s", r_time / 1000);
            }

            moveKey(g_map, &playerX, &playerY, &score, num);
            gotoxy(20, MAP_SIZE_H);
            printf("Score: %2d\n", score);

            if (playerX == numX && playerY == numY)
            {
                score++;
                g_map[numY][numX] = -2;  //ã���� �ù踦 �����

                break;
            }
        }

        if (GetTickCount() - start_time >= timer) {
            break;
        }

        g_map[numY][numX] = -2;  // ã���� �ù踦 �����

        if (score % 2 == 0 && score != 0)
        {
            timer -= 2000;
        }
    }

    system("cls");
    if (score == targetScore)
    {
        printf("�ù� ���� �ϼ�.");
        gotoxy(10, 7);
        printf("   ##     #   ######### ");
        gotoxy(10, 8);
        printf("   ##     #          ## ");
        gotoxy(10, 9);
        printf("   ##  ####      #   ## ");
        gotoxy(10, 10);
        printf("   ###    #      #   ## ");
        gotoxy(10, 11);
        printf("  #####   #      #   #  ");
        gotoxy(10, 12);
        printf("###  ###  # ############");
        gotoxy(10, 13);
        printf("##        #             ");
        gotoxy(10, 14);
        printf("    ######     ######   ");
        gotoxy(10, 15);
        printf("   ###  ###   ########  ");
        gotoxy(10, 16);
        printf("   #      #   ##     ## ");
        gotoxy(10, 17);
        printf("   ##    ##   ##    ##  ");
        gotoxy(10, 18);
        printf("   ########    #######  ");
        Sleep(1000);
        return 1;
    }
    else
    {
        printf("�ù� ���� ����.");
        gotoxy(10, 7);
        printf("    #     #          #  #");
        gotoxy(10, 8);
        printf("    #     #  ####### #  #");
        gotoxy(10, 9);
        printf("   ###    #    #  #  #  #");
        gotoxy(10, 10);
        printf("  #####   #    #  #  #  #");
        gotoxy(10, 11);
        printf(" ##  ###  #    #  #  ####");
        gotoxy(10, 12);
        printf("##     #  #    #  #  #  #");
        gotoxy(10, 13);
        printf("  #########    #  #  #  #");
        gotoxy(10, 14);
        printf("          #   ########  #");
        gotoxy(10, 15);
        printf("          #  #########  #");
        gotoxy(10, 16);
        printf("   ########          #  #");
        gotoxy(10, 17);
        printf("   #                 #  #");
        gotoxy(10, 18);
        printf("   ########          #  #");
        Sleep(1000);
        return 0;
    }

}

void draw_board() {
    system("cls");
    int mini_game_map[MAP_SIZE_H][MAP_SIZE_W];
    //�̴ϰ��� �� ����
    for (int i = 0; i < MAP_SIZE_H; i++)
    {
        for (int j = 0; j < MAP_SIZE_W; j++)
        {
            if (i == 0 || i == MAP_SIZE_H - 1 || j == 0 || j == MAP_SIZE_W - 1)
                mini_game_map[i][j] = WALL;
            else
                mini_game_map[i][j] = CLEARSPACE;
        }
    }
    //map �׸���
    drawMap(mini_game_map);
}
void draw_customer_map(Note notes[WIDTH][HEIGHT], int score, int count) {

    gotoxy(40, 1);
    printf("���� ����: %d\n", score);
    gotoxy(40, 2);
    printf("��ǥ ����: %d\n", count);
    gotoxy(1, 1);
    for (int i = 0; i < HEIGHT; i++) {
        gotoxy(1, i + 1);
        for (int j = 0; j < WIDTH; j++) {
            if (notes[j][i].active) {
                if (j == 0) {

                    printf("| ���� |");
                }
                if (j == 1) {
                    printf("| ��� |");
                }
                if (j == 2) {
                    printf("| ���� |");
                }
            }
            else {
                printf("|      |");
            }
        }
        printf("\n");
    }
    gotoxy(1, HEIGHT - 3);
    printf("------------------------");
    gotoxy(1, HEIGHT);
    printf("------------------------");
}

void generate_note(Note notes[WIDTH][HEIGHT]) {
    int random_key = rand() % WIDTH;
    notes[random_key][0].active = 1;
    notes[random_key][0].position = 0;
}
void update_notes(Note notes[WIDTH][HEIGHT]) {
    for (int j = 0; j < WIDTH; j++) {
        for (int i = HEIGHT - 1; i > 0; i--) {
            notes[j][i] = notes[j][i - 1];
        }
        notes[j][0].active = 0;
    }
}

int customer(int level)
{
    int NOTE_INTERVAL; // ��Ʈ ���� ����
    int speed, count_c;
    //game ����
    Note notes[WIDTH][HEIGHT] = { 0 };
    int score_s = 0;
    clock_t start_time = clock();
    clock_t current_time;
    clock_t last_note_time = start_time;
    time_t time_count_start, time_count_now;

    srand(time(NULL));
    system("cls");
    printf("���� ����\n");
    draw_board();

    //level�� ��ǥ
    if (level == 0) {
        speed = 10;
        count_c = 5;
    }
    else if (level == 1) {
        speed = 7;
        count_c = 10;
    }
    else {
        speed = 4;
        count_c = 20;
    }
    time_count_start = time(NULL);
    time_count_now = time(NULL);
    while ((current_time = clock()) < start_time + GAME_DURATION) {
        NOTE_INTERVAL = ((rand() % 3) + 1) * speed;
        int timer = GAME_DURATION;
        time_count_start = time(NULL);
        if ((current_time - last_note_time) >= NOTE_INTERVAL * CLOCKS_PER_SEC / 10) {
            generate_note(notes);
            last_note_time = current_time;
        }
        update_notes(notes);
        gotoxy(40, 3);
        printf("���� �ð�: %2d��", GAME_DURATION / 1000 + time_count_now - time_count_start);
        if (_kbhit()) {
            int key = _getch() - '0';
            if (key + '0' == ENTER)
                break;
            if (key >= 1 && key <= WIDTH) {
                if (notes[key - 1][HEIGHT - 1].active) {
                    score_s++;
                    notes[key - 1][HEIGHT - 1].active = 0;
                }
                else if (notes[key - 1][HEIGHT - 2].active) { // ������ ���� �� �ִ� ���� �߰�
                    score_s++;
                    notes[key - 1][HEIGHT - 2].active = 0;
                }
                else
                    printf("");
            }
        }
        draw_customer_map(notes, score_s, count_c);
        Sleep(300);
    }

    printf("���� ����! ���� ����: %d\n", score_s);
    //��ǥ ����
    if (count_c <= score_s)
    {
        system("cls");
        gotoxy(10, 7);
        printf("   ##     #   ######### ");
        gotoxy(10, 8);
        printf("   ##     #          ## ");
        gotoxy(10, 9);
        printf("   ##  ####      #   ## ");
        gotoxy(10, 10);
        printf("   ###    #      #   ## ");
        gotoxy(10, 11);
        printf("  #####   #      #   #  ");
        gotoxy(10, 12);
        printf("###  ###  # ############");
        gotoxy(10, 13);
        printf("##        #             ");
        gotoxy(10, 14);
        printf("    ######     ######   ");
        gotoxy(10, 15);
        printf("   ###  ###   ########  ");
        gotoxy(10, 16);
        printf("   #      #   ##     ## ");
        gotoxy(10, 17);
        printf("   ##    ##   ##    ##  ");
        gotoxy(10, 18);
        printf("   ########    #######  ");
        Sleep(1000);
        return 1;
    }
    //��ǥ ����
    else
    {
        system("cls");
        gotoxy(10, 7);
        printf("    #     #          #  #");
        gotoxy(10, 8);
        printf("    #     #  ####### #  #");
        gotoxy(10, 9);
        printf("   ###    #    #  #  #  #");
        gotoxy(10, 10);
        printf("  #####   #    #  #  #  #");
        gotoxy(10, 11);
        printf(" ##  ###  #    #  #  ####");
        gotoxy(10, 12);
        printf("##     #  #    #  #  #  #");
        gotoxy(10, 13);
        printf("  #########    #  #  #  #");
        gotoxy(10, 14);
        printf("          #   ########  #");
        gotoxy(10, 15);
        printf("          #  #########  #");
        gotoxy(10, 16);
        printf("   ########          #  #");
        gotoxy(10, 17);
        printf("   #                 #  #");
        gotoxy(10, 18);
        printf("   ########          #  #");
        Sleep(1000);
        return 0;
    }
}

int mini_game_fail_penalty() {   //*//
    if (boss_speed_level < MAX_BOSS_SPEED_LEVEL) {   //*//
        boss_speed_level++;   //*//
        return BOSS_SPEED_UP_POSSIBLE;   //*//
    }   //*//
    return BOSS_SPEED_UP_IMPOSSIBLE;   //*//
}   //*//