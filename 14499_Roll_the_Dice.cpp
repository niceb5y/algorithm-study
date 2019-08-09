#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dice, board;
vector<int> commandList;
vector<int> xMove = { 1,-1,0,0 };
vector<int> yMove = { 0,0,-1,1 };
int row, column, commandNum, diceStartRow, diceStartColumn;
pair<int, int> dicePosition;
bool executeCommand(int index);
int main() {
	dice = vector<vector<int>>(4, vector<int>(3, 0));
	/*dice[0][1] = 2;
	dice[1][0] = 4;
	dice[1][1] = 1;
	dice[1][2] = 3;
	dice[2][1] = 5;
	dice[3][1] = 6;*/
	//7 - pointer == top
	cin >> column;
	cin >> row;
	cin >> diceStartColumn;
	cin >> diceStartRow;
	dicePosition = make_pair(diceStartColumn, diceStartRow);
	board = vector<vector<int>>(column, vector<int>(row, 0));
	cin >> commandNum;
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			cin >> board[i][j];
		}
	}
	commandList = vector<int>(commandNum);
	for (int i = 0; i < commandNum; i++) {
		cin >> commandList[i];
		commandList[i]--;
	}
	for (int i = 0; i < commandNum; i++) {
		if (executeCommand(i)) {
			cout << dice[1][1] << endl;
		}
	}
	return 0;
}

bool executeCommand(int index){
	int temp;
	switch (commandList[index]){
	case 0:
		if (dicePosition.second + xMove[commandList[index]] >= row) {
			return false;
		}
		dicePosition.second += xMove[commandList[index]];
		temp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = temp;
		break;
	case 1:
		if (dicePosition.second + xMove[commandList[index]] < 0) {
			return false;
		}
		dicePosition.second += xMove[commandList[index]];
		temp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = temp;
		break;
	case 2:
		if (dicePosition.first + yMove[commandList[index]] < 0) {
			return false;
		}
		dicePosition.first += yMove[commandList[index]];
		temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;
		break;
	case 3:
		if (dicePosition.first + yMove[commandList[index]] >= column) {
			return false;
		}
		dicePosition.first += yMove[commandList[index]];
		temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;
		break;
	default:
		return false;
	}
	if (board[dicePosition.first][dicePosition.second] == 0) {
		board[dicePosition.first][dicePosition.second] = dice[3][1];
	}
	else {
		dice[3][1] = board[dicePosition.first][dicePosition.second];
		board[dicePosition.first][dicePosition.second] = 0;
	}
	return true;
}
