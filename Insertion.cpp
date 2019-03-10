#include "pch.h"
#include <iostream>
#include <vector>
typedef int KeyType;
using namespace std;
void solve();
struct Node
{
	//����
	KeyType key;
	//size = �������� ����
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
//��ƮƮ���� key �������� �ɰ���
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
	//Node�� ��Ʈ�� �Ǿ�� �Ҷ�
	//Node�� �������� Ʈ���� �ٽ� �����Ѵ�
	if (root->priority < node->priority) {
		NodePair splited = split(root, node->key);
		node->setLeft(splited.first);
		node->setRight(splited.second);
		return node;
	}
	//Ű���� ���̳���
	else if (node->key < root->key) {
		root->setLeft(insert(root->left, node));
	}
	else {
		root->setRight(insert(root->right, node));
	}
	return root;
}
//�ΰ��� Ʈ�� ��ġ�� a�� �ִ��� b�� �ּڰ����� �������� ����
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
//����ã��
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
//�������� ���� �˻�Ʈ��: Ʈ�� �̿��ϱ�
//Ʈ���� ������ ũ��� ������� priority�� ���� ū ��尡 ��Ʈ�� �ȴ�
//���� �̺��� ū ��尡 ������ �ʴ��̻� ��������� ������� ���� �˻� Ʈ���� ���� ������
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
	//�ϴ� ���ĵǾ��ִ� Ʈ�� ����
	for (int i = 0; i < boardSize; i++) {
		tempBoard = insert(tempBoard, new Node(i + 1));
	}
	//���������� ���������Ұ� ���� �������� ���ĵǹǷ� �̸� �̿��Ѵ�
	for (int i = boardSize - 1; i >= 0; i--) {
		//�� �� �ڿ� ��� ���� �ִ����� �˼��ִ�
		int larger = shiftNum[i];
		//ã�� �������� - �̺��� ū�� = �� ���� ���
		Node* k = kth(tempBoard, i + 1 - larger);
		basicArray[i] = k->key;
		tempBoard = erase(tempBoard, k->key);
	}
}