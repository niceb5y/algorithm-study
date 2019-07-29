#include"pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candyNum;
int gotMoney;
vector<pair<int, int>> candyList;
vector<int> cache;
int main() {
	while (true)
	{
		cin >> candyNum;
		float m1;
		cin >> m1;
		if (candyNum == 0) {
			return 0;
		}
		candyList = vector<pair<int, int>>(candyNum);
		for (int i = 0; i < candyNum; i++) {
			int candyCalorie;
			float candyPrice;
			cin >> candyCalorie;
			cin >> candyPrice;
			int converter = (int)(candyPrice * 100 + 0.5);
			candyList[i] = make_pair(candyCalorie, converter);
		}
		gotMoney = (int)(m1 * 100 + 0.5);
		cache = vector<int>(gotMoney + 1, 0);

		//바텀업으로 풀어보기
		int Total = 0;
		for (int i = 0; i < candyNum; i++) {
			for (int tempMoney = candyList[i].second; tempMoney <= gotMoney; tempMoney++) {
				if (tempMoney - candyList[i].second >= 0) {
					cache[tempMoney] = max(cache[tempMoney], cache[tempMoney - candyList[i].second] + candyList[i].first);
					Total = max(cache[tempMoney], Total);
				}
			}
		}
		cout << Total << endl;
	}
}