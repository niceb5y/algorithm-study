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
//유클리드 알고리즘의 변형으로 빠르게 최대공약수 구하기
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
//a 와 b의 최대 공약수는 a-b 와 b의 최대 공약수와 같다
//a-b의 목적은 a를 b로 나눈 나머지를 구하려는데 목적이 있다
int GCD(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return GCD(b, a%b);
}
//a/b와 같거나 큰 정수를 구한다
int NearUp(int a, int b) {
	//올림을 위해 1의 값인 b/b를 더한다
	//a/b자체가 정수일때를 대비해 b-1를 더한다
	return(a + b - 1) / b;
}
void solve() {
	int recipeGCD = recipe[0];
	//제작법의 최대공약수를 구한다
	for (int i = 1; i < materialNum; i++) {
		recipeGCD = GCD(recipe[i], recipeGCD);
	}
	int maxRate = recipeGCD;
	//최대 비율로 들어간 물품을 찾는다
	for (int i = 0; i < materialNum; i++) {
		maxRate = max(maxRate, NearUp(put[i] * recipeGCD, recipe[i]));
	}
	//최대비율만큼 재료를 넣는다
	for (int i = 0; i < materialNum; i++) {
		need[i] = recipe[i] * maxRate / recipeGCD - put[i];
	}
 }