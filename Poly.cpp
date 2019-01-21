#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tiling(int input);
const int maxCase = 10000000;
int squareNum;
vector<vector<int>> cache;
int poling(int square, int lastwidth);
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> squareNum;
		cache = vector<vector<int>>(squareNum + 2, vector<int>(squareNum + 2, -1));
		int total = 0;
		for (int i = 1; i <= squareNum; i++) {
			total += poling(squareNum,i);
			total %= maxCase;
		}
		cout << total << endl;
	}
	return 0;
}
//정해진 정사각형으로 세로 단조인 폴리노미노 생성하기
//맨 위에서부터 아래로 하나씩 폴리노미노를 만족시킨다
//square만큼의 사각형으로 형성된, 맨 윗줄이 topwidth만큼의 길이를 가진 폴리노미노의 갯수 반환
int poling(int square, int topwidth)
{
	//기저사례: 쌓아야할 사각형을 전부 마지막 줄에 몰아넣을때
	if (square == topwidth) {
		return 1;
	}
	int& memo = cache[square][topwidth];
	if (memo != -1) {
		return memo;
	}
	memo = 0;
	//두번째줄에 있을 사각형의 갯수
	for (int second = 1; second <= square - topwidth; second++) {
		//맨 윗줄에 second 만큼의 길이인 사각형을 놓을수 있는 방법의 수
		int pileCase = topwidth + second - 1;
		//폴리노미노 아래가 폴리노미노면 전체적으로 폴리노미노가 된다
		//second를 제일 윗로 가지는 폴리노미노의 경우의수와 방법의 수를 곱하자
		pileCase *= poling(square - topwidth, second);
		pileCase %= maxCase;
		memo += pileCase;
		memo %= maxCase;
	}
	return memo;
}
