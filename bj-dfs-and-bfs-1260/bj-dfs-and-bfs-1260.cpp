#include <iostream>
#include <vector>
#include <queue>

/*
"방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고"  "방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고"  "방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고"  "방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고"  "방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고"   "방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고"   "방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고" 
BFS를 할 때, 정점을 방문했다는 표시는 반드시 그 정점을 큐에 넣을 때 해야 합니다. 큐에서 뺄 때 표시를 하면 중복 방문이 일어날 수 있습니다. 왜 중복 방문이 일어날 수 있는지 알아야 BFS를 제대로 이해했다고 할 수 있지 않을까 생각됩니다.
DFS를 재귀로 구현했을 때도 마찬가지입니다. 정점을 방문했다는 표시는 반드시 그 정점에서 DFS 호출을 시작할 때 해야 합니다.
파이썬의 최대 재귀 깊이는 1,000 정도입니다. 그래서 재귀로 DFS를 구현하면 런타임 에러가 납니다. sys.setrecursionlimit으로 이 깊이를 조절할 수 있습니다.
입력으로 주어지는 간선은 양방향입니다. 즉 a b가 한 줄에 주어진다면 a에서 b로도 갈 수 있고, b에서 a로도 갈 수 있습니다.
그래도 모르시겠다면, 이 문제의 질문게시판에는 반례로 올라온 데이터가 상당히 많습니다. 그 데이터들이 잘 돌아가는지 확인해 보고 문제점을 찾아 보세요.
*/
using namespace std;

class Node {
    public:
    bool visited;
    vector<int> adjacent;
    Node()
    {
        visited = false;
    }
    void visit()
    {
        visited = true;
    }
};

bool first = true;
Node *graph;

void DFSsearch(int nodeNumber) {
    // root 노드 방문
    Node *n = &graph[nodeNumber];
    n->visit();
    cout << nodeNumber << ' ';
    for (auto l : n->adjacent) {
        if(graph[l].visited == false)
            DFSsearch(l);
    }
}

void BFSsearch(int nodeNumber) {
    queue<int> lvlQ; // 방문된 노드를 담아두는 큐
    // root 노드 방문
    Node *n = &graph[nodeNumber];
    n->visit();
    lvlQ.push(nodeNumber);
    if(first){
        first = false;
    cout << nodeNumber;
    }
    else
    cout << ' ' << nodeNumber;
    while (!lvlQ.empty()) {
        Node *t = &graph[lvlQ.front()];
        lvlQ.pop();
        t->visit();
        for (auto l : t->adjacent) {
            if(graph[l].visited == false) {
                graph[l].visit();
                lvlQ.push(l);
                if(first) {
                    first = false;
                    cout << l;
                }
                else
                    cout << ' ' << l;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, V;
    // N : 정점 수, M : 간선 수, V : 탐색 시작 정점
    cin >> N >> M >> V;
    graph = new Node[N + 1]; // N개의 정점을 생성 (0번 인덱스는 버린다.)
    for (int i = 0; i < M; i++) {
        int sN, eN; // 간선이 연결하는 두 정점
        cin >> sN >> eN;
        // 양방향이므로 두 방향에서 서로 연결
        graph[sN].adjacent.push_back(eN);
        graph[eN].adjacent.push_back(sN);
    }
    DFSsearch(V);
    cout << '\n';
    // 방문 여부 초기화
    for (int i = 1; i <= N; i++) {
        graph[i].visited = false;
    }
    BFSsearch(V);
    cout << '\n';
    return 0;
}
