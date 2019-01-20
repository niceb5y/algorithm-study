#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int depth, limitDay;
vector<vector<double>> cache;
double goBed(int depth, int days);
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
int main() {
	cout << fixed;
	cout.precision(11);
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> depth;
		cin >> limitDay;
		cache = vector<vector<double>>(depth, vector<double>(limitDay, -1.0));
		cout << goBed(0, 0) << endl;
	}
	return 0;
}
//������ �칰 ������ ����
//����� ���� ������ ����Ž���� �⺻���� �Ѵ�
double goBed(int climbed, int days)
{
	if (days >= limitDay) {
		if (climbed >= depth) {
			return 1.0;
		}
		else {
			return 0.0;
		}
	}
	if (climbed >= depth) {
		return 1.0;
	}
	double& memo = cache[climbed][days];
	if (memo != -1.0) {
		return memo;
	}
	//����� �� ������ Ȯ���� �ο��ɶ� �� ����� ���� Ȯ���� �����ش�
	memo = 0.75*goBed(climbed + 2, days + 1) + 0.25*goBed(climbed + 1, days + 1);
	return memo;
}
