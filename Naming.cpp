#include "pch.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<int>matchString(const string& input);
//KMP�˰���
//���ڿ��� �˻��Ҷ� ����ġ �߻��� ���� �������� ������ ���� �ð��Ҹ� ���δ�
//�κ� ��ġ ���ڿ����� ���λ絵 �ǰ� ���̻絵 �Ǵ� �κ� ���ڿ��� ���̸�ŭ �ǳʶپ �˻��Ѵ�
int main() {
	string Neddle1, Needle2;
		cin >> Neddle1;
		cin >> Needle2;
		string Neddle = Neddle1 + Needle2;
		vector<int> result, table = matchString(Neddle);
		int size = Neddle.size();
		while (size > 0)
		{
			//�ϴ� �ڱ� �ڽ��� �ִ´�
			result.push_back(size);
			//���� �� ���̻��� ���� �� ���̻縦 ã�� ��������
			size = table[size - 1];
		}
		for (int i = result.size() - 1; i >= 0; i--) {
			cout << result[i] << " ";
		}
		cout << endl;
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
