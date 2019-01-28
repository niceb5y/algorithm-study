#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> board;
vector<vector<int>> cache;
int boardSize;
int casemin = INT16_MIN;
int play(int left, int right);
//게임의 필승법을 찾는 동적 계획법
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		board = vector<int>(boardSize);
		cache = vector<vector<int>>(boardSize, vector<int>(boardSize,casemin));
		for (int i = 0; i < boardSize; i++) {
			cin >> board[i];
		}
		cout << play(0, boardSize - 1) << endl;
	}
	return 0;
}
//게임의 알고리즘은 틱택토와 비슷하다
//인수나 부호같은걸로 서로의 턴을 표현하는게 중요
int play(int left, int right)
{
	//기저사례: 모든 숫자다 처리되었을때
	if (left > right) {
		return 0;
	}
	int&memo = cache[left][right];
	if (memo != casemin) {
		return memo;
	}
	//수를 가져가는경우
	//이번 카드의 점수를 취한것에서 상대방의 점수를 뺀다
	memo = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));
	//수의 범위가 허락하는동안
	if (right - left > 0) {
		//이번의 2수를 포기하므로 없는 점수 상태에서 상대방의 점수를 깍는다
		memo = max(memo, -play(left + 2, right));
		memo = max(memo, -play(left, right - 2));
	}
	return memo;
}
