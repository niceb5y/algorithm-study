#include <iostream>
#include <algorithm>

using namespace std;

/*
problem:
덩달이가 길을 걷고 있는데, 산 신령이 나타나서 길에 돈을 쭉 놓으면서

덩달아 돈을 마음 껏 주워가라. 단, 연속해서 3 개의 돈을 줍지는 못한다
불쌍한 덩달이가 가장 많은 돈을 줍도록 여러분이 덩달이를 도와주는 프로그램을 작성하는 것이 문제이다.

input:
첫 번째 라인은 수의 개수를 입력하고 다음 줄에 수 들이 입력된다. 수 는 양의 정수이고 합해서 30000 을 초과 하지 않고 수의 개수는 100 개를 넘지 않는다.

output:
가장 많이 주울수 있는 돈의 액수를 출력한다.
*/

int main(void)
{
	int input[100];
	int array[100][3];
	int num,mx;
	mx = 0;
	cin>>num;
	for(int i = 0  ; i < num ; i++){
		cin >> input[i];
	}
	array[0][0] = input[0];
	array[0][1] = 0;
	array[0][2] = 0;
	array[1][0] = input[0] + input[1];
	array[1][1] = input[1];
	array[1][2] = 0;
	array[2][0] = input[1] + input[2];
	array[2][1] = input[0] + input[2];
	array[2][2] = input[2];
	for(int i = 3 ; i < num ; i++){
		array[i][0] = max(array[i-1][1], array[i-1][2])+ input[i];
		array[i][1] = max(max(array[i-2][0],array[i-2][1]), array[i-2][2]) + input[i];
		array[i][2] = max(max(array[i-3][0],array[i-3][1]),array[i-3][2]) + input[i];
	}
	for(int i = 0 ; i < num ; i++){
		for(int j = 0 ; j < 3 ; j++){
			mx = max(mx,array[i][j]);
		}
	}
	cout<<mx<<endl;
	
}
/*
예전에 풀었던 계단 문제와 유사하게 풀었다.
그 전 계단문제가 최대 2계단밖에 오르지 못하는 문제였다면 이 문제는 최대 3계단 오르는 문제로 생각해서 풀었다.
3계단 오르는 문제로 생각한 이유는 최대값을 구하는 것이기 떄문에 4계단을 오른다는 것은 말이 안된다. 4계단을 오른다면 중간 계단을 무조건 경유할수 있는데 한번에 오른다면 최대값이 될 수 없다.
점화식은
한계단만 오르는 경우는 그 전에 2계단이나 3계단을 오른 경우(그 전에 1계단을 올랐다는 뜻은 이미 연속된 2계단 째라는 의미이다.)
두계단,3계단은 그 전에 어떤 것이든  상관이 없다.
가장 높이 올라간 경우가 max값이 아닐수도 있으므로 전체값을 비교하여 max값을 찾아낸다.
*/
