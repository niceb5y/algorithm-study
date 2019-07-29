#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> board;
vector<vector<int>> cache;
vector<pair<int, int>> moveMode = { make_pair(0,1),make_pair(0,-1),make_pair(1,0),make_pair(-1,0) };
int column, row;
int totalSum(int tRow, int tCol);
bool isPossible(int tRow, int tCol, int moveDest);
int main() {
	cin >> row;
	cin >> column;
	board = vector<vector<int>>(row, vector<int>(column, -1));
	cache = vector<vector<int>>(row, vector<int>(column, -1));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> board[i][j];
		}
	}
	cout << totalSum(0, 0) << endl;
}

int totalSum(int tRow, int tCol) {
	
	if (cache[tRow][tCol] != -1) {
		return cache[tRow][tCol];
	}
	if (tRow == row - 1 && tCol == column - 1) {
		cache[tRow][tCol] = 1;
		return 1;
	}
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		if (isPossible(tRow, tCol, i)) {
			temp += totalSum(tRow + moveMode[i].first, tCol + moveMode[i].second);
		}
	}
	cache[tRow][tCol] = temp;
	return temp;
}

bool isPossible(int tRow, int tCol, int moveDest)
{
	if (tRow + moveMode[moveDest].first < 0 || tRow + moveMode[moveDest].first >= row) {
		return false;
	}
	if (tCol + moveMode[moveDest].second < 0 || tCol + moveMode[moveDest].second >= column) {
		return false;
	}
	if (board[tRow][tCol] <= board[tRow + moveMode[moveDest].first][tCol + moveMode[moveDest].second]) {
		return false;
	}
	return true;
}
