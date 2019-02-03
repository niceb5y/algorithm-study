#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int _data) {
        data = _data;
    }
};

class LL {
    public:
    Node *start;
    Node *curr; // end of LL (죽이기 전 한정)
    int total;
    LL() {
        total = 0;
    }
    void push_back(int _data)
    {
        if(!total) {
            start = curr = new Node(_data);
            curr->next = start;
        }
        else {
            curr->next = new Node(_data);
            curr->next->next = start;
            curr = curr->next;
        }
        total++;
    }
    int gotoKill(int len) {
        // 킬후 한칸 후퇴
        total--;
        Node *tmp;
        int len_back = len - 1;
        while(len_back--) {
            curr = curr->next;
        }
        tmp = curr;
        int ret = tmp->next->data;
        curr->next = curr->next->next;
        //delete tmp->next; // 시간절약상 회수 생략
        return ret;
    }
};

int main(void)
{
    int N, M;
    cin >> N >> M;
    LL ll = LL();
    for(int i = 1; i <= N; i++) {
        ll.push_back(i);
    }
    cout << '<';
    // M만큼 이동해서 죽.인.다.
    while(ll.total) {
        // curr 이동후 킬
        cout << ll.gotoKill(M);
        if(ll.total >= 1) cout << ", ";
    }
    cout << ">\n";
    return 0;
}
