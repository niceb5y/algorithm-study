#include "pch.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<int, int>> arrows;
vector<pair<int, int>> convexArrows;
pair<int, int> mostDown;
int arrowNum;
bool arrowsort(pair<int, int> first, pair<int, int> second);
bool isClockWise(pair<int, int> first, pair<int, int> second, pair<int, int> challenger);
int main() {
	cout << fixed;
	cout.precision(10);
	cin >> arrowNum;
	int x, y;
	cin >> x;
	cin >> y;
	arrows.push_back(make_pair(x, y));
	mostDown = make_pair(x, y);
	for (int i = 1; i < arrowNum; i++) {
		cin >> x;
		cin >> y;
		if (mostDown == make_pair(x, y)) {
			continue;
		}
		arrows.push_back(make_pair(x, y));
		if (y < mostDown.second || (y == mostDown.second && x < mostDown.first)) {
			mostDown = make_pair(x, y);
		}
	}
	//시계방향으로 소트
	sort(arrows.begin(), arrows.end(), arrowsort);
	if (arrows.size() <= 1) {
		cout << 0.0 << endl;
		return 0;
	}
	convexArrows.push_back(arrows[0]);
	convexArrows.push_back(arrows[1]);
	for (int i = 2; i < arrows.size(); i++) {
		double FirstAtan = atan2(convexArrows.back().second - mostDown.second, convexArrows.back().first - mostDown.first);
		double SecondAtan = atan2(arrows[i].second - mostDown.second, arrows[i].first - mostDown.first);
		if (FirstAtan == SecondAtan) {
			continue;
		}
		while (convexArrows.size() >1){
			if (isClockWise(convexArrows[convexArrows.size() - 2], convexArrows.back(), arrows[i])) {
				convexArrows.push_back(arrows[i]);
				break;
			}
			convexArrows.pop_back();
		}
	}
	//end of convexhull
	double maximum = 0.0;
	for (int i = 0; i < convexArrows.size(); i++) {
		for (int j = i + 1; j < convexArrows.size(); j++) {
			double distance = sqrt(pow(convexArrows[i].first - convexArrows[j].first, 2) + pow(convexArrows[i].second - convexArrows[j].second, 2));
			maximum = max(maximum, distance);
		}
	}
	cout << maximum << endl;
	return 0;
}

bool arrowsort(pair<int, int> first, pair<int, int> second) {
	if (first == mostDown) {
		return true;
	}
	else if (second == mostDown) {
		return false;
	}
	double FirstAtan = atan2(first.second - mostDown.second, first.first - mostDown.first);
	double SecondAtan = atan2(second.second - mostDown.second, second.first - mostDown.first);
	if (FirstAtan < SecondAtan) {
		return true;
	}
	else if (FirstAtan > SecondAtan) {
		return false;
	}
	else {
		return abs(first.first - mostDown.first) + abs(first.second - mostDown.second) > abs(second.first - mostDown.first) + abs(second.second - mostDown.second);
	}
}

bool isClockWise(pair<int, int> first, pair<int, int> second, pair<int, int> challenger)
{
	int one, two, three, four;
	one = second.first - first.first;
	two = second.second - first.second;
	three = challenger.first - first.first;
	four = challenger.second - first.second;

	return (one*four - two*three) > 0;
}
