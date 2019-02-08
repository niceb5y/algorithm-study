#include "pch.h"
#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>

using namespace std;
int spotNum;
vector<double> spotX, spotY;
vector<vector<double>> spotDistance;
bool decision(double gap);
double optimize();
//����ȭ������ ���� ������ �ٲپ� Ǯ��
//x���� ���� ���� �ִ°�? �� �ٲپ�� �ܼ�������
int main() {
	cout << fixed;
	cout.precision(2);
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> spotNum;
		spotX = vector<double>(spotNum);
		spotY = vector<double>(spotNum);
		spotDistance = vector<vector<double>>(spotNum, vector<double>(spotNum, 0));
		for (int i = 0; i < spotNum; i++) {
			cin >> spotX[i];
			cin >> spotY[i];
		}
		for (int i = 0; i < spotNum; i++) {
			for (int j = 0; j < spotNum; j++) {
				spotDistance[i][j] = sqrt(pow(spotX[i] - spotX[j], 2) + pow(spotY[i] - spotY[j], 2));
			}
		}
		cout << optimize() << endl;
	}
	return 0;
}
//gap�������� ��� ������ ���� �����Ѱ�?
bool decision(double gap) {
	vector<bool> visited(spotNum, false);
	visited[0] = true;
	//���İ� ��� ��ġ�� �ִ´�
	queue<int> que;
	que.push(0);
	int seen = 0;
	while (!que.empty())
	{
		int here = que.front();
		que.pop();
		seen++;
		for (int there = 0; there < spotNum; there++) {
			//���� ���İ� ��� �湮���� ���� ���϶� �湮�غ���
			if (!visited[there] && spotDistance[here][there] <= gap) {
				visited[there] = true;
				que.push(there);
			}
		}
	}
	return seen == spotNum;
}

//Draph������ �̺й��̶� ����ϴ�
//�� �̹����� �ּ��� �ظ� ���ؾ� �ϹǷ� ���� ������ �ݴ�� �Ѵ�
double optimize()
{
	double low = 0.0, high = 1426.0;
	for (int i = 0; i < 100; i++) {
		double mid = (low + high) / 2.0;
		if (decision(mid)) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	return high;
}
