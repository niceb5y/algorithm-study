#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int people, lastPeople;
double courseTotal;
vector<vector<double>> peopleSpec;
double calcTime(double runLen, int people);
double diff(double runLen);
double maxDiff();
enum specInfo {
	running,
	cycling
};
//삼분 검색으로 해 구하기
//순증가이며, 유니모달함수라면 극점을 삼분검색으로 검색하는게 빠르다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> courseTotal;
		cin >> people;
		lastPeople = people - 1;
		peopleSpec = vector<vector<double>>(people,vector<double>(2));
		for (int i = 0; i < people; i++) {
			cin >> peopleSpec[i][running];
			cin >> peopleSpec[i][cycling];
		}
		if (maxDiff() == 0) {
			cout << "Impossible" << endl;
		}
		else {
			cout << maxDiff() << endl;
		}
	}
	return 0;
}
//한 선수의 코스길이 구하기
double calcTime(double runLen, int people)
{
	double cycleLen = courseTotal - runLen;
	return runLen/peopleSpec[people][running] + cycleLen/peopleSpec[people][cycling];
}
//달리기 길이가 정해졌을때 마지막 선수가 얼마나 빠르게 이길수 있는지 계산
double diff(double runLen)
{
	double cheater = calcTime(runLen, lastPeople);
	double others = calcTime(runLen, 0);
	for (int i = 1; i < people - 1; i++) {
		others = min(others, calcTime(runLen, i));
	}
	return others - cheater;
}

double maxDiff()
{
	//최적문제를 판정 문제로 바꾸어 푸는 형식으로 바꾼다
	double low = 0, high = courseTotal;
	//이분법이랑 비슷하게 진행한다
	for (int i = 0; i < 100; i++) {
		double min3 = (2 * low + high) / 3;
		double max3 = (low + high * 2) / 3;
		//극점이 두 구간 사이에 있거나, 순하락 구간인것
		if (diff(min3) > diff(max3)) {
			high = max3;
		}
		//극점이 두 구간 사이에 있거나 순증가 구간인것
		else {
			low = min3;
		}
	}
	//cheater의 시간이 더 커서 음수가 반환된다면
	//이길 수가 없다
	if (diff((low + high) / 2) < 0) {
		return 0;
	}
	return (low + high) / 2;
}
