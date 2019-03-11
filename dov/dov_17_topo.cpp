#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
problem
그래프의 정보가 주어질 때 위상 정렬하는 프로그램을 작성하는 것이 문제이다.
input:
입력의 첫 줄은 정점의 수(100 이하의 정수) 를 , 다음 줄 부터는 간선의 정보가 정점의 쌍으로 입력 되어 있다. 입력의 끝은 EOF 이다.
output:
답이 여러개인 경우 사전식 순서로 먼저 나오는 것을 출력하고 , 사이클이 존재하면 impossible 을 출력한다.
test
*/

typedef vector<int> vi;
vi array[101];
bool isvisit[101];
bool isfinish[101];
stack<int> st;
int dfs(int start);
int indgree[101];

int main(void)
{
	fill(indgree,indgree+101,0);
	fill(isvisit,isvisit+101,false);
	fill(isfinish,isfinish+101,false);
	int N;
	cin>>N;
	int s,e;
	while((s=cin.get()) != EOF){
		cin>>s>>e;
		array[s].push_back(e);
		indgree[e]++;
	}
	int start;
	for(int i = 1; i <= N ; i++){
		if(indgree[i] == 0)
			start = i;
	}
	
	
	if(dfs(start) ){
		cout<<"impossible"<<endl;
		return 0;
	}
	st.push(start);
	for(int i = 0 ; i < N ; i++){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	
}

int dfs(int start)
{
	sort(array[start].begin(),array[start].end(), greater<int>()); //stack에 들어가므로 사전식으로 나오려면 dfs를 역순으로 해야한다.
	isvisit[start] = true;
	for(int i = 0 ; i < array[start].size() ; i++){
		if(array[start].at(i) == start){ //array.size()가 0인경우에도 왜인지는 모르겠는데 for문이 돈다 그거 방지용
			break;
		}
		//cout<<start<<" "<<array[start].at(i)<<" "<<isvisit[array[start].at(i)]<<" "<<isfinish[array[start].at(i)]<<endl;
		if(isvisit[array[start].at(i)] == false){
			if(dfs(array[start].at(i)) == 1){
				return 1;
			}
			st.push(array[start].at(i));
		}
		else if(isfinish[array[start].at(i)] == false) //cycle 존재 여부 확인 용이다. 
			return 1;
	}
	isfinish[start] = true;
	return 0;
}
/*
위상 정렬문제를 dfs로 풀어보았다.
저번에 풀었던 indgree방식이 생각하기가 쉬운편이고 문제 풀이가 편하지만 코드가 길어지게 된다.
반면에 dfs는 확실히 코드가 짧아지는 느낌이 있다,.(내가 너무 이상하게 풀어서 나는 비슷하게 나온거 같다)
그냥 dfs하면서 stack에 집어넣으면 되니깐....
근데 cycle 판별이 너무 복잡하다. 변수를 하나 더 사용해야 한다. 그런 조건 따지는부분을 제외하면 dfs로도 풀만한거 같다. 


*/
