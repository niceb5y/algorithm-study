#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks)
{
	for (int i = 0; i < CLOCKS; i++)
		if (clocks[i] != 12)
			return false;

	return true;
}

void push(vector<int>& clocks, int swtch)
{
	for (int i = 0; i < CLOCKS; i++) {
		if (linked[swtch][i] == 'x') {
			clocks[i] += 3;
			if (clocks[i] == 15)
				clocks[i] = 3;
		}
	}
}

int solve(vector<int>& clocks, int swtch)
{
	if (swtch == SWITCHES)
		return areAligned(clocks) ? 0 : INF;

	int ret = INF;

	for (int i = 0; i < 4; i++) {
		ret = min(ret, i + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C;

	cin >> C;
	while (C--) {
		vector<int> clocks(CLOCKS, 0);

		for (int i = 0; i < CLOCKS; i++)
			cin >> clocks[i];

		int ans = solve(clocks, 0);

		if (ans == INF)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}

	return 0;
}
