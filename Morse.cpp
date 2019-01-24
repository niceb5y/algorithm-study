#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int longnum, shortnum, target;
vector<vector<int>> binary;
string generate(int n, int m, int skip);
//�ظ� ���� ���ؾ� �ϴ� ���� ��ȹ��
//k��° ���� �����س��� �Ѵ�
int main() {
	//���װ���� �̸� ����� ���´�
	binary = vector<vector<int>>(201, vector<int>(201, 0));
	for (int i = 0; i <= 200; i++) {
		binary[i][0] = binary[i][i] = 1;
		for (int j = 1; j < i; j++) {
			binary[i][j] = min(1000000000, binary[i - 1][j - 1] + binary[i - 1][j]);
		}
	}

	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> longnum;
		cin >> shortnum;
		cin >> target;
		if (target >= binary[longnum + shortnum][longnum]) {
			cout << generate(longnum, shortnum, binary[longnum + shortnum][longnum]) << endl;
		}
		else {
			cout << generate(longnum, shortnum, target - 1) << endl;
		}
	}
	return 0;
}
//k��° �� ���ϱ�: ��� ��츦 Ž���ϴ� ���� Ž�� ��ݿ� ���� ��ȹ������ �ٲ۴�
//���� ���������� �����ϸ� k-1������ �ǳʶٴ� ����� �̿��Ѵ�.
//�������� ���� k��°�� �Ҽӵ� ���� �ƴѰ�츦 ����ؼ� Ž���� ���� �������� �ٿ� ������.
//������ ������ ������ ������ �־����� skip+1���� �迭�� ���
string generate(int longsign, int shortsign, int skip)
{
	//�������: longsign=0�Ͻ� shortsign�����
	if (longsign == 0) {
		return string(shortsign,'O');
	}
	//���� skip�� ������ ������ �������� �����Ұ��
	if (skip < binary[longsign + shortsign - 1][longsign - 1]) {
		return "-" + generate(longsign - 1, shortsign, skip);
	}
	//�� ���ϰ��, skip���� �������� ������ŭ�� ���� ����Ѵ�
	return "O" + generate(longsign, shortsign - 1, skip - binary[longsign + shortsign - 1][longsign - 1]);
}
