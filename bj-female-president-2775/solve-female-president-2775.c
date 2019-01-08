#include <stdio.h>

/* Problem: https://www.acmicpc.net/problem/2775 */

int main(int argc, char *argv[])
{
    int TestCase; // 테스트 케이스
    int k, n; // k층  n호
    int answerTable[15][15] = {0, }; // (1 <= k <= 14, 1 <= n <= 14)
    int i, j;
    for (i = 1; i <= 14; i++) answerTable[0][i] = i; // 0층
    for (i = 0; i <= 14; i++) answerTable[i][1] = 1; // 1호
    scanf("%d", &TestCase);
    while(TestCase--) {
        scanf("%d %d", &k, &n);
        if (n == 1) printf("1\n");
        else if (answerTable[k][n] != 0)    printf("%d\n", answerTable[k][n]);
        else {
            for (i = 1; i <= k; i++) { // 1층부터 시작
                for (j = 2; j <= n; j++) {
                    answerTable[i][j] = answerTable[i][j - 1] + answerTable[i - 1][j]; // (1, 2) = (1, 1) + (0, 2)
                }
            }
            printf("%d\n", answerTable[k][n]);
        }

    }
    return 0;
}
