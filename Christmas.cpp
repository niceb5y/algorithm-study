#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Limit = 20091101;
int boxNum, childNum;
vector<int> boxItem;
vector<int> subSum;
vector<int> modSum;
int singleBuy();
int variousBuy();
//�κ��� �迭�� �����Ͽ� Ǯ��
//�̶� �κ����� 0����i���� ���̴�
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boxNum;
		cin >> childNum;
		boxItem = vector<int>(boxNum);
		subSum = vector<int>(boxNum + 1);
		modSum = vector<int>(boxNum + 1);
		subSum[0] = 0;
		modSum[0] = 0;
		for (int i = 0; i < boxNum; i++) {
			cin >> boxItem[i];
			subSum[i + 1] = subSum[i] + boxItem[i];
			modSum[i + 1] = subSum[i + 1] % childNum;
		}
		cout << singleBuy() << " " << variousBuy() << endl;
	}
	return 0;
}
//i���� j���� �����Ҷ� �� ������ ���� �������� 0�̹Ƿ�
//i�� �κ��հ� j�� �κ����� ��̼��� ������ �������� ���ٸ�
//�� ���� ���̸� ����ϴ� �������� �������� ������� ��̼��� ���� �ȴ�
//�ᱹ ������ ���� �κ��� ���Ҹ� �ΰ��� ¦������ �ȴ�
int singleBuy()
{
	vector<long long>count(childNum, 0);
	int result = 0;
	for (int i = 0; i < boxNum + 1; i++) {
		count[modSum[i]]++;
	}
	for (int i = 0; i < childNum; i++) {
		if (count[i] >= 2) {
			result = (result + (count[i] * (count[i] - 1) / 2)) % Limit;
		}
	}
	return result;
}
//���� ��ȹ���� �̿��Ѵ�.
//0-i ���� ����� i-j���� ������ �� 0-j������ ����Ѵ�
//�̶� i�� �������� �ȳ������� �ִ�
int variousBuy()
{
	vector<int> result (boxNum + 1, 0);
	//ĳ�ÿ��� 
	vector<int> cache(childNum, -1);
	for (int i = 0; i < boxNum + 1; i++) {
		if (i > 0) {
			//i��° ���ڸ� ���� �ʴ´�
			result[i] = result[i - 1];
		}
		else {
			result[i] = 0;
		}
		int temp = cache[modSum[i]];
		if (temp != -1) {
			result[i] = max(result[i], result[temp] + 1);
		}
		//ĳ�ÿ��� �ڵ������� ���� �������� ���� ������ ��ġ�� ����ȴ�
		cache[modSum[i]] = i;
	}
	return result.back();
}
