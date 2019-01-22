#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int totalvillige, targetday,prisontown;
vector<vector<int>> board;
vector<int> connectednumlist;
vector<vector<double>> cache;
vector<int> targettownlist;
double gotoBed(int here, int leftday);
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
//마르코프 연쇄 문제(유한개의 상태, 매 시간마다 상태변경, a->b할때 a의 상태에만 좌우됨,시간과 사건에 독립적)
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> totalvillige;
		cin >> targetday;
		cin >> prisontown;
		board = vector<vector<int>>(totalvillige, vector<int>(totalvillige));
		connectednumlist = vector<int>(totalvillige, 0);
		for (int i = 0; i < totalvillige; i++) {
			for (int j = 0; j < totalvillige; j++) {
				cin >> board[i][j];
				if (board[i][j] == 1) {
					connectednumlist[i]++;
				}
			}
		}
		int targetnum;
		cin >> targetnum;
		targettownlist = vector<int>(targetnum);
		for (int i = 0; i < targetnum; i++) {
			cin >> targettownlist[i];
		}
		cache = vector<vector<double>>(totalvillige + 1, vector<double>(targetday + 1, -1.0));
		cout << fixed;
		cout.precision(10);
		for (int i = 0; i < targetnum; i++) {
			cout << gotoBed(targettownlist[i], targetday)<<" ";
		}
		cout << endl;
	}
	return 0;
}
//leftday 후에 here에 위치할 확률을 구해보자
//시작점은 정해져 있으므로 거꾸로 푸는게 더 유리
double gotoBed(int here, int leftday)
{
	//제한일에 도달했을때
	if (leftday == 0) {
		//감옥까지 갔다면 성공
		if (here == prisontown) {
			return 1.0;
		}
		//그 외에는 실패
		return 0.0;
	}
	//메모이제이션
	double& memo = cache[here][leftday];
	if (memo != -1.0) {
		return memo;
	}
	memo = 0.0;
	for (int nexttown = 0; nexttown < totalvillige; nexttown++) {
		if (board[here][nexttown] == 1) {
			//이쪽으로 넘어올수 있는 확률을 구한다
			memo += gotoBed(nexttown, leftday - 1) / connectednumlist[nexttown];
		}
	}
	return memo;
}
