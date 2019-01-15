#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> numList;
vector<int> cache;
int setDifficulty(int start, int num);
int memoring(int start);
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
int main() {
	int testcase;
	string inputNum;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> inputNum;
		//ó������ ������ ������ ����� �� ��� ������ ���� �־��༭ �ڵ�ȭ ��Ų��
		numList = vector<int>(inputNum.size() + 3);
		cache = vector<int>(inputNum.size()+3, -1);
		numList[0] = -999;
		numList[1] = -999;
		numList[2] = -999;
		for (int i = 3; i < inputNum.size() + 3; i++) {
			numList[i] = inputNum.at(i-3) - '0';
		}
		//������ ���� ���� ���� ���ش�
		cout << memoring(0)-1 << endl;
	}
	return 0;
}
//������ ������ ���̵� ����
int setDifficulty(int start, int num)
{
	int firstWord = numList[start];
	//1������ ���ڰ� ���ӵǸ� ���̵� 1
	bool is1 = true;
	for (int i = 0; i < num; i++) {
		if (firstWord != numList[start + i]) {
			is1 = false;
			break;
		}
	}
	if (is1) {
		return 1;
	}
	//���������ϰ�츦 �Ǵ�
	int set2or5 = numList[start] - numList[start+1];
	bool is2or5 = true;
	for (int i = 0; i < num - 1; i++) {
		if (numList[start + i] - numList[start + i + 1] != set2or5) {
			is2or5 = false;
			break;
		}
	}
	if (is2or5) {
		//1�� �þ�ų� �پ���� ���̵��� 2
		if (set2or5 == 1 || set2or5 == -1) {
			return 2;
		}
		//�̿��� ���������� ��� ���̵��� 5
		else {
			return 5;
		}
	}
	//���ڰ� ������ ������ ��츦 �Ǵ�
	vector<int> twiceList = vector<int>(2,numList[start]);
	twiceList[1] = numList[start + 1];
	bool is4 = true;
	for (int i = 0; i < num; i++) {
		if (numList[start + i] != twiceList[i % 2]) {
			is4 = false;
			break;
		}
	}
	if (is4) {
		return 4;
	}
	return 10;
}

//����Լ�
int memoring(int start)
{
	if (start >= numList.size()) {
		return 0;
	}
	int& memo = cache[start];
	if (memo != -1) {
		return memo;
	}
	//memo���� �ִ��� �����ϳ� ���߿� ���̵��� �߰��� ��������
	//�����÷θ� �����ؼ� ������ ū ���� �����صд�.
	memo = 9999999;
	if (start == 0) {
		memo = min(memo, memoring(start + 3) + setDifficulty(start, 3));
	}
	else {
		for (int i = 3; i <= 5; i++) {
			if (start + i <= numList.size()) {
				memo = min(memo, memoring(start + i) + setDifficulty(start, i));
			}
		}
	}
	return memo;
}


