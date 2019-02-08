#include "pch.h"
#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>

using namespace std;
int spotNum;
vector<double> spotX, spotY;
vector<vector<double>> spotDistance;
bool decision(double gap);
double optimize();
//최적화문제를 결정 문제로 바꾸어 풀기
//x보다 좋은 값이 있는가? 로 바꾸어보면 단순해진다
int main() {
	cout << fixed;
	cout.precision(2);
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> spotNum;
		spotX = vector<double>(spotNum);
		spotY = vector<double>(spotNum);
		spotDistance = vector<vector<double>>(spotNum, vector<double>(spotNum, 0));
		for (int i = 0; i < spotNum; i++) {
			cin >> spotX[i];
			cin >> spotY[i];
		}
		for (int i = 0; i < spotNum; i++) {
			for (int j = 0; j < spotNum; j++) {
				spotDistance[i][j] = sqrt(pow(spotX[i] - spotX[j], 2) + pow(spotY[i] - spotY[j], 2));
			}
		}
		cout << optimize() << endl;
	}
	return 0;
}
//gap간격으로 모든 기지를 연결 가능한가?
bool decision(double gap) {
	vector<bool> visited(spotNum, false);
	visited[0] = true;
	//전파가 닿는 위치를 넣는다
	queue<int> que;
	que.push(0);
	int seen = 0;
	while (!que.empty())
	{
		int here = que.front();
		que.pop();
		seen++;
		for (int there = 0; there < spotNum; there++) {
			//만약 전파가 닿고 방문하지 않은 곳일때 방문해본다
			if (!visited[there] && spotDistance[here][there] <= gap) {
				visited[there] = true;
				que.push(there);
			}
		}
	}
	return seen == spotNum;
}

//Draph문제의 이분법이랑 비슷하다
//단 이번에는 최소인 해를 구해야 하므로 간격 배정은 반대로 한다
double optimize()
{
	double low = 0.0, high = 1426.0;
	for (int i = 0; i < 100; i++) {
		double mid = (low + high) / 2.0;
		if (decision(mid)) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	return high;
}
