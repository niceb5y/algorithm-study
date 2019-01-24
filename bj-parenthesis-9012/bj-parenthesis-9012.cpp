#include <iostream>
#include <stack>

/*
    Problem: https://www.acmicpc.net/problem/9012
*/

using namespace std;

int main(void)
{
    string input;
    int T;
    bool flag;
    cin >> T;
    while(T--) {
        flag = true;
        stack<char> st;
        cin >> input;
        for(auto &i : input) {
            if(i == '(') st.push('(');
            else if(st.size()) {
                st.pop();
            } 
            else {
                flag = false;
                cout << "NO" << endl;
                break;
            }
        }
        if(flag){
            if(st.size() == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
