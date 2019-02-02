#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int musicNum, totalTime,favMusicNum;
vector<int> musicPlaytime;
vector<vector<double>> rate;
vector<int> favMusic;
vector<double> favRate;
vector<vector<double>> cache;
vector<double> imbededOn();
int main() {
	int testcase;
	cin >> testcase;
	cout << fixed;
	cout.precision(10);
	for (int trial = 0; trial < testcase; trial++) {
		cin >> musicNum;
		musicPlaytime = vector<int>(musicNum);
		rate = vector<vector<double>>(musicNum, vector<double>(musicNum));
		//한곡의 최대길이는 4분이다
		cache = vector<vector<double>>(5, vector<double>(musicNum,0.0));
		cin >> totalTime;
		cin >> favMusicNum;
		favMusic = vector<int>(favMusicNum);
		for (int i = 0; i < musicNum; i++) {
			cin >> musicPlaytime[i];
		}
		for (int i = 0; i < musicNum; i++) {
			for (int j = 0; j < musicNum; j++) {
				cin >> rate[i][j];
			}
		}
		for (int i = 0; i < favMusicNum; i++) {
			cin >> favMusic[i];
		}
		vector<double> aLongTimeAfter = imbededOn();
		for (int i = 0; i < favMusicNum; i++) {
			cout << aLongTimeAfter[favMusic[i]]<<" ";
		}
		cout << endl;
	}
	return 0;
}
//일정시간후에 MP3에서 좋아하는 음악이 나올지를 계산
//마르코르 연쇄 문제이다
vector<double> imbededOn()
{
	//[Time]분 후에 [Song]이 재생될 확률 계산
	cache[0][0] = 1.0;
	//결과적으로 Total Time일때 Cache에는 끝시간의 확률들만 남아있게 된다.
	for (int time = 1; time <= totalTime; time++) {
		//다음음악 전체 탐색
		for (int song = 0; song < musicNum; song++) {
			//슬라이드 윈도 기법
			double& temp = cache[time % 5][song];
			temp = 0.0;
			for (int last = 0; last < musicNum; last++) {
				//이전음악 전체 탐색
				//이전의 모든 확률에서이번 확률을 더한다
				temp += cache[(time - musicPlaytime[last] + 5) % 5][last] * rate[last][song];
			}
		}
	}
	vector<double> result = vector<double>(musicNum,0.0);
	//모든 음악 탐색
	for (int music = 0; music < musicNum; music++) {
		for (int musicStartTime = totalTime - musicPlaytime[music] + 1; musicStartTime <= totalTime; musicStartTime++) {
			result[music] += cache[musicStartTime % 5][music];
		}
	}
	return result;
}
