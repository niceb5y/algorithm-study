#include <iostream>
#include <stack>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string line;
  while (getline(cin, line)) {
    if (line == ".")
      break;

    stack<char> stk;

    bool valid = true;
    for (auto &c : line) {
      if (c == '(' || c == '[')
        stk.push(c);
      else if (c == ')') {
        if (stk.empty() || stk.top() != '(') {
          valid = false;
          break;
        } else
          stk.pop();
      } else if (c == ']') {
        if (stk.empty() || stk.top() != '[') {
          valid = false;
          break;
        } else
          stk.pop();
      }
    }
    cout << (valid && stk.empty() ? "yes" : "no") << "\n";
  }
}
