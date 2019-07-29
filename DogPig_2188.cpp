#include <iostream>
#include <vector>
using namespace std;

bool DFS(int index);
vector<vector<int>>board;
vector<bool> visited;
vector<int> result;
int cowNum, roomNum;
int main() {
	cin >> cowNum;
	cin >> roomNum;
	board = vector<vector<int>>(cowNum);
	for (int i = 0, wantedNum; i < cowNum; i++) {
		cin >> wantedNum;
		for (int j = 0, wantBox; j < wantedNum; j++) {
			cin >> wantBox;
			board[i].push_back(wantBox - 1);
		}
	}
	result = vector<int>(roomNum, -1);
	int total = 0;
	for (int i = 0; i < cowNum; i++) {
		visited = vector<bool>(cowNum, false);
		if (DFS(i)) {
			total++;
		}
	}
	cout << total << endl;
	return 0;
}

bool DFS(int index) {
	if (visited[index]) {
		return false;
	}
	visited[index] = true;
	for (int i = 0; i < board[index].size(); i++) {
		int nearPoint = board[index][i];
		if (result[nearPoint] == -1) {
			result[nearPoint] = index;
			return true;
		}
	}

	for (int i = 0, nextReset; i < board[index].size(); i++) {
		nextReset = board[index][i];
		if (DFS(result[nextReset])) {
			result[nextReset] = index;
			return true;
		}
	}
	return false;
}