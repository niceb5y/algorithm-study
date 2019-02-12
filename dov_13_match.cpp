#include <iostream>
#include <stack>
#include <stdio.h>

/*
problem
수식이 주어질 때 같은 짝의 괄호의 위치를 찾는 문제이다.
(a*(b+c)+d)
이 경우에는 3 과 7 , 0 과 10 이 한 쌍의 괄호이다.

input
입력은 공백없이 입력된다. 입력되는 문자는 소문자,소괄호,(+,-,*,/)이다.
문자열의 길이는 최대 50 까지이다.

output
왼쪽에서 오른쪽을 가면서 먼저 짝이 맞는 (여는 괄호 위치, 닫는 괄호 위치) 순으로 출력하고, 짝이 맞지 않는 수식은 not match 를 출력한다.


*/


using namespace std;
char poly[51];
int array[50];

int main(void)
{
	int index = 0;
	stack<int> s;
	scanf("%s",poly);
	int i = 0;
	do
	{
		if(poly[i] == '('){
			s.push(i);
		}
		else if(poly[i] == ')'){
			if(s.empty()){
				cout<<"not match"<<endl;
				return 0;
			}
			array[index] = s.top();
			array[index + 1] = i;
			index += 2;
			s.pop();
		}
		i++;
	}while(poly[i] != 0);
	if(s.empty() == false){
		cout<<"not match"<<endl;
		return 0;
	}
	else{
		for(int i = 0 ; i< index ; i += 2){
			cout<<array[i]<<" "<<array[i+1]<<endl;
		}
	}
	return 0;
}


/*
sol
stack의 기본문제인 괄호 매칭 문제이다.

'(' 를 만났을 경우 index를 stack에 push하고
')'를 만난 경우 stack에서 pop하여 매칭 시켜준다.

')'를 만나서 pop하는 경우에 stack이 비워있으면 정상적인 식이 아니므로 에러메시지를 출력한다.
모든 식이 끝났는데 stack이 비워져있지 않은 경우 역시 정상적인 식이 아니므로 에러메시지를 출력한다.


*/
