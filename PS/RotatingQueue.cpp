#include "pch.h"
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> board;
int queueSize, listNum;
int needCalc();
int main()
{
	cin >> queueSize;
	board = vector<int>(queueSize);
	cin >> listNum;
	for (int i = 0; i < queueSize; i++) {
		board[i] = i+1;
	}
	cout << needCalc() << endl;
}

int needCalc()
{
	int total = 0, targetPosition, target, pos = 0;
	for (int i = 0; i < listNum; i++) {
		cin >> target;
		targetPosition = distance(board.begin(), find(board.begin(), board.end(), target));
		total += min(abs(targetPosition - pos), (int)board.size() - abs(targetPosition - pos));
		board.erase(board.begin() + targetPosition);
		if (targetPosition >= board.size()) {
			pos = 0;
		}
		else {
			pos = targetPosition;
		}
	}
	return total;
}
