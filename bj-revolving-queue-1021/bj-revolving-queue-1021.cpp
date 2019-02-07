#include <iostream>
#include <cstring>

/* Problem https://www.acmicpc.net/problem/1021 */

using namespace std;

class deque;

class Node {
    friend class deque;
    private:
    int data;
    Node *prev;
    Node *next;
    public:
    Node(int data)
    {
        this->data = data;
        this->next = this->prev = nullptr;
    }
};

class deque {
    private:
    Node *front;
    Node *back;
    int number;
    public:
    deque()
    {
        front = back = nullptr;
        number = 0;
    }
    bool push_front(int _x)
    {
        if (!number) {
            front = back = new Node(_x);
        }
        else {
            // <---- rear   .....     front---->
            front->next = new Node(_x);
            front->next->prev = front;
            front = front->next;
        }
        ++number;
        return true;
    }
    bool push_back(int _x)
    {
        if(!number) {
            front = back = new Node(_x);
        }
        else {
            back->prev = new Node(_x);
            back->prev->next = back;
            back = back->prev;
        }
        ++number;
        return true;
    }
    bool pop_front(int *_x)
    {
        if (!number) return false;
        *_x = front->data;
        Node *tmp = front;
        front = front->prev;
        delete tmp;
        --number;
        return true;
    }
    bool pop_back(int *_x)
    {
        if (!number) return false;
        *_x = back->data;
        Node *tmp = back;
        back = back->next;
        delete tmp;
        --number;
        return true;
    }
    bool get_front(int *_x)
    {
        if(!number) return false;
        *_x = front->data;
        return true;
    }
    bool get_back(int *_x)
    {
        if(!number) return false;
        *_x = back->data;
        return true;
    }
    int size()
    {
        return number;
    }
    bool empty()
    {
        return !number;
    }
    bool shift_left()
    {
        int t; // 잉여잉여
        if (!number) return false;
        if (number == 1) return true;
        if(!pop_back(&t)) return false;
        return push_front(t);
    }
    bool shift_right()
    {
        int t; // 잉여잉여
        if (!number) return false;
        if (number == 1) return true;
        if(!pop_front(&t)) return false;
        return push_back(t);
    }
    void print()
    {
        cout << "<=== rear front ===>" << endl;
        Node * curr = back;
        for (int i = 0; i < number; i++) {
            cout << curr->data;
            curr = curr->next;
            if (i != number-1 ) cout << '-';
        }
        cout << endl;
    }
};

int main(void)
{
    deque deck;
    // 첫 번째 연산 : pop_front와 동일
    // <==== rear ... front ====>
    int N; // 큐의 크기
    int M; // 뽑아낼 수의 개수
    cin >> N >> M;
    int *willPop = new int[M];// 뽑아내려고 하는 수의 위치
    for (int i = 1; i <= N; i++) {
        deck.push_front(i);
    }
    deck.print();
    for (int i = 0; i < M; i++) {
        cin >> willPop[i];
    }


    delete[] willPop;
    return 0;
}
