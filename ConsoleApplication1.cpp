// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int xPosition[8] = { 0,1,1,1,0,-1,-1,-1 };
int yPosition[8] = { -1,-1,0,1,1,1,0,-1 };
int testcase = 0, words = 0;
string board[5];
string word;
bool search(string toFind, int index, int x, int y);
int main()
{
	cin >> testcase;
	cin.ignore();
	for (int test = 0; test < testcase;test++) {
		for (int filledLine = 0; filledLine < 5; filledLine++) {
			cin>>board[filledLine];
			cin.ignore();
		}
		cin >> words;
		cin.ignore();
		for (int currentWord = 0; currentWord < words; currentWord++) {
			cin >> word;
			cin.ignore();
			bool find = false;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (board[i][j] == word[0]) {
						//finded word is index
						find = search(word,0,i,j);
					}
					if (find) {
						break;
					}
				}
				if (find) {
					break;
				}
			}
			if (!find) {
				cout << word << " NO" << endl;
			}
		}
	}
	return 0;
}

bool search(string toFind, int index, int x, int y) {
	if (toFind.length() == index + 1) {
		cout << toFind << " YES"<<endl;
		return true;
	}
	bool result;
	for (int i = 0; i < 8; i++) {
		if (!(x + xPosition[i] < 0 || x + xPosition[i] > 4 || y + yPosition[i] < 0 || y + yPosition[i]>4)) {
			if (board[x + xPosition[i]][y + yPosition[i]] == toFind[index + 1]) {
				if (search(toFind, index + 1, x + xPosition[i], y + yPosition[i])) {
					return true;
				}
			}
		}
	}
	return false;
}