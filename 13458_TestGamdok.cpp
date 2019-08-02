#include <iostream>
#include <vector>
using namespace std;

int testRoomNum, master, sub;
vector<int> testRoom;
int main() {
	cin >> testRoomNum;
	for (int i = 0, a; i < testRoomNum; i++) {
		cin >> a;
		testRoom.push_back(a);
	}
	cin >> master;
	cin >> sub;
	long long result = 0;
	for (int i = 0; i < testRoomNum; i++) {
		result += 1;
		testRoom[i] -= master;
		if (testRoom[i] > 0) {
			result += testRoom[i] / sub;
			if (testRoom[i] % sub > 0) {
				result++;
			}
		}
	}
	cout << result;
	return 0;
}