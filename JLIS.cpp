#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cache;
vector<int> board1, board2;
int jlis(int input1, int input2);
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
//LIS�� 2���� ���� ���̿��� ���Ѵ�
int main() {
	int testcase, length1, length2, temp;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> length1;
		cin >> length2;
		//���� ù�迭�� ù���� ���� �ǳʶ��� �߻� �Ҽ� �ִ�
		cache = vector<vector <int>>(length1+1, vector<int>(length2+1,-1));
		//�迭�� ũ�⸦ 1�� �ø���
		board1 = vector<int>(length1+1);
		board2 = vector<int>(length2+1);
		for (int i = 1; i < length1+1; i++) {
			cin >> board1[i];
		}
		for (int i = 1; i < length2+1; i++) {
			cin >> board2[i];
		}
		//ù��°ĭ�� �ּҰ����� �д�
		board1[0] = INT32_MIN;
		board2[0] = INT32_MIN;
		int maxLength = 0;
		//�Ǿ��� �ּҰ��̱⶧���� for���� ��� �˾Ƽ� ���ȴ�
		maxLength = max(maxLength, jlis(0, 0));
		//�Ǿ��� �ּҰ�ũ�� 2���� ������
		cout << maxLength - 2 << endl;
	}
	return 0;
}
//��ģ LIS
int jlis(int input1, int input2)
{
	int& temp = cache[input1][input2];
	if (temp != -1) {
		return temp;
	}
	//�̹����� �ΰ��� ����� ���ԵǹǷ� 2�� �����ش�.
	//�ʹ��� �ּڰ� 2���� �� ���̹Ƿ� ���߿� ���ش�
	temp = 2;
	int maxNumber = max(board1[input1], board2[input2]);
	for (int i = input1 + 1; i < board1.size(); i++) {
		if (maxNumber < board1[i]) {
			temp = max(temp, 1 + jlis(i, input2));
		}
	}
	for (int j = input2 + 1; j < board2.size(); j++) {
		if (maxNumber < board2[j]) {
			temp = max(temp, 1 + jlis(input1, j));
		}
	}
	return temp;
}
