#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int fastGone = 100000, lateCome = 0, studentNum;
int main() {
	cin >> studentNum;
	for (int i = 0,come,gone; i < studentNum; i++) {
		cin >> come;
		cin >> gone;
		fastGone = min(fastGone, gone);
		lateCome = max(lateCome, come);
	}
	if (lateCome - fastGone <= 0) {
		cout << 0;
	}
	else {
		cout << lateCome - fastGone;
	}
	return 0;
}