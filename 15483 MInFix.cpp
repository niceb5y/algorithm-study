#include "pch.h"

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

vector<vector<int>> cache;
string first, second;
int minFixer(int a, int b);
int main() {
	cin >> first;
	cin >> second;
	cache = vector<vector<int>>(first.length() + 1, vector<int>(second.length() + 1, -1));
	cout << minFixer(first.length(), second.length());
}

int minFixer(int a, int b)
{
	if (cache[a][b] != -1) {
		return cache[a][b];
	}
	if (a == 0) {
		cache[a][b] = b;
		return b;
	}
	if (b == 0) {
		cache[a][b] = a;
		return a;
	}

	int temp = 1000*1000;
	int editCost = 1;
	if (first.at(a - 1) == second.at(b - 1)) {
		editCost = 0;
	}
	temp = min(temp, minFixer(a - 1, b - 1) + editCost);
	temp = min(temp, minFixer(a, b - 1) + 1);
	temp = min(temp, minFixer(a - 1, b) + 1);
	cache[a][b] = temp;
	return temp;
}
