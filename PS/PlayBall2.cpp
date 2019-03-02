#include "pch.h"
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

vector<vector<bool>> board;
int xHole, yHole;
int xSize,ySize;
pair<int, int> rRolled, bRolled;
int isRollable(pair<int, int> r, pair<int, int> b, int rolltype);
int minRoll(pair<int, int> r, pair<int, int> b, int rolled);
int main()
{
	string oneLine;
	cin >> ySize;
	cin >> xSize;
	board = vector<vector<bool>>(ySize, vector<bool>(xSize, false));
	pair<int, int> r, b;
	for (int i = 0; i < ySize; i++) {
		cin >> oneLine;
		for (int j = 0; j < oneLine.size(); j++) {
			if (oneLine.at(j) == '#') {
				board[i][j] = false;
			}
			else if (oneLine.at(j) == 'O') {
				yHole = i;
				xHole = j;
				board[i][j] = true;
			}
			else if (oneLine.at(j) == 'R') {
				r = make_pair(j, i);
				board[i][j] = true;
			}
			else if (oneLine.at(j) == 'B') {
				b = make_pair(j, i);
				board[i][j] = true;
			}
			else {
				board[i][j] = true;
			}
		}
	}
	int result = minRoll(r, b, 0);
	if (result > 10) {
		cout << -1 << endl;
	}
	else {
		cout << minRoll(r, b, 0) << endl;
	}
}
//0=왼쪽 1== 오른쪽 2==위쪽 3==아래쪽
int isRollable(pair<int, int> r, pair<int, int>b, int rolltype)
{
	queue<pair<int, int>> ballQueue;
	pair<int, int> rolledBall = make_pair(-1, -1);
	bool redFirst= false;
	bool status = false;
	//가로로 굴린다
	if (rolltype == 0||rolltype==1) {
		//두 공이 같은 열에 있을시
		//r가 b보다 앞서있다면 r가 구멍의 우선권을 가진다
		if (r.second == b.second && (r.first < b.first && rolltype ==0)||(r.first>b.first&&rolltype==1)) {
			ballQueue.push(r);
			ballQueue.push(b);
			redFirst = true;
		}
		//대부분의 경우는 b가 우선권을 가진다
		else {
			ballQueue.push(b);
			ballQueue.push(r);
		}
	}
	//세로로 굴린다
	else {
		//r가 b보다 앞서있다면 r가 구멍의 우선권을 가진다
		if (r.first == b.first&&(r.second < b.second && rolltype == 2) || (r.second > b.second&&rolltype == 3)) {
			ballQueue.push(r);
			ballQueue.push(b);
			redFirst = true;
		}
		//대부분의 경우는 b가 우선권을 가진다
		else {
			ballQueue.push(b);
			ballQueue.push(r);
		}
	}
	//큐가 비워질때까지 굴린다
	while (!ballQueue.empty()) {
		pair<int, int> temp = ballQueue.front();
		ballQueue.pop();
		if (rolltype == 0) {
			while (true)
			{
				if (temp.first - 1 < 0 || board[temp.second][temp.first - 1] == false || (temp.second == rolledBall.second && temp.first - 1 == rolledBall.first)) {
					break;
				}
				if (temp.first - 1 == xHole && temp.second == yHole) {
					if (redFirst == !ballQueue.empty()) {
						status = true;
					}
					else {
						return 0;
					}
				}
				temp.first--;
			}
		}
		else if (rolltype == 1) {
			while (true)
			{
				if (temp.first + 1 >= xSize || board[temp.second][temp.first + 1] == false || (temp.second == rolledBall.second && temp.first + 1 == rolledBall.first)) {
					break;
				}
				if (temp.first + 1 == xHole && temp.second == yHole) {
					if (redFirst == !ballQueue.empty()) {
						status = true;
					}
					else {
						return 0;
					}
				}
				temp.first++;
			}
		}
		else if (rolltype == 2) {
			while (true)
			{
				if (temp.second - 1 < 0 || board[temp.second - 1][temp.first] == false || (temp.first == rolledBall.first && temp.second - 1 == rolledBall.second)) {
					break;
				}
				if (temp.second - 1 == yHole && temp.first == xHole) {
					if (redFirst == !ballQueue.empty()) {
						status = true;
					}
					else {
						return 0;
					}
				}
				temp.second--;
			}
		}
		else if (rolltype == 3) {
			while (true)
			{
				if (temp.second + 1 >= ySize || board[temp.second + 1][temp.first] == false || (temp.first == rolledBall.first && temp.second + 1 == rolledBall.second)) {
					break;
				}
				if (temp.second + 1 == yHole && temp.first == xHole) {
					if (redFirst == !ballQueue.empty()) {
						status = true;
					}
					else {
						return 0;
					}
				}
				temp.second++;
			}
		}
		if (status) {
			rRolled = make_pair(-2, -2);
		}
		else {
			//굴러간 후의 모습을 저장해놓는다
			if (redFirst == !ballQueue.empty()) {
				rRolled = temp;
			}
			else {
				bRolled = temp;
			}
			rolledBall = temp;
		}
	}
	//두개다 굴렸지만 게임이 끝나지 않았다면
	//0 = 불가 1 = 가능 2 = 게임끝
	if (status) {
		return 2;
	}
	return 1;
}

int minRoll(pair<int, int> r, pair<int, int> b, int rolled)
{
	int total = 999;
	if (rolled > 9) {
		return 999;
	}
	for (int i = 0; i < 4; i++) {
		//4방향으로 굴러본 후의 결과 저장
		int status = isRollable(r, b, i);
		//기저사례: 1번만 더 굴리면 끝날때
		if (status == 2) {
			return rolled + 1;
		}
		else if (status == 1) {
			//굴려서 변화가 있었다면
			if (r != rRolled || b != bRolled) {
				total = min(total, minRoll(rRolled, bRolled, rolled + 1));
			}
		}
	}
	return total;
}
