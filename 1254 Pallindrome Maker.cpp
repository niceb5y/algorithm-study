#include "pch.h"

#include<iostream>
#include<string>
using namespace std;
bool isPalendrome(int index);

string board;
int main() {
	cin >> board;
	for (int i = 0; i + 1 < board.size(); i++) {
		if (isPalendrome(i)) {
			cout << board.size() + i << endl;
			return 0;
		}
	}
	cout << board.size() * 2 - 1 << endl;
	return 0;
}

bool isPalendrome(int index)
{
	int start = index, end = board.size()-1;
	while (end-start >0)
	{
		if (board[start] != board[end]) {
			return false;
		}
		start++;
		end--;
	}
	return true;
}
