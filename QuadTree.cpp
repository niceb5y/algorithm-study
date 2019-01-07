#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int point = 0;
string flipFlop(string input, int startPoint);
int main() {
	int testcase = 0;
	cin >> testcase;
	string mainBoard;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> mainBoard;
		point = 0;
		cout << flipFlop(mainBoard, point) << endl;
	}
	return 0;
}

string flipFlop(string input, int startPoint) {
	if (input.at(startPoint) == 'w' || input.at(startPoint) == 'b') {
		return string(input.substr(startPoint,1));
	}
	else if (input.at(startPoint) == 'x') {
		vector<string> flippedQuads = vector<string>(4,"");
		for (int quad = 0; quad < 4; quad++) {
			point++;
			flippedQuads[quad] = flipFlop(input, point);
		}
		string flippedString = "x"+flippedQuads[2] + flippedQuads[3] + flippedQuads[0] + flippedQuads[1];
		return flippedString;
	}
	return "";
}