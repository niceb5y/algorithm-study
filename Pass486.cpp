#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int Limit = 10000000;
//i�� ���� ���� ���μ�
vector<int> minFactor = vector<int>(Limit+1);
//i���� minfactor(i)�� � ����ִ°�
vector<int>minFactorPow = vector<int>(Limit + 1);
//i�� ���� ����� ��
vector<int>Factor = vector<int>(Limit + 1);
void getFactor();
void erathos();
//�����佺�׳׽��� ü�� �̿��� ��� ���ϱ�
int main() {
	erathos();
	getFactor();
	int testcase,factNum,low,high, possible;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> factNum;
		cin >> low;
		cin >> high;
		possible = 0;
		for (int i = low; i <= high; i++) {
			if (Factor[i] == factNum) {
				possible++;
			}
		}
		cout << possible << endl;
	}
	return 0;
}

void getFactor()
{
	Factor[1] = 1;
	for (int i = 2; i <= Limit; i++) {
		//�Ҽ��ǰ�� �����2��
		if (minFactor[i] == i) {
			minFactorPow[i] = 1;
			Factor[i] = 2;
		}
		//�ռ����� ���
		else {
			int minFact = minFactor[i];
			int divided = i / minFact;
			//���̻� �ּҷ� ������ ���� �ʴ´ٸ�
			if (minFactor[divided] != minFact) {
				minFactorPow[i] = 1;
			}
			//���������Ϳ��� �� ������ ���Ѵ�
			else {
				minFactorPow[i] = minFactorPow[divided] + 1;
			}
			int totalFact = minFactorPow[i];
			//����� ���� ���� ���� �Ҽ��� ���� ���ڿ��� �� �Ҽ� �ϳ��� �߰� �ѰͰ� ����
			Factor[i] = (Factor[divided] / totalFact)*(totalFact + 1);
		}
	}
}
//���� ���� ���μ� ���ϱ�
void erathos()
{
	minFactor[0] = minFactor[1] = -1;
	//�ʱ��� ���� �ڱ� �ڽ�
	for(int i = 2; i <= Limit; i++) {
		minFactor[i] = i;
	}
	//��x�� p*q�� ǥ���ɶ� �ݵ�� �ϳ��� x�� ������ �����̴�
	int sqrtn = int(sqrt(Limit));
	for (int i = 2; i <= sqrtn; i++) {
		//������ �ʾҴٸ�
		if (minFactor[i] == i) {
			//�־��� ������ ������� �ּҷ� �־�д�
			for (int j = i * i; j <= Limit; j += i) {
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
}
