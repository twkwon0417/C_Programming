#include "Game.h"

int frame_cnt = 0;  // which frame are we in, In 60frames   // could
int boss_speed_array[] = { 20, 15, 12, 10, 6, 5, 3 };   //*//
int boss_speed_level = 0;   //*//
int boss_frame = 20;   //*//

int boss_y = 20;
int boss_x = 20;

int time_taken = 0;

void move_boss(int(*map)[MAP_SIZE_W], int* player_y, int* player_x) {
    // based on player
    int diff_y = *player_y - boss_y;
    int diff_x = *player_x - boss_x;

    int abs_diff_y = abs(diff_y);
    int abs_diff_x = abs(diff_x);

    // 차이가 크게 나는 쪽을 먼저 움직일꺼야
    if (map[boss_y + 1][boss_x] == -2 && map[boss_y][boss_x + 1] == -2 && map[boss_y - 1][boss_x] == -2 && map[boss_y][boss_x - 1] == -2)
    {
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
    if (map[boss_y + 1][boss_x] == -2)
    {
        boss_y++;
    }
    if (map[boss_y][boss_x + 1] == -2)
    {
        boss_x++;
    }
    if (map[boss_y - 1][boss_x] == -2)
    {
        boss_y--;
    }
    if (map[boss_y][boss_x - 1] == -2)
    {
        boss_x--;
    }
}
void draw_boss(int(*map)[MAP_SIZE_W], int* player_y, int* player_x) {
    printf(" \b");
    move_boss(map, player_y, player_x);
    gotoxy(boss_x, boss_y);
    printf("B\b");
}

int check_caught(int* player_y, int* player_x) {   // not yet added to where it supposed to be
    if (*player_y == boss_y && *player_x == boss_x) {
        return 0;   // should be defined int meaning game has ended
    }
}

void gotoxy(int x, int y)
{
    COORD Cur = { x,y };
    // 커서를 이동해주는 함수
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//시작 화면
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
    printf("> 게임 시작");
    gotoxy(x, y + 1);
    printf("게임 설명");
    gotoxy(x, y + 2);
    printf("게임 종료");
    gotoxy(24, 20);
    printf("현재 player: %s", pn);


    do {
        int ch = _getch();
        if (ch == ENTER || ch == SPACE)
            return y - M_H;
        if (ch == 224) {
            ch = _getch();
            printf(" \b");
            switch (ch) {
                //y좌표는 최대 M_H에서 M_H++2
                case UP: //키보드 UP
                    if (y > M_H) {
                        gotoxy(x - 2, y);
                        printf(" ");
                        gotoxy(x - 2, --y);
                        printf(">");
                    }
                    break;
                case DOWN: //키보드 DOWN
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

//맵 선택
int menu(void)
{
    int x = M_W;
    int y = M_H;
    system("cls");
    gotoxy(0, y - 8);
    printf("                      [난이도 선택]\n\n");

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
                //y좌표는 최대 M_H에서 M_H+3
                case UP: //키보드 UP
                    if (y > M_H) {
                        gotoxy(x - 2, y);
                        printf(" ");
                        gotoxy(x - 2, --y);
                        printf(">");
                    }
                    break;
                case DOWN: //키보드 DOWN
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

//게임 룰
int rule(void)
{
    int contract[MAP_SIZE_H][MAP_SIZE_W];
    generate_map(contract);
    draw_map(contract);

    gotoxy(1, 0);
    printf("계약서(게임 설명)");
    gotoxy(2, 3);
    printf("1. 시간 안에 숨겨진 월급을 찾아라.");
    gotoxy(2, 6);
    printf("2. 3종류의 미니게임");
    gotoxy(2, 7);
    printf("\t- 목표 점수 이상 획득 성공: 월급 10만원 증가");
    gotoxy(2, 8);
    printf("\t- 목표 점수 이상 획득 실패: 월급 10만원 감소");
    gotoxy(2, 9);
    printf("\t\t\t\t    점장님 속도 증가");
    gotoxy(2, 11);
    printf("2-1. 물품정리: A, S, D키를 사용하여 물품을 알맞은 칸에");
    gotoxy(2, 12);
    printf("               넣어라.");
    gotoxy(2, 14);
    printf("2-2. 손님    : 1, 2, 3키를 사용하여 물품이 칸에 들어오면");
    gotoxy(2, 15);
    printf("               알맞은 키를 눌러라.(리듬게임 형식)");
    gotoxy(2, 17);
    printf("2-3. 택배정리: 방향키를 사용하여 제한시간 안에 택배 O를");
    gotoxy(2, 18);
    printf("               받아라.");

    int x = M_W;
    int y = M_H + 7;
    gotoxy(x - 2, y);
    printf("> back");  //return -1
    gotoxy(x, y + 1);
    printf("게임 시작"); //return -2

    do {
        int ch = _getch();
        if (ch == ENTER || ch == SPACE)
            return y - M_H - 7;
        if (ch == 224) {
            ch = _getch();
            printf(" \b");
            switch (ch) {
                //y좌표는 최대 M_H에서 M_H+1
                case UP: //키보드 UP
                    if (y > M_H + 7) {
                        gotoxy(x - 2, y);
                        printf(" ");
                        gotoxy(x - 2, --y);
                        printf(">");
                    }
                    break;
                case DOWN: //키보드 DOWN
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

//맵 안의 벽 생성
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
                printf("#");
                textcolor(WHITE);
            }
            else //-1과 -2 제외한 숫자 깃발
                printf("O");
        }
        printf("\n");
    }
}

int pause(void)
{
    int x = M_W;
    int y = M_H;
    system("cls");
    gotoxy(0, y - 8);
    printf("                         [일시 정지]\n\n");

    gotoxy(x - 2, y);
    printf("> 이어 하기");  //return -1
    gotoxy(x, y + 1);
    printf("메인 메뉴"); //return -2
    gotoxy(x, y + 2);
    printf("게임 종료"); //return -3

    do {
        int ch = _getch();
        if (ch == ENTER || ch == SPACE)
            return y - M_H;
        if (ch == 224) {
            ch = _getch();
            printf(" \b");
            switch (ch) {
                //y좌표는 최대 M_H에서 M_H+2
                case UP: //키보드 UP
                    if (y > M_H) {
                        gotoxy(x - 2, y);
                        printf(" ");
                        gotoxy(x - 2, --y);
                        printf(">");
                    }
                    break;
                case DOWN: //키보드 DOWN
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
    char* str = "계약서(게임 설명)        Enter키를 누르면 skip\n\n\n \\
    1. 시간 안에 숨겨진 월급을 찾아라.\n\n\n \\
        2. 3종류의 미니게임\n   \\
        - 목표 점수 이상 획득 성공 : 월급 10만원 증가\n \\
        - 목표 점수 이상 획득 실패 : 월급 10만원 감소, 점장님 속도 증가\n\n\\
        2 - 1. 물품정리: A, S, D키를 사용하여 물품을 알맞은 칸에\n\\
        \t\t 넣어라.\n\n\\
        2 - 2. 손님    : 1, 2, 3키를 사용하여 물품이 칸에 들어오면\n\\
        \t\t 알맞은 키를 눌러라.(리듬게임 형식)\n\n\\
        2 - 3. 택배정리: 방향키를 사용하여 제한시간 안에 택배 O를\n\\
        \t\t 받아라.\n\n\\
        확인한 후에 서명하세요.\n\\
        player 서명 : ";
    slow_print(str, 30);
    init(1); //커서 안 보이기
    fgets(name, NAMESIZE, stdin);
    name[strcspn(name, "\n")] = '\0';
    init(0);
}

void skip()
{
    system("cls");   //skip후 전체 내용출력
    printf("계약서(게임 설명)\n\n\n\\
    1. 시간 안에 숨겨진 월급을 찾아라.\n\n\n\\
        2. 3종류의 미니게임\n\\
        - 목표 점수 이상 획득 성공 : 월급 10만원 증가\n\\
        - 목표 점수 이상 획득 실패 : 월급 10만원 감소, 점장님 속도 증가\n\n\\
        2 - 1. 물품정리: A, S, D키를 사용하여 물품을 알맞은 칸에\n\\
        \t\t 넣어라.\n\n\\
        2 - 2. 손님    : 1, 2, 3키를 사용하여 물품이 칸에 들어오면\n\\
        \t\t 알맞은 키를 눌러라.(리듬게임 형식)\n\n\\
        2 - 3. 택배정리: 방향키를 사용하여 제한시간 안에 택배 O를\n\\
        \t\t 받아라.\n\n\\
        확인한 후에 서명하세요.\n\\
        player 서명 : ");
}

void skip_f()
{
    system("cls");   //skip후 전체 내용출력
    printf("학비와 생활비를 충당하기 위해 편의점 알바를 시작하게 되는데...");
}

//맵 안에서 움직이기
int move_key(int(*map)[MAP_SIZE_W], int* x, int* y, int level, int* money, char playName[])
{
    Sleep(1000 / FRAME);  // 화면은 1초마다 60번 업데이트 된다.

    frame_cnt++;
    if (frame_cnt == 61) {   // TODO:not sure if it iterates 60 time and resetted
        frame_cnt = 1;
        time_taken++;
    }
    // how boss moves
    if (frame_cnt % boss_frame == 0) {
        gotoxy(boss_x, boss_y);
        draw_boss(map, y, x);
    }

    if (*x == boss_x && *y == boss_y) {   //*//
        gotoxy(80, 80);   //*//
        //printf("hit");   //*//
        // where deffect happen
        if (boss_x == 1 && boss_y == 1) {   //*//
            *x = 60;   //*//
            *y = 60;   //*//
        }   //*//
        else {   //*//
            *x = 1;   //*//
            *y = 1;   //*//
        }   //*//
    }   //*//

    int ch, f, stop;

    gotoxy(*x, *y);
    textcolor(YELLOW);
    printf("p\b");
    textcolor(WHITE);
    if (_kbhit())
    {
        ch = _getch();
        //ESC 눌렀을때 일시정지
        if (ch == ESC)
        {
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
                    if (map[(*y) - 1][*x] == CLEARSPACE)
                    {
                        (*y)--;
                        return GARBAGE;
                    }
                    else if (map[(*y) - 1][*x] == WALL || map[(*y) - 1][*x] == BLOCK) //벽
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
    }


}



int game_start(int(*map)[MAP_SIZE_W], int start, int* x, int* y, char playName[])
{
    int item, level, ch;
    int money = 100; //초기 월급

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
            item = move_key(map, x, y, level, &money, playName);

            //타이머
            gotoxy(61, 1);
            printf("남은시간");
            gotoxy(62, 2);   //*//
            gotoxy(62, 2);   //*//
            printf("%4d", TIME_LIMIT - time_taken);   //*//
            if (TIME_LIMIT - time_taken <= 0) {   //*//   시간 초과시 종료
                //printf로 시간 종료 알려주기
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
                printf("월급: %4d만원", money);
            }
            else
                money = 0;

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
                    return 1; //반환이 1이면 시작화면으로
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
        //게임 룰 설명(계약서)
        system("cls");
        int r;
        r = rule();
        if (r == 0)
        {
            return 1; //메인 메뉴로(뒤로 가기)
        }
        else
            return 2; //게임 시작

    }
    else
    {
        return 0; //반환이 0이면 종료
    }
}
