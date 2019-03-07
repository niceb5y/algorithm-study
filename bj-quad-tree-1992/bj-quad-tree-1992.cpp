#include <iostream>
#include <cctype>
#include <queue>

using namespace std;

int N;
char video_infrm[64][64];
queue<char> compress_result;

// start에서부터 우하영역의 w_h * w_h 만큼의 정사각형 영역이 모두 같은 정보인지 여부를 리턴
bool isAllSame(int r, int c, int w_h)
{
    char fix = video_infrm[r][c];
    for (int i = r; i < r + w_h; i++) {
        for (int j = c; j < c + w_h; j++) {
            if (fix != video_infrm[i][j]) return false;
        }
    }
    return true;
}

void solve(int r, int c, int w_h)
{
    // 검사 영역의 전체 판이 같은지 여부를 확인한다.
    if ( isAllSame (r, c, w_h) ) {
        compress_result.push(video_infrm[r][c]);
    }
    else {
        // '(' 를 큐에 넣고 4개로 쪼개게 된다.
        compress_result.push('(');
        solve(r, c, w_h / 2);
        solve(r, c + w_h / 2, w_h / 2);
        solve(r + w_h / 2, c, w_h / 2);
        solve(r + w_h / 2, c + w_h / 2, w_h / 2);
        compress_result.push(')');

    }
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            do {
                c = cin.get();
                video_infrm[i][j] = c;
            } while( isspace(c) );
        }
    }
    solve(0, 0, N);
    // 큐를 방출한다.
    while (!compress_result.empty()) {
        char data = compress_result.front();
        cout << data;
        compress_result.pop();
    }
    cout << endl;
    return 0;
}
