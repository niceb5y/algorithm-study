#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tiling(int input);
int asyctiling(int width);
const int maxCase = 1000000007;
int boardSize;
vector<int> asynccache;
vector<int> cache;
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		cache = vector<int>(boardSize + 1, -1);
		asynccache = vector<int>(boardSize + 1, -1);
		cout << asyctiling(boardSize) << endl;
	}
	return 0;
}
//대칭이 되지 않는 방법으로 타일을 설치해보기

//대칭적일때 이 함수를 이용한다
//양쪽 끝부터 타일링을 한다
int asyctiling(int width) {
	if (width <= 2) {
		return 0;
	}
	int& memo = asynccache[width];
	if (memo != -1) {
		return memo;
	}
	memo = 0;
	//판의 양 옆을 채울수 있는 경우의 수는 총 4가지이다
	//양 끝을 세워서 채웠을때 대칭형이다
	memo = (memo + asyctiling(width - 2)) % maxCase;
	//양 끝을 누워서 채웠을때 대칭형이다
	memo = (memo + asyctiling(width - 4)) % maxCase;
	//왼쪽 끝을 세워서 채우고, 오른쪽 끝을 누워서 채웠을때 비대칭이 확정된다
	memo = (memo + tiling(width - 3)) % maxCase;
	//오른쪽 끝을 세워서 채우고, 왼쪽 끝을 누워서 채웠을때 비대칭이 확정된다

	//한가지의 루트가 maxCase만큼의 수를 넘어갈수 있으므로 따로 두번 계산한다
	//제한된 수가 주어질때 항상 오버플로를 주의하자
	memo = (memo + tiling(width - 3)) % maxCase;
	return memo;
	
}
//비대칭이 확정되면 기존 타일링 기법을 이용한다
//시작점부터 타일링한다
int tiling(int input)
{
	if (input <= 1) {
		return 1;
	}
	int& memo = cache[input];
	if (memo != -1) {
		return memo;
	}
	else {
		memo = (tiling(input - 1) + tiling(input - 2)) % maxCase;
		return memo;
	}
}