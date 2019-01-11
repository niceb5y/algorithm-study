#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> board;
vector<vector<int>> cache;
int drillDown(int y, int x);
int triangleSize;
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> triangleSize;
		board = vector<vector<int>>(triangleSize, vector<int>(triangleSize, 0));
		cache = vector<vector<int>>(triangleSize, vector<int>(triangleSize, -1));
		for (int i = 0; i < triangleSize; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> board[i][j];
			}
		}
		cout << drillDown(0, 0) << endl;
	}
	return 0;
}

int drillDown(int y, int x)
{
	if (y == triangleSize - 1) {
		return board[y][x];
	}
	int& temp = cache[y][x];
	if (temp != -1) {
		return temp;
	}
	temp = max(drillDown(y+1,x), drillDown(y+1,x+1))+board[y][x];
	return temp;
}
