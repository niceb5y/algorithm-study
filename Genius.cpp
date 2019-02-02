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
		//�Ѱ��� �ִ���̴� 4���̴�
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
//�����ð��Ŀ� MP3���� �����ϴ� ������ �������� ���
//�����ڸ� ���� �����̴�
vector<double> imbededOn()
{
	//[Time]�� �Ŀ� [Song]�� ����� Ȯ�� ���
	cache[0][0] = 1.0;
	//��������� Total Time�϶� Cache���� ���ð��� Ȯ���鸸 �����ְ� �ȴ�.
	for (int time = 1; time <= totalTime; time++) {
		//�������� ��ü Ž��
		for (int song = 0; song < musicNum; song++) {
			//�����̵� ���� ���
			double& temp = cache[time % 5][song];
			temp = 0.0;
			for (int last = 0; last < musicNum; last++) {
				//�������� ��ü Ž��
				//������ ��� Ȯ�������̹� Ȯ���� ���Ѵ�
				temp += cache[(time - musicPlaytime[last] + 5) % 5][last] * rate[last][song];
			}
		}
	}
	vector<double> result = vector<double>(musicNum,0.0);
	//��� ���� Ž��
	for (int music = 0; music < musicNum; music++) {
		for (int musicStartTime = totalTime - musicPlaytime[music] + 1; musicStartTime <= totalTime; musicStartTime++) {
			result[music] += cache[musicStartTime % 5][music];
		}
	}
	return result;
}
