#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> paintDistances;
vector<vector<int>> cache;
int vectorSize;
int minCost(int tempHouse, int tempColor);

int main() {
	cin >> vectorSize;
	paintDistances = vector<vector<int>>(vectorSize, vector<int>(3, -1));
	cache = vector<vector<int>>(vectorSize, vector<int>(3, -1));
	for (int i = 0; i < vectorSize; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> paintDistances[i][j];
		}
	}
	int temp = 1000 * vectorSize;
	for (int i = 0; i < 3; i++) {
		temp = min(temp, minCost(0, i));
	}
	cout << temp << endl;
}

int minCost(int tempHouse, int tempColor){
	int temp;
	if (cache[tempHouse][tempColor] != -1) {
		return cache[tempHouse][tempColor];
	}
	if (tempHouse == vectorSize - 1) {
		return paintDistances[tempHouse][tempColor];
	}
	temp = 1000 * vectorSize;
	for (int i = 1; i < 3; i++) {
		temp = min(temp, paintDistances[tempHouse][tempColor] + minCost(tempHouse + 1, (tempColor + i) % 3));
	}
	cache[tempHouse][tempColor] = temp;
	return temp;
}
