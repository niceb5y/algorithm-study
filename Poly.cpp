#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tiling(int input);
const int maxCase = 10000000;
int squareNum;
vector<vector<int>> cache;
int poling(int square, int lastwidth);
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> squareNum;
		cache = vector<vector<int>>(squareNum + 2, vector<int>(squareNum + 2, -1));
		int total = 0;
		for (int i = 1; i <= squareNum; i++) {
			total += poling(squareNum,i);
			total %= maxCase;
		}
		cout << total << endl;
	}
	return 0;
}
//������ ���簢������ ���� ������ ������̳� �����ϱ�
//�� ���������� �Ʒ��� �ϳ��� ������̳븦 ������Ų��
//square��ŭ�� �簢������ ������, �� ������ topwidth��ŭ�� ���̸� ���� ������̳��� ���� ��ȯ
int poling(int square, int topwidth)
{
	//�������: �׾ƾ��� �簢���� ���� ������ �ٿ� ���Ƴ�����
	if (square == topwidth) {
		return 1;
	}
	int& memo = cache[square][topwidth];
	if (memo != -1) {
		return memo;
	}
	memo = 0;
	//�ι�°�ٿ� ���� �簢���� ����
	for (int second = 1; second <= square - topwidth; second++) {
		//�� ���ٿ� second ��ŭ�� ������ �簢���� ������ �ִ� ����� ��
		int pileCase = topwidth + second - 1;
		//������̳� �Ʒ��� ������̳�� ��ü������ ������̳밡 �ȴ�
		//second�� ���� ���� ������ ������̳��� ����Ǽ��� ����� ���� ������
		pileCase *= poling(square - topwidth, second);
		pileCase %= maxCase;
		memo += pileCase;
		memo %= maxCase;
	}
	return memo;
}
