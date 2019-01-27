#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//ƽ���信���� ��� ���� ���� �����ϴ�
vector<vector<int>> wincaseX({ 
	vector<int>({0,1,2}),
	vector<int>({0,1,2}), 
	vector<int>({0,1,2}), 
	vector<int>({0,0,0}), 
	vector<int>({1,1,1}), 
	vector<int>({2,2,2}), 
	vector<int>({0,1,2}), 
	vector<int>({2,1,0}) });
vector<vector<int>> wincaseY({
	vector<int>({0,0,0}),
	vector<int>({1,1,1}),
	vector<int>({2,2,2}),
	vector<int>({0,1,2}),
	vector<int>({0,1,2}),
	vector<int>({0,1,2}),
	vector<int>({0,1,2}),
	vector<int>({0,1,2}) });
vector<string> board;
vector<int> cache;
int boardSize = 3;
int binarying(vector<string>& board);
int canWin(vector<string>& board,char turn);
bool gameSet(vector<string>& board, char turn);
//������ �ʽ¹��� ã�� ���� ��ȹ��
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		board = vector<string>(boardSize);
		//���� ��� ��츦 ĳ�� 3x3�� ó�� �����ϴ�
		int casesize = pow(3,boardSize*boardSize);
		cache = vector<int>(casesize, -2);
		for (int i = 0; i < boardSize; i++) {
			cin >> board[i];
		}
		char currentP = 'x';
		char oppositeP = 'o';
		int marked = 0;
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (board[i][j] == 'x' || board[i][j] == 'o') {
					marked++;
				}
			}
		}
		if (marked % 2 == 1) {
			currentP = 'o';
			oppositeP = 'x';
		}
		if (gameSet(board, 'x')) {
			cout << "x" << endl;
			continue;
		}
		else if (gameSet(board, 'o')) {
			cout << "o" << endl;
			continue;
		}
		int result = canWin(board, currentP);
		if (result == 0) {
			cout << "TIE" << endl;
		}
		else if (result == 1) {
			cout << currentP << endl;
		}
		else if (result == -1) {
			cout << oppositeP << endl;
		}
		else {
			cout << "Result Wrong" << endl;
		}
	}
	return 0;
}

//�������� 3������ ��ȯ���ش�
int binarying(vector<string>& board)
{
	int total = 0;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			//3������ �Ǿտ� ��ĭ����
			total *= 3;
			//o�Ͻ� 1���� x�Ͻ� 2����
			if (board[i][j] == 'o') {
				total++;
			}
			else if (board[i][j] == 'x') {
				total += 2;
			}
		}
	}
	return total;
}
//turn�� ������ ���ʰ� �������� �̱�� �ִ����� �Ǵ�
//�̱�� �ִٸ� 1, ���°� �ּ��̸� 0, �����ۿ� ���ٸ� -1 ����
int canWin(vector<string>& board, char turn)
{
	char opposit;
	if (turn == 'o') {
		opposit = 'x';
	}
	else if (turn == 'x') {
		opposit = 'o';
	}
	//�������: ������ �Ѽ��� ������ �����ٸ�
	if (gameSet(board, opposit)) {
		return -1;
	}

	int& memo = cache[binarying(board)];
	if (memo != -2) {
		return memo;
	}
	int setCase = 2;
	//���� �ξ ����� ����
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j] == '.') {
				board[i][j] = turn;
				//�̋� ����Ǵ°� ������ �¸� �����̴�
				setCase = min(setCase, canWin(board, opposit));
				board[i][j] = '.';
			}
		}
	}
	//������ ���ų� ���� �Ұ��϶�
	if (setCase == 0 || setCase == 2) {
		memo = 0;
		return memo;
	}
	//������ �¸� ���ΰ� ���� �̿� ���� �¸����ο� �޷��ִ�
	memo = -setCase;
	return memo;
}
//�̸� ����� �º��� ��츦 ���鼭 �̰���� �Ǵ�
bool gameSet(vector<string>& board, char turn)
{
	for (int i = 0; i < 8; i++) {
		bool fact = true;
		for (int j = 0; j < 3; j++) {
			if (board[wincaseX[i][j]][wincaseY[i][j]] != turn) {
				fact = false;
			}
		}
		if (fact) {
			return fact;
		}
	}
	return false;
}