#include <stdio.h>

/* Problem : https://www.acmicpc.net/problem/10997 */

    /*
    N => 행 x 열
    1 => 1 x 1
    2 => 7 x 5 /// (4, 2) 시작
    3 => 11 x 9 /// (6, 4) 시작
    4 => 15 x 13 /// (8, 6) 시작
    ...
    n => (4n - 1) x (4n - 3) (n > 1)
    ...
    100 =>  399 x 397
    */
enum direction {up=0, down, left, right};
short N;
short board[399][397];
typedef struct {
    short r;
    short c;
} COORD, *PCOORD;

void printStar()
{
    int i, j;
    for (i = 0; i < 4 * N - 1; i++) {
        for (j = 0; j < 4 * N - 3; j++) {
            if(!board[i][j]) putchar(' ');
            else putchar('*');
        }
        if(i != 4 * N - 2) putchar('\n');
    }
}

void gotoXY(PCOORD POS)
{
    board[POS->r][POS->c] = '*';
}

void drawDirection(PCOORD POS, int direction, int times)
{
    switch(direction) {
        case up:
            while(times--) {
                POS->r--;
                gotoXY(POS);
            }
        break;
        case down:
            while(times--) {
                POS->r++;
                gotoXY(POS);
            }
        break;
        case left:
            while(times--) {
                POS->c--;
                gotoXY(POS);
            }
        break;
        case right:
            while(times--) {
                POS->c++;
                gotoXY(POS);
            }
        break;
    }
}

int main(int argc, char *argv[])
{
    int i, n = 2, cN;
    COORD currentPosition;
    scanf("%hd", &N);
    if(N == 1) { printf("*"); return 0; }
    currentPosition.r = 2 * N;
    currentPosition.c = 2 * N - 2;
    gotoXY(&currentPosition); // 별을 찍는 액션 (초기위치)

    //위 2 오 2 (공통)
    drawDirection(&currentPosition, up, 2);
    drawDirection(&currentPosition, right, 2);
    //아 2n 왼 2n 위 2n + 2 오 2n
    cN = N - 1;
    while(cN--) {
        drawDirection(&currentPosition, down, 2 * n);
        drawDirection(&currentPosition, left, 2 * n);
        drawDirection(&currentPosition, up, 2 * n + 2);
        drawDirection(&currentPosition, right, 2 * n);
        if(cN) drawDirection(&currentPosition, right, 2); // 2개 꼬리 추가
        n += 2;
    }
    printStar();
    return 0;
}
