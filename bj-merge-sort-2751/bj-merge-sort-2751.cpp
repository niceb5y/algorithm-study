#include <iostream>
#include <cstdio>
#include <set>
#include <functional>
using namespace std;

int main(void)
{
    int N, n;
    set<int> s;
    set<int>::iterator iter;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &n);
        s.insert(n);
    }
    for(iter = s.begin(); iter != s.end(); iter++) {
        printf("%d\n", *iter);
    }
    return 0;
}
