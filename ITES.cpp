#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
struct RNG
{
	unsigned seed;
	RNG():seed(1983){}
	unsigned next() {
		unsigned result = seed;
		seed = ((seed * 214013u) + 2531011u);
		return result % 10000 + 1;
	}
};
int countRanges(int key, int number);
//공간 복잡도가 높은 문제를 풀기위한 자료구조 활용하기
int main() {
	int testcase,key,total;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> key;
		cin >> total;
		cout << countRanges(key, total) << endl;
	}
	return 0;
}
//구간의 갯수를 반환한다
int countRanges(int key, int number)
{
	RNG rng;
	//구간을 조사할때 선입 선출방식으로 지정 구간만 저장하므로 큐를 사용한다
	queue<int> range;
	int result = 0, rangeSum = 0;
	for (int i = 0; i < number; i++) {
		int tempSignal = rng.next();
		rangeSum += tempSignal;
		range.push(tempSignal);

		//만약 구간합이 key 보다 크다면
		while (rangeSum > key)
		{
			//큐의 모든 원소의 합은 항상 key보다 작게 설정된다
			rangeSum -= range.front();
			//범위를 벗어난다면 먼저 들어온 원소가 나간다
			range.pop();
		}
		if (rangeSum == key) {
			result++;
		}
	}
	return result;
}
