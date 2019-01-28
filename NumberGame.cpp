#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> board;
vector<vector<int>> cache;
int boardSize;
int casemin = INT16_MIN;
int play(int left, int right);
//������ �ʽ¹��� ã�� ���� ��ȹ��
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		board = vector<int>(boardSize);
		cache = vector<vector<int>>(boardSize, vector<int>(boardSize,casemin));
		for (int i = 0; i < boardSize; i++) {
			cin >> board[i];
		}
		cout << play(0, boardSize - 1) << endl;
	}
	return 0;
}
//������ �˰����� ƽ����� ����ϴ�
//�μ��� ��ȣ�����ɷ� ������ ���� ǥ���ϴ°� �߿�
int play(int left, int right)
{
	//�������: ��� ���ڴ� ó���Ǿ�����
	if (left > right) {
		return 0;
	}
	int&memo = cache[left][right];
	if (memo != casemin) {
		return memo;
	}
	//���� �������°��
	//�̹� ī���� ������ ���ѰͿ��� ������ ������ ����
	memo = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));
	//���� ������ ����ϴµ���
	if (right - left > 0) {
		//�̹��� 2���� �����ϹǷ� ���� ���� ���¿��� ������ ������ ��´�
		memo = max(memo, -play(left + 2, right));
		memo = max(memo, -play(left, right - 2));
	}
	return memo;
}
