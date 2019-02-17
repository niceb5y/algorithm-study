#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include<cfloat>

using namespace std;
//cos �ﰢ�Լ��� ���Լ�
const double PI = 2.0*acos(0.0);

struct vector2
{
	//��� �������� �����̶�� ����
	double x, y;
	//�����Ϸ��� �������� ������ ���´� �� ����ü�� ������ �ڵ�θ� �����ȴ�
	explicit vector2(double x_ = 0, double y_ = 0): x(x_),y(y_){}
	//�Լ� �ڿ� const�� ���Ͻ� ��� ������ �Ұ����ϴ�
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
	//�Ǽ� ����
	vector2 operator *(double rhs) const {
		return vector2(x * rhs, y * rhs);
	}
	//������ ���� ��ȯ
	double norm() const {
		//���̰� x,y�� �����ﰢ���� ������ ������ش�
		return hypot(x, y);
	}
	//������ �������� ��ȯ
	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}
	//������ ����
	double polar() const {
		//float �� mod(������) fmod
		//atan2 = ��ũź��Ʈ ��ȯ
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
	}
	//������ ���� ����
	//������ ��������,����, �翵�� ���Ҷ� ���
	double dot(const vector2& rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	//������ ���� ����
	//���ͷ� �̷���� ����纯�� ũ�� ���
	//�� ������ ���⼺ ���
	double cross(const vector2& rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	//�� ���͸� rhs�� �翵������
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};
//���Ͱ� �ݽð���⿡ �ִٸ� ��� , �ð�����̶�� ����, �����̸� 0 ��ȯ
double ccw(vector2 a, vector2 b);
double ccw(vector2 p, vector2 a, vector2 b);
//�� ������ �������� x�� �ִ´�
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 x);
//��p�� ��ab�϶� ������ ���� ���Ѵ�
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b);
//���� ���������� �Ÿ� ���ϱ�
double pointtoLine(vector2 p, vector2 a, vector2 b);
//�� ������ �������� �Ǵ��ϱ�
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d);

typedef vector<vector2> polygon;
//���ϲ����� ã�� �������� �˰���
polygon giftWrap(const vector<vector2>& points);
//�ΰ��� �ٰ����� ��ħ���� ����
bool polygonIntersects(const polygon& p, const polygon& q);
//��q�� �ٰ��� p�� ���ԵǾ��ִ��� �Ǵ�
bool isInside(vector2 q, const vector<vector2> p);

polygon nerd, notnerd;
vector<vector2> nerdPoint, notnerdPoint;
//���Ϲ����� �������� ���� Ŭ������ �����س�����
//��κ� ����ϰ� Ǯ����. ���Ϳ� ���� �˾Ƴ����� ����
int main() {
	int testcase;
	cin >> testcase;
	//�ΰ��� ���������� ���� �ٰ����� �����Ѵ�
	//�� �ٰ��� �ΰ��� ��ġ�� �ʴ´ٸ� ������ �ִ�
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
	//���� ���� �Ʒ��� ���Ҹ� ã�´�
	vector2 pivot = *min_element(points.begin(), points.end());
	hull.push_back(pivot);
	while (true)
	{
		vector2 ph = hull.back(), next = points[0];
		//������ʿ� �ִ� ���� �������� �̾���鼭 ���� �ٰ����� �����
		//���Ͱ� �����̸� �� ���� ����
		for (int i = 1; i < n; i++) {
			//����� points[i]�� �� �����̴�
			double cross = ccw(ph, next, points[i]);
			//������ points�� �� �հ��� �ִ�
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
		//�ΰ��� �ٰ��� ���� q�� y��ǥ�� �����°�
		if ((p[i].y > q.y) != (p[j].y > q.y)) {
			double atX = (p[j].x - p[i].x)*(q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if (q.x < atX) {
				++crosses;
			}
		}
	}
	return crosses % 2 > 0;
}
