#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;

vector<vector<int>> board, revboard;
vector<set<int>> componentAdjust;
int townNum, flightNum, startTown, endTown;
vector<int> townBegin, townEnd, componentTown;
vector<int> compSize;
int marker = 1, componentMarker = 0, sizeCalculator = 0;
stack<int> townStack;
void DFS(int index);
void RDFS(int index);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> townNum;
	board = vector<vector<int>>(townNum);
	revboard = vector<vector<int>>(townNum);
	cin >> flightNum;
	cin >> startTown;
	cin >> endTown;
	startTown--;
	endTown--;
	int from, to;
	for (int i = 0; i < flightNum; i++) {
		cin >> from;
		cin >> to;
		board[from - 1].push_back(to - 1);
		revboard[to - 1].push_back(from - 1);
	}
	townBegin = vector<int>(townNum, -1);
	townEnd = vector<int>(townNum, -1);
	componentTown = vector<int>(townNum, -1);
	componentAdjust = vector<set<int>>(townNum);
	for (int i = 0; i < townNum; i++) {
		if (townBegin[i] == -1) {
			DFS(i);
		}
	}
	while (!townStack.empty()) {
		int index = townStack.top();
		if (componentTown[index] == -1) {
			RDFS(index);
			componentMarker++;
			compSize.push_back(sizeCalculator);
			sizeCalculator = 0;
		}
		townStack.pop();
	}
	for (int i = 0; i < townNum; i++) {
		int tempComp = componentTown[i];
		for (int j = 0; j < board[i].size(); j++) {
			int nextComp = componentTown[board[i][j]];
			if (tempComp != -1 && nextComp != -1 && tempComp != nextComp) {
				componentAdjust[tempComp].insert(nextComp);
			}
		}
	}
	int tempPosition = componentTown[startTown];

	return 0;
}

void DFS(int index)
{
	townBegin[index] = marker;
	marker++;
	for (int i = 0; i < board[index].size(); i++) {
		if (townBegin[board[index][i]] == -1) {
			DFS(board[index][i]);
		}
	}
	townEnd[index] = marker;
	townStack.push(index);
	marker++;
	return;
}

void RDFS(int index)
{
	componentTown[index] = componentMarker;
	sizeCalculator++;
	for (int i = 0; i < revboard[index].size(); i++) {
		int temp = revboard[index][i];
		if (componentTown[temp] == -1) {
			RDFS(temp);
		}
	}
}