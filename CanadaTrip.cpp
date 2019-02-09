#include "pch.h"
#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>

using namespace std;
int townNum,target;
vector<vector<int>> townInfo;
enum town {
	Town_Position,
	Sign_First,
	Sign_Gap
};
bool decision(int dist);
int optimize();
//����ȭ������ ���� ������ �ٲپ� Ǯ��
//x���� ���� ���� �ִ°�? �� �ٲپ�� �ܼ�������
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> townNum;
		cin >> target;
		//[������ȣ][���������κ����� �Ÿ�, ù ǥ���ǰ� �������� �Ÿ�, ǥ���� ����]
		townInfo = vector<vector<int>>(townNum,vector<int>(3));
		for (int i = 0; i < townNum; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> townInfo[i][j];
			}
		}
		cout << optimize() << endl;
	}
	return 0;
}
//dist ���� Ž�������� Target �̻��� ǥ������ ���� �ִ°�
bool decision(int dist) {
	int result = 0;
	for (int i = 0; i < townNum; i++) {
		//i��° ������ ǥ������ ��Ÿ���� �κб��� dist�� ���°�
		if (dist >= townInfo[i][Town_Position] - townInfo[i][Sign_First]) {
			//town���� �ִ� ������ �Ÿ� - ù ǥ���� ���� ��� / ���� +1(0�̿��� ǥ���� 1���� ���´�)
			result += (min(dist, townInfo[i][Town_Position]) - (townInfo[i][Town_Position] - townInfo[i][Sign_First])) / townInfo[i][Sign_Gap] + 1;
		}
	}
	if (result >= target) {
		return true;
	}
	else {
		return false;
	}
}

int optimize() {
	//������ �ִ� �Ÿ� high
	int low = 0, high = 8030000;
	//��Ȯ�� ��, low==high�� ���� ���ؾ� �ϹǷ� ��� ������
	while (low + 1 < high) {
		int mid = (low + high) / 2;
		if (decision(mid)) {
			//�ʹ� �����Ƿ�
			high = mid;
		}
		else {
			//�� �����Ƿ�
			low = mid;
		}
	}
	return high;
}