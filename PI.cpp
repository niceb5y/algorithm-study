#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> numList;
vector<int> cache;
int setDifficulty(int start, int num);
int memoring(int start);
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
int main() {
	int testcase;
	string inputNum;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> inputNum;
		//처음부터 문제가 갈리는 경우의 수 경우 임의의 수를 넣어줘서 자동화 시킨다
		numList = vector<int>(inputNum.size() + 3);
		cache = vector<int>(inputNum.size()+3, -1);
		numList[0] = -999;
		numList[1] = -999;
		numList[2] = -999;
		for (int i = 3; i < inputNum.size() + 3; i++) {
			numList[i] = inputNum.at(i-3) - '0';
		}
		//임의의 수에 대한 값을 빼준다
		cout << memoring(0)-1 << endl;
	}
	return 0;
}
//정해진 수열의 난이도 측정
int setDifficulty(int start, int num)
{
	int firstWord = numList[start];
	//1가지의 숫자가 연속되면 난이도 1
	bool is1 = true;
	for (int i = 0; i < num; i++) {
		if (firstWord != numList[start + i]) {
			is1 = false;
			break;
		}
	}
	if (is1) {
		return 1;
	}
	//등차수열일경우를 판단
	int set2or5 = numList[start] - numList[start+1];
	bool is2or5 = true;
	for (int i = 0; i < num - 1; i++) {
		if (numList[start + i] - numList[start + i + 1] != set2or5) {
			is2or5 = false;
			break;
		}
	}
	if (is2or5) {
		//1씩 늘어나거나 줄어들경우 난이도는 2
		if (set2or5 == 1 || set2or5 == -1) {
			return 2;
		}
		//이외의 등차수열일 경우 난이도는 5
		else {
			return 5;
		}
	}
	//숫자가 번갈아 나오는 경우를 판단
	vector<int> twiceList = vector<int>(2,numList[start]);
	twiceList[1] = numList[start + 1];
	bool is4 = true;
	for (int i = 0; i < num; i++) {
		if (numList[start + i] != twiceList[i % 2]) {
			is4 = false;
			break;
		}
	}
	if (is4) {
		return 4;
	}
	return 10;
}

//재귀함수
int memoring(int start)
{
	if (start >= numList.size()) {
		return 0;
	}
	int& memo = cache[start];
	if (memo != -1) {
		return memo;
	}
	//memo에는 최댓값을 저장하나 나중에 난이도가 추가로 더해진다
	//오버플로를 주의해서 적당히 큰 수를 저장해둔다.
	memo = 9999999;
	if (start == 0) {
		memo = min(memo, memoring(start + 3) + setDifficulty(start, 3));
	}
	else {
		for (int i = 3; i <= 5; i++) {
			if (start + i <= numList.size()) {
				memo = min(memo, memoring(start + i) + setDifficulty(start, i));
			}
		}
	}
	return memo;
}


