#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string Base;
vector<vector<bool>> isPalendrome;
vector<int> minDevide;
int madeDevide(int start);
int main() {
	cin >> Base;
	isPalendrome = vector<vector<bool>>(Base.length(),vector<bool>(Base.length(),false));
	for (int wordLen = 1; wordLen <= Base.length(); wordLen++) {
		for (int i = 0; i < Base.length(); i++) {
			//이번 길이 초과시
			if (i + wordLen - 1 >= Base.length()) {
				break;
			}
			// 1개의 문자일시 팰린드롬
			if (wordLen == 1) {
				isPalendrome[i][i+wordLen-1] = true;
			}
			//2개의 문자이며 좌우가 대칭시 팰린드롬
			else if (wordLen == 2 && Base.at(i) == Base.at(i+wordLen-1)) {
				isPalendrome[i][wordLen + i -1] = true;
			}
			//3개 이상의 문자이며 좌우가 같고 한단계 전이 팰린드롬이라면 팰린드롬
			else if (Base.at(i) == Base.at(i+wordLen-1) && isPalendrome[i+1][i+wordLen-2]) {
				isPalendrome[i][i+wordLen-1] = true;
			}
		}
	}
	minDevide = vector<int>(Base.length(), Base.length()+1);
	cout << madeDevide(0) << endl;
	return 0;
}

int madeDevide(int start)
{
	//기저사례 만약 범위 초과라면 리턴
	if (start >= Base.length()) {
		return 0;
	}
	if (minDevide[start] != Base.length() + 1) {
		return minDevide[start];
	}
	for (int i = start; i < Base.length(); i++) {
		//해당 인덱스까지 팰린드롬이라면
		if (isPalendrome[start][i]) {
			//나머지를 팰린드롬 해본다
			minDevide[start] = min(minDevide[start], madeDevide(i + 1) + 1);
		}
	}
	return minDevide[start];
}
