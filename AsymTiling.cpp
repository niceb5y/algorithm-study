#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tiling(int input);
int asyctiling(int width);
const int maxCase = 1000000007;
int boardSize;
vector<int> asynccache;
vector<int> cache;
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		cache = vector<int>(boardSize + 1, -1);
		asynccache = vector<int>(boardSize + 1, -1);
		cout << asyctiling(boardSize) << endl;
	}
	return 0;
}
//��Ī�� ���� �ʴ� ������� Ÿ���� ��ġ�غ���

//��Ī���϶� �� �Լ��� �̿��Ѵ�
//���� ������ Ÿ�ϸ��� �Ѵ�
int asyctiling(int width) {
	if (width <= 2) {
		return 0;
	}
	int& memo = asynccache[width];
	if (memo != -1) {
		return memo;
	}
	memo = 0;
	//���� �� ���� ä��� �ִ� ����� ���� �� 4�����̴�
	//�� ���� ������ ä������ ��Ī���̴�
	memo = (memo + asyctiling(width - 2)) % maxCase;
	//�� ���� ������ ä������ ��Ī���̴�
	memo = (memo + asyctiling(width - 4)) % maxCase;
	//���� ���� ������ ä���, ������ ���� ������ ä������ ���Ī�� Ȯ���ȴ�
	memo = (memo + tiling(width - 3)) % maxCase;
	//������ ���� ������ ä���, ���� ���� ������ ä������ ���Ī�� Ȯ���ȴ�

	//�Ѱ����� ��Ʈ�� maxCase��ŭ�� ���� �Ѿ�� �����Ƿ� ���� �ι� ����Ѵ�
	//���ѵ� ���� �־����� �׻� �����÷θ� ��������
	memo = (memo + tiling(width - 3)) % maxCase;
	return memo;
	
}
//���Ī�� Ȯ���Ǹ� ���� Ÿ�ϸ� ����� �̿��Ѵ�
//���������� Ÿ�ϸ��Ѵ�
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
		memo = (tiling(input - 1) + tiling(input - 2)) % maxCase;
		return memo;
	}
}