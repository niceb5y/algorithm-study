#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> board;
vector<vector<int>> pathcache;
vector<vector<int>> sizecache;
int drillDown(int y, int x);
int count(int y, int x);
int triangleSize;
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> triangleSize;
		board = vector<vector<int>>(triangleSize, vector<int>(triangleSize, 0));
		pathcache = vector<vector<int>>(triangleSize, vector<int>(triangleSize, -1));
		sizecache = vector<vector<int>>(triangleSize, vector<int>(triangleSize, -1));
		for (int i = 0; i < triangleSize; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> board[i][j];
			}
		}
		cout << count(0, 0) << endl;
	}
	return 0;
}

int drillDown(int y, int x)
{
	//�������: �ٴڿ� ������ �״�� ����
	if (y == triangleSize - 1) {
		return board[y][x];
	}
	int& temp = sizecache[y][x];
	if (temp != -1) {
		return temp;
	}
	//�ڱ� �ڽ� ������ �ִ����� ���� ���
	temp = max(drillDown(y + 1, x), drillDown(y + 1, x + 1)) + board[y][x];
	return temp;
}
//�ﰢ���� �ִ� ��� ��Ʈ ���� ���ϱ�
int count(int y, int x)
{
	//�������: �ٴڿ� ������ Ȯ�� ��Ʈ 1��
	if (y == triangleSize - 1) {
		return 1;
	}
	int& temp = pathcache[y][x];
	if (temp != -1) {
		return temp;
	}
	temp = 0;
	if (drillDown(y + 1, x) > drillDown(y + 1, x + 1)) {
		temp += count(y + 1, x);
	}
	else if (drillDown(y + 1, x) < drillDown(y + 1, x + 1)) {
		temp += count(y + 1, x + 1);
	}
	else if (drillDown(y + 1, x) == drillDown(y + 1, x + 1)) {
		temp += count(y + 1, x) + count(y + 1, x + 1);
	}
	return temp;
}
