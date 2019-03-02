#include <iostream>
#include <map> // 넘버로 노드를 찾기 위해서

using namespace std;

int N; // 노드 수
map< int, pair<int, int> > tree;
// map<현재 노드 번호, pair<왼쪽 노드 번호, 오른쪽 노드 번호>>

typedef struct  {
    
} stree;

stree *tree2;

int row = 0; // 열과 레벨 (최대 / 최소)
int *minRow;
int *maxRow;
int *checkRoot;

int inorder(int currentNode, int level) {
    // 왼쪽 자식 노드 방문
    if (tree[currentNode].first != -1)
        inorder(tree[currentNode].first, level + 1);
        
    // 현재 노드 방문 (방문 시에 바이어스를 민다.) 
    //cout << row << "열 " << "방문 : " << currentNode << " 레벨 : " << level << endl;
    if (minRow[level] == -1 && maxRow[level] == -1) {
        minRow[level] = row;
        maxRow[level] = row;
    } else {
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
    minRow = new int[N + 1]; // minRow[레벨] = 가장 낮은 열
    maxRow = new int[N + 1]; // maxRow[레벨] = 가장 높은 열
    for (int i = 0; i < N; i++) {
        minRow[i + 1] = -1;
        maxRow[i + 1] = -1;
        cin >> curr >> left >> right;
        tree.insert(make_pair(curr, make_pair(left, right)));
    }
    
    // 루트 노드 파악.
    int Root = 1;
    
    checkRoot = new int[N+1];
    for (int i = 1; i <= N; i++) {
        checkRoot[i] = -1;
    }
    for (int i = 1; i <= N; i++) {
        if(tree[i].first != -1)
            checkRoot[tree[i].first] = 1;
        if(tree[i].second != -1)
            checkRoot[tree[i].second] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (checkRoot[i] == -1) {
            Root = i;
        }
    }
    
    
    inorder(Root, 1); // 첫번째 인자를 1로 썼지만 원래는 루트 노드를 알아서 찾아야 한다. ru
    int ansLvl = 0;
    int maxLength = -1;
    for (int i = 1; i <= N; i++) {
        //cout << maxRow[i] - minRow[i] + 1 << endl;
        if ( maxLength < maxRow[i] - minRow[i] + 1 ) {
            ansLvl = i;
            maxLength = maxRow[i] - minRow[i] + 1;
        }
    }
    cout << ansLvl << ' ' << maxLength << endl;
    /* 
    for(auto it = tree.begin(); it != tree.end(); it++) {
        cout << it->first << " : " << it->second.first << ", " << it->second.second << endl;
    }
    */
    return 0;
}
