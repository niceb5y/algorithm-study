#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<bool>> board;
string inputBuffer;
int boardSize;
void inCode(pair<int, int> startIJ, pair<int, int> endIJ);
bool canCompile(pair<int, int> startIJ, pair<int, int> endIJ);
int main()
{
	cin >> boardSize;
	board = vector<vector<bool>>(boardSize, vector<bool>(boardSize, false));
	for (int i = 0; i < boardSize; i++) {
		cin >> inputBuffer;
		for (int j = 0; j < boardSize; j++) {
			if (inputBuffer.at(j) == '0') {
				board[i][j] = false;
			}
			else {
				board[i][j] = true;
			}
		}
	}
	inCode(make_pair(0, 0), make_pair(boardSize, boardSize));
}

void inCode(pair<int, int> startIJ, pair<int, int> endIJ)
{
	if (canCompile(startIJ, endIJ)) {
		if (board[startIJ.first][startIJ.second]) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else {
		pair<int, int> midPoint = make_pair((startIJ.first + endIJ.first) / 2, (startIJ.second + endIJ.second) / 2);
		cout << "(";
		inCode(startIJ, make_pair(midPoint.first, midPoint.second));
		inCode(make_pair(startIJ.first, midPoint.second), make_pair(midPoint.first, endIJ.second));
		inCode(make_pair(midPoint.first, startIJ.second), make_pair(endIJ.first, midPoint.second));
		inCode(make_pair(midPoint.first, midPoint.second), endIJ);
		cout << ")";
	}
}

bool canCompile(pair<int, int> startIJ, pair<int, int> endIJ)
{
	bool fieldCode = board[startIJ.first][startIJ.second];
	for (int i = startIJ.first; i < endIJ.first; i++) {
		for (int j = startIJ.second; j < endIJ.second; j++) {
			if (board[i][j] != fieldCode) {
				return false;
			}
		}
	}
	return true;
}
