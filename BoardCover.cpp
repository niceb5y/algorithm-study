#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int boardLine, boardSize;
vector<vector<bool>> board;
int cover(vector<vector<bool>>& board);
bool boardChanger(int fillPointx, int fillPointy, vector<vector<bool>>& board, int type, bool Covering);
int coverType[4][3][2] = {
	{{0,0},{1,0}, {0,1}},
	{{0,0},{0,1}, {1,1}},
	{{0,0},{1,0}, {1,1}},
	{{0,0},{1,0}, {1,-1}}
};
int main() {
	int testcase = 0;
	cin >> testcase;
	cin.ignore();
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardLine;
		cin.ignore();
		cin >> boardSize;
		cin.ignore();
		board = vector<vector<bool>>(boardLine, vector<bool>(boardSize, false));
		string input;
		int whiteCount = 0;
		for (int i = 0; i < boardLine; i++) {
			cin >> input;
			cin.ignore();
			for (int j = 0; j < boardSize; j++) {
				if (input[j] == '#') {
					board[i][j] = true;
				}
				else {
					whiteCount++;
				}
			}
		}
		if (whiteCount % 3 != 0) {
			cout << 0 << endl;
		}
		else {
			int total = 0;
			total = cover(board);
			cout << total << endl;
		}
	}
	return 0;
}

int cover(vector<vector<bool>>& board) {
	int frontX = -1, frontY = -1;
	for (int i = 0; i < boardLine; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (!board[i][j]) {
				frontX = i;
				frontY = j;
				break;
			}
		}
		if (frontY != -1) {
			break;
		}
	}
	if (frontY == -1) {
		return 1;
	}
	int total = 0;
	for (int coverCase = 0; coverCase < 4; coverCase++) {
		if (boardChanger(frontX, frontY, board, coverCase, true)) {
			total += cover(board);
			boardChanger(frontX, frontY, board, coverCase, false);
		}
	}
	return total;
}

bool boardChanger(int fillPointx, int fillPointy, vector<vector<bool>>& board,int type,bool Covering) {
	bool goOn = true;
	for (int targetTile = 0; targetTile < 3; targetTile++) {
		if (fillPointx + coverType[type][targetTile][0] < 0 || fillPointy + coverType[type][targetTile][1] < 0) {
			goOn = false;
		}
		else if (fillPointx + coverType[type][targetTile][0] >= boardLine || fillPointy + coverType[type][targetTile][1] >= boardSize) {
			goOn = false;
		}
		else if (Covering && board[fillPointx + coverType[type][targetTile][0]][fillPointy + coverType[type][targetTile][1]]) {
			goOn = false;
		}
	}
	if (goOn) {
		for (int targetTile = 0; targetTile < 3; targetTile++) {
			
			board[fillPointx + coverType[type][targetTile][0]][fillPointy + coverType[type][targetTile][1]] = !(board[fillPointx + coverType[type][targetTile][0]][fillPointy + coverType[type][targetTile][1]]);
		}
	}
	return goOn;
}