#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> cache;
int target;
int main() {
	cin >> target;
	cache = vector<vector<int>>(2, vector<int>(10, -1));
	cache[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		cache[0][i] = 1;
	}

	for (int i = 0; i < target; i++) {
		for (int j = 0; j < 10; j++) {
			cache[(i + 1) % 2][j] = 0;
		}
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				cache[(i + 1) % 2][j + 1] = (cache[(i + 1) % 2][j + 1] + cache[i % 2][j])% 1000000000;
			}
			else if (j == 9) {
				cache[(i + 1) % 2][j - 1] = (cache[(i + 1) % 2][j - 1] + cache[i % 2][j]) % 1000000000;
			}
			else {
				cache[(i + 1) % 2][j + 1] = (cache[(i + 1) % 2][j + 1] + cache[i % 2][j]) % 1000000000;
				cache[(i + 1) % 2][j - 1] = (cache[(i + 1) % 2][j - 1] + cache[i % 2][j]) % 1000000000;
			}
		}
	}
	int total = 0;
	for (int i = 0; i < 10; i++) {
		total = (total + cache[(target + 1) % 2][i])%1000000000;
	}
	cout << total << endl;
}