#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
struct RNG
{
	unsigned seed;
	RNG():seed(1983){}
	unsigned next() {
		unsigned result = seed;
		seed = ((seed * 214013u) + 2531011u);
		return result % 10000 + 1;
	}
};
int countRanges(int key, int number);
//���� ���⵵�� ���� ������ Ǯ������ �ڷᱸ�� Ȱ���ϱ�
int main() {
	int testcase,key,total;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> key;
		cin >> total;
		cout << countRanges(key, total) << endl;
	}
	return 0;
}
//������ ������ ��ȯ�Ѵ�
int countRanges(int key, int number)
{
	RNG rng;
	//������ �����Ҷ� ���� ���������� ���� ������ �����ϹǷ� ť�� ����Ѵ�
	queue<int> range;
	int result = 0, rangeSum = 0;
	for (int i = 0; i < number; i++) {
		int tempSignal = rng.next();
		rangeSum += tempSignal;
		range.push(tempSignal);

		//���� �������� key ���� ũ�ٸ�
		while (rangeSum > key)
		{
			//ť�� ��� ������ ���� �׻� key���� �۰� �����ȴ�
			rangeSum -= range.front();
			//������ ����ٸ� ���� ���� ���Ұ� ������
			range.pop();
		}
		if (rangeSum == key) {
			result++;
		}
	}
	return result;
}
