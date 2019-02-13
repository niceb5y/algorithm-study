#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int people, lastPeople;
double courseTotal;
vector<vector<double>> peopleSpec;
double calcTime(double runLen, int people);
double diff(double runLen);
double maxDiff();
enum specInfo {
	running,
	cycling
};
//��� �˻����� �� ���ϱ�
//�������̸�, ���ϸ���Լ���� ������ ��а˻����� �˻��ϴ°� ������
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> courseTotal;
		cin >> people;
		lastPeople = people - 1;
		peopleSpec = vector<vector<double>>(people,vector<double>(2));
		for (int i = 0; i < people; i++) {
			cin >> peopleSpec[i][running];
			cin >> peopleSpec[i][cycling];
		}
		if (maxDiff() == 0) {
			cout << "Impossible" << endl;
		}
		else {
			cout << maxDiff() << endl;
		}
	}
	return 0;
}
//�� ������ �ڽ����� ���ϱ�
double calcTime(double runLen, int people)
{
	double cycleLen = courseTotal - runLen;
	return runLen/peopleSpec[people][running] + cycleLen/peopleSpec[people][cycling];
}
//�޸��� ���̰� ���������� ������ ������ �󸶳� ������ �̱�� �ִ��� ���
double diff(double runLen)
{
	double cheater = calcTime(runLen, lastPeople);
	double others = calcTime(runLen, 0);
	for (int i = 1; i < people - 1; i++) {
		others = min(others, calcTime(runLen, i));
	}
	return others - cheater;
}

double maxDiff()
{
	//���������� ���� ������ �ٲپ� Ǫ�� �������� �ٲ۴�
	double low = 0, high = courseTotal;
	//�̺й��̶� ����ϰ� �����Ѵ�
	for (int i = 0; i < 100; i++) {
		double min3 = (2 * low + high) / 3;
		double max3 = (low + high * 2) / 3;
		//������ �� ���� ���̿� �ְų�, ���϶� �����ΰ�
		if (diff(min3) > diff(max3)) {
			high = max3;
		}
		//������ �� ���� ���̿� �ְų� ������ �����ΰ�
		else {
			low = min3;
		}
	}
	//cheater�� �ð��� �� Ŀ�� ������ ��ȯ�ȴٸ�
	//�̱� ���� ����
	if (diff((low + high) / 2) < 0) {
		return 0;
	}
	return (low + high) / 2;
}
