#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include<set>
using namespace std;

vector<vector<int>> board;
vector<set<int>> componentAdjust;
int townNum, flightNum, startTown, endTown;
vector<int> townBegin,componentTown, TravelPlan;
vector<int> compSize;
int marker, componentMarker = 0, sizeCalculator;
stack<int> townStack;
int DFS(int index);
int main() {
	cin >> townNum;
	board = vector<vector<int>>(townNum);
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
	}
	townBegin = vector<int>(townNum, -1);
	componentTown = vector<int>(townNum, -1);
	componentAdjust = vector<set<int>>(townNum);
	compSize = vector<int>(townNum);
	DFS(startTown);
	if (componentTown[endTown] == -1) {
		cout << 0 << endl;
		return 0;
	}
	TravelPlan = vector<int>(componentMarker, 0);
	for (int tempTown = componentMarker - 1; tempTown >= 0; tempTown--) {
		TravelPlan[tempTown] += compSize[tempTown];
		for (set<int>::iterator nextRoute = componentAdjust[tempTown].begin(); nextRoute != componentAdjust[tempTown].end(); nextRoute++) {
			TravelPlan[*nextRoute] = max(TravelPlan[tempTown], TravelPlan[*nextRoute]);
		}
	}
	cout << TravelPlan[componentTown[endTown]] << endl;
	return 0;
}
int DFS(int index)
{
	//현 상황에서 루트랑 제일 가깝게 갈수있는 노드를 리턴
	int result;
	townBegin[index] = marker;
	result = marker;
	marker++;
	townStack.push(index);
	for (int i = 0; i < board[index].size(); i++) {
		int next = board[index][i];
		//미방문시
		if (townBegin[next] == -1) {
			result = min(result,DFS(next));
		}
		//가봤던데이면
		else if (componentTown[board[index][i]] == -1) {
			result = min(result, townBegin[next]);
		}
	}
	//나와 내 자손들이 더이상 거슬러 올라갈수 없다면 하나의 SCC를 이룬다
	if (result == townBegin[index]) {
		while (!townStack.empty()){
			int town = townStack.top();
			townStack.pop();
			componentTown[town] = componentMarker;
			for (int i = 0; i < board[town].size(); i++) {
				int compAdjust = board[town][i];
				//만약 다른 컴포넌트로 접근이 가능하다면
				if (componentTown[compAdjust] != -1 && componentTown[compAdjust] != componentMarker) {
					componentAdjust[componentMarker].insert(componentTown[compAdjust]);
				}
			}
			sizeCalculator++;
			if (town == index) {
				break;
			}
		}
		compSize[componentMarker] = sizeCalculator;
		componentMarker++;
		sizeCalculator = 0;
	}
	return result;
}