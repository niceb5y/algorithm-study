#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vectorSize;
vector<int> NeedLife;
vector<int> gainHappy;
vector<vector<int>> cache;
int Life = 100;
int getMaxHappy(int tempLife, int tempIndex);
int main() {
	cin >> vectorSize;
	NeedLife = vector<int>(vectorSize,-1);
	gainHappy = vector<int>(vectorSize, -1);
	for (int i = 0; i < vectorSize; i++) {
		cin >> NeedLife[i];
	}
	for (int i = 0; i < vectorSize; i++) {
		cin >> gainHappy[i];
	}
	cache = vector<vector<int>>(Life+1,vector<int>(vectorSize,-1));
	cout << getMaxHappy(Life, 0) << endl;
}

int getMaxHappy(int tempLife, int tempIndex)
{
	if (tempIndex == vectorSize) {
		return 0;
	}

	if (cache[tempLife][tempIndex] != -1) {
		return cache[tempLife][tempIndex];
	}
	int temp = 0;
	if (tempLife - NeedLife[tempIndex] > 0) {
		temp = max(temp, getMaxHappy(tempLife - NeedLife[tempIndex], tempIndex + 1) + gainHappy[tempIndex]);
	}
	temp = max(temp, getMaxHappy(tempLife, tempIndex + 1));
	cache[tempLife][tempIndex] = temp;
	return temp;
}
