#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string Base;
vector<vector<bool>> isPalendrome;
vector<int> minDevide;
int madeDevide(int start);
int main() {
	cin >> Base;
	isPalendrome = vector<vector<bool>>(Base.length(),vector<bool>(Base.length(),false));
	for (int wordLen = 1; wordLen <= Base.length(); wordLen++) {
		for (int i = 0; i < Base.length(); i++) {
			//�̹� ���� �ʰ���
			if (i + wordLen - 1 >= Base.length()) {
				break;
			}
			// 1���� �����Ͻ� �Ӹ����
			if (wordLen == 1) {
				isPalendrome[i][i+wordLen-1] = true;
			}
			//2���� �����̸� �¿찡 ��Ī�� �Ӹ����
			else if (wordLen == 2 && Base.at(i) == Base.at(i+wordLen-1)) {
				isPalendrome[i][wordLen + i -1] = true;
			}
			//3�� �̻��� �����̸� �¿찡 ���� �Ѵܰ� ���� �Ӹ�����̶�� �Ӹ����
			else if (Base.at(i) == Base.at(i+wordLen-1) && isPalendrome[i+1][i+wordLen-2]) {
				isPalendrome[i][i+wordLen-1] = true;
			}
		}
	}
	minDevide = vector<int>(Base.length(), Base.length()+1);
	cout << madeDevide(0) << endl;
	return 0;
}

int madeDevide(int start)
{
	//������� ���� ���� �ʰ���� ����
	if (start >= Base.length()) {
		return 0;
	}
	if (minDevide[start] != Base.length() + 1) {
		return minDevide[start];
	}
	for (int i = start; i < Base.length(); i++) {
		//�ش� �ε������� �Ӹ�����̶��
		if (isPalendrome[start][i]) {
			//�������� �Ӹ���� �غ���
			minDevide[start] = min(minDevide[start], madeDevide(i + 1) + 1);
		}
	}
	return minDevide[start];
}
