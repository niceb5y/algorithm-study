#include "pch.h"
#include <iostream>
#include <vector>
typedef int KeyType;
using namespace std;
void solve();
struct Node
{
	//원소
	KeyType key;
	//size = 서브노드의 갯수
	int priority, size;
	Node *left, *right;
	Node(const KeyType &_key):key(_key),priority(rand()),size(1),left(NULL),right(NULL) {}
	void setLeft(Node *newLeft) {
		left = newLeft;
		calcSize();
	}
	void setRight(Node *newRight) {
		right = newRight;
		calcSize();
	}
	void calcSize() {
		size = 1;
		if (left) {
			size += left->size;
		}
		if (right) {
			size += right->size;
		}
	}
};
typedef pair<Node*, Node*> NodePair;
//루트트리를 key 기준으로 쪼갠다
NodePair split(Node* root, KeyType key) {
	if (root == NULL) {
		return NodePair(NULL, NULL);
	}

	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	else {
		NodePair ls = split(root->left, key);
		root->setLeft(ls.second);
		return NodePair(ls.first, root);
	}
}
Node* insert(Node* root, Node* node) {
	if (root == NULL) {
		return node;
	}
	//Node가 루트가 되어야 할때
	//Node를 기준으로 트리를 다시 생성한다
	if (root->priority < node->priority) {
		NodePair splited = split(root, node->key);
		node->setLeft(splited.first);
		node->setRight(splited.second);
		return node;
	}
	//키값이 차이날때
	else if (node->key < root->key) {
		root->setLeft(insert(root->left, node));
	}
	else {
		root->setRight(insert(root->right, node));
	}
	return root;
}
//두개의 트립 합치기 a의 최댓값이 b의 최솟값보다 작을때를 상정
Node* merge(Node* a, Node* b) {
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}
Node* erase(Node* root, KeyType key) {
	if (root == NULL) {
		return root;
	}
	if (root->key == key) {
		Node* result = merge(root->left, root->right);
		delete root;
		return result;
	}
	if (key < root->key) {
		root->setLeft(erase(root->left, key));
	}
	else {
		root->setRight(erase(root->right, key));
	}
	return root;
}
//원소찾기
Node* kth(Node* root, int k) {
	int leftside = 0;
	if (root->left != NULL) {
		leftside = root->left->size;
	}
	if (k <= leftside) {
		return kth(root->left, k);
	}
	if (k == leftside + 1) {
		return root;
	}
	return kth(root->right, k - leftside - 1);
}

int boardSize;
vector<int> shiftNum, basicArray;
//균형잡힌 이진 검색트리: 트립 이용하기
//트립은 원소의 크기와 상관없이 priority가 제일 큰 노드가 루트가 된다
//만약 이보다 큰 노드가 들어오지 않는이상 서브노드들은 통상적인 이진 검색 트리의 룰을 따른다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		shiftNum = vector<int>(boardSize);
		basicArray = vector<int>(boardSize, -1);
		for (int i = 0; i < boardSize; i++) {
			cin >> shiftNum[i];
		}
		solve();
		for (int i = 0; i < boardSize; i++) {
			cout << basicArray[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

void solve() {
	Node* tempBoard = NULL;
	//일단 정렬되어있는 트리 구현
	for (int i = 0; i < boardSize; i++) {
		tempBoard = insert(tempBoard, new Node(i + 1));
	}
	//삽입졍렬은 마지막원소가 제일 마지막에 정렬되므로 이를 이용한다
	for (int i = boardSize - 1; i >= 0; i--) {
		//이 수 뒤에 몇개의 수가 있는지를 알수있다
		int larger = shiftNum[i];
		//찾지 않은수들 - 이보다 큰수 = 이 수의 노드
		Node* k = kth(tempBoard, i + 1 - larger);
		basicArray[i] = k->key;
		tempBoard = erase(tempBoard, k->key);
	}
}