#include "pch.h"
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;

//���̻� �迭�� �����ϴ� �ǹ�-���̾ �˰���
//aaaaa....x���� ���ڿ��ϰ�� ������ ���ϸ� �ð��� �����ɸ���
//1��° ������ ���� 2��°���� ���� 4��° ���� ���ڸ��� ����� ���� �׷���� �����Ѵ�
//group�� ������ ��¥�� �� ���� ���ڿ����� ������ ������ 2��� start�� �ǳʶپ �����ϴ�
struct Comparator
{
	//start��° �������� ���ĵǰ� �׷��� �־�������
	//start*2��°�� �������� ��������Ѵ�
	const vector<int>& group;
	int start;
	Comparator(const vector<int>& _group, int _start):group(_group),start(_start){
		//group = _group;
		//start = _start;
	}
	//���� �� ��ġ�� �Է�
	bool operator ()(int a, int b) {
		if (group[a] != group[b]) {
			return group[a] < group[b];
		}
		//���ڰ� ������ start�� ���� ���ڸ� ����
		return group[a + start] < group[b + start];
	}

};
vector<int> getSuffixArray(const string& input);
int commonPrefix(const string& input, int i, int j);
int longestHabit(const string& input, int time);
//���̻� �迭
//�κ� ���� ���� �����ϴ�
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
//���̻� �迭�� �����ҽ�
//���̻���� ���������� �迭�ؼ� �����Ѵ�
//�� ���� ���̻��� ���� ��ġ���� �迭�� �����ϸ� ����ȿ���� ��������
vector<int> getSuffixArray(const string & input)
{
	int n = input.size();
	//���-���̾ �˰��� �̿�
	//ù��° ���ں��� ��
	int start = 1;
	//���� ���ڵ��� �� �׷�
	vector<int> group(n + 1);
	for (int i = 0; i < n; i++) {
		//�ϴ� �� �׷��� ������ ���ڿ��� �״�� �Ѵ�
		group[i] = input[i];
	}
	group[n] = -1;
	vector<int> result(n);
	for (int i = 0; i < n; i++) {
		result[i] = i;
	}
	//��������°���� ��� �񱳰� ����������
	while (start < n)
	{
		Comparator compare2T(group, start);
		//�ϴ� ��ó�����ڼ����� ���ĵȴ�
		sort(result.begin(), result.end(), compare2T);
		//���⼭ �׷��� ���� ����� �ɷ�����
		start *= 2;
		if (start >= n) {
			break;
		}
		//������ ���ƴٸ� ���ο� �׷� ����
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		//���������� �׷��� ���´�
		newGroup[result[0]] = 0;
		for (int i = 1; i < n; i++) {
			//�������ڿ� �ٸ��ٸ�
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
//���ڿ��� �κй��ڿ��� ���� ���ϱ� ���ؼ��� ���̻� �迭�� �ʿ��ϴ�
//���̻縶�� �ϳ��� ���ڸ� ��� ���� �� ���� = �κй��ڿ� �����̴�
//�׷��� �ߺ��� ���ϱ����� ���������� ���ĵ� �迭���� ���κа� ����� �κ��� ���� �ȴ�

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
	//���̻� �迭 ����
	vector<int> table = getSuffixArray(input);
	int result = 0;
	for (int i = 0; i + time <= input.size(); i++) {
		//time�� �̻� �����ؾ� �ϴ� �ܾ��̱⿡ ���̻� �迭�� i+k-1��°���� ���� ���η� �����ϴ� �ܾ �����ؾ� �Ѵ�
		//�����ϴ� ������ ���̰� ���� ����� ����
		result = max(result, commonPrefix(input, table[i], table[i + time - 1]));
	}
	return result;
}
