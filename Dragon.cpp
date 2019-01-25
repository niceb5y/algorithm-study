#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int testcase = 1000000001;
int genLength[51];
string xExpand = "X+YF";
string yExpand = "FX-Y";
string zeroGen = "FX";
int inputGen, inputIndex, inputLen;
//해를 직접 구해야 하는 동적 계획법
//k번째 답을 도출해내야 한다
char generate(int skip, string& curve, int needgen);
int main() {
	//n세대의 드래곤커브 길이를 구해놓는다
	genLength[0] = 1;
	for (int i = 1; i <= 50; i++) {
		genLength[i] = min(testcase, 2 * genLength[i - 1] + 2);
	}
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> inputGen;
		cin >> inputIndex;
		cin >> inputLen;
		for (int i = 0; i < inputLen; i++) {
			cout << generate(inputIndex + i-1, zeroGen, inputGen);
		}
		cout << endl;
	}
	return 0;
}

char generate(int skip, string & curve, int needgen)
{
	//기저사례: 확장할 세대가 끝났을떄 찾는 위치의 문자 반환
	if (needgen == 0) {
		if (skip > curve.size()) {
			return '#';
		}
		return curve[skip];
	}
	//i번째 문자를 즉시 확장시키는 방식
	for (int i = 0; i < curve.size(); i++) {
		if (curve[i] == 'X' || curve[i] == 'Y') {
			//해당문자를 끝까지 확장시켜도 그 뒤에나오는 문자를 확장시키는위치에 답이 존재할경우
			if (skip >= genLength[needgen]) {
				skip -= genLength[needgen];
			}
			//X를 만났을때 즉시 확장시킨다
			else if (curve[i] == 'X') {
				return generate(skip, xExpand, needgen - 1);
			}
			//Y를 만났을때 즉시 확장시킨다
			else {
				return generate(skip, yExpand, needgen - 1);
			}
		}
		//F,+,-같은 문자는 건너뛴다
		else if (skip > 0) {
			skip--;
		}
		//skip이 0일시
		else {
			return curve[i];
		}
	}
	//실행되면 안되는 코드
	return '#';
}
