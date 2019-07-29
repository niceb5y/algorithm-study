#include "pch.h"

#include <iostream>
#include <vector>

using namespace std;

vector<long long> cache;
int target;
int main() {
	int trial;
	cin >> trial;
	for (int casees = 0; casees < trial; casees++) {
		cin >> target;
		target = target - 1;
		cache = {1,1,1,2,2,0};
		if (target < 5) {
			cout << cache[target] << endl;
		}
		else {
			long long temp;
			for (int i = 5; i <= target; i++) {
				temp = cache[(i - 1) % 6] + cache[(i - 5) % 6];
				cache[i % 6] = temp;
			}
			cout << temp << endl;
		}
	}

}