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
	//�ù踦 �հ����� ���� �̵���Ű�°� ���� �ʴ�
	//����� �ù�� �ᱹ ���� �̵��ϴ°� �����Ƿ� ���� ������ Ǭ��
	singleCache = vector<int>(parcelNum,-1);
	singleCache[0] = min(heliCost, roadCost*parcelDist[0]);
	planeCache = vector<vector<int>>(parcelNum, vector<int>(parcelNum, -1));
	//�ð� ������ ���� ĳ��
	//������ ĳ��
	for (int i = 0; i < parcelNum; i++) {
		planeCache[i][i] = 0;
		for (int j = i+1; j < parcelNum; j++) {
			planeCache[i][j] = parcelDist[j] - parcelDist[i] + planeCache[i][j - 1];
		}
	}
	//������ ��� �ְԵǹǷ� �������� ���� ĳ��������Ѵ�
	//������ ĳ��
	for (int i = 0; i < parcelNum; i++) {
		for (int j = i - 1; j >= 0; j--) {
			planeCache[i][j] = parcelDist[i] - parcelDist[j] + planeCache[i][j + 1];
		}
	}
	//ü�� ��Ʈ���� �˰��� ����
	for (int i = 1; i < parcelNum; i++) {
		//�̹� �ù踦 �׳� ����ϴ°� ������?
		singleCache[i] = singleCache[i - 1] + parcelDist[i] * roadCost;
		int minCost = COST_MAX;
		//����⸦ ��� ����ϴ°� ������?
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