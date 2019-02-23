#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

int matchReverseString(const string& ordinary, const string& reverse);
vector<int>matchString(const string& input);
//KMP�˰���
//���ڿ��� �˻��Ҷ� ����ġ �߻��� ���� �������� ������ ���� �ð��Ҹ� ���δ�
//�κ� ��ġ ���ڿ����� ���λ絵 �ǰ� ���̻絵 �Ǵ� �κ� ���ڿ��� ���̸�ŭ �ǳʶپ �˻��Ѵ�
int main() {
	int testCase;
	cin >> testCase;
	string normal, _reverse;
	for (int trial = 0; trial < testCase; trial++) {
		cin >> normal;
		_reverse = normal;
		reverse(_reverse.begin(), _reverse.end());
		cout << 2*normal.size() - matchReverseString(normal, _reverse) << endl;
	}
	return 0;
}
//KMP�˰����� ���ϴ� ���ڿ��� ����� �����ϸ� ���� ���´�
int matchReverseString(const string & ordinary, const string & reverse)
{
	int ordiSize = ordinary.size(), reveSize = reverse.size();
	//�ΰ��� ������ �ٸ��ٸ� needle���� ���̺��� �������� �Ѵ�.
	vector<int> prefix = matchString(reverse);
	int space = 0, matched = 0;
	while (space < ordiSize)
	{
		//���ĭ�� ���ڰ� ���ٸ�
		if (matched < reveSize && ordinary[space + matched] == reverse[matched]) {
			matched++;
			//��� ���簡 �Ϸ�Ǿ��ٸ�
			if (space + matched == ordiSize) {
				return matched;
			}
		}
		else {
			//�ϳ��� ��ġ ���Ѵٸ�
			if (matched == 0) {
				space++;
			}
			else {
				space += matched - prefix[matched - 1];
				matched = prefix[matched - 1];
			}
		}
	}
	return 0;
}

//���ڿ��� �κ���ġ ���̺� ����
vector<int> matchString(const string & input)
{
	int inputSize = input.size();
	vector<int> result(inputSize, 0);
	int space = 1, matched = 0;
	//�������� ��ġ�κ��� ���� ����������
	//�ְ����� ���� ���ķκ��ʹ� �������� �ִ밪�� �ɼ� �����Ƿ� ������ space�� �����ص� �ȴ�
	//��� �κб��̸� 1���� ����Ѵ� �׷��Ƿ� �����ص� ��� ���°�
	while (space + matched < inputSize)
	{
		//���� ��ġ��
		if (input.at(space + matched) == input.at(matched)) {
			//�� ��ġ�ϳ� �����Ѵ�
			matched++;
			//�ش� ��ġ�κ��� ���̸� ����
			result[space + matched - 1] = matched;
		}
		//����ġ��
		//KMP�˰���
		else {
			//���ڰ� �ϳ��� ��ġ ���� �ʾҴٸ�
			if (matched == 0) {
				//��ĭ �������� ����
				space++;
			}
			//��� ��ġ �� ����ġ�� ���Դٸ�
			else {
				//���λ� = ���̻��̹Ƿ� �� ��ġ�ϴ� ������ �����ϴºκк��� �����Ѵ�
				space += matched - result[matched - 1];
				//���̻籸������ �����Ƿ� �� �������� Ž���ϸ� �ȴ�
				matched = result[matched - 1];
			}
		}
	}
	return result;
}