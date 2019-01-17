#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int tiling(int input);
vector<int> cache;
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
int main() {
	int testcase, boardSize;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		cache = vector<int>(boardSize + 1, -1);
		cout << tiling(boardSize) << endl;
	}
	return 0;
}

int tiling(int input)
{
	if (input <= 1) {
		return 1;
	}
	int& memo = cache[input];
	if (memo != -1) {
		return memo;
	}
	else {
		memo = (tiling(input - 1) + tiling(input - 2)) % 1000000007;
		return memo;
	}
}
