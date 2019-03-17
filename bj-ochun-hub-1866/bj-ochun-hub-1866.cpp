#include <iostream>
#include <algorithm>

using namespace std;

int N;
int tb[3001];
int dp[3001]; // 디피디피
int truck_cost, hellgi_cost;

int get_marginal_value(int i, int j)
{
    
}

int main(void)
{
    cin >> N;
    tb[0] = 0;
    for (int i = 1; i <= N; i++) cin >> tb[i];
    cin >> truck_cost >> hellgi_cost;
    sort(tb + 1, tb + N + 1); // 택배상자를 정렬

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + tb[i] * truck_cost; // 새로운 대상 하나를 트럭으로 방문해 본다.
        int hell = hellgi_cost; // 헬기를 떨굴 위치를 조정해 본다.
        
        // 새로운 택배 배송지가 생겼으니 그 지점부터 처음까지 헬기 떨굴 위치를 재조정 해본다.
        // 코스트는 헬기 비용 + 헬기 도착지점에서 퍼지는 택배들 가격이다.
        // 0(홈) 1 2 -----------------j---- i
        //                            8 9 10 11 12 13 14 15 ==> 11~12 임. (8 + 15) + 1/ 2 = 24 / 2 = 12
        //                             9 10 11 12 13 ==>  11 임. (9 + 13)  / 2 = 11 
        //                             8 9 10 ==> (8+10)/2 =>9
        //                            8 9 10 11 => 8+11)/2 => 9
        // j ~ i 중간에 헬기를 떨구는게 좋겠다. (i + j / 2)
        for (int j = i; j >= 1; j--) {
            hell +=  // 헬기 떨군 비용 + 바퀴벌레처럼 퍼져나가는 비용
        }
    }






    cout << dp[N] << endl;
    
    return 0;
}





/*

c += s[i]-s[x]-s[x-1]+s[j-1]

            s[i] => a
            s[x-1] => b


*/
