#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int Limit = 10000000;
//i의 가장 작은 소인수
vector<int> minFactor = vector<int>(Limit+1);
//i에는 minfactor(i)가 몇개 들어있는가
vector<int>minFactorPow = vector<int>(Limit + 1);
//i가 가진 약수의 수
vector<int>Factor = vector<int>(Limit + 1);
void getFactor();
void erathos();
//에라토스테네스의 체를 이용한 약수 구하기
int main() {
	erathos();
	getFactor();
	int testcase,factNum,low,high, possible;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> factNum;
		cin >> low;
		cin >> high;
		possible = 0;
		for (int i = low; i <= high; i++) {
			if (Factor[i] == factNum) {
				possible++;
			}
		}
		cout << possible << endl;
	}
	return 0;
}

void getFactor()
{
	Factor[1] = 1;
	for (int i = 2; i <= Limit; i++) {
		//소수의경우 약수는2개
		if (minFactor[i] == i) {
			minFactorPow[i] = 1;
			Factor[i] = 2;
		}
		//합성수의 경우
		else {
			int minFact = minFactor[i];
			int divided = i / minFact;
			//더이상 최소로 나누어 지지 않는다면
			if (minFactor[divided] != minFact) {
				minFactorPow[i] = 1;
			}
			//나누어진것에서 그 갯수를 더한다
			else {
				minFactorPow[i] = minFactorPow[divided] + 1;
			}
			int totalFact = minFactorPow[i];
			//약수의 수는 제일 작은 소수로 나눈 숫자에서 이 소수 하나를 추가 한것과 같다
			Factor[i] = (Factor[divided] / totalFact)*(totalFact + 1);
		}
	}
}
//제일 작은 소인수 구하기
void erathos()
{
	minFactor[0] = minFactor[1] = -1;
	//초기의 값은 자기 자신
	for(int i = 2; i <= Limit; i++) {
		minFactor[i] = i;
	}
	//수x가 p*q로 표현될때 반드시 하나는 x의 제곱근 이하이다
	int sqrtn = int(sqrt(Limit));
	for (int i = 2; i <= sqrtn; i++) {
		//구하지 않았다면
		if (minFactor[i] == i) {
			//주어진 숫자의 배수들을 최소로 넣어둔다
			for (int j = i * i; j <= Limit; j += i) {
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
}
