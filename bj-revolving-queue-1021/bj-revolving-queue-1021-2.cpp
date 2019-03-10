#include <iostream>
#include <deque>

using namespace std;

int N; // 큐의 크기 (<=50)
int M; // 뽑아낼 원소 수
int *willPop; // 뽑아낼 원소 목록
int answer; // 2, 3번 연산 횟수
deque<int> dq; // 양방향 순환 큐

// 1번 연산
void pop_first()
{
    dq.pop_front();
}

// 2번 연산
void shift_left()
{
    ++answer;
    int data = dq.front();
    dq.pop_front();
    dq.push_back(data);
}

// 3번 연산
void shift_right()
{
    ++answer;
    int data = dq.back();
    dq.pop_back();
    dq.push_front(data);
}

// 시계반대방향으로 회전하면서 원하는 원소 빼기
void goLeft(int goal)
{
    while (goal != dq.front())   shift_left();
    pop_first();
}

// 시계방향으로 회전하면서 원하는 원소 빼기
void goRight(int goal)
{
    while (goal != dq.front())   shift_right();
    pop_first();
}

int main(void)
{
    answer = 0;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    
    willPop = new int[M];
    
    for (int i = 0; i < M; i++) {
        cin >> willPop[i];
    }

    for (int i = 0; i < M; i++) {
        int popValue = willPop[i]; // 팝 될 값 선언
        if (popValue == dq.front()) {
            // 뺄 것이 프론트에 있는 원소인 경우.
            pop_first(); // 뺀다.
            continue;
        }
        // 목표 원소의 인덱스를 파악한다.
        int index = 0;
        for (auto i = dq.begin(); i != dq.end(); ++i) {
            if (*i == popValue) break;
            ++index;
        }
        
        int currN = dq.size();
        // 더 가까운 방향을 선택하다
        if (currN - index > currN / 2) {
            goLeft(popValue);
        } else goRight(popValue);
    }
    cout << answer << endl;
    return 0;
}
