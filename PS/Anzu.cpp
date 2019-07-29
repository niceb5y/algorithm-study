#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//������ �ּ� �Ҽ� ����
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
	//��� ���� 0�̵ǰ� ��� ����� ���� �ϳ�, ��� �Ȱ��¹��̴�
	cache[0][0] = 1;
	cache[1][0] = 1;
	//�̹� ������ ������
	for (int candyTemp = 0; candyTemp < candyList.size(); candyTemp++) {
		//���� ������ִ� ����� ���� ���Ѵ�
		for (int currSum = 0; currSum <= total; currSum++) {
			cache[candyTemp % 2][currSum] = 0;
			//���� ������ �� ���ϱ�
			for (int tempCandyNum = 0; tempCandyNum <= candyList[candyTemp].second; tempCandyNum++) {
				//�� �ʰ��� false
				if (candyList[candyTemp].first * tempCandyNum > currSum) {
					continue;
				}
				//�̹� �μ��� x�� ���ϴ� ����Ǽ� 1���� + �̹������� ���ڸ� ����� ����� �ϸ�
				//���� ���� ����� ������ �̴� ������ ����� �ϳ��̴�
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
	//�ʱ��� ���� �ڱ� �ڽ�
	for (int i = 2; i <= minFactor.size() - 1; i++) {
		minFactor[i] = i;
	}
	//��x�� p*q�� ǥ���ɶ� �ݵ�� �ϳ��� x�� ������ �����̴�
	int sqrtn = int(sqrt(minFactor.size() - 1));
	for (int i = 2; i <= sqrtn; i++) {
		//������ �ʾҴٸ�
		if (minFactor[i] == i) {
			//�־��� ������ ������� �ּҷ� �־�д�
			for (int j = i * i; j <= minFactor.size() - 1; j += i) {
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
}