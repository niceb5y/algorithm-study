#include <iostream>
#include <cstring>

using namespace std;

unsigned answer = 0;
char num[2][10001];

int main(void)
{
    int len[2];
    cin >> num[0] >> num[1];
    len[0] = strlen(num[0]);
    len[1] = strlen(num[1]);
    for (int i = 0; i < len[0]; i++) {
        for (int j = 0; j < len[1]; j++) {
            answer += (num[0][i]-'0') * (num[1][j]-'0');
        }
    }
    cout << answer << endl;
    return 0;
}
