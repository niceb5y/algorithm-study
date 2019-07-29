#include "pch.h"
#include <iostream>
using namespace std;
int totalLine;
int main() {
	cin >> totalLine;
	for (int i = 0; i < totalLine; i++) {
		for (int j = 0; j <= i - 1; j++) {
			cout << ' ';
		}
		for (int j = 0; j < totalLine - i - 1; j++) {
			cout << '*';
		}
		cout << '*';
		for (int j = 0; j < totalLine - i - 1; j++) {
			cout << '*';
		}
		if (i + 1 != totalLine) {
			cout << endl;
		}
	}
	for (int i = 1; i < totalLine; i++) {
		cout << endl;
		for (int j = 0; j < totalLine-i -1; j++) {
			cout << ' ';
		}
		for (int j = 0; j <=i-1; j++) {
			cout << '*';
		}
		cout << '*';
		for (int j = 0; j <= i-1; j++) {
			cout << '*';
		}
	}
	return 0;
}