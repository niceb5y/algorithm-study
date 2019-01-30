#include <iostream>
#include <stack>

using namespace std;
enum {OPEN_SMALL = -1, CLOSE_SMALL = -2, OPEN_LARGE = -3, CLOSE_LARGE = -4};
int main(void)
{
    bool invalid = false;
    int levelSmall = 0; // () 괄호쌍 수
    int levelLarge = 0; // [] 괄호쌍 수
    int answer = 0; // 괄호열의 값 (최대 14,348,907 = 3^15)
    stack<int> s; // 괄호열을 담는 stack
    char input[31]; // 괄호열을 나타내는 문자열
    cin >> input;
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (c == '(')
        {
            s.push(OPEN_SMALL);
            ++levelSmall;
        }
        else if (c == ')')
        {
            if (!s.size() || !levelSmall || s.top() == OPEN_LARGE) { invalid = true;  break; }
            --levelSmall;
            if (s.top() == OPEN_SMALL) {
                s.pop();
                if (s.size() && s.top() > 0)  {int t = s.top(); s.pop();  s.push(t + 2);}
                else    s.push(2);
            } else {
                // 숫자가 있을 경우 '(N' => '2N'
                int t = s.top() * 2; // 이거 하기 전에 계산
                s.pop();
                s.pop();
                //여기서 옆도 숫자인경우?
                if (s.size() && s.top() > 0) { int t2 = s.top(); s.pop(); s.push(t + t2); }
                else s.push(t); // * 2
            }
        }
        else if (c == '[')
        {
            s.push(OPEN_LARGE);
            ++levelLarge;
        }
        else // ']'
        {
            if (!s.size() || !levelLarge || s.top() == OPEN_SMALL) { invalid = true;  break; }
            --levelLarge;
            if (s.top() == OPEN_LARGE) {
                s.pop();
                if (s.size() && s.top() > 0)  {int t = s.top(); s.pop();  s.push(t + 3);}
                else    s.push(3);
            } else {
                // 숫자가 있을 경우
                int t = s.top() * 3;
                s.pop();
                s.pop();
                //여기서 옆도 숫자인경우?
                if (s.size() && s.top() > 0) { int t2 = s.top(); s.pop(); s.push(t + t2); }
                else s.push(t); // * 3
            }
        }
    }
    if(levelLarge || levelSmall) invalid = true;
    if (!invalid) {
        while (s.size()) {
            answer += s.top();
            s.pop();
        }
    }

    printf("%d\n", invalid ? 0 : answer);
    return 0;
}
