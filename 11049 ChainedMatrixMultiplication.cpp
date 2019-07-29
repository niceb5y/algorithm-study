#include "pch.h"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> board;
int boardSize;
vector<vector<int>> cache;

int minMulti(int start, int end);
int main() {
	cin >> boardSize;
	board = vector<pair<int, int>>(boardSize);

	cache = vector<vector<int>>(boardSize, vector<int>(boardSize, -1));
	for (int i = 0; i < boardSize; i++) {
		int row, col;
		cin >> row;
		cin >> col;
		board[i] = make_pair(row, col);
	}
	cout << minMulti(0, boardSize - 1) << endl;
}

int minMulti(int start, int end)
{
	if (cache[start][end] != -1) {
		return cache[start][end];
	}
	if (start == end) {
		cache[start][end] = 0;
		return 0;
	}
	int temp = INT32_MAX;
	for (int i = start; i+1 <= end; i++) {
		temp = min(temp, minMulti(start, i) + minMulti(i + 1, end)+(board[start].first*board[i].second*board[end].second));
	}
	cache[start][end] = temp;
	return temp;
}
