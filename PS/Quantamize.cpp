#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> bizList;
vector<vector<int>> cache;
vector<vector<int>> Jumpcache;
int bizNum, groupTNum, firstCut;
int cutBiz(int index, int groupNum);
int main() {
	cin >> bizNum;
	bizList = vector<int>(bizNum);
	cin >> groupTNum;
	cache = vector<vector<int>>(bizNum, vector<int>(groupTNum + 1, -1));
	Jumpcache = vector<vector<int>>(bizNum, vector<int>(groupTNum + 1, -1));
	for(int i = 0; i< bizNum;i++){
		cin >> bizList[i];
	}
	cout << cutBiz(0, groupTNum) << endl;
	int jumpNum = 0;
	
	for (int i = groupTNum; i > 0; i--) {
		cout << Jumpcache[jumpNum][i]<<" ";
		jumpNum += Jumpcache[jumpNum][i];
	}
}

int cutBiz(int index, int groupNum)
{
	int result = 100*bizNum;
	//메모이제이션
	if (cache[index][groupNum] != -1) {
		return cache[index][groupNum];
	}
	//기저사례: 주어진 index 이후로 1개의 묶음을 만들어낼시
	if (groupNum == 1) {
		result = 0;
		for (int i = index; i < bizNum; i++) {
			result += bizList[i];
		}
		cache[index][groupNum] = result;
		//이번 최적의 점프갯수 저장
		Jumpcache[index][groupNum] = bizNum - index;
		return result;
	}
	//주어진 구슬을 그룹수를 만족할정도까지 일일히 잘라본다
	int thisGroupTotal = 0;
	int jumpSync;
	for (int i = 1; i + index <= bizNum + 1 - groupNum; i++) {
		//이번 그룹의 합을 늘려나간다
		thisGroupTotal += bizList[i + index - 1];
		//나머지 그룹을 최적으로 자른다
		int cutResult = cutBiz(i + index, groupNum - 1);
		//최적으로 그룹화된 결과와 이번 결과중 최대를 저장한다
		cutResult = max(cutResult, thisGroupTotal);
		if (cutResult < result) {
			//최대값의 최소값을 저장한다
			result = cutResult;
			jumpSync = i;
		}
	}
	cache[index][groupNum] = result;
	Jumpcache[index][groupNum] = jumpSync;
	return result;
}
