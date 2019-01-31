#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int budget,sushiTypes;
vector<int> cache;
vector<int> price;
vector<int> satisfy;

int helpYourself();
//재귀법을 이용하지 않는 동적 계획법
//반복문에 의한 동적계획법으로 반복적 동적계획법이라 한다
//메모리를 줄일수있는 슬라이드 윈도 기법적용 가능
//콜백이 줄어들어 조금 빠르다
//단 직관적이지 않고 호출의 순서를 고려해야한다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> sushiTypes;
		cin >> budget;
		//슬라이드 윈도 기법
		//초밥의 최대가격은 20000이므로 그 이후의 범위는 고려할 필요가 없다
		//필요한 부분만 그때그때 캐싱하는 기법
		//초밥은 전부 100원 단위이므로 100미만은 나누어서 캐싱한다
		cache = vector<int>(201,-1);
		price = vector<int>(sushiTypes);
		satisfy = vector<int>(sushiTypes);
		for (int i = 0; i < sushiTypes; i++) {
			cin >> price[i];
			cin >> satisfy[i];
		}
		for (int i = 0; i < sushiTypes; i++) {
			price[i] = price[i] / 100;
		}
		budget = budget / 100;
		cout << helpYourself() << endl;
	}
	return 0;
}

int helpYourself()
{
	int memo = 0;
	cache[0] = 0;
	//모든 경우의 수 탐색
	for (int cash = 1; cash <= budget; cash++) {
		int possible = 0;
		//현재 cash로 구입할수있는 모든 초밥 탐색
		for (int sushi = 0; sushi < sushiTypes; sushi++) {
			//살수있다면
			if (cash >= price[sushi]) {
				//슬라이드 윈도 기법
				possible = max(possible, cache[(cash - price[sushi])%201] + satisfy[sushi]);
			}
		}
		//현재 가격에서 최상의 방법으로 초밥을 먹는방법 저장
		cache[cash % 201] = possible;
		//모든 가격 최상의 방법 저장
		memo = max(memo, possible);
	}
	return memo;
}
