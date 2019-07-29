#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct line
{
	int x1, y1;
	int x2, y2;
};
bool isMeet(int firstLine, int secondLine);
bool oneDMeet(int firstLine, int secondLine);
int findCCW(int baseLine, int dotX, int dotY);
int getRoot(int index);
vector<int> parentArray, unionArray;
vector<line> lineArray;
int lineNumber;
int main() {
	cin >> lineNumber;
	parentArray = vector<int>(lineNumber, -1);
	unionArray = vector<int>(lineNumber, 0);
	for (int i = 0; i < lineNumber; i++) {
		parentArray[i] = i;
	}
	for (int i = 0; i < lineNumber; i++) {
		line tempLine;
		cin >> tempLine.x1;
		cin >> tempLine.y1;
		cin >> tempLine.x2;
		cin >> tempLine.y2;
		lineArray.push_back(tempLine);
	}
	for (int i = 0; i < lineNumber - 1; i++) {
		for (int j = i + 1; j < lineNumber; j++) {
			if (isMeet(i, j)) {
				int rootI = getRoot(i), rootJ = getRoot(j);
				if (rootI > rootJ) {
					parentArray[rootI] = rootJ;
				}
				else if (rootI < rootJ) {
					parentArray[rootJ] = rootI;
				}
			}
		}
	}
	for (int i = 0; i < lineNumber; i++) {
		int root = getRoot(i);
		unionArray[root]++;
	}
	int maxValue = 0, groupSize = 0;
	for (int i = 0; i < unionArray.size(); i++) {
		if (unionArray[i] != 0) {
			groupSize++;
			maxValue = max(maxValue, unionArray[i]);
		}
	}
	cout << groupSize << endl;
	cout << maxValue << endl;
	return 0;
}

bool isMeet(int firstLine, int secondLine)
{
	int result1 = findCCW(firstLine, lineArray[secondLine].x1, lineArray[secondLine].y1);
	int result2 = findCCW(firstLine, lineArray[secondLine].x2, lineArray[secondLine].y2);

	if (result1 == 0 && result2 == 0) {
		return oneDMeet(firstLine, secondLine);
	}
	if (result1 * result2 <= 0) {
		result1 = findCCW(secondLine, lineArray[firstLine].x1, lineArray[firstLine].y1);
		result2 = findCCW(secondLine, lineArray[firstLine].x2, lineArray[firstLine].y2);
		if (result1 * result2 <= 0) {
			return true;
		}
		return false;
	}
	return false;
}

bool oneDMeet(int firstLine, int secondLine)
{
	long long firstSub, secondSub;
	if (lineArray[firstLine].x1 == lineArray[firstLine].x2) {
		firstSub = (lineArray[firstLine].y1 - lineArray[secondLine].y1) * (lineArray[firstLine].y2 - lineArray[secondLine].y1);
		secondSub = (lineArray[firstLine].y1 - lineArray[secondLine].y2) * (lineArray[firstLine].y2 - lineArray[secondLine].y2);
	}
	else {
		firstSub = (lineArray[firstLine].x1 - lineArray[secondLine].x1) * (lineArray[firstLine].x2 - lineArray[secondLine].x1);
		secondSub = (lineArray[firstLine].x1 - lineArray[secondLine].x2) * (lineArray[firstLine].x2 - lineArray[secondLine].x2);
	}
	if (firstSub <= 0 || secondSub <= 0) {
		return true;
	}
	if (lineArray[secondLine].x1 == lineArray[secondLine].x2) {
		firstSub = (lineArray[secondLine].y1 - lineArray[firstLine].y1) * (lineArray[secondLine].y2 - lineArray[firstLine].y1);
		secondSub = (lineArray[secondLine].y1 - lineArray[firstLine].y2) * (lineArray[secondLine].y2 - lineArray[firstLine].y2);
	}
	else {
		firstSub = (lineArray[secondLine].x1 - lineArray[firstLine].x1) * (lineArray[secondLine].x2 - lineArray[firstLine].x1);
		secondSub = (lineArray[secondLine].x1 - lineArray[firstLine].x2) * (lineArray[secondLine].x2 - lineArray[firstLine].x2);
	}
	if (firstSub <= 0 || secondSub <= 0) {
		return true;
	}
	return false;
}

int findCCW(int baseLine, int dotX, int dotY)
{
	long long firstSub, secondSub, thirdSub, finalResult;
	firstSub = lineArray[baseLine].x1 * lineArray[baseLine].y2 - lineArray[baseLine].y1 * lineArray[baseLine].x2;
	secondSub = lineArray[baseLine].x2 * dotY - dotX * lineArray[baseLine].y2;
	thirdSub = lineArray[baseLine].y1 * dotX - dotY * lineArray[baseLine].x1;
	finalResult = firstSub + secondSub + thirdSub;
	if (finalResult < 0) {
		return -1;
	}
	else if (finalResult > 0) {
		return 1;
	}
	return 0;
}

int getRoot(int index)
{
	int result = parentArray[index];
	while (parentArray[result] != result) {
		result = parentArray[result];
	}
	return result;
}