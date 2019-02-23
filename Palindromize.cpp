#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

int matchReverseString(const string& ordinary, const string& reverse);
vector<int>matchString(const string& input);
//KMP알고리즘
//문자열을 검색할때 불일치 발생시 다음 시작점을 빠르게 구해 시간소모를 줄인다
//부분 일치 문자열에서 접두사도 되고 접미사도 되는 부분 문자열의 길이만큼 건너뛰어서 검색한다
int main() {
	int testCase;
	cin >> testCase;
	string normal, _reverse;
	for (int trial = 0; trial < testCase; trial++) {
		cin >> normal;
		_reverse = normal;
		reverse(_reverse.begin(), _reverse.end());
		cout << 2*normal.size() - matchReverseString(normal, _reverse) << endl;
	}
	return 0;
}
//KMP알고리즘을 비교하는 문자열을 뒤집어서 조사하면 답이 나온다
int matchReverseString(const string & ordinary, const string & reverse)
{
	int ordiSize = ordinary.size(), reveSize = reverse.size();
	//두개의 내용이 다르다면 needle쪽의 테이블을 기준으로 한다.
	vector<int> prefix = matchString(reverse);
	int space = 0, matched = 0;
	while (space < ordiSize)
	{
		//헤당칸의 글자가 같다면
		if (matched < reveSize && ordinary[space + matched] == reverse[matched]) {
			matched++;
			//모든 조사가 완료되었다면
			if (space + matched == ordiSize) {
				return matched;
			}
		}
		else {
			//하나도 일치 안한다면
			if (matched == 0) {
				space++;
			}
			else {
				space += matched - prefix[matched - 1];
				matched = prefix[matched - 1];
			}
		}
	}
	return 0;
}

//문자열의 부분일치 테이블 생성
vector<int> matchString(const string & input)
{
	int inputSize = input.size();
	vector<int> result(inputSize, 0);
	int space = 1, matched = 0;
	//시작점과 일치부분의 합이 끝날때까지
	//최고점을 찍은 이후로부터는 나머지는 최대값이 될수 없으므로 나머지 space는 무시해도 된다
	//모든 부분길이를 1번에 계산한다 그러므로 무시해도 상관 없는것
	while (space + matched < inputSize)
	{
		//글자 일치시
		if (input.at(space + matched) == input.at(matched)) {
			//더 일치하나 조사한다
			matched++;
			//해당 일치부분의 길이를 대입
			result[space + matched - 1] = matched;
		}
		//불일치시
		//KMP알고리즘
		else {
			//글자가 하나도 일치 하지 않았다면
			if (matched == 0) {
				//한칸 다음부터 조사
				space++;
			}
			//몇개의 일치 후 불일치가 나왔다면
			else {
				//접두사 = 접미사이므로 그 일치하는 구간이 시작하는부분부터 시작한다
				space += matched - result[matched - 1];
				//접미사구간까지 같으므로 그 다음부터 탐색하면 된다
				matched = result[matched - 1];
			}
		}
	}
	return result;
}