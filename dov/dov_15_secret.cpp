#include <iostream>
#include <stdlib.h>
#include <vector>

/*
problem:
베시는 우리를 탈출하기로 맘 먹은 소들의 우두머리다. 이 소들은 서로에세 이진 메시지를 보내고 있다.

아주 영리한 첩자를 둔 존은 M (1 <= M <= 50,000)개의 메시지에서 첫 bi (1 <= b_i <= 10,000) 비트를 가로 챌수 있었다.

그는 소들이 사용할 만한 일련의 N (1 <= N <= 50,000)개의 코드표를 모았다.

불행히도 , 그는 코드표의 j 첫 cj (1 <= c_j <= 10,000) 비트만을 알았다.

모든 코드표 j 에 대해서 얼마나 많은 코드표가 일치하는 가를 알고 싶어한다. ( 즉 , 코드표 j 에 대해서 , 메시지와 코드표가 얼만큼 첫 이니셜 비트가 있는지를)

이 일이 당신이 할 일이다.

입력의 총 비트 수는 즉 ci 와 bi 의 합은 500,000 을 넘지 않는다.

input:
첫 줄에는 M 과 N 이 주어진다.
다음 M 줄에는 가로 챈 코드 수 bi , 다음 bi 개의 0 혹은 1 이 입력된다.
다음 N 줄에는 코드 표 cj , 다음 cj 개의 0 혹은 1
output:
M 줄이 출력된다. j 번째 줄은 j 번째 코드표가 매치하는 메시지의 수를 출력한다.

*/


using namespace std;
typedef struct _node{
	int finish;
	int pass;
	struct _node * left;
	struct _node * right;
}node;
void make_tree(int num,node *head);

int main(void)
{
	int M,N;
	int result;
	cin >> M>>N;
	node * head = (node*)malloc(sizeof(node));
	node * current;
	node dumy;
	dumy.pass = 0;
	dumy.finish = 0;
	dumy.left = NULL;
	dumy.right = NULL;
	make_tree(M,head);
	for(int i = 0 ; i < N ; i++){
		int c;
		cin>>c;
		current = head;
		result = 0;
		for(int j = 0; j < c ; j++){
			int temp;
			cin>>temp;
			if(temp == 0){
				if(current->left == NULL){
					current = &dumy;
					continue;
				}
				current = current -> left;
			}
			else{
				if(current -> right == NULL){
					current = &dumy;
					continue;
				}
				current = current -> right;
			}
			result += current -> finish;
		}
		result += current -> pass;
		cout<<result<<endl;
	}
}

void make_tree(int num,node *head)
{
	int c = 0;
	node * current = head;
	for(int i = 0 ; i < num ; i++){
		cin>>c;
		current = head;
		for(int j = 0 ; j < c ; j++){
			int temp;
			cin>>temp;
			if(temp == 0){
				if(current -> left == NULL){
					current -> left = (node*)malloc(sizeof(node));
				}
				current = current -> left;
				current->pass++;
			}
			else{
				if(current -> right == NULL){
					current -> right = (node*)malloc(sizeof(node));
				}
				current = current -> right;
				current->pass++;
			}
			if(j == c -1){
				current -> pass--;
				current -> finish++;
			}
		}
	}
}

/*
sol:
trie문제이다.
이진수 패턴을 비교할떄 트리를 사용하여 패터을 비교하는 문제이다.
간단할 줄 알았는데 생각보다 너무 오래걸렷다.
일단 막혔던 부분은 통과하는 부분과 끝나는 부분 
저걸 구분하려고 bool 변수와 if문을 썼다가 너무 복잡해져서 포기하다 인터넷을 찾아보니 
간단하게 그냥 각 노드의 path 갯수를 나타내는 변수를 pass 와 finish로 나누면 되었다.
test개수가 기본이 2000개라서 어디가 틀렸는지 확인 할 수가 없어서 너무 오래걸렸다.
+
백준에서 동일한 문제가 있어서 제출해봤는데 시간 초과가 뜬다. malloc이 문제인듯? 나중에 해결해야 겠다.

*/
