#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<vector<int>> board, cache;
vector<int> sizeMapping;
int colNum, rowNum;
int roomNumber = 1;
int findSize(int i, int j, int comeFrom);
int main() {
	cin >> colNum;
	cin >> rowNum;
	board = vector<vector<int>>(rowNum, vector<int>(colNum, -1));
	cache = vector<vector<int>>(rowNum, vector<int>(colNum, -1));
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			if (cache[i][j] == -1) {
				sizeMapping.push_back(findSize(i, j, 0));
				roomNumber++;
			}
		}
	}
	cout << roomNumber - 1 << endl;
	int maxRoom = 0;
	for (int i = 0; i < sizeMapping.size(); i++) {
		maxRoom = max(maxRoom, sizeMapping[i]);
	}
	cout << maxRoom << endl;
	maxRoom = 2;
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			if (i + 1 < rowNum && cache[i][j] != cache[i+1][j]) {
				maxRoom = max(maxRoom, sizeMapping[cache[i][j] - 1] + sizeMapping[cache[i + 1][j] - 1]);
			}
			if (j + 1 < colNum && cache[i][j] != cache[i][j + 1]) {
				maxRoom = max(maxRoom, sizeMapping[cache[i][j] - 1] + sizeMapping[cache[i][j + 1] - 1]);
			}
		}
	}
	cout << maxRoom << endl;
	return 0;
}

int findSize(int i, int j, int comeFrom)
{
	cache[i][j] = roomNumber;
	int newWay = (board[i][j] | comeFrom),roomSize = 1;
	if (newWay == 15) {
		return roomSize;
	}
	for (int x = 0; x < 4; x++) {
		int togo = 1 << x;
		if ((newWay & togo) != togo) {
			switch (togo)
			{
			case 1:
				if (j - 1 >= 0 && cache[i][j - 1] == -1) {
					roomSize += findSize(i, j - 1, 4);
				}
				break;
			case 4:
				if (j + 1 < colNum && cache[i][j + 1] == -1) {
					roomSize += findSize(i, j + 1, 1);
				}
				break;
			case 2:
				if (i - 1 >= 0 && cache[i - 1][j] == -1) {
					roomSize += findSize(i - 1, j, 8);
				}
				break;
			case 8:
				if (i + 1 < rowNum && cache[i + 1][j] == -1) {
					roomSize += findSize(i + 1, j, 2);
				}
				break;
			default:
				break;
			}
		}
	}
	return roomSize;
}
