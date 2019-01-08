#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> cache;
vector<vector<int>> board;
int jump(int y, int x);
int boardSize;
int main() {
	int testcase = 0;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		board = vector<vector<int>>(boardSize,vector<int>(boardSize));
		cache = vector<vector<int>>(boardSize, vector<int>(boardSize,-1));
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				cin >> board[i][j];
			}
		}
		int ret = jump(0, 0);
		if (ret != 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

int jump(int y, int x)
{
	if (y >= boardSize || x >= boardSize) {
		return 0;
	}
	if (y == boardSize - 1 && x >= boardSize - 1) {
		return 1;
	}
	int& result = cache[y][x];
	if (result != -1) {
		return result;
	}
	int jumpSize = board[y][x];
	return result = (jump(y+jumpSize,x)||jump(y,x+jumpSize));
}
