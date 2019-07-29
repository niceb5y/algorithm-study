#include "pch.h"

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int nMinus2 = 0, nMinus1 = 1, n;
	int target, temp;
	cin >> target;
	for (int i = 0; i < target - 1; i++) {
		temp = nMinus2 + nMinus1;
		nMinus2 = nMinus1;
		nMinus1 = temp;
	}
	cout << nMinus1 << endl;
}