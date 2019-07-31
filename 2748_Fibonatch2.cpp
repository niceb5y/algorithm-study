#include <iostream>
using namespace std;

int target;
int main() {
	cin >> target;
	long long n0 = 0, n1 = 1, temp;
	for (int i = 1; i < target; i++) {
		temp = n0 + n1;
		n0 = n1;
		n1 = temp;
	}
	cout << n1;
	return 0;
}