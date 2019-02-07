#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int camNum, spotNum;
vector<double> spot;
bool decision(const vector<double>& location, int cameras, double gap);
double optimize(const vector<double>& location, int cameras);
//최적화문제를 결정 문제로 바꾸어 풀기
//x보다 좋은 값이 있는가? 로 바꾸어보면 단순해진다
int main() {
	cout << fixed;
	cout.precision(2);
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> camNum;
		cin >> spotNum;
		spot = vector<double>(spotNum);
		for (int i = 0; i < spotNum; i++) {
			cin >> spot[i];
		}
		cout << optimize(spot, camNum) << endl;
	}
	return 0;
}

//주어진 장소에 cameras만큼 설치할때 모든 간격이 gap보다 넓어야 한다
bool decision(const vector<double>& location, int cameras, double gap)
{
	//탐욕법: 제일 왼쪽에 카메라를 두지 않는 최적해가 있다면, 이 최적해의 제일 왼쪽을 설치구간의 처음으로 이동해도 된다
	//그러므로 제일 왼쪽부터 카메라를 두는게 이득
	//거리제한
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(); i++) {
		//거리제한보다 넘게 왔을때
		if (limit <= location[i]) {
			installed++;
			//이 장소로부터 gap 동안 카메라를 설치 할 수 없다
			limit = gap + location[i];
		}
	}
	//설치된 카메라가 요구사항보다 많게 되었다면 어쨋거나 성공
	return installed >= cameras;
}

//최적화 문제 안에 결정 문제를 포함하게끔 짜는게 포인트
double optimize(const vector<double>& location, int cameras)
{
	//거리의최대값 = 240
	//값의 범위이다
	double lo = 0, hi = 241;
	//13장의 이분법 일단 그냥 쓰자
	for (int i = 0; i < 100; i++) {
		//일종의 하이 로우 게임
		double mid = (hi + lo) / 2.0;
		//답을 하이 로우로 찾아낸다
		//mid 간격으로 배치 가능하면
		if (decision(location, cameras, mid)) {
			//좀더 넓게 배치해본다
			lo = mid;
		}
		//배치가 불가능 하면
		else {
			//더 좁게 배치해본다
			hi = mid;
		}
	}
	//범위중 제일 낮은값
	return lo;
}
