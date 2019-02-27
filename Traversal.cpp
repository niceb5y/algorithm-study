#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> slice(const vector<int>& bread, int a, int b);
void printPostOrdered(const vector<int>& preOrder, const vector<int>& inOrder);
//Ʈ���� ������ Ž������
//����: �ڽ�->�ڽļ�
//����: �޳��->�ڽ�->�������
//����:�ڽ�->�ڽ�
int main(){
	int testCase,treeSize;
	vector<int> preOrdered, inOrdered;
	cin >> testCase;
	for (int trial = 0; trial < testCase; trial++) {
		cin >> treeSize;
		preOrdered = vector<int>(treeSize);
		inOrdered = vector<int>(treeSize);
		for (int i = 0; i < treeSize; i++) {
			cin >> preOrdered[i];
		}
		for (int i = 0; i < treeSize; i++) {
			cin >> inOrdered[i];
		}
		printPostOrdered(preOrdered, inOrdered);
		cout << endl;
	}
	return 0;
}

vector<int> slice(const vector<int>& bread, int a, int b)
{
	return vector<int>(bread.begin() + a, bread.begin() + b);
}
//������ ������� ����� �־����� ��������� �Ѵ�
void printPostOrdered(const vector<int>& preOrder, const vector<int>& inOrder)
{
	const int size = preOrder.size();
	if (preOrder.empty()) {
		return;
	}
	//���������� �� ó���� ��Ʈ����̴�
	const int root = preOrder[0];
	const int LeftLen = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
	//��Ʈ��� ũ�⸦ �A��(-1)
	const int RightLen = size - LeftLen - 1;
	//���� ��� Ž��
	printPostOrdered(slice(preOrder, 1, LeftLen + 1), slice(inOrder, 0, LeftLen));
	//������ ��� Ž��
	printPostOrdered(slice(preOrder, LeftLen + 1, size), slice(inOrder, LeftLen + 1, size));
	cout << root << ' ';
}

