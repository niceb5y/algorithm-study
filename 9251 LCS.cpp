#include "pch.h"

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string first, second;
vector<vector<int>> cache;
int largestLCS(int a, int b);
int main() {
	cin >> first;
	cin >> second;
	cache = vector<vector<int>>(first.length(),vector<int>(second.length(),-1));
	cout << largestLCS(0, 0) << endl;
}

int largestLCS(int a, int b)
{
	if (cache[a][b] != -1) {
		return cache[a][b];
	}
	int temp = 0;
	if (a == first.length() - 1){

		for (int tempIndex = b; tempIndex < second.length(); tempIndex++) {
			if (second.at(tempIndex) == first.at(a)) {
				temp = 1;
				cache[a][b] = 1;
				return temp;
			}
		}
		return temp;
	}
	if (b == second.length() - 1) {

		for (int tempIndex = a; tempIndex < first.length(); tempIndex++) {
			if (first.at(tempIndex) == second.at(b)) {
				temp = 1;
				cache[a][b] = 1;
				return temp;
			}
		}
		return temp;
	}

	if (first.at(a) == second.at(b)) {
		temp = largestLCS(a + 1, b + 1) + 1;
	}
	else {
		temp = max(temp, largestLCS(a + 1, b));
		temp = max(temp, largestLCS(a, b + 1));
	}
	cache[a][b] = temp;
	return temp;
}
