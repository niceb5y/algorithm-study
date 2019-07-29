#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numberNum, maxLen;
vector<int> numberList;
vector<int> numberPosition;
vector<int> numberVector;

int main() {
	cin >> numberNum;
	numberList = vector<int>(numberNum);
	for (int i = 0; i < numberNum; i++) {
		cin >> numberList[i];
	}
	numberPosition = vector<int>(numberNum,-1);
	numberVector = vector<int>(numberNum + 1, 1000);
	numberVector[0] = -1;
	for (int i = 0; i < numberNum; i++) {
		int index = lower_bound(numberVector.begin(), numberVector.end(), numberList[i])-numberVector.begin();
		numberPosition[i] = index;
		numberVector[index] = numberList[i];
	}
	maxLen = *max_element(numberPosition.begin(), numberPosition.end());
	cout << maxLen << endl;
	int maxIndex;
	for (int i = numberNum - 1; i >= 0; i--) {
		if (numberPosition[i] == maxLen) {
			maxIndex = i;
			break;
		}
	}
	int tempLen = maxLen;
	vector<int> printVector;
	for (int i = maxIndex; i >= 0; i--) {
		if (numberPosition[i] == tempLen) {
			printVector.push_back(numberList[i]);
			tempLen--;
		}
		if (tempLen == 0) {
			break;
		}
	}
	for (int i = printVector.size() - 1; i >= 0; i--) {
		cout << printVector[i] << " ";
	}
}