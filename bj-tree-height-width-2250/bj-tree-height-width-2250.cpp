#include <iostream>

using namespace std;

int N; // 노드 수

pair<int, int> *tree; // 인덱스 : 자기 자신의 번호, pair<int, int> 자식 2개의 번호

int row = 0;    // 열과 레벨 (최대 / 최소)
int *minRow;    // 열거리 최솟값
int *maxRow;    // 열거리 최댓값
int *checkRoot; // 루트 노드 체크용

void inorder(int currentNode, int level)
{
    // 왼쪽 자식 노드 방문
    if (tree[currentNode].first != -1)
        inorder(tree[currentNode].first, level + 1);

    // 중앙 노드 방문
    if (minRow[level] == -1 && maxRow[level] == -1)
    {
        minRow[level] = row;
        maxRow[level] = row;
    }
    else
    {
        minRow[level] = minRow[level] > row ? row : minRow[level];
        maxRow[level] = maxRow[level] < row ? row : maxRow[level];
    }
    row++;
    // 오른쪽 노드 방문
    if (tree[currentNode].second != -1)
        inorder(tree[currentNode].second, level + 1);
}

int main(void)
{
    int curr, left, right;
    cin >> N;
    tree = new pair<int, int>[N + 1]; // 1~N
    minRow = new int[N + 1];          // minRow[레벨] = 가장 낮은 열
    maxRow = new int[N + 1];          // maxRow[레벨] = 가장 높은 열
    for (int i = 0; i < N; i++)
    {
        minRow[i + 1] = -1;
        maxRow[i + 1] = -1;
        cin >> curr >> left >> right;
        tree[curr] = make_pair(left, right);
    }

    // 루트 노드가 어떤지 파악한다.
    int Root = 1;

    checkRoot = new int[N + 1];
    for (int i = 1; i <= N; i++)
    {
        checkRoot[i] = -1;
    }
    for (int i = 1; i <= N; i++)
    {
        if (tree[i].first != -1)
            checkRoot[tree[i].first] = 1;
        if (tree[i].second != -1)
            checkRoot[tree[i].second] = 1;
    }

    // 자식으로 택해지지 않은 노드는 부모 노드이다.
    for (int i = 1; i <= N; i++)
    {
        if (checkRoot[i] == -1)
        {
            Root = i;
        }
    }

    inorder(Root, 1); // 루트 노드부터 시작해서 중위 순회를 한다.

    int ansLvl = 0;
    int maxLength = -1;

    // 제일 너비가 넓은 레벨을 구한다.
    for (int i = 1; i <= N; i++)
    {
        if (maxLength < maxRow[i] - minRow[i] + 1)
        {
            ansLvl = i;
            maxLength = maxRow[i] - minRow[i] + 1;
        }
    }
    cout << ansLvl << ' ' << maxLength << endl;
    return 0;
}
