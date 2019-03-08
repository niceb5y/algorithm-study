#include <iostream>

using namespace std;

int N, M; // 구슬 수, 나눌 그룹 수
int beads[300]; // 구슬들에 적힌 숫자 집합
int min_in_max;

bool is_shrink_mid(int mid)
{
    // 그룹핑이 더 적게 나온다면 mid를 줄여야 하고 (left 변화없음, right는 mid 앞으로, mid는 다시 계산)
    // 그룹핑이 더 많이 나온다면 mid를 늘려야 한다. (left는 mid 뒤로, right 변화없음, mid는 다시 계산)
    int sum = 0; // 합계 계산을 카운트
    int nmb_group = 1; // 그룹 개수를 추정
    // 누적합이 mid를 초과한다면 그룹 수를 늘려야 한다.
    for (int i = 0; i < N - 1; i++) {
        sum += beads[i];
        if ( sum > mid ) {
            nmb_group++;
            sum = beads[i];
        }
    }
    // 마지막 구슬
    if (sum + beads[N - 1] > mid) nmb_group++;

    if (nmb_group > M) return false;
    return true;
    // 늘린 수의 그룹이 M초과시 false를 리턴
}

// 매개변수식 탐색을 사용하였다.
void parametric_search()
{
    int left = 0;
    int right = N * 100; // 구슬에 써진 최대의 수 100 * 구슬 개수
    int mid; // [그룹 내 최댓값]의 최솟값을 mid로 상정하고 그룹핑이 몇개 나오나 세본다.

    min_in_max = right;

    while (left <= right) {
        mid = (left + right) / 2;
        if (is_shrink_mid(mid)) {
            right = mid - 1;
            if (mid < min_in_max) min_in_max = mid;
        } else {
            left = mid + 1;
        }
    }
    // cout << "미드(최소 최댓값) : " << min_in_max << endl;
}

int main(void)
{
    cin >> N >> M;
    for  (int i = 0; i < N; i++) cin >> beads[i];

    parametric_search();

    cout << min_in_max << endl;

    // 사혼의 구슬조각들
    // 그냥 각자 최댓값만 안 넘게 해서 출력함.
    // 어차피 저지 되겠지 뭐 정답이 여러개일수도 있음
    int sum = 0, incount = 0;
    for (int i = 0; i < N; i++) {
        sum += beads[i];
        if (sum > min_in_max) {
            sum = beads[i];
            cout << incount << ' ';
            incount = 0;
        }
        incount++;
    }
    // 마지막 구슬
    cout << incount << endl;
    

    return 0;
}
