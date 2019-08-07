#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int peopleNum;
vector<vector<int>> board;
vector<int> teamStart, teamLink;
int solve(int index);
int calculatePowerSub();
int main() {
	cin >> peopleNum;
	board = vector<vector<int>>(peopleNum, vector<int>(peopleNum, 0));
	for (int i = 0; i < peopleNum; i++) {
		for (int j = 0; j < peopleNum; j++) {
			cin >> board[i][j];
		}
	}
	cout << solve(0);
	return 0;
}

int solve(int index){
	if (teamStart.size() >= peopleNum / 2) {
		for (int i = index; i < peopleNum; i++) {
			teamLink.push_back(i);
		}
		int result = calculatePowerSub();
		for (int i = peopleNum; i > index; i--) {
			teamLink.pop_back();
		}
		return result;
	}
	else if (teamLink.size() >= peopleNum / 2) {
		for (int i = index; i < peopleNum; i++) {
			teamStart.push_back(i);
		}
		int result = calculatePowerSub();
		for (int i = peopleNum; i > index; i--) {
			teamStart.pop_back();
		}
		return result;
	}
	else if(index >= peopleNum){
		return calculatePowerSub();
	}
	else {
		int lowest = INT32_MAX;
		teamStart.push_back(index);
		lowest = min(lowest, solve(index + 1));
		teamStart.pop_back();
		teamLink.push_back(index);
		lowest = min(lowest, solve(index + 1));
		teamLink.pop_back();
		return lowest;
	}
}

int calculatePowerSub(){
	int teamStartPower = 0, teamLinkPower = 0;
	for (int i = 0; i < peopleNum / 2; i++) {
		for (int j = 0; j < peopleNum / 2; j++) {
			teamStartPower += board[teamStart[i]][teamStart[j]];
		}
	}
	for (int i = 0; i < peopleNum / 2; i++) {
		for (int j = 0; j < peopleNum / 2; j++) {
			teamLinkPower += board[teamLink[i]][teamLink[j]];
		}
	}
	if (teamStartPower > teamLinkPower) {
		return teamStartPower - teamLinkPower;
	}
	else {
		return teamLinkPower - teamStartPower;
	}
}
