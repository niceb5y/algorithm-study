#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> board;
vector<vector<int>> cache;
int parts;
int quantize(int start, int parts);
int minError(int start, int num);
//���� ��ȹ��(���� �κ� ����)
//�κ� �������� �� �ִ� ������ ���س���
int main() {
	int testcase, boardSize;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		board = vector<int>(boardSize);
		cin >> parts;
		cache = vector<vector<int>>(boardSize, vector<int>(parts+1, -1));
		for (int i = 0; i < boardSize; i++) {
			cin >> board[i];
		}
		//����ȭ�� A ���� ū B�� A�� ����ȭ������ ������ ����
		//����ȭ�� ������ n ����� �ᱹ ���ĵ� ������ n���� �����°Ŷ� ����
		sort(board.begin(), board.end());
		cout << quantize(0, parts) << endl;
	}
	return 0;
}
//����ȭ: ī�޶��� ���ø� ����Ѱ� ������ �ּ�ȭ�϶�
//
int quantize(int start, int needParts)
{
	//�迭�� ������ �����ҽ�
	if (start == board.size()) {
		return 0;
	}
	//�迭�� ���� �������� �ʾ����� ���� ��Ʈ�� ��������
	//�߸� �й��Ѱ� Ȯ���ϹǷ� �ſ� ū �� ����
	if (needParts == 0) {
		//���� ������� �ٸ� ���̶� ������ �����÷ΰ� �Ͼ�� �ִ�
		//������ ū ���� ��������
		return 99999999;
	}
	//�޸������̼�
	int& memo = cache[start][needParts];
	if (memo != -1) {
		return memo;
	}
	memo = 99999999;
	//ù ������ ����� �� ������ �迭�� ������ �������� ������
	//�������ǿ� ���� for�� ���ǽĵ� �ٲ�� �Ѵ�
	//���� ũ�⸦ ���������Ƿ� ����ũ����� ��� ���Ѿ��Ѵ�
	for (int jump = 1; start + jump <= board.size(); jump++) {
		memo = min(memo, quantize(start + jump, needParts - 1) + minError(start, jump));
	}
	return memo;
}
//�ּ� ���� ���ϱ�
int minError(int start, int num)
{
	int avarage = 0,result = 0;
	for (int i = 0; i < num; i++) {
		avarage += board[start + i];
	}
	//�������� �����Ѵ�
	avarage = (int)(((double)avarage / num) + 0.5);
	//�������� ������ ������ ������ ���Ѵ�
	for (int i = 0; i < num; i++) {
		result += pow(avarage - board[start + i],2);
	}
	return result;
}
