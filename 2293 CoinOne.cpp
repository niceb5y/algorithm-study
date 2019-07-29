#include "pch.h"

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int wishCost, coinNumber;
vector<int> coinList;
vector<int> cache;

int main() {
	cin >> coinNumber;
	cin >> wishCost;
	coinList = vector<int>(coinNumber);
	for (int i = 0; i < coinNumber; i++) {
		cin >> coinList[i];
	}
	coinList.erase(unique(coinList.begin(), coinList.end()), coinList.end());
	cache = vector<int>(wishCost + 1, 0);
	cache[0] = 1;
	for (int i = 0; i < coinList.size(); i++) {
		for (int tempDest = coinList[i]; tempDest <= wishCost; tempDest++) {
			cache[tempDest] += cache[tempDest - coinList[i]];
		}
	}
	cout << cache[wishCost] << endl;
}

