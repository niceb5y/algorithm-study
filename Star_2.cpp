#include "pch.h"
#include <iostream>
using namespace std;
int lineNum;
int main() {
	cin >> lineNum;
	for (int i = 1; i <= lineNum; i++) {
		for (int j = 1; j <= lineNum - i; j++) {
			cout << ' ';
		}
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		if (i != lineNum) {
			cout << endl;
		}
	}
	return 0;
}