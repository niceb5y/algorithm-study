#include <iostream>
#include <utility>
#include <vector>
#include <cctype>
#include <queue>
#include <cstring>

using namespace std;

enum { LEFT, RIGHT, UP, DOWN };

typedef struct {
    int r;
    int c;
} Point;

typedef struct Node {
    int level;
    Point red;
    Point blue;
} Node;

queue<Node *> bfs_queue;
bool visit[10][10][10][10]; // red r, red c, blue r, blue c state 중복없이 방문하기

int N, M; // board size (rows, columns)
bool board[10][10]; // pass or not // 0: non-pass 1: passable
Point goal; // coord of goal

Node root; // root Node
int answer = -1;

// 공을 기울였을 때 목적지의 위치를 반환한다.
Point will_skew(Point &start, int direction)
{
    Point curr;
    curr.r = start.r;
    curr.c = start.c;
    // 고려해야 할 것 : goal in 여부
    switch(direction)
    {
        case LEFT:
        while(board[curr.r][curr.c-1]) {
            curr.c--;
            if (goal.r == curr.r && goal.c == curr.c) {
                break; // goal-in
            }
        }
        break;
        case UP:
        while(board[curr.r-1][curr.c]) {
            curr.r--;
            if (goal.r == curr.r && goal.c == curr.c) {
                break; // goal-in
            }
        }
        break;
        case DOWN:
        while(board[curr.r+1][curr.c]) {
            curr.r++;
            if (goal.r == curr.r && goal.c == curr.c) {
                break; // goal-in
            }
        }
        break;
        case RIGHT:
        while(board[curr.r][curr.c+1]) {
            curr.c++;
            if (goal.r == curr.r && goal.c == curr.c) {
                break; // goal-in
            }
        }
        break;
    }
    return curr;
}

int main(void)
{
    memset(visit, 0, sizeof visit); // 방문 여부를 결정하는 변수를 초기화
    root.level = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            do {
                c = cin.get();
                if(c == '#')
                    board[i][j] = false; // 벽이면 모두 방문 불가로 설정
                else
                    board[i][j] = true; // 그 외의 경우 모두 방문 가능으로 설정
            } while( isspace(c) );
            if (c == 'R') {
                root.red.r = i;
                root.red.c = j;
            }
            else if (c == 'B') {
                root.blue.r = i;
                root.blue.c = j;
            }
            else if (c == 'O') {
                goal.r = i;
                goal.c = j;
            }
        }
    }
    
    // 초기상태 방문 플래그를 on으로 설정한다
    visit[root.red.r][root.red.c][root.blue.r][root.blue.c] = true;
    // 루트 노드를 큐에 넣는다.
    bfs_queue.push(&root);
    
    while (!bfs_queue.empty()) {
        Node *curr = bfs_queue.front();
        bfs_queue.pop();
        
        if (curr->level > 10) break; // 10번 초과로 굴리면 실패
        // 적색 공이 구멍에 위치해 있으면 성공 
        if (curr->red.r == goal.r && curr->red.c == goal.c) {
            answer = curr->level;
            break;
        }
        
    // 자식 노드 수를 결정하기 위해 4방향을 방문한다.
    for (int i = 0; i < 4; i++) {
        Point test_red = will_skew(curr->red, i);
        Point test_blue = will_skew(curr->blue, i);
        
        // blue가 골에 들어가면 고려하지 않는 경우이므로 버린다.
        if (test_blue.r == goal.r && test_blue.c == goal.c) continue;
        
        
        // 둘이 겹치면 - 골대인 경우 제외 - diff를 보고 밀어낸다
        if (test_red.r == test_blue.r && test_red.c == test_blue.c) {
            // cout << "두 구슬이 서로 겹치는 것 같음" << endl;
            // 기울인 방향에 따라 계산
            switch (i) {
                case 0 : // 왼
                // RB ? <== BR ? <==
                    curr->red.c < curr->blue.c ? test_blue.c++ : test_red.c++;
                break;
                case 1 : //오
                    // RB ? ==> BR ? ==>
                    curr->red.c < curr->blue.c ? test_red.c-- : test_blue.c--;
                break;
                case 2 : //위
                    // 블루가 아래에 있었는가? r(엔터)b
                    // 아니면 b(엔터)r
                    curr->red.r < curr->blue.r ? test_blue.r++ : test_red.r++;
                break;
                case 3 : //아
                    // 블루가 아래에 있었는가? r(엔터)b
                    // 아니면 b(엔터)r
                    curr->red.r < curr->blue.r ? test_red.r-- : test_blue.r--;
                break;
            }
        }
        
        // 테스트에 성공하면 루트의 자식 노드에 추가하고,  그것을 큐에 넣는다.
        // visit 플래그를 켠다.
        if (!visit[test_red.r][test_red.c][test_blue.r][test_blue.c]) {
            visit[test_red.r][test_red.c][test_blue.r][test_blue.c] = true;
            Node *child = new Node();
            child->red.r = test_red.r;
            child->red.c = test_red.c;
            child->blue.r = test_blue.r;
            child->blue.c = test_blue.c;
            child->level = curr->level + 1;
            bfs_queue.push(child);
            
        }
    }
    
    
    
    } // end of while
    cout << answer << endl;
    
    return 0;
}
