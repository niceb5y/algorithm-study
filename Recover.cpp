#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int restore(int last, int used);
string decode(int last, int used);
int wordNum;
vector<string> wordList;
vector<vector<int>> overlapList;
vector<vector<int>> cache;
//�ظ� ���� ���ؾ� �ϴ� ���� ��ȹ��
int main() {
	int testcase, boardSize;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> wordNum;
		bool finded;
		vector<string> wordList2 = vector<string>(wordNum);
		//�� �ܾ �ٸ� �ܾ��� �κ��϶� ����������
		for (int i = 0; i < wordNum; i++) {
			cin >> wordList2[i];
		}
		vector<int> comboed = vector<int>();
		for (int i = 0; i < wordNum; i++) {
			for (int j = 0; j < wordNum; j++) {
				if (i == j) {
					continue;
				}
				if (wordList2[j].find(wordList2[i]) != string::npos) {
					comboed.push_back(i);
					break;
				}
			}
		}
		wordList = vector<string>();
		for (int i = 0; i < wordNum; i++) {
			if (find(comboed.begin(), comboed.end(), i) != comboed.end()) {
				continue;
			}
			wordList.push_back(wordList2[i]);
		}
		wordNum = wordList.size();
		overlapList = vector<vector<int>>(wordNum, vector<int>(wordNum, -1));
		//i��° �ܾ� �ڿ� j��° �ܾ ���ö� ��ġ�� �κ��� �ִ븦 ���Ѵ�.
		for (int i = 0; i < wordNum; i++) {
			for (int j = 0; j < wordNum; j++) {
				if (i == j) {
					overlapList[i][j] = -1;
					continue;
				}
				int overlap = 0;
				string a = wordList[i];
				string b = wordList[j];
				int count;
				for (count = min(a.length(), b.length()); count > 0; count--) {
					if (a.substr(a.length() - count) == b.substr(0, count)) {
						break;
					}
				}
				overlapList[i][j] = count;
			}
		}
		cache = vector<vector<int>>(wordNum, vector<int>(1<<wordNum,-1));
		int Bestlast = 0;
		int BestScore = 0;
		//ù Last�� ��������Ѵ�
		for (int i = 0; i < wordNum; i++) {
			int temp = restore(i, (1 << i));
			if (BestScore < temp) {
				BestScore = temp;
				Bestlast = i;
			}
		}
		if (Bestlast == -1) {
			cout << "Wrong" << endl;
		}
		cout << wordList[Bestlast]+decode(Bestlast, 1 << Bestlast) << endl;
	}
	return 0;
}
//�����ϴ� ���ǿ� ������ ����ϴ�
//�迭�� ����ȭ ���Ѽ� �����ϴ°� ����Ʈ�̴�
//�ܾ��� ��ġ�� �κ��� �ִ�ȭ�ؼ� ���
//last�� �� ���������� �̿��߰�, used�� ����Ʈ��� �ܾ �̿�������
//������ ��ġ�ºκ��� ���� Ŭ���� ��ġ�� ���� ���
int restore(int last, int used)
{
	//�������: ��� �ܾ ���غ�����
	//��Ʈ����ũ: 1�ڿ� wordNum��ŭ 0 �� ���̰� 1�� ���� wordNum-1��ŭ 1�� �̷���� ���ڰ� �ȴ�
	if (used == (1 << wordNum)-1) {
		return 0;
	}
	int& memo = cache[last][used];
	if (memo != -1) {
		return memo;
	}
	memo = 0;
	for (int next = 0; next < wordNum; next++) {
		//next�� �ڸ��κп� ���ؼ� ��ü�� 0���� 1���� �Ǵܵȴ�
		//��¥�� �ٸ��κ��� �� 0�� �ǹǷ�
		if ((used & (1 << next)) == 0) {
			int tempMax = overlapList[last][next] + restore(next, used + (1 << next));
			memo = max(memo, tempMax);
		}
	}
	return memo;
}

//������ ������
string decode(int last, int used)
{
	//�������: ��� �ܾ ���غ�����
//��Ʈ����ũ: 1�ڿ� wordNum��ŭ 0 �� ���̰� 1�� ���� wordNum-1��ŭ 1�� �̷���� ���ڰ� �ȴ�
	if (used == (1 << wordNum) - 1) {
		return "";
	}
	for (int next = 0; next < wordNum; next++) {
		//������ �ݴ�� ���� ���θ� �Ǵ��Ѵ�
		//0�ǿܿ� �� 1�� ���ΰ��̹Ƿ� �ܾ ���ԵȰ��̴�
		if (used&(1 << next)) {
			continue;
		}
		else {
			//�̹� �ܾ �������� ������ ����
			int ifUsed = restore(next, used + (1 << next)) +overlapList[last][next];
			//�� �ܾ ��¥ ���������� ���� ���϶� �ܾ ���ԵȰ�
			if (ifUsed == restore(last, used)) {
				//���ڰ� ��ġ�°� ������ �κк��� ������ ó���Ѵ�
				//debugContent: overlap�� next���̿� ���ٸ�?
				return (wordList[next].substr(overlapList[last][next]) + decode(next, used + (1 << next)));
			}
		}
	}
	return "SomeThing Worng";
}