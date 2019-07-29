#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMove(int xPos, int yPos);

const vector<int> xMove = { -1,1,0,0 };
const vector<int> yMove = { 0,0,1,-1 };
int fieldSize;
vector<vector<int>> bambooField;
vector<vector<int>> cache;

int main() {
	cin >> fieldSize;
	bambooField = vector<vector<int>>(fieldSize, vector<int>(fieldSize, -1));
	cache = vector<vector<int>>(fieldSize, vector<int>(fieldSize, -1));

	for (int i = 0; i < fieldSize; i++) {
		for (int j = 0; j < fieldSize; j++) {
			cin >> bambooField[i][j];
		}
	}
	int maxLive = 1;
	for (int i = 0; i < fieldSize; i++) {
		for (int j = 0; j < fieldSize; j++) {
			maxLive = max(maxLive, maxMove(i, j));
		}
	}
	cout << maxLive << endl;
	return 0;
}
//�̹� ��ǥ������ �Ϸ�� �̹� �Լ����� ���ϴ°����� ����
int maxMove(int xPos, int yPos)
{
	if (cache[xPos][yPos] != -1) {
		return cache[xPos][yPos];
	}
	int maxLive = 1;
	for (int direction = 0; direction < 4; direction++) {
		int nextX = xPos + xMove[direction];
		int nextY = yPos + yMove[direction];
		//���� �ʰ��Ͻ�
		if (nextX < 0 || nextX >= fieldSize || nextY < 0 || nextY >= fieldSize) {
			continue;
		}
		//������ҿ� �볪���� ������
		if (bambooField[xPos][yPos] >= bambooField[nextX][nextY]) {
			continue;
		}
		maxLive = max(maxLive, maxMove(nextX, nextY) + 1);
	}
	cache[xPos][yPos] = maxLive;
	return maxLive;
}
