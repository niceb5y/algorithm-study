#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> PPAPTreeField;
vector<vector<bool>> isPPorAP;
vector<vector<pair<int,int>>> subsum;
vector<vector<int>> cache;
int row, column;
int main() {
	cin >> row;
	cin >> column;
	string temp;
	PPAPTreeField =  vector<vector<int>>(row, vector<int>(column, -1));
	//true == ���
	isPPorAP = vector<vector<bool>>(row, vector<bool>(column, false));
	//<��� �κ���, �ٳ��� �κ���>
	subsum = vector<vector<pair<int,int>>>(row, vector<pair<int,int>>(column));
	cache = vector<vector<int>>(row, vector<int>(column, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> temp;
			if (temp.at(0) == 'A') {
				isPPorAP[i][j] = true;
			}
			temp = temp.substr(1);
			PPAPTreeField[i][j] = atoi(temp.c_str());
		}
	}
	//�κ��� �����
	for (int i = row -1; i >= 0 ; i--) {
		for (int j = column -1; j >=0; j--) {
			if (i == row - 1 || j == column - 1) {
				subsum[i][j] = make_pair(0, 0);
			}
			else {
				int AppleSum = subsum[i + 1][j].first;
				int BananaSum = subsum[i][j + 1].second;
				if (isPPorAP[i + 1][j]) {
					AppleSum += PPAPTreeField[i + 1][j];
				}
				if (!isPPorAP[i][j + 1]) {
					BananaSum += PPAPTreeField[i][j + 1];
				}
				subsum[i][j] = make_pair(AppleSum, BananaSum);
			}
		}
	}
	//���� - �� ������� ä��������
	for (int i = row - 2; i >= 0; i--) {
		for (int j = column - 2; j >= 0; j--) {
			int maxFruit = 0;
			//�Ʒ��� �����ΰ�� ���ο��� �ٳ����� Ȯ�������� ��Եȴ�
			maxFruit = max(maxFruit, cache[i + 1][j] + subsum[i][j].second);
			//�������� ������ ��� ���ο��� ����� Ȯ�������� ��Եȴ�
			maxFruit = max(maxFruit, cache[i][j + 1] + subsum[i][j].first);
			//�밢������ �����ΰ�� ���ο� ���ο��� ��� ������ Ȯ�������� ��Եȴ�
			maxFruit = max(maxFruit, cache[i + 1][j + 1] + subsum[i][j].first + subsum[i][j].second);
			cache[i][j] = maxFruit;
		}
	}
	cout << cache[0][0] << endl;
	return 0;
}
