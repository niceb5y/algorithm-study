#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int boardSize, timeLimit;
int maxScore;
vector<pair<int, int>> board;
bool pair_sort(pair<int, int> first, pair<int, int> second);
bool isPromise(int studiedTime, int getScore, int index);
void study(int studiedTime, int getScore, int index);
int main() {
	cin >> boardSize;
	cin >> timeLimit;
	for (int i = 0; i < boardSize; i++) {
		int chapterTime, Score;
		cin >> chapterTime;
		cin >> Score;
		board.push_back(make_pair(chapterTime, Score));
	}
	sort(board.begin(), board.end(), pair_sort);
	maxScore = 0;
	study(0, 0, -1);
	cout << maxScore << endl;
	return 0;
}
bool pair_sort(pair<int, int> first, pair<int, int> second) {
	double firstAverage = (double)first.second / (double)first.first;
	double secondAverage = (double)second.second / (double)second.first;
	return firstAverage > secondAverage;
}

bool isPromise(int studiedTime, int getScore, int index)
{
	if (studiedTime > timeLimit) {
		return false;
	}
	int tempTime = studiedTime;
	double tempScore = getScore;
	int i;
	for (i = index + 1; i < boardSize; i++) {
		if (tempTime + board[i].first <= timeLimit) {
			tempTime += board[i].first;
			tempScore += board[i].second;
		}
		else {
			break;
		}
	}
	if (i < boardSize) {
		tempScore += (timeLimit - tempTime) * ((double)board[i].second / (double)board[i].first);
	}
	if (tempScore > maxScore) {
		return true;
	}
	return false;
}

void study(int studiedTime, int getScore, int index)
{
	if (!isPromise(studiedTime, getScore, index)) {
		return;
	}
	if (index == boardSize-1) {
		if (getScore > maxScore) {
			maxScore = getScore;
		}
		return;
	}
	study(studiedTime + board[index + 1].first, getScore + board[index + 1].second, index + 1);
	study(studiedTime, getScore, index + 1);
}
