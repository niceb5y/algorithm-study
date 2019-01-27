#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//틱택토에서의 우승 경우는 예측 가능하다
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
//게임의 필승법을 찾는 동적 계획법
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		board = vector<string>(boardSize);
		//판의 모든 경우를 캐싱 3x3은 처리 가능하다
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

//보드판을 3진수로 반환해준다
int binarying(vector<string>& board)
{
	int total = 0;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			//3진수의 맨앞에 빈칸생성
			total *= 3;
			//o일시 1대입 x일시 2대입
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
//turn의 상대방의 차례가 끝났을때 이길수 있는지를 판단
//이길수 있다면 1, 비기는게 최선이면 0, 질수밖에 없다면 -1 리턴
int canWin(vector<string>& board, char turn)
{
	char opposit;
	if (turn == 'o') {
		opposit = 'x';
	}
	else if (turn == 'x') {
		opposit = 'o';
	}
	//기저사례: 상대방의 한수로 게임이 끝났다면
	if (gameSet(board, opposit)) {
		return -1;
	}

	int& memo = cache[binarying(board)];
	if (memo != -2) {
		return memo;
	}
	int setCase = 2;
	//내가 두어볼 경우의 수들
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j] == '.') {
				board[i][j] = turn;
				//이떄 저장되는건 상대방의 승리 여부이다
				setCase = min(setCase, canWin(board, opposit));
				board[i][j] = '.';
			}
		}
	}
	//게임이 비겼거나 진행 불가일때
	if (setCase == 0 || setCase == 2) {
		memo = 0;
		return memo;
	}
	//상대방의 승리 여부가 비기기 이외 나의 승리여부에 달려있다
	memo = -setCase;
	return memo;
}
//미리 저장된 승부의 경우를 보면서 이겼는지 판단
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