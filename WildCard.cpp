#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int>> cache;
bool match(int wTemp, int sTemp);
string wild, baseText;
int main()
{
	int testcase = 0,toSearch = 0;
	vector<string> matched;
	cin >> testcase;
	cin.ignore();
	for (int trial = 0; trial < testcase; trial++) {
		cin >> wild;
		cin >> toSearch;
		matched = vector<string>();
		for (int i = 0; i < toSearch; i++) {
			cin >> baseText;
			cache = vector<vector<int>>(101, vector<int>(101, -1));
			if (match(0, 0)) {
				matched.push_back(baseText);
			}
		}
		sort(matched.begin(), matched.end());
		for (string temp : matched) {
			cout << temp << endl;
		}
	}
	return 0;
}

bool match(int wTemp, int sTemp)
{
	int& memo = cache[wTemp][sTemp];
	if (memo != -1) {
		return memo;
	}
	if (wTemp < wild.size() && sTemp < baseText.size() && (wild[wTemp] == '?' || wild[wTemp] == baseText[sTemp])) {
		memo = match(wTemp + 1, sTemp + 1);
		return memo;
	}
	if (wTemp == wild.size()) {
		if (sTemp == baseText.size()) {
			memo = 1;
			return memo;
		}
		else {
			memo = 0;
		}
		return memo;
	}
	if (wild[wTemp]=='*') {
		if (match(wTemp+1,sTemp)||(sTemp<baseText.size()&&match(wTemp,sTemp+1))) {
			memo = 1;
			return memo;
		}
	}
	memo = 0;
	return memo;
}
