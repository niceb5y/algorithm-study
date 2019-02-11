#include "pch.h"
#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>

using namespace std;
int polySize;
const double solLimit = 10;
vector<double> poly;
vector<double> diffrentiate(vector<double>& inputP);
vector<double>solveLow(vector<double>& inputP);
vector<double>solve(vector<double>& inputP);
double envaluate(vector<double>& inputP, double x0);
int main() {
	cout << fixed;
	cout.precision(12);
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> polySize;
		poly = vector<double>(polySize + 1, 0.0);
		for (int i = 0; i < polySize + 1; i++) {
			cin >> poly[i];
		}
		vector<double> result = solve(poly);
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) {
			cout << result[i]<<" ";
		}
		cout << endl;
	}
	return 0;
}
//미분한다
vector<double> diffrentiate(vector<double>& inputP)
{
	vector<double> result = vector<double>(inputP.size() - 1);
	for (int i = 0; i < result.size(); i++) {
		result[i] = inputP[i] * (inputP.size() - 1 - i);
	}
	return result;
}
//1,2차를 푼다
vector<double> solveLow(vector<double>& inputP)
{
	vector<double> result = vector<double>();
	if (inputP.size() == 3) {
		result.push_back((-inputP[1] - sqrt(pow(inputP[1], 2) - 4 * inputP[0] * inputP[2])) / (2 * inputP[0]));
		result.push_back((-inputP[1] + sqrt(pow(inputP[1], 2) - 4 * inputP[0] * inputP[2])) / (2 * inputP[0]));
	}
	else if (inputP.size() == 2) {
		result.push_back((-inputP[1])/inputP[0]);
	}
	return result;
}
//풀이부
vector<double> solve(vector<double>& inputP)
{
	//기저사례: 방정식이 2차 이하일때
	int n = inputP.size() - 1;
	if (n <= 2) {
		return solveLow(inputP);
	}
	//한단계 미분한다
	vector<double> downD = diffrentiate(inputP);
	//함수의 극점을 구한다
	vector<double> downDS = solve(downD);
	//구간을 설정한다
	downDS.insert(downDS.begin(), -solLimit - 1);
	downDS.insert(downDS.end(), solLimit + 1);
	vector<double> result = vector<double>();
	//모든 극점 사이를 본다
	for (int i = 0; i + 1 < downDS.size(); i++) {
		//극점의 x좌표
		double x1 = downDS[i], x2 = downDS[i + 1];
		//극점의 y좌표
		double y1 = envaluate(inputP, x1), y2 = envaluate(inputP,x2);
		//두 극점의 좌표가 같다면 이 구간동안 0점을 지나지 않는다
		if (y1*y2 > 0) {
			continue;
		}
		if (y1 > y2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		//이분법 사용의 시작
		for (int iter = 0; iter < 100; iter++) {
			double xMid = (x1 + x2) / 2;
			double yMid = envaluate(inputP,xMid);
			//부호가 같다 = 아직 같은 구역에 있다 = 해는 더 뒤에 있다
			if (y1*yMid > 0) {
				y1 = yMid;
				x1 = xMid;
			}
			else {
				y2 = yMid;
				x2 = xMid;
			}
		}
		//이분법으로 오차를 최소화한 해
		result.push_back((x1 + x2) / 2);
	}
	sort(result.begin(), result.end());
	return result;
}
//함수에 x0대입시의 해를 구한다
double envaluate(vector<double>& inputP, double x0)
{
	double result = 0.0;
	for (int i = 0; i < inputP.size()-1; i++) {
		result += inputP[i] * pow(x0, inputP.size() - 1 - i);
	}
	result += inputP[inputP.size() - 1];
	return result;
}
