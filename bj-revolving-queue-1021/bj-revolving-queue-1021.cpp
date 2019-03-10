#include <iostream>
#include <deque>

/* Problem https://www.acmicpc.net/problem/1021 */

using namespace std;

int n, r;
// 양방향 큐로 덱을 사용한다.
deque<int> deq;
deque<int>::iterator iter;

int main(void)
{
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
        deq.push_back(i);
    int cnt = 0; // 2,3 계열 연산 횟수
    for (int i = 0; i < r; i++) {
        int now;
        cin >> now; // 1 6 3 2 7 9 8 4 10 5
        int size = deq.size();
        int index = 1;
        
        for (iter = deq.begin(); iter < deq.end(); iter++) {
            // 덱을 탐색하면서 원하는 노드의 위치를 찾아낸다.
            if (*iter == now) break;
            index++;
        }
        int left = index - 1;
        int right = size - index + 1;
        // 시계반대방향으로 회전하는게 더 빠르다면
        if (left < right) {
            // 왼연산
            for (int i = 1; i <= left; i++) {
                deq.push_back(deq.at(0));
                deq.pop_front();
                cnt++;
            }
            deq.pop_front();
        }
        // 시계방향으로 회전하는게 더 빠르다면
        else {
            // 오른연산
            for (int i = 1; i <= right; i++) {
                deq.push_front(deq.at(size - 1));
                deq.pop_back();
                cnt++;
            }
            deq.pop_front();
        }
    }
    cout << cnt << endl;
    return 0;
}
