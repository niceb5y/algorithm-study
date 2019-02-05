#include <iostream>
#include <cstring>

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
};

int main(void)
{
    deque deck;
    bool is_successed;
    int x;
    int N;
    char command[11];
    int command_num;
    cin >> N;
    while (N--) {
        cin >> command;
        if (strcmp(command, "push_front") == 0) {
            cin >> command_num;
            is_successed = deck.push_front(command_num);
        }
        else if (strcmp(command, "push_back") == 0) {
            cin >> command_num;
            is_successed = deck.push_back(command_num);
        }
        else if (strcmp(command, "pop_front") == 0) {
            is_successed = deck.pop_front(&x);
            if(!is_successed) cout << -1 << '\n';
            else cout << x << '\n';
        }
        else if (strcmp(command, "pop_back") == 0) {
            is_successed = deck.pop_back(&x);
            if(!is_successed) cout << -1 << '\n';
            else cout << x << '\n';
        }
        else if (strcmp(command, "size") == 0) {
            cout << deck.size() << '\n';
        }
        else if (strcmp(command, "empty") == 0) {
            cout << deck.empty() ? 1 : 0;
            cout << '\n';
        }
        else if (strcmp(command, "front") == 0) {
            is_successed = deck.get_front(&x);
            if(!is_successed) cout << -1 << '\n';
            else cout << x << '\n';
        }
        else {
            // back
            is_successed = deck.get_back(&x);
            if(!is_successed) cout << -1 << '\n';
            else cout << x << '\n';
        }
    }
    return 0;
}
