#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cache;
vector<int> board;
int lis(int input);
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
int main() {
	int testcase, length,temp;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> length;
		cache = vector<int>(length, -1);
		board = vector<int>(length);
		for (int i = 0; i < length; i++) {
			cin >> board[i];
		}
		int maxLength = 0;
		//��� ��ġ���� �����غ���
		for (int i = 0; i < length; i++) {
			maxLength = max(maxLength, lis(i));
		}
		cout << maxLength << endl;
	}
	return 0;
}
//���� �κ� ���� ���ϱ�
int lis(int input)
{
	int& temp = cache[input];
	if (temp != -1) {
		return temp;
	}
	//input ��ġ�� ���Ҵ� ���ԵǹǷ� 1�� �־��ش�
	temp = 1;
	//�ڱ� �ڽź��� ū ���� �����ؼ� �� ������ ���۵Ǵ� �ִ� �������� ���ϱ�
	for (int i = input + 1; i < board.size(); i++) {
		if (board[input] < board[i]) {
			//������ �� ù���ڴ� ������ ������ �����Ƿ� 1�� �����൵ ���������� �����ȴ�
			temp = max(temp,1+lis(i));
		}
	}
	return temp;
}
