#include <iostream>
#include <stack>

using namespace std;

// calculate(): 괄호의 값을 계산하는 함수
// str: 괄호가 들어있는 문자열
int calculate(const string &str) {
  // bracket_stack: 괄호가 담길 스택
  stack<char> bracket_stack;
  // sum: 괄호의 값의 합
  // operand: 괄호에 더해질 피연산자
  int sum = 0, operand = 1;
  for (int i = 0; i < (int)str.length(); ++i) {
    if (str[i] == '(') {
      // 여는 소괄호인 경우
      // 괄호를 스택에 집어넣는다.
      bracket_stack.push('(');
      // 피연산자를 2배로 한다.
      operand *= 2;
    } else if (str[i] == '[') {
      // 여는 대괄호인 경우
      // 괄호를 스택에 집어넣는다.
      bracket_stack.push('[');
      // 피연산자를 3배로 한다.
      operand *= 3;
    } else if (str[i] == ')') {
      // 닫는 소괄호인 경우
      // 스택이 비어있거나, 닫는 순서가 잘못되었으면 0을 반환한다.
      if (bracket_stack.size() == 0 || bracket_stack.top() != '(') {
        return 0;
      }
      // 직전에 입력받은 괄호가 여는 소괄호였으면 피연산자를 더한다
      if (str[i - 1] == '(') {
        sum += operand;
      }
      // 피연산자를 원래대로 되돌린다.
      operand /= 2;
      // 여는 소괄호를 스택에서 제거한다.
      bracket_stack.pop();
    } else if (str[i] == ']') {
      // 닫는 대괄호인 경우
      // 스택이 비어있거나, 닫는 순서가 잘못되었으면 0을 반환한다.
      if (bracket_stack.size() == 0 || bracket_stack.top() != '[') {
        return 0;
      }
      // 직전에 입력받은 괄호가 여는 대괄호였으면 피연산자를 더한다
      if (str[i - 1] == '[') {
        sum += operand;
      }
      // 피연산자를 원래대로 되돌린다.
      operand /= 3;
      // 여는 대괄호를 스택에서 제거한다.
      bracket_stack.pop();
    }
  }
  return bracket_stack.empty() ? sum : 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string brakets;
  getline(cin, brakets);
  cout << calculate(brakets) << endl;
}
