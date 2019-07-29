#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int vertexNum, edgeNum, endNumber, SCCNum, startPosition, restaurantNum, maxCost;
vector<vector<int>> board, revBoard;
vector<bool> isVisited, reachable, restaurantNode;
vector<vector<bool>> SCCConnect;
vector<int> finishFix, SCCVertex, ATMGot, restaurantList, SCCCost, SCCMaxCost;
void DFS(int index);
void RDFS(int index);
void CalMax(int index, int got);
int main() {
	cin >> vertexNum;
	cin >> edgeNum;
	int start, end, money;

	board = vector<vector<int>>(vertexNum);
	revBoard = vector<vector<int>>(vertexNum);
	for (int i = 0; i < edgeNum; i++) {
		cin >> start;
		cin >> end;
		board[start - 1].push_back(end - 1);
		revBoard[end - 1].push_back(start - 1);
	}
	for (int i = 0; i < vertexNum; i++) {
		cin >> money;
		ATMGot.push_back(money);
	}
	cin >> startPosition;
	startPosition--;
	cin >> restaurantNum;
	for (int i = 0; i < restaurantNum; i++) {
		int temp;
		cin >> temp;
		restaurantList.push_back(temp - 1);
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
	SCCCost = vector<int>(SCCNum, 0);
	SCCConnect = vector<vector<bool>>(SCCNum, vector<bool>(SCCNum, false));
	restaurantNode = vector<bool>(SCCNum, false);
	for (int i = 0; i < SCCNum; i++) {
		for (int j = 0; j < SCCGroup[i].size(); j++) {
			SCCCost[i] += ATMGot[SCCGroup[i][j]];
			if (restaurantNode[i] == false) {
				vector<int>::iterator itor = find(restaurantList.begin(), restaurantList.end(), SCCGroup[i][j]);
				if (itor != restaurantList.end()) {
					restaurantNode[i] = true;
				}
			}
			for (int k = 0; k < board[SCCGroup[i][j]].size(); k++) {
				int nextDest = board[SCCGroup[i][j]][k];
				SCCConnect[SCCVertex[SCCGroup[i][j]]][SCCVertex[nextDest]] = true;
			}
		}
	}
	maxCost = 0;
	SCCMaxCost = vector<int>(SCCNum, 0);
	reachable = vector<bool>(SCCNum, false);
	reachable[SCCVertex[startPosition]] = true;
	for (int i = SCCVertex[startPosition]; i < SCCNum; i++) {
		if (reachable[i]) {
			SCCMaxCost[i] += SCCCost[i];
			if (restaurantNode[i]) {
				maxCost = max(maxCost, SCCMaxCost[i]);
			}
			for (int j = 0; j < SCCNum; j++) {
				if (SCCConnect[i][j]) {
					SCCMaxCost[j] = max(SCCMaxCost[j], SCCMaxCost[i]);
					reachable[j] = true;
				}
			}
		}
	}
	//CalMax(SCCVertex[startPosition], 0);
	cout << maxCost << endl;
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
void DFS(int index) {
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

void CalMax(int index, int got){
	vector<int>::iterator itor = find(restaurantList.begin(), restaurantList.end(), index);
	if (itor != restaurantList.end()) {
		maxCost = max(maxCost, got + SCCCost[index]);
	}
	for (int i = 0; i < SCCNum; i++) {
		if (SCCConnect[index][i] && i != index) {
			CalMax(i, got + SCCCost[index]);
		}
	}
}
