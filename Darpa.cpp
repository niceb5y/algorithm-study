#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int camNum, spotNum;
vector<double> spot;
bool decision(const vector<double>& location, int cameras, double gap);
double optimize(const vector<double>& location, int cameras);
//����ȭ������ ���� ������ �ٲپ� Ǯ��
//x���� ���� ���� �ִ°�? �� �ٲپ�� �ܼ�������
int main() {
	cout << fixed;
	cout.precision(2);
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> camNum;
		cin >> spotNum;
		spot = vector<double>(spotNum);
		for (int i = 0; i < spotNum; i++) {
			cin >> spot[i];
		}
		cout << optimize(spot, camNum) << endl;
	}
	return 0;
}

//�־��� ��ҿ� cameras��ŭ ��ġ�Ҷ� ��� ������ gap���� �о�� �Ѵ�
bool decision(const vector<double>& location, int cameras, double gap)
{
	//Ž���: ���� ���ʿ� ī�޶� ���� �ʴ� �����ذ� �ִٸ�, �� �������� ���� ������ ��ġ������ ó������ �̵��ص� �ȴ�
	//�׷��Ƿ� ���� ���ʺ��� ī�޶� �δ°� �̵�
	//�Ÿ�����
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(); i++) {
		//�Ÿ����Ѻ��� �Ѱ� ������
		if (limit <= location[i]) {
			installed++;
			//�� ��ҷκ��� gap ���� ī�޶� ��ġ �� �� ����
			limit = gap + location[i];
		}
	}
	//��ġ�� ī�޶� �䱸���׺��� ���� �Ǿ��ٸ� ��¶�ų� ����
	return installed >= cameras;
}

//����ȭ ���� �ȿ� ���� ������ �����ϰԲ� ¥�°� ����Ʈ
double optimize(const vector<double>& location, int cameras)
{
	//�Ÿ����ִ밪 = 240
	//���� �����̴�
	double lo = 0, hi = 241;
	//13���� �̺й� �ϴ� �׳� ����
	for (int i = 0; i < 100; i++) {
		//������ ���� �ο� ����
		double mid = (hi + lo) / 2.0;
		//���� ���� �ο�� ã�Ƴ���
		//mid �������� ��ġ �����ϸ�
		if (decision(location, cameras, mid)) {
			//���� �а� ��ġ�غ���
			lo = mid;
		}
		//��ġ�� �Ұ��� �ϸ�
		else {
			//�� ���� ��ġ�غ���
			hi = mid;
		}
	}
	//������ ���� ������
	return lo;
}
