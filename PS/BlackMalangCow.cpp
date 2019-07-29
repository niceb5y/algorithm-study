#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> pipe;
vector<vector<int>> cache,board;
int pipeNum, startNode = 0, endNode = 25,result = 0;
queue<pair<int, int>> pipeLine;
int main() {
	pipe = vector<vector<int>>(52);
	cache = vector<vector<int>>(52, vector<int>(52, 0));
	board = vector<vector<int>>(52, vector<int>(52, 0));
	cin >> pipeNum;
	char from, to;
	int fromTrans, toTrans, cost;
	for (int i = 0; i < pipeNum; i++) {
		cin >> from;
		cin >> to;
		cin >> cost;
		if (from >= 'a') {
			fromTrans = from - 'a' + 26;
		}
		else {
			fromTrans = from - 'A';
		}
		if (to >= 'a') {
			toTrans = to - 'a' + 26;
		}
		else {
			toTrans = to - 'A';
		}
		if (board[fromTrans][toTrans] == 0) {
			pipe[fromTrans].push_back(toTrans);
			pipe[toTrans].push_back(fromTrans);
		}
		board[fromTrans][toTrans] += cost;
		board[toTrans][fromTrans] += cost;
	}
	while (true){
		vector<int> routeSaver = vector<int>(52,-1);
		routeSaver[0] = 0;
		pipeLine.push(make_pair(0, INT32_MAX));
		int tempSize = 0;
		while (!pipeLine.empty() && routeSaver[endNode] == -1) {
			int tempNode = pipeLine.front().first;
			tempSize = pipeLine.front().second;
			pipeLine.pop();
			for (int i = 0; i < pipe[tempNode].size(); i++) {
				if (board[tempNode][pipe[tempNode][i]] - cache[tempNode][pipe[tempNode][i]] > 0 && routeSaver[pipe[tempNode][i]] == -1) {
					pipeLine.push(make_pair(pipe[tempNode][i],min(tempSize, board[tempNode][pipe[tempNode][i]] - cache[tempNode][pipe[tempNode][i]])));
					routeSaver[pipe[tempNode][i]] = tempNode;
					if (routeSaver[endNode] != -1) {
						tempSize = min(tempSize, board[tempNode][pipe[tempNode][i]] - cache[tempNode][pipe[tempNode][i]]);
						break;
					}
				}
			}
		}
		if (routeSaver[endNode] == -1) {
			break;
		}
		int backTracking = endNode;
		while (backTracking != startNode) {
			cache[routeSaver[backTracking]][backTracking] += tempSize;
			cache[backTracking][routeSaver[backTracking]] -= tempSize;
			backTracking = routeSaver[backTracking];
		}
		result += tempSize;
		queue<pair<int, int>> temp;
		swap(pipeLine, temp);
	}

	cout << result << endl;
	return 0;
}