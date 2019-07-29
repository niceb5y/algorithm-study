#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vertexCost;
vector<vector<pair<int,int>>> board;
int vertexNum, edgeNum, startNode;
struct Edge{
	int start;
	int end;
	int cost;
	Edge(int a, int b, int c) : start(a), end(b), cost(c){};
};
struct cmp {
	bool operator()(Edge t, Edge u) {
		return t.cost > u.cost;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin >> vertexNum;
	cin >> edgeNum;
	cin >> startNode;
	startNode--;
	vertexCost = vector<int>(vertexNum, INT32_MAX);
	vertexCost[startNode] = 0;
	board = vector<vector<pair<int, int>>>(vertexNum);
	int start, end, cost;
	for (int i = 0; i < edgeNum; i++) {
		cin >> start;
		cin >> end;
		cin >> cost;
		board[start - 1].push_back(make_pair(end - 1, cost));
	}
	priority_queue<Edge,vector<Edge>,cmp> dj_queue;
	dj_queue.push(Edge(startNode,startNode,0));
	while (!dj_queue.empty()) {
		Edge nearest = dj_queue.top();
		dj_queue.pop();
		if (nearest.cost > vertexCost[nearest.end]) {
			continue;
		}
		for (int i = 0; i < board[nearest.end].size(); i++) {
			if (vertexCost[board[nearest.end][i].first]> vertexCost[nearest.end] + board[nearest.end][i].second) {
				vertexCost[board[nearest.end][i].first] = vertexCost[nearest.end] + board[nearest.end][i].second;
				dj_queue.push(Edge(nearest.end, board[nearest.end][i].first, vertexCost[board[nearest.end][i].first]));
			}
		}
	}
	for (int i = 0; i < vertexNum; i++) {
		if (vertexCost[i] == INT32_MAX) {
			cout << "INF" << endl;
		}
		else {
			cout << vertexCost[i] << endl;
		}
	}
	return 0;
}
