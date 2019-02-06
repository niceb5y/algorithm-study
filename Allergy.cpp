#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int friendNum, foodNum,bestCase;
vector<vector<int>> canEat,canEaten;
void party(vector<int>& myFood, int choosen);
//정렬용 함수들
bool compare(const vector<int> &a, const vector<int> &b) {
	return a.size() < b.size();
}
bool revcompare(const vector<int> &a, const vector<int> &b) {
	return a.size() > b.size();
}
//조합 탐색
//완전 탐색중 거쳐갈 필요가 없는 부분은 가지 않음으로써 시간을 절약하는 방법
//동적계획법의 메모이제이션이 공간상 어려울경우 시도
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> friendNum;
		cin >> foodNum;
		//모든 음식을 다 만들경우가 최대
		bestCase = foodNum;
		//i가 먹을수 있는 음식들
		canEat = vector<vector<int>>(friendNum);
		//i를 먹을수 있는 친구들 목록
		canEaten = vector<vector<int>>(foodNum);
		vector<string> friendName = vector<string>(friendNum);
		for (int i = 0; i < friendNum; i++) {
			cin >> friendName[i];
		}
		for (int food = 0; food < foodNum; food++) {
			int size;
			cin >> size;
			canEaten[food] = vector<int>(size);
			for (int i = 0; i < size; i++) {
				string eater;
				cin >> eater;
				for (int j = 0; j < friendNum; j++) {
					if (friendName[j] == eater) {
						canEaten[food][i] = j;
						canEat[j].push_back(food);
						break;
					}
				}
			}
		}
		//많이 먹을수 있는 음식을 먼저 고려하는게 이득
		//먹을 음식이 제일 적은 아이부터 고려하는게 이득
		//sort(canEaten.begin(), canEaten.end(),revcompare);
		//sort(canEat.begin(), canEat.end(),compare);
		vector<int> itemList = vector<int>(friendNum, 0);
		party(itemList, 0);
		cout << bestCase << endl;
	}
	return 0;
}
//i번째 아이가 먹을수 있는 음식의 수
void party(vector<int>& myFood, int choosen)
{
	//음식이 너무 많을때 리턴
	if (choosen >= bestCase) {
		return;
	}
	//아무것도 못먹는 사람을 찾아낸다
	int firstPity = 0;
	for (firstPity = 0; firstPity < friendNum; firstPity++) {
		if (myFood[firstPity] == 0) {
			break;
		}
	}
	//맨 앞의 거름으로 인해 choosen은 항상 bestcase보다 작다
	if (firstPity >= friendNum) {
		bestCase = choosen;
		return;
	}
	//첫번째로 못먹을 아이를 위한 음식을 고려한다
	for (int food = 0; food < canEat[firstPity].size(); food++) {
		int thisfood = canEat[firstPity][food];
		for (int feed = 0; feed < canEaten[thisfood].size(); feed++) {
			myFood[canEaten[thisfood][feed]]++;
		}
		party(myFood, choosen + 1);
		for (int feed = 0; feed < canEaten[thisfood].size(); feed++) {
			myFood[canEaten[thisfood][feed]]--;
		}
	}
}
