#include <iostream>

using namespace std;

int N, M;       // 구슬 수, 나눌 그룹 수
int beads[300]; // 입력 데이터 : 구슬들에 적힌 숫자 집합
int answer;     // 정답!

bool decision(int x)
{
    /*
    예를들어
    |----------(mid)-----x*---|
    상황에서 mid가 x*보다 큰지 작은지 판별해야 한다.
    여기서는 mid 뜻이 최소인 최댓값이므로 그룹별 구슬들의 누적합을 계산해 본다.
    */
    int sum = 0;       // 그룹당 누적합 저장용
    int nmb_group = 1; // 나눌 그룹 개수 (기본값 : 1)이고 누적합이 mid를 넘으면 이 변수가 증가된다.
    for (int i = 0; i < N - 1; i++)
    {
        // 마지막 구슬을 빼는 이유는 끝 원소 (비어있는) 옆에 그룹핑이 또 되지 않게 하기 위함이다.
        if (x < beads[i])
        {
            // 구슬 하나가 최소 최댓값을 상회한다면
            return false; // 일단 최소 최댓값은 이 값 이상일 것이므로 더 이상 어떻게 할 수 없다.
        }
        sum += beads[i]; // 구슬의 합을 누적시켜 나가면서
        if (x < sum)
        {
            // 누적합이 최소 최댓값을 넘는 순간 그룹을 증가시킴
            nmb_group++;
            sum = beads[i]; // 새로운 그룹의 시작 구슬의 숫자로 시작하기
        }
    }

    // 마지막 구슬 체크
    if (x < sum + beads[N - 1])
        nmb_group++;

    if (nmb_group > M)
        return false; // 주어진 그룹보다 잘게 나눠지면 이 최소 최댓값은 더 늘어나야 한다.
    return true;      // 좀 더 줄여봐도 될 것 같다.
}

// 매개변수식 탐색을 사용하였다.
void parametric_search(int max)
{
    // low : 구슬을 안 끼웠을 때...
    // high : 구슬에 써진 모든 수의 합
    int low = 0;
    int high = max; // 모든 구슬의 합을 초기 high 값으로 설정
    int mid;        //  파라메트릭 서치의 시작 (여기서 mid는 적절히 나눴을 때 최소인 최댓값이다)
    answer = max;   //우선 최댓값을 정답으로 설정하기

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (decision(mid))
        {
            high = mid - 1;
            // 결정함수에 물어보기
            if (mid < answer)
                answer = mid; // 정답을 갱신한다.
        }
        else
        {
            low = mid + 1;
        }
    }
}

int main(void)
{
    cin >> N >> M;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> beads[i];
        max += beads[i];
    }
    parametric_search(max);

    cout << answer << endl;

    // 최댓값을 안넘을때까지 자름
    int sum = 0;
    int cnt = 0;
    int nsum = 0;
    int rest_groups = M;

    // 그룹 수 = 구슬 수
    if (N == M)
    {
        while (M--)
            printf("1 ");
        printf("\n");
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        ++cnt;
        sum += beads[i];
        if (answer < sum)
        {
            // 그룹 쪼개기
            printf("%d ", cnt - 1);
            rest_groups--;
            nsum += cnt - 1;
            sum = beads[i];
            cnt = 1;
        }
    }
    // 남은 그룹 수가 1이면 그냥 땜빵하기
    if (rest_groups == 1)
    {
        printf("%d", N - nsum);
    }
    // 남은 그룹 수랑 구슬이랑 일치시, 쭈욱 1로 때우기
    else if (rest_groups == N - nsum)
    {
        while (rest_groups--)
            printf("1 ");
    }
    else
    {
        // 남은 구슬 수 > 남은 그룹 수이면 (그 반대의 경우는 있을 수 없을 것이다.)
        // 1개 1개.... (나머지) 이렇게 묶는다.
        int ncnt = 0;
        while (rest_groups-- > 1)
        {
            ncnt++;
            printf("1 ");
        }
        printf("%d ", N - ncnt - nsum + 1);
    }
    printf("\n");
    return 0;
}
