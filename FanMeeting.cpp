#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//28
using namespace std;
vector<int> karatsuba(vector<int> a,vector<int> b);
vector<int> smallMultiply(vector<int> a, vector<int> b);
vector<int> addVector(vector<int> a, vector<int> b,int k);
vector<int> subVector(vector<int> a, vector<int> b);
int main() {
	int testcase = 0;
	cin >> testcase;
	string member, fans;

	for (int trial = 0; trial < testcase; trial++) {
		cin >> member;
		cin >> fans;
		vector<int> memberVector = vector<int>(member.size());
		vector<int> fanVector = vector<int>(fans.size());
		for (int i = 0; i < member.size(); i++) {
			if (member[i] == 'M') {
				memberVector[i] = 1;
			}
			else {
				memberVector[i] = 0;
			}
		}
		for (int i = 0; i < fans.size(); i++) {
			if (fans[i] == 'M') {
				fanVector[i] = 1;
			}
			else {
				fanVector[i] = 0;
			}
		}
		vector<int> result = karatsuba(memberVector,fanVector);
		int count = 0;
		for (int a : result) {
			if (a == 0) {
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
//FastMultiply Karatsuba Algo
vector<int> karatsuba(vector<int> a, vector<int> b)
{
	if (a.size() < b.size()) {
		return karatsuba(b, a);
	}
	if (a.size() == 0 || b.size() == 0) {
		return vector<int>(0);
	}
	if (a.size() < 50) {
		return smallMultiply(a, b);
	}
	int halfPoint = a.size() / 2;
	int bSize = b.size();
	vector<int> a0(&a[0], &a[halfPoint]);
	vector<int> a1(&a[halfPoint+1], &a[a.size()-1]);
	vector<int> b0(&b[0], &b[min(bSize-1,halfPoint)]);
	//
	vector<int> b1(&b[min(bSize-1, halfPoint)], &b[bSize-1]);

	vector<int> z2 = karatsuba(a1,b1);

	vector<int> z0 = karatsuba(a0, b0);

	vector<int> z1 = karatsuba(a0, b0);
	z1 = subVector(z1, z0);
	z1 = subVector(z1, z2);

	vector<int> ret = vector<int>();
	ret = addVector(ret, z0, 0);
	ret = addVector(ret, z1, halfPoint);
	ret = addVector(ret, z2, halfPoint * 2);
	return ret;
}

vector<int> smallMultiply(vector<int> a, vector<int> b)
{
	vector<int> output = vector<int>(a.size()+b.size()+1);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			output[i + j] = output[i + j] + (a[i]*b[j]);
		}
	}
	return output;
}

vector<int> addVector(vector<int> a, vector<int> b, int k)
{
	a.resize(max(a.size(),b.size()+k));
	for (int i = 0; i < b.size(); i++) {
		a[i + k] = a[i + k] + b[i];
	}
	return a;
}

vector<int> subVector(vector<int> a, vector<int> b)
{
	a.resize(max(a.size(),b.size()+1));
	for (int i = 0; i < b.size(); i++) {
		a[i] = a[i] - b[i];
	}
	return a;
}
