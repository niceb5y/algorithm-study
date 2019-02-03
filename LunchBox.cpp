#include "pch.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int boxNum;
vector<int> hotTime,eatTime;
//탐욕적 알고리즘
//스케쥴링 문제는 탐욕법을 고려해보자
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boxNum;
		hotTime = vector<int>(boxNum);
		eatTime = vector<int>(boxNum);
		for (int i = 0; i < boxNum; i++) {
			cin >> hotTime[i];
		}
		for (int i = 0; i < boxNum; i++) {
			cin >> eatTime[i];
		}
		//뎁히는 시간과는 상관없이 먹는데 오래걸리는 도시락을 먼저 데우는게 이득이다
		vector<pair<int, int>> minusOrder;
		for (int i = 0; i < boxNum; i++) {
			//먹는데 오래걸리는 항목을 맨 앞으로 정렬하기 위한 -부호
			minusOrder.push_back(make_pair(-eatTime[i], i));
		}
		sort(minusOrder.begin(), minusOrder.end());
		int result = 0, makeupTime = 0;
		for (int i = 0; i < boxNum; i++) {
			//먹는데 제일 오래 걸릴박스
			int tempBox = minusOrder[i].second;
			//이전의 박스와 지금까지의 박스들의 총 데우는 시간 합
			makeupTime += hotTime[tempBox];
			//점심시간은 마지막 박스까지 데우고 먹어야 끝난다
			result = max(result, makeupTime + eatTime[tempBox]);
		}
		cout << result << endl;
	}
	return 0;
}