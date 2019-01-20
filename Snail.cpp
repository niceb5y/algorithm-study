#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int depth, limitDay;
vector<vector<double>> cache;
double goBed(int depth, int days);
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
int main() {
	cout << fixed;
	cout.precision(11);
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> depth;
		cin >> limitDay;
		cache = vector<vector<double>>(depth, vector<double>(limitDay, -1.0));
		cout << goBed(0, 0) << endl;
	}
	return 0;
}
//달팽이 우물 오르기 문제
//경우의 수의 문제는 완전탐색을 기본으로 한다
double goBed(int climbed, int days)
{
	if (days >= limitDay) {
		if (climbed >= depth) {
			return 1.0;
		}
		else {
			return 0.0;
		}
	}
	if (climbed >= depth) {
		return 1.0;
	}
	double& memo = cache[climbed][days];
	if (memo != -1.0) {
		return memo;
	}
	//경우의 수 문제에 확률이 부여될때 각 경우의 수에 확률을 곱해준다
	memo = 0.75*goBed(climbed + 2, days + 1) + 0.25*goBed(climbed + 1, days + 1);
	return memo;
}
