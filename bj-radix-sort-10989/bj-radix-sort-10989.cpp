#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

/* Problem https://www.acmicpc.net/problem/10989 */

/*
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다.
둘째 줄부터 N개의 줄에는 숫자가 주어진다.
이 수는 10,000보다 작거나 같은 자연수이다. // 1~4로도 충분할거같은데 다섯자리수는 하나다.
*/

int N; // 정렬할 수의 개수
int numbers_counting[10001] = {0, };// 1 ~ 10000의 개수를 셀 수 있다. (0도 포함이긴 함)
// int *sorted;

void print_repeat(int num, int rep)
{
    while(rep--) printf("%d\n", num);
}

int main(int argc, char *argv[])
{
    int count;
    int user_input;
    cin >> N;
    count = N;
    // sorted = new int[N];
    while(count--) {
        scanf("%d", &user_input);
        numbers_counting[user_input]++; // 수의 출현 빈도를 세어준다.
    }
    for(int i = 1; i < 10001; i++) {
        if(numbers_counting[i] != 0) print_repeat(i, numbers_counting[i]);
    }
    // for (int i = 1; i < 10001; i++) numbers_counting[i] += numbers_counting[i - 1]; // 누적합으로 바꿔준다. 
    // // => 메모리 초과로 인해 그냥 빈도만큼 반복출력

    /* xxxxx
    // 누적합으로 얻을 수 있는 것은 숫자에 따른 위치를 알수 있게 해준다.
    // 예를 들어 정렬 결과가 0,0,0,2,2,2,2 ... 이면 0의 누적합은 3, 2의 누적합은 4 (1의 누적합은 0)
    // 데이터 배열을 거꾸로 돌면서 정렬된 배열(일 예정)에 차례대로 꽂아준다.
    for(int i = N - 1; i >= 0; i--) {
        sorted[numbers_counting[numbers[i]]-- - 1] = numbers[i];
    }
    for(int i = 0; i < N; i++) {
        printf("%d\n", sorted[i]);
    }
    */
    return 0;
}