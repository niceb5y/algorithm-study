#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> board;
vector<int> driveCost;
int cityNum, roadNum;
int main() {
	cin >> cityNum;
	cin >> roadNum;
	board = vector<vector<pair<int, int>>>(cityNum);
	for (int i = 0, start, end, cost; i < roadNum; i++) {
		cin >> start;
		cin >> end;
		cin >> cost;
		board[start - 1].push_back(make_pair(end - 1, cost));
	}
	driveCost = vector<int>(cityNum, INT32_MAX);
	driveCost[0] = 0;
	for (int trial = 0; trial < cityNum - 1; trial++) {
		for (int i = 0; i < cityNum; i++) {
			for (int j = 0; j < board[i].size(); j++) {
				int next = board[i][j].first;
				int nextCost = board[i][j].second;
				int tempCost = driveCost[i];
				if (tempCost != INT32_MAX && tempCost + nextCost < driveCost[next]) {
					driveCost[next] = tempCost + nextCost;
				}
			}
		}
	}

	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < board[i].size(); j++) {
			int next = board[i][j].first;
			int nextCost = board[i][j].second;
			int tempCost = driveCost[i];
			if (tempCost != INT32_MAX && tempCost + nextCost < driveCost[next]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int i = 1; i < cityNum; i++) {
		if (driveCost[i] == INT32_MAX) {
			cout << -1 << endl;
		}
		else {
			cout << driveCost[i] << endl;
		}
	}
	return 0;
}