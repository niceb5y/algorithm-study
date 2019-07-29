#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string first, second;
vector<vector<int>> cache;
int setMaxLCS(int a, int b);
void decode(int a, int b);
bool reachEnd;
int main() {
	cin >> first;
	cin >> second;
	cache = vector<vector<int>>(first.length(), vector<int>(second.length(), -1));
	cout << setMaxLCS(0, 0) << endl;
	reachEnd = false;
	decode(0, 0);
}

int setMaxLCS(int a, int b)
{
	if (cache[a][b] != -1) {
		return cache[a][b];
	}
	int temp = 0;
	if (a == first.length() - 1) {
		for (int tempIndex = b; tempIndex < second.length(); tempIndex++) {
			if (first.at(a) == second.at(tempIndex)) {
				cache[a][b] = 1;
				return 1;
			}
		}
		cache[a][b] = 0;
		return 0;
	}

	if (b == second.length() - 1) {
		for (int tempIndex = a; tempIndex < first.length(); tempIndex++) {
			if (first.at(tempIndex) == second.at(b)) {
				cache[a][b] = 1;
				return 1;
			}
		}
		cache[a][b] = 0;
		return 0;
	}

	if (first.at(a) == second.at(b)) {
		temp = setMaxLCS(a + 1, b + 1) + 1;
	}
	else {
		temp = max(temp, setMaxLCS(a, b + 1));
		temp = max(temp, setMaxLCS(a + 1, b));
	}
	cache[a][b] = temp;
	return temp;
}

void decode(int a, int b)
{
	if (reachEnd) {
		return;
	}
	int currMax = setMaxLCS(a, b);
	if (currMax == 0) {
		return;
	}

	if (a == first.length() - 1 && currMax == 1) {
		cout << first.at(a);
		reachEnd = true;
		return;
	}
	if (b == second.length() - 1 && currMax == 1) {
		cout << second.at(b);
		reachEnd = true;
		return;
	}

	if (first.at(a) == second.at(b)) {
		cout << first.at(a);
		if (currMax == 1) {
			reachEnd = true;
			return;
		}
		decode(a + 1, b + 1);
	}
	if (currMax == setMaxLCS(a + 1, b)) {
		decode(a + 1, b);
	}
	if (currMax == setMaxLCS(a, b + 1)) {
		decode(a, b + 1);
	}
}
