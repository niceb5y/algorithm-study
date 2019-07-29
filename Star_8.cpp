#include "pch.h"
#include <iostream>
using namespace std;

int lineNum;
int main() {
	cin >> lineNum;
	for (int i = 1; i <= lineNum; i++) {
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		for (int j = 0; j < lineNum - i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < lineNum - i; j++) {
			cout << ' ';
		}
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		if (i != lineNum) {
			cout << endl;
		}
	}
	for (int i = 1; i < lineNum; i++) {
		cout << endl;
		for (int j = 0; j < lineNum - i; j++) {
			cout << '*';
		}
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < lineNum - i; j++) {
			cout << '*';
		}
	}
	return 0;
}