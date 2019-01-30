#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *fr;
    Node *rf;
    Node(int x) {
        data = x;
        fr = nullptr;
        rf = nullptr;
    }
};

class Queue {
    private:
    Node *front;
    Node *rear;
    int size;
    public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    void push(int x)
    {
        if (!size) {
            front = new Node(x);
            rear = front;
        } else {
            Node *temp = rear;
            rear = new Node(x);
            temp->fr = rear;
            rear->rf = temp;
        }
        ++size;
    }
    int pop(void)
    {
        if (!size) return -1;
        Node *tmp = front;
        int ret  = front->data;
        if (size == 1) {
            size = 0;
            front = rear = nullptr;
            delete tmp;
            return ret;
        }
        size--;
        front = front->fr;
        delete tmp;
        return ret;
    }
    int size2(void) {
        return size;
    }
    int empty(void) {
        return !size;
    }
    int front2(void) {
        if(size)
        return front->data;
        else
        return -1;
    }
    int back(void) {
        if(size)
        return rear->data;
        else
        return -1;
    }
    void print(void)
    {
        cout << size << " 타임즈" << endl;
        int times = size;
        Node *curr = front;
        while(times--)
        {
            cout << curr->data << endl;
            curr = curr->fr;
        }
    }
};


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    char command[6];
    int arg;
    Queue que;
    cin >> N;
    while(N--) {
        cin >> command;
        if(command[1] == 'u') {
            // push
            cin >> arg;
            que.push(arg);
        }
        else if(command[1] == 'o') {
            // pop
            cout << que.pop() << '\n';
        }
        else if(command[1] == 'i') {
            // size
            cout << que.size2() << '\n';
        }
        else if(command[1] == 'm') {
            // empty
            cout << que.empty() << '\n';
        }
        else if(command[1] == 'r') {
            // front
            cout << que.front2() << '\n';
        }
        else {
            // back
            cout << que.back() << '\n';
        }
    }
    return 0;
}
