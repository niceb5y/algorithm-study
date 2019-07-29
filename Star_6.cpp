#include "pch.h"
#include <iostream>
using namespace std;

int lineNum;
int main() {
	cin >> lineNum;
	for (int i = 0; i < lineNum; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < lineNum - i - 1; j++) {
			cout << '*';
		}
		cout << "*";
		for (int j = 0; j < lineNum - i - 1; j++) {
			cout << '*';
		}
		if (i + 1 != lineNum) {
			cout << endl;
		}
	}
	return 0;
}