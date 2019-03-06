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
	//�޸������̼�
	if (cache[index][groupNum] != -1) {
		return cache[index][groupNum];
	}
	//�������: �־��� index ���ķ� 1���� ������ ������
	if (groupNum == 1) {
		result = 0;
		for (int i = index; i < bizNum; i++) {
			result += bizList[i];
		}
		cache[index][groupNum] = result;
		//�̹� ������ �������� ����
		Jumpcache[index][groupNum] = bizNum - index;
		return result;
	}
	//�־��� ������ �׷���� �������������� ������ �߶󺻴�
	int thisGroupTotal = 0;
	int jumpSync;
	for (int i = 1; i + index <= bizNum + 1 - groupNum; i++) {
		//�̹� �׷��� ���� �÷�������
		thisGroupTotal += bizList[i + index - 1];
		//������ �׷��� �������� �ڸ���
		int cutResult = cutBiz(i + index, groupNum - 1);
		//�������� �׷�ȭ�� ����� �̹� ����� �ִ븦 �����Ѵ�
		cutResult = max(cutResult, thisGroupTotal);
		if (cutResult < result) {
			//�ִ밪�� �ּҰ��� �����Ѵ�
			result = cutResult;
			jumpSync = i;
		}
	}
	cache[index][groupNum] = result;
	Jumpcache[index][groupNum] = jumpSync;
	return result;
}
