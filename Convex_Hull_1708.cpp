#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool pointSort(pair<int, int> first, pair<int, int> second);
long long findSignedArea(pair<int, int> first, pair<int, int>second, pair<int, int> challenger);
int pointNum;
vector<pair<int, int>> pointList;
pair<int, int> mostdown;
int main() {
	cin >> pointNum;
	int x, y;
	mostdown = make_pair(40001, 40001);
	for (int i = 0; i < pointNum; i++) {
		cin >> x;
		cin >> y;
		pointList.push_back(make_pair(x, y));
		if (mostdown.second > y || (mostdown.second == y && mostdown.first > x)) {
			mostdown = make_pair(x, y);
		}
	}
	sort(pointList.begin(), pointList.end(), pointSort);
	vector<pair<int, int>> convexPoints;
	convexPoints.push_back(pointList[0]);
	convexPoints.push_back(pointList[1]);
	pair<int, int> zeroPoint = make_pair(-40001, -40001);
	for (int i = 2; i < pointList.size(); i++) {
		double check1 = atan2(convexPoints.back().second - mostdown.second, convexPoints.back().first - mostdown.first);
		double check2 = atan2(pointList[i].second - mostdown.second, pointList[i].first - mostdown.first);
		if (check1 == check2) {
			continue;
		}
		while (pointList.size()>0){
			if (findSignedArea(convexPoints[convexPoints.size() - 2], convexPoints.back(), pointList[i]) > 0) {
				convexPoints.push_back(pointList[i]);
				break;
			}
			convexPoints.pop_back();
		}
	}

	cout << convexPoints.size() << endl;
	return 0;
}

bool pointSort(pair<int, int> first, pair<int, int> second) {
	if (first == mostdown) {
		return true;
	}
	else if (second == mostdown) {
		return false;
	}
	double firstCCW, secondCCW;
	firstCCW = atan2(first.second - mostdown.second, first.first - mostdown.first);
	secondCCW = atan2(second.second - mostdown.second, second.first - mostdown.first);
	/*pair<int, int> zeroPoint = make_pair(-40001, -40001);
	firstCCW = findSignedArea(zeroPoint, mostdown, first);
	secondCCW = findSignedArea(zeroPoint, mostdown, second);

	if (firstCCW < 0 && secondCCW >0) {
		return false;
	}
	else if (firstCCW > 0 && secondCCW < 0) {
		return true;
	}
	else if (firstCCW < 0 && secondCCW < 0) {
		if (firstCCW > secondCCW) {
			return true;
		}
		else if (firstCCW < secondCCW) {
			return false;
		}
		else {
			return abs(first.first - mostdown.first) + abs(first.second - mostdown.second) > abs(second.first - mostdown.first) + abs(second.second - mostdown.second);
		}
	}*/
	if (firstCCW < secondCCW) {
		return true;
	}
	else if (firstCCW > secondCCW) {
		return false;
	}
	else {
		return abs(first.first - mostdown.first) + abs(first.second - mostdown.second) > abs(second.first - mostdown.first) + abs(second.second - mostdown.second);
	}
}

long long findSignedArea(pair<int, int> first, pair<int, int>second, pair<int, int> challenger) {
	long long area1, area2, area3;
	area1 = (long long)first.first * (long long)second.second - (long long)first.second * (long long)second.first;
	area2 = (long long)second.first * (long long)challenger.second - (long long)second.second * (long long)challenger.first;
	area3 = (long long)challenger.first * (long long)first.second - (long long)challenger.second * (long long)first.first;
	return area1 + area2 + area3;
}