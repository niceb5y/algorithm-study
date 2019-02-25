#include "pch.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<int> KMPSearch(const string& Hay, const string& Needle);
vector<int>matchString(const string& input);
int needShift(const string& now, const string& todo);
//KMP�˰���
//���ڿ��� �˻��Ҷ� ����ġ �߻��� ���� �������� ������ ���� �ð��Ҹ� ���δ�
//�κ� ��ġ ���ڿ����� ���λ絵 �ǰ� ���̻絵 �Ǵ� �κ� ���ڿ��� ���̸�ŭ �ǳʶپ �˻��Ѵ�
int main() {
	int testCase,dialCase;
	string temp, target;
	cin >> testCase;
	for (int trial = 0; trial < testCase; trial++) {
		int minShift = 0;
		cin >> dialCase;
		cin >> temp;
		for (int i = 0; i < dialCase; i++) {
			cin >> target;
			if (i % 2 == 0) {
				minShift += needShift(target, temp);
			}
			else {
				minShift += needShift(temp, target);
			}
			temp = target;
		}
		cout << minShift << endl;
	}
	return 0;
}
//�������� KMP �˰���
vector<int> KMPSearch(const string & Hay, const string & Needle)
{
	int hayLen = Hay.size(), needLen = Needle.size();
	vector<int> result;
	vector<int> needleTable = matchString(Needle);
	int matched = 0;
	//i�� space ��Ȱ�� �Ѵ�
	for (int i = 0; i < hayLen; i++) {
		//��ġ�ϴٰ� ��߳����
		//Hay�� �������� �̵���Ŵ���ν� Needle�� ��ĭ �̵���Ű�°ſ� ����� ȿ���� ����
		while (matched > 0 && Hay.at(i) != Needle.at(matched)) {
			//���������� ���λ� = ���̻��� �� ������ ���̻��� ������������ �̵��Ѵ�
			matched = needleTable[matched - 1];
		}
		if (Hay.at(i) == Needle.at(matched)) {
			matched++;
			//��ġ���� ã������
			if (matched == needLen) {
				//��ġ�� ����ִ´�
				result.push_back(i - matched + 1);
				//���� ��ġ�κ��� ã�ƺ���
				matched = needleTable[matched - 1];
			}
		}
	}
	return result;
}

int needShift(const string & now, const string & todo)
{
	vector<int> temp = KMPSearch(now + now, todo);
	if (temp.size() < 1) {
		return now.size();
	}
	return temp[0];
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