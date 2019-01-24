#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;
vector<char> op; // '+' '-' 등의 operations
int pushedMaxNumber = 0;
int popedMinNumber = 999999;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;
        if (pushedMaxNumber < cmd) {
            // 뭔가 갑자기 큰 수가 나오면 거기까지 push 수행
            while(pushedMaxNumber != cmd) {
                // cout << "(+) " << pushedMaxNumber+1 << "를 푸쉬함" << endl;
                op.push_back('+');
                st.push(++pushedMaxNumber);
            }
            // 그리고 그 숫자를 pop 해야됨
            // cout << "(-) " << st.top() << "를 팝함" << endl;
            op.push_back('-');
            popedMinNumber = st.top() < popedMinNumber ? st.top() : popedMinNumber;
            st.pop();
        } else {
            // 어떤 수를 받았는데 고인물이다.. 그러면 계속 pop 해본다.
            // 4 3 or 4 2
            if (pushedMaxNumber > cmd) {
                if(!st.size()) {
                    cout << "NO" << endl;
                    return 0;
                }
                while(st.size() && st.top() != cmd) {
                    // cout << "(-)" << st.top() << "를 팝함" << endl;
                    op.push_back('-');
                    st.pop();
                }
                if(st.size()) {
                    // cout << "(-)" << st.top() << "를 팝함" << endl;
                    op.push_back('-');
                    st.pop(); // 하나 더.
                }
            } else {
                // cout << "안 되는 연산." << endl;
            }
        }
    }
    for (auto &i : op) {
        cout << i << '\n';
    }
    return 0;
}
