#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, V;
bool graph[1001][1001] = {0, }; // 희소행렬  
bool visit[1001] = {0, };
queue<int> que;

void dfs_search(int v)
{
    // 첫 노드 방문
    cout << v << ' ';
    visit[v] = true;
    for (int i = 1; i <= N; i++) {
        if (graph[v][i] && !visit[i]) 
            dfs_search(i);
    }
}

void bfs_search(int v)
{
    // 첫 노드 방문
    cout << v << ' ';
    que.push(v);
    visit[v] = true;
    while(que.size()) {
        int idx = que.front();
        que.pop();
        for(int i = 1; i <= N; i++) {
            if (graph[idx][i] && !visit[i]) {
                cout << i << ' ';
                que.push(i);
                visit[i] = true;
            }
        }
    }
}

int main(void)
{   
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }
    dfs_search(V);
    memset(visit, 0, 1001);
    cout << '\n';
    bfs_search(V);
    return 0;
}
