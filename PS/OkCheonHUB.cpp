#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>

#define COST_MAX 1000000000;
using namespace std;
int parcelNum, roadCost, heliCost;
vector<int> parcelDist;
vector<int> singleCache;
vector<vector<int>> planeCache;
int main() {
	cin >> parcelNum;
	parcelDist = vector<int>(parcelNum);
	for (int i = 0; i < parcelNum; i++) {
		cin >> parcelDist[i];
	}
	sort(parcelDist.begin(), parcelDist.end());
	cin >> roadCost;
	cin >> heliCost;
	//택배를 먼곳까지 직접 이동시키는건 좋지 않다
	//가까운 택배는 결국 차로 이동하는게 좋으므로 선형 구조로 푼다
	singleCache = vector<int>(parcelNum,-1);
	singleCache[0] = min(heliCost, roadCost*parcelDist[0]);
	planeCache = vector<vector<int>>(parcelNum, vector<int>(parcelNum, -1));
	//시간 단축을 위한 캐싱
	//정방향 캐싱
	for (int i = 0; i < parcelNum; i++) {
		planeCache[i][i] = 0;
		for (int j = i+1; j < parcelNum; j++) {
			planeCache[i][j] = parcelDist[j] - parcelDist[i] + planeCache[i][j - 1];
		}
	}
	//순서가 상관 있게되므로 역방향을 따로 캐싱해줘야한다
	//역방향 캐싱
	for (int i = 0; i < parcelNum; i++) {
		for (int j = i - 1; j >= 0; j--) {
			planeCache[i][j] = parcelDist[i] - parcelDist[j] + planeCache[i][j + 1];
		}
	}
	//체인 매트릭스 알고리즘 변형
	for (int i = 1; i < parcelNum; i++) {
		//이번 택배를 그냥 운송하는게 좋을까?
		singleCache[i] = singleCache[i - 1] + parcelDist[i] * roadCost;
		int minCost = COST_MAX;
		//비행기를 섞어서 운송하는게 좋을까?
		for (int j = i; j >= 0; j--) {
			if (j == 0) {
				minCost = min(minCost, heliCost + roadCost * (planeCache[(j + i) / 2][i] + planeCache[(j + i) / 2][j]));
				break;
			}
			minCost = min(minCost,singleCache[j - 1]+ heliCost + roadCost * (planeCache[(j + i) / 2][i] + planeCache[(j + i) / 2][j]));
		}
		singleCache[i] = min(singleCache[i], minCost);
	}
	cout << singleCache[parcelNum-1] << endl;
}