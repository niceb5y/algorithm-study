#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lanNum, needLan;
vector<long long> lanLen;
bool isCuttuable(long long len);
int main() {
	cin >> lanNum;
	cin >> needLan;
	lanLen = vector<long long>(lanNum);
	long long maxLen = 0;
	for (int i = 0; i < lanNum; i++) {
		cin >> lanLen[i];
		maxLen = max(maxLen,lanLen[i]);
	}
	long long high = maxLen * lanNum, low = 1, mid = (high + low) / 2;
	while (true)
	{
		if (high - low <= 1) {
			if (isCuttuable(high)) {
				cout << high << endl;
				return 0;
			}
			cout << low << endl;
			return 0;
		}
		if (isCuttuable(mid)) {
			low = mid;
		}
		else {
			high = mid;
		}
		mid = (high + low) / 2;
	}
}

bool isCuttuable(long long len)
{
	int leftLan = needLan;
	for (int i = 0; i < lanNum; i++) {
		leftLan -= lanLen[i] / len;
		if (leftLan <= 0) {
			return true;
		}
	}
	return false;
}
