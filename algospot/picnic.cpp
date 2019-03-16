#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<bool> >& arr, vector<bool>& check, int n)
{
	int first = -1;

	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			first = i;
			break;
		}
	}

	if (first == -1)
		return 1;

	int ret = 0;

	for (int second = first + 1; second < n; second++) {
		if (check[second] == false && arr[first][second] == true) {
			check[first] = check[second] = true;
			ret += solve(arr, check, n);
			check[first] = check[second] = false;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C, n, m;

	cin >> C;
	while (C--) {
		vector<vector<bool> > arr(10, vector<bool>(10, false));
		vector<bool> check(10, false);
		int x, y;

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			arr[x][y] = arr[y][x] = true;
		}

		cout << solve(arr, check, n) << "\n";
	}

	return 0;
}
