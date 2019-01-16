#include <stdio.h>

/* Problem : https://www.acmicpc.net/problem/10993 */

short N;
short board[1023][2045];
enum direction {up=0, down, left, right};
enum tType {inv=0, original};

/**
 * 1 => 1 x 1 (행 x 열)
 * 2 => 3 x 5 (+2, +4)
 * 3 => 7 x 13 (+4, +8)
 * 4 => 15  x 29 (+8, +16)  
 * 
 * N => ( (2^N)-1, (2^(N+1))-3 )
 * 
 * 10 => 1023 x 2045
 * */


typedef struct {
    short r;
    short c;
} COORD, *PCOORD;

int mypow(int b, int times) {
    int re = 1;
    while(times--)  re *= b;
    return re;
}


void gotoXY(PCOORD POS)
{
    board[POS->r][POS->c] = '*';
}

// 현위치 제외
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

void drawTriangle(int type, PCOORD START_POINT, int height)
{
    int i;
    COORD tmp, tmp2;
    tmp.r = START_POINT->r;
    tmp.c = START_POINT->c;
    tmp2.r = START_POINT->r;
    tmp2.c = START_POINT->c;
    gotoXY(&tmp); // 꼭지점 별 찍기
    for(i = 1; i < height; i++) {
        // height : 7
        // 중간부분 별 찍기
        if(type == original) {
            tmp.r++; // 좌별
            tmp2.r++; // 우별
        }
        else {
            tmp.r--; // 좌별
            tmp2.r--; // 우별
        }
        tmp.c--; // 좌별
        tmp2.c++; // 우별
        gotoXY(&tmp);
        gotoXY(&tmp2);
    }
    drawDirection(&tmp, right, height * 2 - 3);// 하단 별 찍기
}

void printStar()
{
    int i, j;
    int r, c;
    r = mypow(2, N) - 1;
    c = mypow(2, N + 1) - 3;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if(!board[i][j]) {
                if((N % 2 == 1 && j<=c/2+i) || (N % 2 == 0 &&j<c-i))
                putchar(' ');
            }
            else putchar('*');
        }
        if(i != r - 1)
        putchar('\n');
    }
}

// * N => ( (2^N)-1, (2^(N+1))-3 )
int main(int argc, char* argv[])
{
    short i, r, c;
    scanf("%hd", &N); //ex N : 4
    if (N == 1) { putchar('*'); return 0; }
    COORD corner;
    c = mypow(2, N + 1) - 3;
    corner.c = c / 2; // 삼각형의 꼭지점 c는 항상 일정
    corner.r = N % 2 == 0 ? (mypow(2, N) - 1) - 1: 0; // 삼각형 초기 꼭지점 위치
    for (i = N; i >= 2; i--) {
        r = mypow(2, i) - 1; // 삼각형의 높이를 구한다. N:2, 3
        drawTriangle(i % 2, &corner, r);
        if(i % 2 == 0 && i != 2)  {//지금이 짝수라면 다음 삼각형은 홀수형(정방향)
            corner.r = corner.r - r + 2;  // => 이게 아니라 꼭지점- 높이 + 2
        }
        else if(i % 2 == 1)
            corner.r = corner.r + r - 2;//현재의 꼭지점 좌표 + 높이
        else {
            // i : 2 인 경우 (마지막)
            // 바로 위에 * 하나를 찍고 완성.
            corner.r--;
            gotoXY(&corner);       
        }
    }
    printStar();
    return 0;
}
