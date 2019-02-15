#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int materialNum;
vector<int> recipe;
vector<int> put;
vector<int> need;

int GCD(int a, int b);
void solve();
//��Ŭ���� �˰����� �������� ������ �ִ����� ���ϱ�
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> materialNum;
		recipe = vector<int>(materialNum);
		put = vector<int>(materialNum);
		need = vector<int>(materialNum, 0);
		for (int i = 0; i < materialNum; i++) {
			cin >> recipe[i];
		}
		for (int i = 0; i < materialNum; i++) {
			cin >> put[i];
		}
		solve();
		for (int i = 0; i < materialNum; i++) {
			cout << need[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
//a �� b�� �ִ� ������� a-b �� b�� �ִ� ������� ����
//a-b�� ������ a�� b�� ���� �������� ���Ϸ��µ� ������ �ִ�
int GCD(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return GCD(b, a%b);
}
//a/b�� ���ų� ū ������ ���Ѵ�
int NearUp(int a, int b) {
	//�ø��� ���� 1�� ���� b/b�� ���Ѵ�
	//a/b��ü�� �����϶��� ����� b-1�� ���Ѵ�
	return(a + b - 1) / b;
}
void solve() {
	int recipeGCD = recipe[0];
	//���۹��� �ִ������� ���Ѵ�
	for (int i = 1; i < materialNum; i++) {
		recipeGCD = GCD(recipe[i], recipeGCD);
	}
	int maxRate = recipeGCD;
	//�ִ� ������ �� ��ǰ�� ã�´�
	for (int i = 0; i < materialNum; i++) {
		maxRate = max(maxRate, NearUp(put[i] * recipeGCD, recipe[i]));
	}
	//�ִ������ŭ ��Ḧ �ִ´�
	for (int i = 0; i < materialNum; i++) {
		need[i] = recipe[i] * maxRate / recipeGCD - put[i];
	}
 }