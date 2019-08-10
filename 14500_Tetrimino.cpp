#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int col, row, maxScore = 0;
vector<vector<int>> board;
//l Mino, square Mino, L Mino, ZMino, TMino, RL Mino, RZMino
//19 Len
vector<vector<int>> allcaseX = { {0,1,2,3},{0,0,0,0},{0,1,0,1},{0,0,0,1},{0,1,2,2},{0,0,0,-1},{0,-1,-2,-2},{0,0,1,1},{0,1,1,2},{0,1,1,2},{0,0,1,0},{0,-1,-1,-2},{0,0,-1,0},/**/{0,0,0,-1},{0,1,2,2},{0,0,0,1},{0,-1,-2,-2},{0,0,-1,-1},{0,1,1,2} };
vector<vector<int>> allcaseY = { {0,0,0,0},{0,1,2,3},{0,0,1,1},{0,1,2,2},{0,0,0,-1},{0,-1,-2,-2},{0,0,0,1},{0,1,1,2},{0,0,-1,-1},{0,0,1,0},{0,-1,-1,-2},{0,0,-1,0},{0,1,1,2},/**/ {0,1,2,2},{0,0,0,1},{0,-1,-2,-2},{0,0,0,-1},{0,1,1,2},{0,0,1,1} };

int getScore(int x, int y, int testCase);
int main(void) {
	cin >> col;
	cin >> row;
	board = vector<vector<int>>(col, vector<int>(row, 0));
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			for (int testCase = 0, temp; testCase < 19; testCase++) {
				temp = getScore(j, i, testCase);
				if (temp != -1) {
					maxScore = max(maxScore, temp);
				}
			}
		}
	}
	cout << maxScore;
}

int getScore(int x, int y, int testCase){
	int result = 0;
	//x = row y = col
	for (int i = 0; i < 4; i++) {
		if (x + allcaseX[testCase][i] < 0 || x + allcaseX[testCase][i] >= row) {
			return -1;
		}
		if (y + allcaseY[testCase][i] < 0 || y + allcaseY[testCase][i] >= col) {
			return -1;
		}
		result += board[y + allcaseY[testCase][i]][x + allcaseX[testCase][i]];
	}
	return result;
}
