#include <iostream>
#define INF 999999999
using namespace std;

class Graph
{
    public:
    int numVertex;
    int **edge;
    Graph(int V, int E)
    {
        numVertex = V;
        edge = new int*[E];
        for (int i = 0; i < E; i++) {
            edge[i] = new int[E];
            for (int j = 0; j < E; j++) {
                edge[i][j] = INF;
            }
        }
    }
    void setEdge(int from, int to, int weight)
    {
        edge[from][to] = weight;
    }
};

void Dijkstra(Graph& G, int r)
{
    const int numVertex = G.numVertex;
    int *dist = new int[numVertex]; // 다익스트라 알고리즘의 결과(최소거리)
    bool *visit = new bool[numVertex]; // 방문 여부 결정
    
    int min;
    int willVisit;
    
    // 초기화 작업
    for (int i = 0; i < numVertex; i++) {
        dist[i] = INF;
        visit[i] = false;
    }
    dist[r] = 0; // 시작점의 거리는 0
    for (int i = 0; i < numVertex; i++) {
        min = INF;
        for (int j = 0; j < numVertex; j++) {
            if (!visit[j] && min > dist[j]) {
                min = dist[j];
                willVisit = j;
            }
        }
        visit[willVisit] = true;
        for (int j = 1; j < numVertex; j++) {
            // 방문한 곳에서 다른 정점까지 거리를 estimate
            if (dist[j] > dist[willVisit] + G.edge[willVisit][j]) {
                dist[j] = dist[willVisit] + G.edge[willVisit][j];
            }
        }
    }
    cout << "from " << r << " : " << endl;
    for (int i = 1; i < numVertex; i++) {
        cout << i << " - " << dist[i] << endl;
    }
}

int main(void)
{
    // 그래프 만들기
    Graph graph(8, 14);
    
    // 간선 잇기
    graph.setEdge(0, 1, 8);
    graph.setEdge(0, 2, 11);
    graph.setEdge(0, 3, 9);
    graph.setEdge(1, 4, 10);
    graph.setEdge(2, 5, 8);
    graph.setEdge(2, 6, 8);
    graph.setEdge(3, 1, 6);
    graph.setEdge(3, 2, 3);
    graph.setEdge(3, 4, 1);
    graph.setEdge(4, 7, 2);
    graph.setEdge(5, 6, 7);
    graph.setEdge(6, 3, 12);
    graph.setEdge(6, 7, 5);
    graph.setEdge(7, 5, 4);
    Dijkstra(graph, 0);
    return 0;
}
