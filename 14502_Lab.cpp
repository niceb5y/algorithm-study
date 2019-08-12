#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<pair<int, int>> ZeroSpace;
void dfs(int y, int x);
int getSafe();
int poleIt(int index, int polled);
int main() {
	cin >> n;
	cin >> m;
	board = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				ZeroSpace.push_back(make_pair(i, j));
			}
		}
	}
	cout << poleIt(0, 0);
	return 0;
}

void dfs(int y, int x){
	board[y][x] = 2;
	if (y - 1 > -1 && board[y - 1][x] == 0) {
		dfs(y - 1, x);
	}
	if (y + 1 < n && board[y + 1][x] == 0) {
		dfs(y + 1, x);
	}
	if (x - 1 > -1 && board[y][x - 1] == 0) {
		dfs(y, x - 1);
	}
	if (x + 1 < m && board[y][x + 1] == 0) {
		dfs(y, x + 1);
	}
}

int getSafe(){
	int safeArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				safeArea++;
			}
		}
	}
	return safeArea;
}

int poleIt(int index, int polled){
	if (polled == 3) {
		vector<vector<int>> temp = board;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 2) {
					dfs(i, j);
				}
			}
		}
		int result = getSafe();
		board = temp;
		return result;
	}
	if (index == ZeroSpace.size()) {
		return 0;
	}
	int result = 0;
	board[ZeroSpace[index].first][ZeroSpace[index].second] = 1;
	result = max(result, poleIt(index + 1, polled + 1));
	board[ZeroSpace[index].first][ZeroSpace[index].second] = 0;
	result = max(result, poleIt(index + 1, polled));
	return result;
}
