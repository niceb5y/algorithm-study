#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> Triangle, cache;
int triangleDepth;
int findDepth(int x, int y);
int main() {
	cin >> triangleDepth;
	Triangle = vector<vector<int>>(triangleDepth, vector<int>(triangleDepth, -1));
	cache = vector<vector<int>>(triangleDepth, vector<int>(triangleDepth, -1));
	for (int i = 0; i < triangleDepth; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> Triangle[i][j];
		}
	}
	cout << findDepth(0, 0) << endl;
}

int findDepth(int x, int y)
{
	if (cache[x][y] != -1) {
		return cache[x][y];
	}
	if (x == triangleDepth - 1) {
		cache[x][y] = Triangle[x][y];
		return Triangle[x][y];
	}
	int temp = 0;
	temp = max(temp, Triangle[x][y] + findDepth(x + 1, y));
	temp = max(temp, Triangle[x][y] + findDepth(x + 1, y + 1));
	cache[x][y] = temp;
	return temp;
}
