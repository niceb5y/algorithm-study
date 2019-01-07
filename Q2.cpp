#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int testcase = 0;
int studentsNum, friendCases,sucessedMatch;
vector<vector<bool>> isFriend;
int matching(vector<bool> input);
int main()
{
	cin >> testcase;
	cin.ignore();
	for (int trial = 0; trial < testcase; trial++) {
		cin >> studentsNum;
		cin.ignore();
		cin >> friendCases;
		cin.ignore();
		isFriend = vector<vector<bool>>(studentsNum, vector<bool>(studentsNum, false));
		int x, y;
		for (int i = 0; i < friendCases; i++) {
			cin >> x;
			cin.ignore();
			cin >> y;
			cin.ignore();
			isFriend[x][y] = true;
			isFriend[y][x] = true;
		}
		vector<bool> marked = vector<bool>(studentsNum, false);
		sucessedMatch = 0;
		matching(marked);
		cout << sucessedMatch << endl;
	}
	return 0;
}

int matching(vector<bool> markedChart) {
	bool fullMarked = true;
	int firstMarked = 0;
	for (int i = 0; i < markedChart.size();i++) {
		if (!(markedChart[i])) {
			fullMarked = false;
		}
		else {
			if (firstMarked < i) {
				firstMarked = i;
			}
		}
	}
	if (fullMarked) {
		return 1;
	}
	for (int i = firstMarked; i < studentsNum; i++) {
		for (int j = 0; j < i; j++) {
			if ((!markedChart[i]) && (!markedChart[j]) && (isFriend[i][j])) {
				markedChart[i] = markedChart[j] = true;
				sucessedMatch += matching(markedChart);
				markedChart[i] = markedChart[j] = false;
			}
		}
	}
	return 0;
}