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
//0=���� 1== ������ 2==���� 3==�Ʒ���
int isRollable(pair<int, int> r, pair<int, int>b, int rolltype)
{
	queue<pair<int, int>> ballQueue;
	pair<int, int> rolledBall = make_pair(-1, -1);
	bool redFirst= false;
	bool status = false;
	//���η� ������
	if (rolltype == 0||rolltype==1) {
		//�� ���� ���� ���� ������
		//r�� b���� �ռ��ִٸ� r�� ������ �켱���� ������
		if (r.second == b.second && (r.first < b.first && rolltype ==0)||(r.first>b.first&&rolltype==1)) {
			ballQueue.push(r);
			ballQueue.push(b);
			redFirst = true;
		}
		//��κ��� ���� b�� �켱���� ������
		else {
			ballQueue.push(b);
			ballQueue.push(r);
		}
	}
	//���η� ������
	else {
		//r�� b���� �ռ��ִٸ� r�� ������ �켱���� ������
		if (r.first == b.first&&(r.second < b.second && rolltype == 2) || (r.second > b.second&&rolltype == 3)) {
			ballQueue.push(r);
			ballQueue.push(b);
			redFirst = true;
		}
		//��κ��� ���� b�� �켱���� ������
		else {
			ballQueue.push(b);
			ballQueue.push(r);
		}
	}
	//ť�� ����������� ������
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
			//������ ���� ����� �����س��´�
			if (redFirst == !ballQueue.empty()) {
				rRolled = temp;
			}
			else {
				bRolled = temp;
			}
			rolledBall = temp;
		}
	}
	//�ΰ��� �������� ������ ������ �ʾҴٸ�
	//0 = �Ұ� 1 = ���� 2 = ���ӳ�
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
		//4�������� ������ ���� ��� ����
		int status = isRollable(r, b, i);
		//�������: 1���� �� ������ ������
		if (status == 2) {
			return rolled + 1;
		}
		else if (status == 1) {
			//������ ��ȭ�� �־��ٸ�
			if (r != rRolled || b != bRolled) {
				total = min(total, minRoll(rRolled, bRolled, rolled + 1));
			}
		}
	}
	return total;
}
