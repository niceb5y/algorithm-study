#include <iostream>

using namespace std;

int N, M; // 구슬 수, 나눌 그룹 수
int beads[300]; // 구슬들에 적힌 숫자 집합
int min_in_max;
int a_table[301]; // 그룹별구슬개수 정답
int aN = 1; //  그룹별구슬개수 수

bool is_shrink_mid(int mid)
{
    // 그룹핑이 더 적게 나온다면 mid를 줄여야 하고 (left 변화없음, right는 mid 앞으로, mid는 다시 계산)
    // 그룹핑이 더 많이 나온다면 mid를 늘려야 한다. (left는 mid 뒤로, right 변화없음, mid는 다시 계산)
    int sum = 0; // 합계 계산을 카운트
    int nmb_group = 1; // 그룹 개수를 추정
    // 누적합이 mid를 초과한다면 그룹 수를 늘려야 한다.
    for (int i = 0; i < N - 1; i++) {
        if (mid < beads[i]) {
            return false; // 하나가 전체 미드레인지 초과시
        }
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

    int sum = 0, incount = 0;
    for (int i = 0; i < N; i++) {
        sum += beads[i];
        incount++;
        if (sum > min_in_max) {
            sum = beads[i];
            a_table[aN++] = incount - 1;
            incount = 1; // curr
        }
    }
    // 마지막 구슬 그룹
    a_table[aN] = incount;
    int diff = M - aN; // 잉여 그룹으로 분배하기 위함
    for (int i = 1; i <= aN; i++) {
        if (a_table[i] != 1) {
            // 잉여 그룹이 있을경우 적절히 구슬들을 임의의 그룹으로 쪼개 주는데
            while (a_table[i] >= 2 && diff-- >= 1) {
                cout << "1 ";
                a_table[i]--;
            }
        }
        cout << a_table[i] << ' ';
    }
    cout << endl;

    return 0;
}
