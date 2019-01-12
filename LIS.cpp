#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cache;
vector<int> board;
int lis(int input);
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
int main() {
	int testcase, length,temp;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> length;
		cache = vector<int>(length, -1);
		board = vector<int>(length);
		for (int i = 0; i < length; i++) {
			cin >> board[i];
		}
		int maxLength = 0;
		//모든 위치에서 시작해본다
		for (int i = 0; i < length; i++) {
			maxLength = max(maxLength, lis(i));
		}
		cout << maxLength << endl;
	}
	return 0;
}
//증가 부분 수열 구하기
int lis(int input)
{
	int& temp = cache[input];
	if (temp != -1) {
		return temp;
	}
	//input 위치의 원소는 포함되므로 1을 넣어준다
	temp = 1;
	//자기 자신보다 큰 수를 포함해서 그 수부터 시작되는 최대 증가수열 구하기
	for (int i = input + 1; i < board.size(); i++) {
		if (board[input] < board[i]) {
			//수열의 맨 첫숫자는 무조건 나보다 작으므로 1을 더해줘도 증가수열은 유지된다
			temp = max(temp,1+lis(i));
		}
	}
	return temp;
}
