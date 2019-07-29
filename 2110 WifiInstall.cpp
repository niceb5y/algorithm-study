#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int houseNum, WifiNum;
vector<int> houseList;

bool canSetting(int distance, int tempwifiNum, int index);
int main() {
	cin >> houseNum;
	cin >> WifiNum;
	houseList = vector<int>(houseNum);

	for (int i = 0; i < houseNum; i++) {
		cin >> houseList[i];
	}
	houseList.erase(unique(houseList.begin(), houseList.end()), houseList.end());
	sort(houseList.begin(), houseList.end());
	int high = houseList[houseList.size() - 1], low = 1, mid = (high + low) / 2;
	while (true)
	{
		if (high - low <= 1) {
			if (canSetting(high,WifiNum,0)) {
				cout << high << endl;
				return 0;
			}
			cout << low << endl;
			return 0;
		}
		if (canSetting(mid,WifiNum, 0)) {
			low = mid;
		}
		else {
			high = mid;
		}
		mid = (high + low) / 2;
	}
}

bool canSetting(int distance, int tempwifiNum, int index)
{
	if (tempwifiNum == 1) {
		return true;
	}
	for (int i = index; i + 1 < houseNum; i++) {
		if (houseList[i + 1] - houseList[index] >= distance) {
			return canSetting(distance, tempwifiNum - 1, i + 1);
		}
	}
	return false;
}
