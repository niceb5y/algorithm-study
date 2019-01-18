#include <cstdio>
#include <cstring>
#include <algorithm>
/*
#define MAX_SIZE 9
int sorted[MAX_SIZE];

void merge(int *array, int left, int mid, int right)
{
    int i, j, k, l;
    i = left; // 정렬된 왼쪽 리스트에 대한 index
    j = mid + 1; // 정렬된 오른쪽 리스트에 대한 index
    k = left; // 정렬될 리스트에 대한 인덱스

    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            sorted[k++] = array[i++];
        else
            sorted[k++] = array[j++];
    }

    if (i > mid) {
        // 오른쪽 잉여
        for(l = j; l <= right; l++) sorted[k++] = array[l];
    } else {
        // 왼쪽 잉여
        for(l = i; l <= mid; l++)   sorted[k++] = array[l];
    }

    for (l = left; l <= right; l++) {
        array[l] = sorted[l];
    }
}

void mergeSort(int *array, int left, int right)
{
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(array, left, mid); // 앞 정렬
        mergeSort(array, mid + 1, right); // 뒤 정렬
        merge(array, left, mid, right);  // 둘을 합치기
    }
}
*/
using namespace std;

struct n {
    char _word[51];
} WORD[20000];

bool compare(n a, n b)
{
    int lenA  = strlen(a._word);
    int lenB = strlen(b._word);
    if (lenA == lenB) return strcmp(a._word, b._word) < 0;
    return lenA < lenB;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%s", WORD[i]._word);

    sort(WORD, WORD + N, compare); // 아니면 병합 정렬

    printf("%s\n", WORD[0]._word);
    for (int i = 1; i < N; i++) {
        if(strcmp(WORD[i]._word, WORD[i - 1]._word) == 0) continue;
        printf("%s\n", WORD[i]._word);
    }
    return 0;
}
