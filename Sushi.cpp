#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int budget,sushiTypes;
vector<int> cache;
vector<int> price;
vector<int> satisfy;

int helpYourself();
//��͹��� �̿����� �ʴ� ���� ��ȹ��
//�ݺ����� ���� ������ȹ������ �ݺ��� ������ȹ���̶� �Ѵ�
//�޸𸮸� ���ϼ��ִ� �����̵� ���� ������� ����
//�ݹ��� �پ��� ���� ������
//�� ���������� �ʰ� ȣ���� ������ ����ؾ��Ѵ�
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> sushiTypes;
		cin >> budget;
		//�����̵� ���� ���
		//�ʹ��� �ִ밡���� 20000�̹Ƿ� �� ������ ������ ����� �ʿ䰡 ����
		//�ʿ��� �κи� �׶��׶� ĳ���ϴ� ���
		//�ʹ��� ���� 100�� �����̹Ƿ� 100�̸��� ����� ĳ���Ѵ�
		cache = vector<int>(201,-1);
		price = vector<int>(sushiTypes);
		satisfy = vector<int>(sushiTypes);
		for (int i = 0; i < sushiTypes; i++) {
			cin >> price[i];
			cin >> satisfy[i];
		}
		for (int i = 0; i < sushiTypes; i++) {
			price[i] = price[i] / 100;
		}
		budget = budget / 100;
		cout << helpYourself() << endl;
	}
	return 0;
}

int helpYourself()
{
	int memo = 0;
	cache[0] = 0;
	//��� ����� �� Ž��
	for (int cash = 1; cash <= budget; cash++) {
		int possible = 0;
		//���� cash�� �����Ҽ��ִ� ��� �ʹ� Ž��
		for (int sushi = 0; sushi < sushiTypes; sushi++) {
			//����ִٸ�
			if (cash >= price[sushi]) {
				//�����̵� ���� ���
				possible = max(possible, cache[(cash - price[sushi])%201] + satisfy[sushi]);
			}
		}
		//���� ���ݿ��� �ֻ��� ������� �ʹ��� �Դ¹�� ����
		cache[cash % 201] = possible;
		//��� ���� �ֻ��� ��� ����
		memo = max(memo, possible);
	}
	return memo;
}
