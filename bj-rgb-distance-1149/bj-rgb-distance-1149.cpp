#include <iostream>
#include <cmath>

/*
    Problem: https://www.acmicpc.net/problem/1149
*/

using namespace std;

int N; // 집 수
int costs[1000][3]; // 색상 가격 정보
int answ_acc[1000][3]; // 가격누적합산
/*
3
26 40 83 // 첫째 집의 비용 R / G / B
49 60 57 // 둘째 ~
13 89 99 // 셋쩨 ~
*/

void dp()
{
    for(int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            // r 선택
            if (j == 0) {
                answ_acc[i][j] = costs[i][j] + min(answ_acc[i - 1][1], answ_acc[i - 1][2]);
            }
            // g 선택
            else if (j == 1) {
                answ_acc[i][j] = costs[i][j] + min(answ_acc[i - 1][0], answ_acc[i - 1][2]);
            }
            // b 선택
            else  {
                answ_acc[i][j] = costs[i][j] + min(answ_acc[i - 1][0], answ_acc[i - 1][1]);
            }
        }
    }
}

int main(void)
{
    int cost_sum = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) // 가격 정보 입력
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    answ_acc[0][0] = costs[0][0];
    answ_acc[0][1] = costs[0][1];
    answ_acc[0][2] = costs[0][2];
    dp();
    cout << min(min(answ_acc[N - 1][0], answ_acc[N - 1][1]), answ_acc[N - 1][2]) << '\n';
    return 0;
}
