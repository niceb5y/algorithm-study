#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int longnum, shortnum, target;
vector<vector<int>> binary;
string generate(int n, int m, int skip);
//해를 직접 구해야 하는 동적 계획법
//k번째 답을 도출해내야 한다
int main() {
	//이항계수를 미리 계산해 놓는다
	binary = vector<vector<int>>(201, vector<int>(201, 0));
	for (int i = 0; i <= 200; i++) {
		binary[i][0] = binary[i][i] = 1;
		for (int j = 1; j < i; j++) {
			binary[i][j] = min(1000000000, binary[i - 1][j - 1] + binary[i - 1][j]);
		}
	}

	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> longnum;
		cin >> shortnum;
		cin >> target;
		if (target >= binary[longnum + shortnum][longnum]) {
			cout << generate(longnum, shortnum, binary[longnum + shortnum][longnum]) << endl;
		}
		else {
			cout << generate(longnum, shortnum, target - 1) << endl;
		}
	}
	return 0;
}
//k번째 답 구하기: 모든 경우를 탐색하는 완전 탐색 기반에 동적 계획법으로 바꾼다
//답을 사전순으로 생성하며 k-1번쨰를 건너뛰는 방법을 이용한다.
//선택지에 따라 k번째가 소속될 경우와 아닌경우를 고려해서 탐색의 수를 절반으로 줄여 나간다.
//장음의 갯수와 단음의 갯수가 주어질때 skip+1번쨰 배열을 출력
string generate(int longsign, int shortsign, int skip)
{
	//기저사례: longsign=0일시 shortsign만출력
	if (longsign == 0) {
		return string(shortsign,'O');
	}
	//만약 skip이 장음을 선택한 범위내에 존재할경우
	if (skip < binary[longsign + shortsign - 1][longsign - 1]) {
		return "-" + generate(longsign - 1, shortsign, skip);
	}
	//그 밖일경우, skip에서 장음선택 갯수만큼을 빼고 계산한다
	return "O" + generate(longsign, shortsign - 1, skip - binary[longsign + shortsign - 1][longsign - 1]);
}
