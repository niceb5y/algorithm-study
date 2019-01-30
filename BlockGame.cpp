#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int board;
vector<short> cache;
vector<int> tilingTypes;
int cellBinaring(int x, int y);
void makeCase();
short gaming(int board);
//������ �ʽ¹��� ã�� ���� ��ȹ��
int main() {
	int testcase;
	cin >> testcase;
	//Ÿ���� ���� ��� ����� �� ����� ����
	makeCase();
	cache = vector<short>(1 << 25 ,-1);
	for (int trial = 0; trial < testcase; trial++) {
		board = 0;
		string inputStream;
		//25����ĭ�� ��� �����ְų� ��������� �� 2�� 25�¸�ŭ ����� ���� �ִ�
		for (int i = 0; i < 5; i++) {
			cin >> inputStream;
			for (int j = 0; j < inputStream.size(); j++) {
				if (inputStream[j] == '#') {
					board = board | (1 << (i * 5 + j));
				}
			}
		}
		if (gaming(board)) {
			cout << "WINNING" << endl;
		}
		else{
			cout << "LOSING" << endl;
		}
	}
	return 0;
}

int cellBinaring(int x, int y)
{
	return 1<<(5*x+y);
}

void makeCase()
{
	//3ĭ¥�� Ÿ�� ���
	//x,y ��ǥ
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			vector<int> squareCells;
			int square = 0;
			//��ǥ�� �簢������ �Ѱ��� ����
			for (int x = 0; x < 2; x++) {
				for (int y = 0; y < 2; y++) {
					squareCells.push_back(cellBinaring(i + x, j + y));
					square += cellBinaring(i + x, j + y);
				}
			}
			for (int i = 0; i < 4; i++) {
				tilingTypes.push_back(square - squareCells[i]);
			}
		}
	}
	//2ĭ¥�� Ÿ���ϰ��
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			tilingTypes.push_back(cellBinaring(i, j) + cellBinaring(i, j + 1));
			tilingTypes.push_back(cellBinaring(j, i) + cellBinaring(j + 1, i));
		}
	}
}
//���� �־����� ���� ��Ÿĥ�� �ִ��� ����
short gaming(int board)
{
	short& memo = cache[board];
	if (memo != -1) {
		return memo;
	}
	memo = 0;
	for (int i = 0; i < tilingTypes.size(); i++) {
		//��ġ�°� �ϳ��� ������
		if (!(board & tilingTypes[i])) {
			//��밡 �̱�� ���ٸ�
			if (!gaming(board | tilingTypes[i])) {
				//���� �̱��
				memo = 1;
				break;
			}
		}
	}
	return memo;
}
