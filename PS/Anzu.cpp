#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//가격의 최소 소수 저장
vector<int> minFactor;
//price,number;
vector<pair<int, int>> candyList;
int candyNum, zero = 0;
void erathos();
vector<vector<long long>> cache;
int main() {
	int temp;
	cin >> candyNum;
	candyList = vector<pair<int, int>>();

	vector<int> tempCandy = vector<int>();
	int candySize;
	for (int i = 0; i < candyNum; i++) {
		cin >> candySize;
		if (candySize == 0) {
			zero++;
			continue;
		}
		tempCandy.push_back(candySize);
	}
	sort(tempCandy.begin(), tempCandy.end());
	candyNum -= zero;
	if (candyNum <= 0) {
		cout << 0 << endl;
		return 0;
	}
	candyList.push_back(make_pair(tempCandy[0], 1));
	int total = candyList[0].first;
	for (int i = 1; i < candyNum; i++) {
		total += tempCandy[i];
		if (candyList.back().first != tempCandy[i]) {
			candyList.push_back(make_pair(tempCandy[i], 1));
		}
		else {
			candyList[candyList.size() - 1].second += 1;
		}
	}
	minFactor = vector<int>(total + 1);
	erathos();
	cache = vector<vector<long long>>(2,vector<long long>(total + 1, 0));
	//모든 합이 0이되게 사는 경우의 수는 하나, 모두 안고르는법이다
	cache[0][0] = 1;
	cache[1][0] = 1;
	//이번 사탕을 따진다
	for (int candyTemp = 0; candyTemp < candyList.size(); candyTemp++) {
		//수를 만들수있는 경우의 수를 구한다
		for (int currSum = 0; currSum <= total; currSum++) {
			cache[candyTemp % 2][currSum] = 0;
			//현재 사탕의 수 구하기
			for (int tempCandyNum = 0; tempCandyNum <= candyList[candyTemp].second; tempCandyNum++) {
				//수 초과시 false
				if (candyList[candyTemp].first * tempCandyNum > currSum) {
					continue;
				}
				//이번 인수를 x번 곱하는 경우의수 1가지 + 이번까지의 숫자를 만드는 방법을 하면
				//다음 수의 결과가 나오고 이는 수많은 방법중 하나이다
				cache[candyTemp%2][currSum] += cache[(candyTemp+1)%2][currSum - candyList[candyTemp].first * tempCandyNum];
			}
		}
	}
	long long result = 0;
	for (int index = 2; index <= total; index++) {
		if (index == minFactor[index]) {
			result += cache[(candyList.size()-1)%2][index];
		}
	}
	result *= (zero + 1);
	cout << result << endl;
}

void erathos()
{
	minFactor[0] = minFactor[1] = -1;
	//초기의 값은 자기 자신
	for (int i = 2; i <= minFactor.size() - 1; i++) {
		minFactor[i] = i;
	}
	//수x가 p*q로 표현될때 반드시 하나는 x의 제곱근 이하이다
	int sqrtn = int(sqrt(minFactor.size() - 1));
	for (int i = 2; i <= sqrtn; i++) {
		//구하지 않았다면
		if (minFactor[i] == i) {
			//주어진 숫자의 배수들을 최소로 넣어둔다
			for (int j = i * i; j <= minFactor.size() - 1; j += i) {
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
}