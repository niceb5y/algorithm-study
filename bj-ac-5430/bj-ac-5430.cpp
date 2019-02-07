#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

/* Problem: https://www.acmicpc.net/problem/5430 */

string inOrderArray;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, p, n, n2; // 케이스, 명령어수, 배열데이터 개수
    int front_ptr, back_ptr; // D에의해 삭제처리되면 이동
    bool error;
    // 즉, 범위는 front부터 back까지이다.
    int dir; // 디렉션 (0 : 정방향, 1 : 역방향)
    cin >> T;
    cin.get();
    while(T--) {
        string ps;
        getline(cin, ps);
        p = ps.length();
        cin >> n; // 배열의 데이터 개수
        cin.get();
        n2 = n;
        error = false;
        front_ptr = 0;
        back_ptr = n - 1;
        dir = 0;
        vector<int> dataArray(n);
        for (auto &i : dataArray) {
            cin.get();
            cin >> i;
        }
        cin.ignore(2, '\n');
/*
        cout << "Test" << n << endl;
        for(int i = 0; i < n; i++) {
            cout << '~' << dataArray[i] << '~' << endl;
        }
*/

        // 이제 명령을 구문해석한다.
        for(int i = 0; i < p; i++) {
            char command = ps[i];
            if (command == 'R') {
                dir = dir == 0 ? 1 : 0;
            } else {
                if (n2 == 0) {
                    error = true;
                    cout << "error" << '\n';
                    break;
                }
                if (dir == 0) {
                    front_ptr++;
                    n2--;
                } else {
                    back_ptr--;
                    n2--;
                }
            }
        }
        // 배열을 출력
        if(!error) {
            cout << '[';
            if(dir == 0) {
                for (int i = front_ptr; i <= back_ptr; i++) {
                    cout << dataArray[i];
                    if (i != back_ptr) cout << ',';
                }
            } else {
                for (int i = back_ptr; i >= front_ptr; i--) {
                    cout << dataArray[i];
                    if(i != front_ptr) cout << ',';
                }
            }
            cout << ']' << '\n';
        }
        
    }
    return 0;
}
