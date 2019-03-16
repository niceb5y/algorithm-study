#include <iostream>
#include <vector>
using namespace std;

const int l_block[4][3][2] = {
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {0,1}, {1,0}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
};

bool set(vector<vector<int> >& board, int x, int y, int type, int delta)
{
	bool ok = true;

	for (int i = 0; i < 3; i++) {
		const int nx = x + l_block[type][i][1];
		const int ny = y + l_block[type][i][0];

		if (nx < 0 || ny < 0 || nx >= board[0].size() ||\
				ny >= board.size())
			ok = false;
		
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

int solve(vector<vector<int> >& board)
{
	int x = -1, y = -1;
	
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j <board[i].size(); j++) {
			if (board[i][j] == 0) {
				x = j;
				y = i;
				break;
			}
		}

		if (y != -1)
			break;
	}

	if (y == -1)
		return 1;

	int ret = 0;

	for (int type = 0; type < 4; type++) {
		if (set(board, x, y, type, 1))
			ret += solve(board);
		set(board, x, y, type, -1);
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C, h, w;

    cin >> C;
    while (C--) {
		cin >> h >> w;

		vector<vector<int> > board(h, vector<int>(w, 0));
		int w_block = 0;
		char c;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> c;
				if (c == '#')
					board[i][j] = 1;
				else
					w_block++;
			}
		}

		if (w_block % 3 != 0)
			cout << 0 << '\n';
		else
			cout << solve(board) << '\n';
    }
	
	return 0;
}
