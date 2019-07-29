#include "pch.h"

#include<iostream>
#include<vector>
using namespace std;

vector<int> board;
vector<vector<int>> cache;
int boardSize, qustionNum;
bool isPalindrome(int start, int end);
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> boardSize;
	board = vector<int>(boardSize+1);
	for (int i = 1; i < boardSize+1; i++) {
		cin >> board[i];
	}
	cin >> qustionNum;
	int startP, endP;
	cache = vector<vector<int>>(boardSize+1, vector<int>(boardSize+1,-1));
	for (int i = 1; i < boardSize + 1; i++) {
		for (int j = i; j < boardSize + 1; j++) {
			isPalindrome(i, j);
		}
	}
	for (int i = 0; i < qustionNum; i++) {
		cin >> startP;
		cin >> endP;
		if (isPalindrome(startP, endP)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}

bool isPalindrome(int start, int end)
{
	if (cache[start][end] != -1) {
		if (cache[start][end] == 1) {
			return true;
		}
		else if (cache[start][end] == 0) {
			return false;
		}
	}
	if (end - start <= 0) {
		cache[start][end] = 1;
		return true;
	}
	if (board[start] == board[end]) {
		bool temp = isPalindrome(start + 1, end - 1);
		if (temp) {
			cache[start][end] = 1;
		}
		else {
			cache[start][end] = 0;
		}
		return temp;
	}
	cache[start][end] = 0;
	return false;
}
