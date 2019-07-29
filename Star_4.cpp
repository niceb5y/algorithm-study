#include "pch.h"
#include<iostream>
using namespace std;
int lineNum;
int main() {
	cin >> lineNum;
	for (int i = lineNum; i > 0; i--) {
		for (int j = 0; j < lineNum - i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < i; j++) {
			cout << '*';
		}
		if (i - 1 != 0) {
			cout << endl;
		}
	}
	return 0;
}