#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int vertexNum, edgeNum, endNumber,SCCNum;
vector<vector<int>> board;
vector<vector<int>> revBoard;
vector<bool> isVisited;
vector<int> finishFix, SCCVertex;
void DFS(int index);
void RDFS(int index);
int main() {
	cin >> vertexNum;
	cin >> edgeNum;
	int start, end;

	board = vector<vector<int>>(vertexNum);
	revBoard = vector<vector<int>>(vertexNum);
	for (int i = 0; i < edgeNum; i++) {
		cin >> start;
		cin >> end;
		board[start - 1].push_back(end - 1);
		revBoard[end - 1].push_back(start - 1);
	}
	isVisited = vector<bool>(vertexNum, false);
	finishFix = vector<int>(vertexNum, -1);
	endNumber = 0;
	for (int i = 0; i < vertexNum; i++) {
		if (!isVisited[i]) {
			DFS(i);
		}
	}
	SCCNum = 0;
	SCCVertex = vector<int>(vertexNum, -1);
	for (int i = finishFix.size() - 1; i >= 0; i--) {
		if (SCCVertex[finishFix[i]] == -1) {
			RDFS(finishFix[i]);
			SCCNum++;
		}
	}
	vector<vector<int>> SCCGroup = vector<vector<int>>(SCCNum);
	for (int i = 0; i < vertexNum; i++) {
		SCCGroup[SCCVertex[i]].push_back(i);
	}
	for (int i = 0; i < SCCNum; i++) {
		sort(SCCGroup[i].begin(), SCCGroup[i].end());
	}
	sort(SCCGroup.begin(), SCCGroup.end());
	cout << SCCNum << endl;
	for (int i = 0; i < SCCNum; i++) {
		for (int j = 0; j < SCCGroup[i].size(); j++) {
			cout << SCCGroup[i][j]+1 << ' ';
		}
		cout << -1 << endl;
	}
	return 0;
}
void RDFS(int index) {
	SCCVertex[index] = SCCNum;
	for (int i = 0; i < revBoard[index].size(); i++) {
		if (SCCVertex[revBoard[index][i]] == -1) {
			RDFS(revBoard[index][i]);
		}
	}
	return;
}
void DFS(int index){
	isVisited[index] = true;
	for (int i = 0; i < board[index].size(); i++) {
		if (!isVisited[board[index][i]]) {
			DFS(board[index][i]);
		}
	}
	finishFix[endNumber] = index;
	endNumber++;
	return;
}
