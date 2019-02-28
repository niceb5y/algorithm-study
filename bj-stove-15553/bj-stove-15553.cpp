#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N; // 방문하는 친구 수
int K; // 성냥 개수
priority_queue<int> blackout_times; // 친구가 방문하지 않는 시각
int t1, t2; // 친구가 방문하는 시각
int start, end22;
int answer;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    cin >> t1;
    start = t1;
    
    for (int i = 2; i <= N; i++) {
        cin >> t2;
        // 친구없는시간 :  뒷친구 방문시간 - 앞친구 나간시간
        blackout_times.push(t2 - t1 - 1);
        t1 = t2;
    }
    
    end22 = t1;
    answer = end22 - start + 1;
    
    while (--K) {
        // K-1 번 빼줌
        answer -= blackout_times.top();
        blackout_times.pop();
    }
    cout << answer << endl;
    
    return 0;
}
