#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int testcase = 1000000001;
int genLength[51];
string xExpand = "X+YF";
string yExpand = "FX-Y";
string zeroGen = "FX";
int inputGen, inputIndex, inputLen;
//�ظ� ���� ���ؾ� �ϴ� ���� ��ȹ��
//k��° ���� �����س��� �Ѵ�
char generate(int skip, string& curve, int needgen);
int main() {
	//n������ �巡��Ŀ�� ���̸� ���س��´�
	genLength[0] = 1;
	for (int i = 1; i <= 50; i++) {
		genLength[i] = min(testcase, 2 * genLength[i - 1] + 2);
	}
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> inputGen;
		cin >> inputIndex;
		cin >> inputLen;
		for (int i = 0; i < inputLen; i++) {
			cout << generate(inputIndex + i-1, zeroGen, inputGen);
		}
		cout << endl;
	}
	return 0;
}

char generate(int skip, string & curve, int needgen)
{
	//�������: Ȯ���� ���밡 �������� ã�� ��ġ�� ���� ��ȯ
	if (needgen == 0) {
		if (skip > curve.size()) {
			return '#';
		}
		return curve[skip];
	}
	//i��° ���ڸ� ��� Ȯ���Ű�� ���
	for (int i = 0; i < curve.size(); i++) {
		if (curve[i] == 'X' || curve[i] == 'Y') {
			//�ش繮�ڸ� ������ Ȯ����ѵ� �� �ڿ������� ���ڸ� Ȯ���Ű����ġ�� ���� �����Ұ��
			if (skip >= genLength[needgen]) {
				skip -= genLength[needgen];
			}
			//X�� �������� ��� Ȯ���Ų��
			else if (curve[i] == 'X') {
				return generate(skip, xExpand, needgen - 1);
			}
			//Y�� �������� ��� Ȯ���Ų��
			else {
				return generate(skip, yExpand, needgen - 1);
			}
		}
		//F,+,-���� ���ڴ� �ǳʶڴ�
		else if (skip > 0) {
			skip--;
		}
		//skip�� 0�Ͻ�
		else {
			return curve[i];
		}
	}
	//����Ǹ� �ȵǴ� �ڵ�
	return '#';
}
