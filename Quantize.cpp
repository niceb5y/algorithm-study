#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> board;
vector<vector<int>> cache;
int parts;
int quantize(int start, int parts);
int minError(int start, int num);
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
int main() {
	int testcase, boardSize;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> boardSize;
		board = vector<int>(boardSize);
		cin >> parts;
		cache = vector<vector<int>>(boardSize, vector<int>(parts+1, -1));
		for (int i = 0; i < boardSize; i++) {
			cin >> board[i];
		}
		//양자화된 A 보다 큰 B는 A의 양자화값보다 작을수 없다
		//양자화할 샘플이 n 개라면 결국 정렬된 집합을 n개로 나누는거랑 같다
		sort(board.begin(), board.end());
		cout << quantize(0, parts) << endl;
	}
	return 0;
}
//양자화: 카메라의 샘플링 비슷한것 오차를 최소화하라
//
int quantize(int start, int needParts)
{
	//배열의 끝까지 도달할시
	if (start == board.size()) {
		return 0;
	}
	//배열의 끝에 도달하지 않았으나 나눌 파트가 남았을때
	//잘못 분배한게 확실하므로 매우 큰 값 리턴
	if (needParts == 0) {
		//역시 결과값이 다른 값이랑 더해져 오버플로가 일어날수 있다
		//적당히 큰 값을 설정하자
		return 99999999;
	}
	//메모이제이션
	int& memo = cache[start][needParts];
	if (memo != -1) {
		return memo;
	}
	memo = 99999999;
	//첫 조각을 떼어내고 난 나머지 배열을 나머지 조각으로 나눈다
	//기저조건에 따라 for의 조건식도 바꿔야 한다
	//순수 크기를 제한했으므로 순수크기까지 통과 시켜야한다
	for (int jump = 1; start + jump <= board.size(); jump++) {
		memo = min(memo, quantize(start + jump, needParts - 1) + minError(start, jump));
	}
	return memo;
}
//최소 오차 구하기
int minError(int start, int num)
{
	int avarage = 0,result = 0;
	for (int i = 0; i < num; i++) {
		avarage += board[start + i];
	}
	//산술평균을 적용한다
	avarage = (int)(((double)avarage / num) + 0.5);
	//명세에따라 오차값 각각의 제곱을 더한다
	for (int i = 0; i < num; i++) {
		result += pow(avarage - board[start + i],2);
	}
	return result;
}
