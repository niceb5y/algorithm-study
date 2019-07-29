#include "pch.h"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> board;
vector<int> subSum;
vector<vector<int>> cache;
int boardSize;
int minCost(int start, int end);
int maxCost;
int main() {
	int testCase;
	cin >> testCase;
	for (int trial = 0; trial < testCase; trial++) {
		cin >> boardSize;
		board = vector<int>(boardSize, -1);
		cache = vector<vector<int>>(boardSize, vector<int>(boardSize, -1));
		subSum = vector<int>(boardSize + 1, 0);
		maxCost = 0;
		for (int i = 0; i < boardSize; i++) {
			cin >> board[i];
			maxCost += board[i];
			subSum[i + 1] = maxCost;
		}
		cout << minCost(0, boardSize - 1) << endl;
	}
}

int minCost(int start, int end) {
	if (cache[start][end] != -1) {
		return cache[start][end];
	}
	if (start == end) {
		cache[start][end] = 0;
		return 0;
	}
	int temp = INT32_MAX;
	for (int i = start; i + 1 <= end; i++) {
		int frontSum = subSum[i + 1] - subSum[start];
		int backSum = subSum[end + 1] - subSum[i + 1];
		temp = min(temp, minCost(start, i) + minCost(i + 1, end)+ frontSum + backSum);
	}
	cache[start][end] = temp;
	return temp;
}