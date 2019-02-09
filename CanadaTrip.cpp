#include "pch.h"
#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>

using namespace std;
int townNum,target;
vector<vector<int>> townInfo;
enum town {
	Town_Position,
	Sign_First,
	Sign_Gap
};
bool decision(int dist);
int optimize();
//최적화문제를 결정 문제로 바꾸어 풀기
//x보다 좋은 값이 있는가? 로 바꾸어보면 단순해진다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> townNum;
		cin >> target;
		//[마을번호][시작점으로부터의 거리, 첫 표지판과 마을간의 거리, 표지판 간격]
		townInfo = vector<vector<int>>(townNum,vector<int>(3));
		for (int i = 0; i < townNum; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> townInfo[i][j];
			}
		}
		cout << optimize() << endl;
	}
	return 0;
}
//dist 까지 탐색했을때 Target 이상의 표지판을 볼수 있는가
bool decision(int dist) {
	int result = 0;
	for (int i = 0; i < townNum; i++) {
		//i번째 마을의 표지판이 나타나는 부분까지 dist를 가는가
		if (dist >= townInfo[i][Town_Position] - townInfo[i][Sign_First]) {
			//town까지 최대 근접한 거리 - 첫 표지판 등장 장소 / 간격 +1(0이여도 표지판 1개는 나온다)
			result += (min(dist, townInfo[i][Town_Position]) - (townInfo[i][Town_Position] - townInfo[i][Sign_First])) / townInfo[i][Sign_Gap] + 1;
		}
	}
	if (result >= target) {
		return true;
	}
	else {
		return false;
	}
}

int optimize() {
	//마을의 최대 거리 high
	int low = 0, high = 8030000;
	//정확한 값, low==high일 때를 구해야 하므로 계속 돌린다
	while (low + 1 < high) {
		int mid = (low + high) / 2;
		if (decision(mid)) {
			//너무 갔으므로
			high = mid;
		}
		else {
			//덜 갔으므로
			low = mid;
		}
	}
	return high;
}