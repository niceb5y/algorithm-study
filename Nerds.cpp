#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include<cfloat>

using namespace std;
//cos 삼각함수의 역함수
const double PI = 2.0*acos(0.0);

struct vector2
{
	//모든 시작점은 원점이라고 가정
	double x, y;
	//컴파일러의 임의적인 생성을 막는다 이 구조체는 오로지 코드로만 구현된다
	explicit vector2(double x_ = 0, double y_ = 0): x(x_),y(y_){}
	//함수 뒤에 const를 붙일시 멤버 변경이 불가능하다
	bool operator ==(const vector2& rhs) const {
		return x == rhs.x&&y == rhs.y;
	}
	bool operator <(const vector2& rhs) const {
		return x == rhs.x&&y == rhs.y;
	}
	vector2 operator +(const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator -(const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	//실수 곱셈
	vector2 operator *(double rhs) const {
		return vector2(x * rhs, y * rhs);
	}
	//벡터의 길이 반환
	double norm() const {
		//길이가 x,y인 직각삼각형의 빗변을 계산해준다
		return hypot(x, y);
	}
	//벡터의 단위벡터 반환
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}
	//벡터의 각도
	double polar() const {
		//float 의 mod(나머지) fmod
		//atan2 = 아크탄젠트 반환
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}
	//벡터의 내적 구현
	//벡터의 수직여부,각도, 사영을 구할때 사용
	double dot(const vector2& rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	//벡터의 외적 구현
	//벡터로 이루어진 평행사변형 크기 계산
	//두 벡터의 방향성 계산
	double cross(const vector2& rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	//이 벡터를 rhs에 사영했을때
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};
//벡터가 반시계방향에 있다면 양수 , 시계방향이라면 음수, 평행이면 0 반환
double ccw(vector2 a, vector2 b);
double ccw(vector2 p, vector2 a, vector2 b);
//두 직선의 교차점을 x에 넣는다
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 x);
//점p와 선ab일때 수선의 발을 구한다
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b);
//점과 직선사이의 거리 구하기
double pointtoLine(vector2 p, vector2 a, vector2 b);
//두 선분의 교차여부 판단하기
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d);

typedef vector<vector2> polygon;
//볼록껍질을 찾는 선물포장 알고리즘
polygon giftWrap(const vector<vector2>& points);
//두개의 다각형의 겹침여부 판정
bool polygonIntersects(const polygon& p, const polygon& q);
//점q가 다각형 p에 포함되어있는지 판단
bool isInside(vector2 q, const vector<vector2> p);

polygon nerd, notnerd;
vector<vector2> nerdPoint, notnerdPoint;
//기하문제는 기초적인 벡터 클래스를 구현해놓으면
//대부분 깔끔하게 풀린다. 벡터에 대해 알아놓도록 하자
int main() {
	int testcase;
	cin >> testcase;
	//두개의 영역에서의 볼록 다각형을 생성한다
	//이 다각형 두개가 겹치지 않는다면 직선이 있다
	for (int trial = 0; trial < testcase; trial++) {
		nerdPoint = vector<vector2>();
		notnerdPoint = vector<vector2>();
		int peopleNum;
		cin >> peopleNum;
		for (int i = 0; i < peopleNum; i++) {
			int isNerd,tempx,tempy;
			cin >> isNerd;
			cin >> tempx;
			cin >> tempy;
			if (isNerd == 1) {
				nerdPoint.push_back(vector2(tempx, tempy));
			}
			else if (isNerd == 0) {
				notnerdPoint.push_back(vector2(tempx, tempy));
			}
			else {
				cout << "Wrong in Input" << endl;
			}
		}
		nerd = giftWrap(nerdPoint);
		notnerd = giftWrap(notnerdPoint);
		if (polygonIntersects(nerd, notnerd)) {
			cout << "THEORY IS INVALID" << endl;
		}
		else {
			cout << "THEORY HOLDS" << endl;
		}
	}
	return 0;
}

double ccw(vector2 a, vector2 b)
{
	return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b)
{
	return ccw(a - p, b - p);
}

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 x)
{
	double result = (b - a).cross(d - c);
	if (fabs(result) < FLT_EPSILON) {
		return false;
	}
	x = a + (b - a)*((c - a).cross(d - c) / result);
	return true;
}

vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b)
{
	return a + (p - a).project(b - a);
}

double pointtoLine(vector2 p, vector2 a, vector2 b)
{
	return (p - perpendicularFoot(p, a, b)).norm();
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d)
{
	double ab = ccw(a, b, c)*ccw(a, b, d);
	double cd = ccw(c, d, a)*ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b < a) {
			swap(a, b);
		}
		if (d < c) {
			swap(c, d);
		}
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}

polygon giftWrap(const vector<vector2>& points)
{
	int n = points.size();
	polygon hull;
	//제일 왼쪽 아래의 원소를 찾는다
	vector2 pivot = *min_element(points.begin(), points.end());
	hull.push_back(pivot);
	while (true)
	{
		vector2 ph = hull.back(), next = points[0];
		//가장왼쪽에 있는 점을 선분으로 이어나가면서 볼록 다각형을 만든다
		//벡터가 평행이면 먼 점을 고른다
		for (int i = 1; i < n; i++) {
			//양수면 points[i]가 더 왼쪽이다
			double cross = ccw(ph, next, points[i]);
			//음수면 points가 더 먼곳에 있다
			double dist = (next - ph).norm() - (points[i] - ph).norm();
			if (cross > 0 || (cross == 0 && dist < 0)) {
				next = points[i];
			}
		}
		if (next == pivot) {
			break;
		}
		hull.push_back(next);
	}
	return hull;
}

bool polygonIntersects(const polygon & p, const polygon & q)
{
	int n = p.size(), m = q.size();
	if (isInside(p[0], q) || isInside(q[0], p)) {
		return true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (segmentIntersects(p[i], p[(i + 1) % n], q[j], q[(j + 1) % m])) {
				return true;
			}
		}
	}
	return false;
}

bool isInside(vector2 q, const vector<vector2> p)
{
	int crosses = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		//두개의 다각형 점이 q의 y좌표를 지나는가
		if ((p[i].y > q.y) != (p[j].y > q.y)) {
			double atX = (p[j].x - p[i].x)*(q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if (q.x < atX) {
				++crosses;
			}
		}
	}
	return crosses % 2 > 0;
}
