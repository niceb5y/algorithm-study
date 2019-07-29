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
	//true == 사과
	isPPorAP = vector<vector<bool>>(row, vector<bool>(column, false));
	//<사과 부분합, 바나나 부분합>
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
	//부분합 만들기
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
	//바텀 - 업 방식으로 채워나가기
	for (int i = row - 2; i >= 0; i--) {
		for (int j = column - 2; j >= 0; j--) {
			int maxFruit = 0;
			//아래로 움직인경우 가로열의 바나나는 확정적으로 얻게된다
			maxFruit = max(maxFruit, cache[i + 1][j] + subsum[i][j].second);
			//왼쪽으로 움직인 경우 세로열의 사과는 확정적으로 얻게된다
			maxFruit = max(maxFruit, cache[i][j + 1] + subsum[i][j].first);
			//대각선으로 움직인경우 가로와 세로열의 모든 과일을 확정적으로 얻게된다
			maxFruit = max(maxFruit, cache[i + 1][j + 1] + subsum[i][j].first + subsum[i][j].second);
			cache[i][j] = maxFruit;
		}
	}
	cout << cache[0][0] << endl;
	return 0;
}
