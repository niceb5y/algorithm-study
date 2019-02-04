#include <iostream>

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
    return 0;
}