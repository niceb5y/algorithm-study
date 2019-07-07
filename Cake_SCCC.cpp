#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> aNum = vector<int>(3), cNum = vector<int>(3);
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> aNum[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> cNum[i];
	}
	cout << cNum[0] - aNum[2] << ' ';
	cout << cNum[1] / aNum[1] << ' ';
	cout << cNum[2] - aNum[0];
	return 0;
}