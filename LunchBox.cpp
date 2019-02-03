#include "pch.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int boxNum;
vector<int> hotTime,eatTime;
//Ž���� �˰���
//�����층 ������ Ž����� ����غ���
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boxNum;
		hotTime = vector<int>(boxNum);
		eatTime = vector<int>(boxNum);
		for (int i = 0; i < boxNum; i++) {
			cin >> hotTime[i];
		}
		for (int i = 0; i < boxNum; i++) {
			cin >> eatTime[i];
		}
		//������ �ð����� ������� �Դµ� �����ɸ��� ���ö��� ���� ����°� �̵��̴�
		vector<pair<int, int>> minusOrder;
		for (int i = 0; i < boxNum; i++) {
			//�Դµ� �����ɸ��� �׸��� �� ������ �����ϱ� ���� -��ȣ
			minusOrder.push_back(make_pair(-eatTime[i], i));
		}
		sort(minusOrder.begin(), minusOrder.end());
		int result = 0, makeupTime = 0;
		for (int i = 0; i < boxNum; i++) {
			//�Դµ� ���� ���� �ɸ��ڽ�
			int tempBox = minusOrder[i].second;
			//������ �ڽ��� ���ݱ����� �ڽ����� �� ����� �ð� ��
			makeupTime += hotTime[tempBox];
			//���ɽð��� ������ �ڽ����� ����� �Ծ�� ������
			result = max(result, makeupTime + eatTime[tempBox]);
		}
		cout << result << endl;
	}
	return 0;
}