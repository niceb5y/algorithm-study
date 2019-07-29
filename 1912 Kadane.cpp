#include "pch.h"

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vectorSize;
vector<int> board;
vector<int> maxSum;
int main() {
	cin >> vectorSize;
	board = vector<int>(vectorSize, -1);
	maxSum = vector<int>(vectorSize + 1, -1);
	board[0] = 0;
	int maximum = INT32_MIN;
	for (int i = 0; i < vectorSize; i++) {
		cin >> board[i];
		if (maxSum[i] > 0) {
			maxSum[i + 1] = board[i] + maxSum[i];
		}
		else {
			maxSum[i + 1] = board[i];
		}
		maximum = max(maximum,maxSum[i+1]);
	}
	cout << maximum << endl;
}