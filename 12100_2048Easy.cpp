#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int boardSize, maxValue;
void Solve(int moveNum, vector<vector<int>> board);
vector<vector<int>> moveDir(int way, vector<vector<int>> board);
int main() {
	maxValue = 0;
	cin >> boardSize;
	vector<vector<int>> board = vector<vector<int>>(boardSize, vector<int>(boardSize, 0));
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cin >> board[i][j];
			maxValue = max(board[i][j], maxValue);
		}
	}
	Solve(0, board);
	cout << maxValue;
	return 0;
}

void Solve(int moveNum, vector<vector<int>> board){
	if (moveNum >= 5) {
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				maxValue = max(maxValue, board[i][j]);
			}
		}
		return;
	}
	vector<vector<int>> temp;
	for (int i = 0; i < 4; i++) {
		temp = moveDir(i, board);
		if (temp == board) {
			for (int i = 0; i < boardSize; i++) {
				for (int j = 0; j < boardSize; j++) {
					maxValue = max(maxValue, board[i][j]);
				}
			}
		}
		else {
			Solve(moveNum + 1, temp);
		}
	}
}

vector<vector<int>> moveDir(int way, vector<vector<int>> board){
	//0=Left, 1== right, 2 == up, 3== down
	if (way == 0) {
		for (int i = 0; i < boardSize; i++) {
			for (int j = 1; j < boardSize; j++) {
				if (board[i][j] == 0) {
					board[i][j] = board[i][j - 1];
					board[i][j - 1] = 0;
				}
				else if (board[i][j] == board[i][j - 1]) {
					board[i][j - 1] += board[i][j];
					board[i][j] = 0;
				}
			}
			for (int num = 0; num < boardSize; num++) {
				for (int j = 0; j < boardSize - 1; j++) {
					if (board[i][j] == 0) {
						board[i][j] = board[i][j + 1];
						board[i][j + 1] = 0;
					}
				}
			}
		}
	}
	else if (way == 1) {
		for (int i = 0; i < boardSize; i++) {
			for (int j = boardSize - 2; j > -1; j--) {
				if (board[i][j] == 0) {
					board[i][j] = board[i][j + 1];
					board[i][j + 1] = 0;
				}
				else if (board[i][j] == board[i][j + 1]) {
					board[i][j + 1] += board[i][j];
					board[i][j] = 0;
				}
			}
			for (int num = 0; num < boardSize; num++) {
				for (int j = boardSize - 1; j > 0; j--) {
					if (board[i][j] == 0) {
						board[i][j] = board[i][j - 1];
						board[i][j - 1] = 0;
					}
				}
			}
		}
	}
	else if (way == 2) {
		for (int i = 0; i < boardSize; i++) {
			for (int j = 1; j < boardSize; j++) {
				if (board[j][i] == 0) {
					board[j][i] = board[j - 1][i];
					board[j - 1][i] = 0;
				}
				else if (board[j][i] == board[j - 1][i]) {
					board[j - 1][i] += board[j - 1][i];
					board[j][i] = 0;
				}
			}
			for (int num = 0; num < boardSize; num++) {
				for (int j = 0; j < boardSize - 1; j++) {
					if (board[j][i] == 0) {
						board[j][i] = board[j + 1][i];
						board[j + 1][i] = 0;
					}
				}
			}
		}
	}
	else if (way == 3) {
		for (int i = 0; i < boardSize; i++) {
			for (int j = boardSize - 2; j > -1; j--) {
				if (board[j][i] == 0) {
					board[j][i] = board[j + 1][i];
					board[j + 1][i] = 0;
				}
				else if (board[j][i] == board[j + 1][i]) {
					board[j + 1][i] += board[j + 1][i];
					board[j][i] = 0;
				}
			}
			for (int num = 0; num < boardSize; num++) {
				for (int j = boardSize - 1; j > 0; j--) {
					if (board[j][i] == 0) {
						board[j][i] = board[j - 1][i];
						board[j - 1][i] = 0;
					}
				}
			}
		}
	}
	else {
		return board;
	}
	return board;
}
