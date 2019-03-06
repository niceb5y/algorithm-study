#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int starLine;
void printStarLine(int wholeLine, int subLine);
int main() {
	cin >> starLine;
	for (int i = 1; i < starLine + 1; i++) {
		printStarLine(starLine, i);
		cout << endl;
	}
	return 0;
}

void printStarLine(int wholeLine, int subLine)
{
	//�������: �ﰢ���� ũ�Ⱑ 3���ϰ�� �׳� Ǯ���Ѵ�
	if (wholeLine == 3) {
		switch (subLine)
		{
		case 1:
			cout << "  *  ";
			break;
		case 2:
			cout << " * * ";
			break;
		case 3:
			cout << "*****";
		default:
			break;
		}
	}
	else if(wholeLine%3 == 0){
		if (subLine <= wholeLine / 2) {
			for (int spaceNum = 0; spaceNum < wholeLine / 2; spaceNum++) {
				cout << " ";
			}
			printStarLine(wholeLine / 2, subLine);
			for (int spaceNum = 0; spaceNum < wholeLine / 2; spaceNum++) {
				cout << " ";
			}
		}
		else {
			printStarLine(wholeLine / 2, subLine - wholeLine / 2);
			cout << " ";
			printStarLine(wholeLine / 2, subLine - wholeLine / 2);
		}
	}
	else {
		cout << "input error" << endl;
		return;
	}
}
