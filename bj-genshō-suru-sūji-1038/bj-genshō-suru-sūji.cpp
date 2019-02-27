#include <iostream>

using namespace std;

int dpdata[10][11]; // (start, 자릿수) , 누적 감소하는 수의 개수 저장

bool is_decreasing(int evalNumber)
{
    int first, second;
    while(evalNumber > 10) {
        // 321 
        first = evalNumber % 10; // 1
        second = ( evalNumber / 10 ) % 10; // 2
        if (first >= second) return false;
        evalNumber /= 10;
    }
    return true;
}

int dp(int start, int ketasu) {
    if(dpdata[start][ketasu] != -1) return dpdata[start][ketasu];
    if (ketasu == 1) {
        // 자리수 두자리로 떨어지면 답은 자명해진다.
        cout << "자명" << endl;
        return dpdata[start][ketasu] = start;
    }
    int tmp = 0;
    for(int i = start - 1; i >= ketasu - 2; i--) {
        //ketasu : 3, == 6 _ _ -> 6 5 _ -> 6 4 _ -> 6 3 _ -> 6 2 _ -> 6 1 _ => loop 탈출
        cout << "[start : " << start << ", 자릿수 : " << ketasu << " 가 ";
        cout << "start2: " << i << " ketasu2 : " << ketasu - 1 << "을 호출" << "]" << endl;
        tmp += dp(i, ketasu - 1);
    }
    cout << "리턴 데이터 : " << tmp << endl;
    return dpdata[start][ketasu] = tmp;
}

int main(void)
{
    //int N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cin >> N;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 11; j++) {
            dpdata[i][j] = -1;
        }
    }
    dp(9, 10); // 9로 시작하는 10자리 수부터 역추적하면서 데이터를 채움 (9,876,543,210)
    cout << '\n';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 11; j++) {
            cout << dpdata[i][j] << '\t';
        }
        cout << '\n';
    }
    
    return 0;
}
