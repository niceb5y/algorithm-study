#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Limit = 20091101;
int boxNum, childNum;
vector<int> boxItem;
vector<int> subSum;
vector<int> modSum;
int singleBuy();
int variousBuy();
//부분합 배열을 생성하여 풀기
//이때 부분합은 0부터i까지 합이다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boxNum;
		cin >> childNum;
		boxItem = vector<int>(boxNum);
		subSum = vector<int>(boxNum + 1);
		modSum = vector<int>(boxNum + 1);
		subSum[0] = 0;
		modSum[0] = 0;
		for (int i = 0; i < boxNum; i++) {
			cin >> boxItem[i];
			subSum[i + 1] = subSum[i] + boxItem[i];
			modSum[i + 1] = subSum[i + 1] % childNum;
		}
		cout << singleBuy() << " " << variousBuy() << endl;
	}
	return 0;
}
//i부터 j까지 구매할때 이 구간의 합의 나머지는 0이므로
//i의 부분합과 j의 부분합을 어린이수로 나눌때 나머지가 같다면
//두 구간 사이를 계산하는 과정에서 나머지가 사라지고 어린이수와 같게 된다
//결국 구간이 같은 부분합 원소를 두개씩 짝지으면 된다
int singleBuy()
{
	vector<long long>count(childNum, 0);
	int result = 0;
	for (int i = 0; i < boxNum + 1; i++) {
		count[modSum[i]]++;
	}
	for (int i = 0; i < childNum; i++) {
		if (count[i] >= 2) {
			result = (result + (count[i] * (count[i] - 1) / 2)) % Limit;
		}
	}
	return result;
}
//동적 계획법을 이용한다.
//0-i 까지 목록중 i-j까지 구입한 후 0-j까지를 계산한다
//이때 i를 넣을수도 안넣을수도 있다
int variousBuy()
{
	vector<int> result (boxNum + 1, 0);
	//캐시에는 
	vector<int> cache(childNum, -1);
	for (int i = 0; i < boxNum + 1; i++) {
		if (i > 0) {
			//i번째 상자를 넣지 않는다
			result[i] = result[i - 1];
		}
		else {
			result[i] = 0;
		}
		int temp = cache[modSum[i]];
		if (temp != -1) {
			result[i] = max(result[i], result[temp] + 1);
		}
		//캐시에는 자동적으로 같은 나머지를 가진 원소의 위치가 저장된다
		cache[modSum[i]] = i;
	}
	return result.back();
}
