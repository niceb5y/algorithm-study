#include "pch.h"
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
//<키,값>의 형식
map<int, int> coords;
bool isDominated(int x, int y);
void deleteDominated(int x, int y);
int hereComesNewChallenger(int x, int y);
//이진트리 Map
int main() {
	int testCase, challengerNum, question, ramen, total;
	cin >> testCase;
	for (int trial = 0; trial < testCase; trial++) {
		coords.clear();
		cin >> challengerNum;
		total = 0;
		for (int i = 0; i < challengerNum; i++) {
			cin >> question;
			cin >> ramen;
			total += hereComesNewChallenger(question, ramen);
		}
		cout << total << endl;
	}
	return 0;
}

bool isDominated(int x, int y)
{
	//x좌표 이상중 제일 작은걸 반환해준다
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end()) {
		//이 점은 제일 왼쪽에 있으므로 어느점에도 지배당하지 않는다
		return false;
	}
	//x이전의 영역으로부터는 자유로우나 그 이후로는 자유롭지 못하다
	//y는 가면 갈수록 낮아지므로 바로 앞의 y값에서 자유롭다면 나머지 y에 대해서도 자유롭다
	return y < it->second;
}

void deleteDominated(int x, int y)
{
	//x좌표 이상중 제일 작은걸 반환해준다
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.begin()) {
		//x좌표는 x중 제일 왼쪽에 있다
		return;
	}
	//이제부터는 x미만의 좌표들이다
	it--;
	while (true)
	{
		//이 다음부터는 x점으로부터 모조리 자유롭다
		if (it->second > y) {
			break;
		}
		//제일 왼쪽점마저 이 점에 지배당한다면
		if (it == coords.begin()) {
			//지우고 끝낸다
			coords.erase(it);
			break;
		}
		else {
			//지우고 다움점으로
			map<int, int>::iterator temp = it;
			temp--;
			coords.erase(it);
			it = temp;
		}
	}
}

int hereComesNewChallenger(int x, int y)
{
	if (isDominated(x, y)) {
		return coords.size();
	}
	else {
		deleteDominated(x, y);
	}
	//map 원소 추가 방식[키]=값
	coords[x] = y;
	return coords.size();
}
