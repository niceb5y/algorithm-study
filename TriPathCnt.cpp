#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> board;
vector<vector<int>> pathcache;
vector<vector<int>> sizecache;
int drillDown(int y, int x);
int count(int y, int x);
int triangleSize;
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> triangleSize;
		board = vector<vector<int>>(triangleSize, vector<int>(triangleSize, 0));
		pathcache = vector<vector<int>>(triangleSize, vector<int>(triangleSize, -1));
		sizecache = vector<vector<int>>(triangleSize, vector<int>(triangleSize, -1));
		for (int i = 0; i < triangleSize; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> board[i][j];
			}
		}
		cout << count(0, 0) << endl;
	}
	return 0;
}

int drillDown(int y, int x)
{
	//기저사례: 바닥에 닿을시 그대로 리턴
	if (y == triangleSize - 1) {
		return board[y][x];
	}
	int& temp = sizecache[y][x];
	if (temp != -1) {
		return temp;
	}
	//자기 자신 이하의 최대합을 가진 결과
	temp = max(drillDown(y + 1, x), drillDown(y + 1, x + 1)) + board[y][x];
	return temp;
}
//삼각형의 최대 경로 루트 갯수 구하기
int count(int y, int x)
{
	//기저사례: 바닥에 닿을시 확정 루트 1개
	if (y == triangleSize - 1) {
		return 1;
	}
	int& temp = pathcache[y][x];
	if (temp != -1) {
		return temp;
	}
	temp = 0;
	if (drillDown(y + 1, x) > drillDown(y + 1, x + 1)) {
		temp += count(y + 1, x);
	}
	else if (drillDown(y + 1, x) < drillDown(y + 1, x + 1)) {
		temp += count(y + 1, x + 1);
	}
	else if (drillDown(y + 1, x) == drillDown(y + 1, x + 1)) {
		temp += count(y + 1, x) + count(y + 1, x + 1);
	}
	return temp;
}
