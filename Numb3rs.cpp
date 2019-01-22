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
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
//�������� ���� ����(���Ѱ��� ����, �� �ð����� ���º���, a->b�Ҷ� a�� ���¿��� �¿��,�ð��� ��ǿ� ������)
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
//leftday �Ŀ� here�� ��ġ�� Ȯ���� ���غ���
//�������� ������ �����Ƿ� �Ųٷ� Ǫ�°� �� ����
double gotoBed(int here, int leftday)
{
	//�����Ͽ� ����������
	if (leftday == 0) {
		//�������� ���ٸ� ����
		if (here == prisontown) {
			return 1.0;
		}
		//�� �ܿ��� ����
		return 0.0;
	}
	//�޸������̼�
	double& memo = cache[here][leftday];
	if (memo != -1.0) {
		return memo;
	}
	memo = 0.0;
	for (int nexttown = 0; nexttown < totalvillige; nexttown++) {
		if (board[here][nexttown] == 1) {
			//�������� �Ѿ�ü� �ִ� Ȯ���� ���Ѵ�
			memo += gotoBed(nexttown, leftday - 1) / connectednumlist[nexttown];
		}
	}
	return memo;
}
