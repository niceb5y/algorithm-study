#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> fences;
int cal(int left, int right);
int main() {
	int testcase = 0;
	cin >> testcase;
	string mainBoard;
	int fencesNum;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> fencesNum;
		fences = vector<int>(fencesNum, 0);
		for (int fence = 0; fence < fencesNum; fence++) {
			cin >> fences[fence];
		}
		cout << cal(0,fencesNum-1) << endl;
	}
	return 0;
}

int cal(int left, int right) {
	if (left == right) {
		return fences[left];
	}
	else {
		int midPoint = (left + right) / 2;
		int maxSide = max(cal(left,midPoint), cal(midPoint+1,right));
		int Ltemp = midPoint;
		int Rtemp = midPoint + 1;
		int possibleHigh = min(fences[Ltemp], fences[Rtemp]);
		int maxSize = possibleHigh * 2;
		while (left < Ltemp || Rtemp < right) {
			if (Rtemp < right && (Ltemp == left || fences[Ltemp - 1] < fences[Rtemp + 1])) {
				Rtemp++;
				possibleHigh = min(possibleHigh, fences[Rtemp]);
			}
			else {
				Ltemp--;
				possibleHigh = min(possibleHigh, fences[Ltemp]);
			}
			maxSize = max(maxSize, (Rtemp - Ltemp+1)*possibleHigh);
			
		}
		return max(maxSide,maxSize);
	}
}