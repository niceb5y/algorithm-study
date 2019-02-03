#include <iostream>

using namespace std;

/*
    Problem: https://www.acmicpc.net/problem/16861
*/

int split_and_add(int num)
{
    int ret = 0;
    while(num) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i = N; ; i++) {
        if(i % split_and_add(i) == 0) {
            cout << i;
            break;
        }
    }
    cout << '\n';
    return 0;
}
