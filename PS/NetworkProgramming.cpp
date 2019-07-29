#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct QueueData
{
	int thisNode;
	int backNode;
	int distance;
	QueueData(int _this, int _back, int _dist):thisNode(_this),backNode(_back),distance(_dist){}
};

struct compare
{
	bool operator()(QueueData first, QueueData second) {
		return first.distance > second.distance;
	}
};
priority_queue <QueueData, vector<QueueData>, compare> routeQueue;
vector<vector<int>> board;
vector<int> connectionCost, connectionMap;
int computerNum, routeNum;
int main() {
	cin >> computerNum;
	cin >> routeNum;
	board = vector<vector<int>>(computerNum,vector<int>(computerNum,-1));
	connectionCost = vector<int>(computerNum, INT32_MAX);
	connectionMap = vector<int>(computerNum, -1);
	connectionCost[0] = 0;
	int to, from, distance;
	for (int i = 0; i < routeNum; i++) {
		cin >> to;
		cin >> from;
		cin >> distance;
		to--;
		from--;
		board[to][from] = distance;
		board[from][to] = distance;
	}
	routeQueue.push(QueueData(0, 0, connectionCost[0]));
	while (!routeQueue.empty())
	{
		QueueData top = routeQueue.top();
		routeQueue.pop();
		if (top.distance > connectionCost[top.thisNode]) {
			continue;
		}
		//connectionCost[top.thisNode] = top.distance;
		//connectionMap[top.thisNode] = top.backNode;
		for (int i = 0; i < computerNum; i++) {
			if (board[top.thisNode][i] != -1) {
				if (connectionCost[top.thisNode] + board[top.thisNode][i] < connectionCost[i]) {
					connectionCost[i] = connectionCost[top.thisNode] + board[top.thisNode][i];
					connectionMap[i] = top.thisNode;
					routeQueue.push(QueueData(i, top.thisNode, connectionCost[top.thisNode] + board[top.thisNode][i]));
				}
			}
		}
	}
	cout << computerNum - 1 << endl;
	for (int i = 1; i < computerNum; i++) {
		cout << i + 1 << " " << connectionMap[i] + 1 << endl;
	}
	return 0;
}