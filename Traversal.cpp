#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> slice(const vector<int>& bread, int a, int b);
void printPostOrdered(const vector<int>& preOrder, const vector<int>& inOrder);
//트리의 세가지 탐색순서
//전위: 자신->자식순
//중위: 왼노드->자신->오른노드
//후위:자식->자신
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
//전위와 중위출력 결과가 주어질때 후위출력은 한다
void printPostOrdered(const vector<int>& preOrder, const vector<int>& inOrder)
{
	const int size = preOrder.size();
	if (preOrder.empty()) {
		return;
	}
	//전위정렬의 맨 처음은 루트노드이다
	const int root = preOrder[0];
	const int LeftLen = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
	//루트노드 크기를 뺸다(-1)
	const int RightLen = size - LeftLen - 1;
	//왼쪽 노드 탐색
	printPostOrdered(slice(preOrder, 1, LeftLen + 1), slice(inOrder, 0, LeftLen));
	//오른쪽 노드 탐색
	printPostOrdered(slice(preOrder, LeftLen + 1, size), slice(inOrder, LeftLen + 1, size));
	cout << root << ' ';
}

