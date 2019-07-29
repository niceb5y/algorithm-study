#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> board, costBoard;
vector<int> xMove = { 0,0,1,-1 };
vector<int> yMove = { 1,-1,0,0 };
struct Edge{
	int x, y;
	int cost;
	Edge(int a,int b,int c):x(a),y(b),cost(c){}
};
struct cmp{
	bool operator()(Edge first, Edge second) {
		return first.cost > second.cost;
	}
};
priority_queue<Edge, vector<Edge>, cmp> dj_queue;
int boardSize, testCase;
int main() {
	testCase = 0;
	while (true){
		testCase++;
		cin >> boardSize;
		if (boardSize == 0) {
			break;
		}
		board = vector<vector<int>>(boardSize, vector<int>(boardSize, -1));
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				cin >> board[i][j];
			}
		}
		costBoard = vector<vector<int>>(boardSize, vector<int>(boardSize, INT32_MAX));
		costBoard[0][0] = board[0][0];
		dj_queue.push(Edge(0,0,costBoard[0][0]));
		while (!dj_queue.empty()){
			Edge nearest = dj_queue.top();
			dj_queue.pop();
			if (costBoard[nearest.x][nearest.y] < nearest.cost) {
				continue;
			}
			for (int i = 0; i < 4; i++) {
				if (nearest.x + xMove[i] >= 0 && nearest.x + xMove[i] < boardSize) {
					if (nearest.y + yMove[i] >= 0 && nearest.y + yMove[i] < boardSize) {
						int nextCost = board[nearest.x + xMove[i]][nearest.y + yMove[i]];
						if (costBoard[nearest.x + xMove[i]][nearest.y + yMove[i]] > nearest.cost + nextCost) {
							costBoard[nearest.x + xMove[i]][nearest.y + yMove[i]] = nearest.cost + nextCost;
							dj_queue.push(Edge(nearest.x + xMove[i], nearest.y + yMove[i], costBoard[nearest.x + xMove[i]][nearest.y + yMove[i]]));
						}
					}
				}
			}
		}
		cout << "Problem " << testCase << ": " << costBoard[boardSize - 1][boardSize - 1] << endl;
	}
	return 0;
}