#include "pch.h"
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;

//접미사 배열을 생성하는 맨버-바이어스 알고리즘
//aaaaa....x같은 문자열일경우 일일히 비교하면 시간이 오래걸린다
//1번째 까지의 문자 2번째까지 문자 4번째 까지 문자만을 고려해 비교후 그룹지어서 정렬한다
//group의 정보는 어짜피 다 동일 문자열에서 나오기 때문에 2배로 start를 건너뛰어도 무방하다
struct Comparator
{
	//start번째 기준으로 정렬되고난 그룹이 주어졌을때
	//start*2번째를 기준으로 대소판정한다
	const vector<int>& group;
	int start;
	Comparator(const vector<int>& _group, int _start):group(_group),start(_start){
		//group = _group;
		//start = _start;
	}
	//비교할 두 위치를 입력
	bool operator ()(int a, int b) {
		if (group[a] != group[b]) {
			return group[a] < group[b];
		}
		//문자가 같으면 start번 후의 숫자를 본다
		return group[a + start] < group[b + start];
	}

};
vector<int> getSuffixArray(const string& input);
int commonPrefix(const string& input, int i, int j);
int longestHabit(const string& input, int time);
//접미사 배열
//부분 문자 계산시 유용하다
int main() {
	int testcase, targetTime;
	cin >> testcase;
	string whatHeTalk;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> targetTime;
		cin >> whatHeTalk;
		cout << longestHabit(whatHeTalk,targetTime) << endl;
	}
	return 0;
}
//접미사 배열을 생성할시
//접미사들을 사전순으로 배열해서 저장한다
//그 이후 접미사의 시작 위치만을 배열에 저장하면 공간효율이 좋아진다
vector<int> getSuffixArray(const string & input)
{
	int n = input.size();
	//멤버-바이어스 알고리즘 이용
	//첫번째 문자부터 비교
	int start = 1;
	//동일 문자들이 들어갈 그룹
	vector<int> group(n + 1);
	for (int i = 0; i < n; i++) {
		//일단 각 그룹의 기준을 문자열과 그대로 한다
		group[i] = input[i];
	}
	group[n] = -1;
	vector<int> result(n);
	for (int i = 0; i < n; i++) {
		result[i] = i;
	}
	//마지막번째까지 모든 비교가 끝날때까지
	while (start < n)
	{
		Comparator compare2T(group, start);
		//일단 맨처음글자순으로 정렬된다
		sort(result.begin(), result.end(), compare2T);
		//여기서 그룹의 범위 벗어남이 걸러진다
		start *= 2;
		if (start >= n) {
			break;
		}
		//정렬이 덜됐다면 새로운 그룹 생성
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		//본격적으로 그룹을 짓는다
		newGroup[result[0]] = 0;
		for (int i = 1; i < n; i++) {
			//저번글자와 다르다면
			if (compare2T(result[i - 1], result[i])) {
				newGroup[result[i]] = newGroup[result[i - 1]] + 1;
			}
			else {
				newGroup[result[i]] = newGroup[result[i - 1]];
			}
		}
		group = newGroup;
	}
	return result;
}
//문자열의 부분문자열의 수를 구하기 위해서는 접미사 배열이 필요하다
//접미사마다 하나씩 글자를 끊어서 세면 그 길이 = 부분문자열 갯수이다
//그러나 중복을 피하기위해 사전순으로 정렬된 배열에서 윗부분과 공통된 부분을 빼면 된다

int commonPrefix(const string & input, int i, int j)
{
	int result = 0;
	while (i<input.size()&&j<input.size()&&input.at(i)==input.at(j))
	{
		i++;
		j++;
		result++;
	}
	return result;
}

int longestHabit(const string & input, int time)
{
	//접미사 배열 생성
	vector<int> table = getSuffixArray(input);
	int result = 0;
	for (int i = 0; i + time <= input.size(); i++) {
		//time번 이상 등장해야 하는 단어이기에 접미사 배열상 i+k-1번째에도 같은 접두로 시작하는 단어가 존재해야 한다
		//만족하는 조건중 길이가 제일 긴것을 저장
		result = max(result, commonPrefix(input, table[i], table[i + time - 1]));
	}
	return result;
}
