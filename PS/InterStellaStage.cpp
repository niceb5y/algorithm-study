#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct vertex
{
	int from;
	int to;
	int cost;
};
int testCase, nodeNum, roadNum, holeNum;
vector<vector<vertex>> board;
vector<int> nodeDistance, updated;
queue<int> nodeQueue;
int main() {
	cin >> testCase;
	for (int trial = 0; trial < testCase; trial++) {
		cin >> nodeNum;
		cin >> roadNum;
		cin >> holeNum;
		board = vector<vector<vertex>>(nodeNum);
		int from, to, cost;
		vertex buffer;
		for (int i = 0; i < roadNum; i++) {
			cin >> from;
			cin >> to;
			cin >> cost;
			from--;
			to--;
			buffer.from = from;
			buffer.to = to;
			buffer.cost = cost;
			board[from].push_back(buffer);
			buffer.from = to;
			buffer.to = from;
			board[to].push_back(buffer);
		}
		for (int i = 0; i < holeNum; i++) {
			cin >> from;
			cin >> to;
			cin >> cost;
			from--;
			to--;
			cost = 0 - cost;
			buffer.from = from;
			buffer.to = to;
			buffer.cost = cost;
			board[from].push_back(buffer);
		}
		nodeDistance = vector<int>(nodeNum, INT32_MAX);
		//nodeDistance[0] = 0;
		updated = vector<int>(nodeNum, 0);
		for (int i = 0; i <nodeNum; i++) {
			if (board[i].size() > 0) {
				nodeDistance[i] = 0;
				nodeQueue.push(i);
				break;
			}
		}
		bool cycleDetected = false;
		while (!nodeQueue.empty())
		{
			int node = nodeQueue.front();
			nodeQueue.pop();
			for (int thisVertex = 0; thisVertex < board[node].size(); thisVertex++) {
				vertex temp = board[node][thisVertex];
				if (nodeDistance[node] != INT32_MAX && nodeDistance[node] + temp.cost < nodeDistance[temp.to]) {
					nodeDistance[temp.to] = nodeDistance[node] + temp.cost;
					updated[temp.to]++;
					if (updated[temp.to] > roadNum+holeNum) {
						cycleDetected = true;
						break;
					}
					nodeQueue.push(temp.to);
				}
			}
			if (cycleDetected) {
				break;
			}
		}
		if (cycleDetected) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}