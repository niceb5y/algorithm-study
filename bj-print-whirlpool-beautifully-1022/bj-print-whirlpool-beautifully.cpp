#include <iostream>

using namespace std;

int _abs(int a) {
    return a>0?a:-a;
}

int _aws(int r, int c)
{
    if (r == c && r == 0) return 1;  //초기값
    if (r > 0 && r == c) return (r + c + 1) * (r + c + 1); // 오른쪽 아래
    if (r < 0 && r == c) return (-r + -c) * (-r + -c) + 1; // 왼쪽 위
    if (r > 0 && c < 0 && r == -c) return _aws(r, -c) - r * 2; // 왼쪽 아래 
    if (r < 0 && c > 0 && -r == c) return _aws(r, -c) + r * 2; // 오른쪽 위
    
    // n, m 좌표가 들어오면 ex)1,2
    // 어느 사각 영역에 속해있는지 파악 (절댓값 큰 수 찾기)
    if (_abs(r) > _abs(c)) {
        // 좌우 상승 영역
        if (r < 0) {
            // 16 15 14 ... 감소하는 영역
            return _aws(r, r) + r - c;
        } else {
            // 22 23 24 ... 증가하는 영역
            return _aws(r, -r) + r + c;
        }
    } else {
        // 상하 상승 영역
        if (c < 0) {
            // 18 19 20 ... 하강하면서 증가하는 영역
            return _aws(c, c) + r - c;
        } else {
            // 12 11 10 ... 하강하면서 감소하는 영역
            return _aws(-c, c) - r - c;
        }
    }
    
    return -9999;
}


int main(void)
{
    for (int i = -3; i <= 3; i++) {
        for (int j = -3; j <= 3; j++) {
            cout << "[";
            cout << _aws(i, j);
            cout << "]\t";
        }
        cout << endl;
    }
    return 0;
}