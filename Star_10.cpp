#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

int totalLine, lineLevel;
void printLevel(int level, bool printValid, int line);
int main() {
	cin >> totalLine;
	lineLevel = (int)((log(totalLine) / log(3))+0.5);
	for (int i = 0; i < totalLine; i++) {
		printLevel(lineLevel, true, i);
		cout << endl;
	}
	return 0;
}

void printLevel(int level, bool printValid, int line){
	if (level == 1) {
		if (!printValid) {
			cout << "   ";
			return;
		}
		if (line == 0) {
			cout << "***";
		}
		else if (line == 1) {
			cout << "* *";
		}
		else if (line == 2) {
			cout << "***";
		}
		else {
			cout << "level 1 case got wrong" << endl;
		}
		return;
	}
	else {
		int tempTotal = pow(3, level);
		int lowTotal = tempTotal / 3;
		if (line >= tempTotal / 3 && line < tempTotal * 2 / 3) {
			printLevel(level - 1, printValid, line % lowTotal);
			printLevel(level - 1, false, line % lowTotal);
			printLevel(level - 1, printValid, line % lowTotal);
		}
		else {
			printLevel(level - 1, printValid, line % lowTotal);
			printLevel(level - 1, printValid, line % lowTotal);
			printLevel(level - 1, printValid, line % lowTotal);
		}
	}
}
