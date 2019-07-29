#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <intrin.h>
//#include <math.h>
using namespace std;
vector<int> wordList;
int wordNumber, availableLetter;
int chapterList = 0;
int getLearned(int learnedLetter);
int makeSyilabus(int lernedLetter, int teachedNum,int start);
int maxWord = 0;
//bool isnotEndGame(int addedLetterList, int tempLerned,int teached);
int main() {
	ios_base::sync_with_stdio(false);
	int learnedLetter = 0;
	learnedLetter |= 1 << ('a' - 'a');
	learnedLetter |= 1 << ('c' - 'a');
	learnedLetter |= 1 << ('i' - 'a');
	learnedLetter |= 1 << ('n' - 'a');
	learnedLetter |= 1 << ('t' - 'a');
	cin >> wordNumber;
	cin >> availableLetter;
	if (availableLetter < 5) {
		cout << 0 << endl;
		return 0;
	}
	else if (availableLetter == 26) {
		cout << wordNumber << endl;
		return 0;
	}
	availableLetter -= 5;
	chapterList = learnedLetter;
	string tempWord;
	for (int i = 0; i < wordNumber; i++) {
		cin >> tempWord;
		tempWord = tempWord.substr(4, tempWord.length() - 8);
		int tempWordList = 0;
		for (int j = 0; j < tempWord.length(); j++) {
			tempWordList |= 1<<tempWord.at(j) - 'a';
		}
		chapterList |= tempWordList;

		wordList.push_back(tempWordList);
	}
	chapterList = chapterList ^ learnedLetter;
	if (chapterList == 0) {
		cout << wordList.size() << endl;
		return 0;
	}
	makeSyilabus(learnedLetter, 0, 0);
	cout << maxWord << endl;
	return 0;

}

int getLearned(int learnedLetter)
{
	int result = 0;
	for (int i = 0; i < wordList.size(); i++) {
		if ((wordList[i] & learnedLetter) == wordList[i]) {
			result++;
		}
	}
	maxWord = max(maxWord, result);
	return result;
}

int makeSyilabus(int lernedLetter, int teachedNum,int start)
{
	if ((lernedLetter & chapterList) == chapterList) {
		cout << wordNumber << endl;
		exit(0);
	}
	if (teachedNum == availableLetter) {
		getLearned(lernedLetter);
		return maxWord;
	}
	int result = 0;
	int chapterIter = chapterList, dividedNum = start;
	chapterIter = chapterIter / powl(2,start);
	while (chapterIter != 0){
		if (chapterIter % 2 == 1) {
			int tempWord = powl(2, dividedNum);
			if ((tempWord | lernedLetter) == lernedLetter) {
				chapterIter = chapterIter / 2;
				dividedNum++;
				continue;
			}
			makeSyilabus((lernedLetter | tempWord), teachedNum + 1, dividedNum);
		}
		chapterIter = chapterIter / 2;
		dividedNum++;
	}
	return result;
}

/*bool isnotEndGame(int addedLetterList, int tempLerned,int teached)
{
	int nowWord = getLearned(addedLetterList);
	if (nowWord > tempLerned) {
		return true;
	}
	int neededWord = 15;
	for (int i = 0; i < wordList.size(); i++) {
		int temp = (addedLetterList & wordList[i]);
		if (temp != wordList[i]) {
			temp = wordList[i] - temp;
			neededWord = min(neededWord, (int)__popcnt(temp));
		}
	}
	if (neededWord + teached > availableLetter) {
		return false;
	}
	return true;
}*/
