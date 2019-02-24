#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int testCase, curruntPos;
	string board;
	while (true)
	{
		cin >> testCase;
		if (testCase == 0) {
			break;
		}
		curruntPos = 0;
		cin.ignore();
		for (int line = 0; line < testCase; line++) {
			getline(cin, board);
			while (true)
			{
				if (board.size() <= curruntPos) {
					break;
				}
				if (board.at(curruntPos) == ' ') {
					break;
				}
				curruntPos++;
			}
		}
		cout << curruntPos + 1 << endl;
	}
	return 0;
}