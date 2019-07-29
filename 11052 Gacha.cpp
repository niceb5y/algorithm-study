#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vectorSize;
vector<int> price;
vector<vector<int>> cache;
int main() {
	cin >> vectorSize;
	price = vector<int>(vectorSize);
	for (int i = 0; i < vectorSize; i++) {
		cin >> price[i];
	}
	cache = vector<vector<int>>(2, vector<int>(vectorSize + 1, 0));
	for (int PackNum = 0; PackNum < vectorSize; PackNum++) {
		for (int cardNum = PackNum + 1; cardNum <= vectorSize; cardNum++) {
			cache[0][cardNum] = max(cache[0][cardNum], price[PackNum] + cache[0][cardNum - (PackNum + 1)]);
		}
	}
	cout << cache[0][vectorSize] << endl;
}