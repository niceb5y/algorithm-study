#include <iostream>
#include <vector>
using namespace std;

int putQueen(int deepLevel);
bool isPromise(int i);

int boardSize;
vector<int> board;
int main() {
	cin >> boardSize;
	board = vector<int>(boardSize, -1);
	int finalResult = 0;
	for (int i = 0; i < boardSize; i++) {
		board[0] = i;
		finalResult += putQueen(1);
		board[0] = -1;
	}
	cout << finalResult << endl;
}
int putQueen(int deepLevel) {
	if (!isPromise(deepLevel - 1)) {
		return 0;
	}
	if (deepLevel == boardSize) {
		return 1;
	}
	int result = 0;
	for (int i = 0; i < boardSize; i++) {
		board[deepLevel] = i;
		result += putQueen(deepLevel + 1);
		board[deepLevel] = -1;
	}
	return result;
}
bool isPromise(int i) {
	int tempPosition = board[i];
	for (int index = 0; index < i; index++) {
		if (board[index] == board[i] || abs(board[index] - board[i]) == abs(index-i)) {
			return false;
		}
	}
	return true;
}