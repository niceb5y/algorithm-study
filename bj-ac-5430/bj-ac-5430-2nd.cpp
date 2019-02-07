#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    cin.get();
    while(T--) {
        string RDcommand;
        getline(cin, RDcommand);
        int n;
        cin >> n;
        cin.get();
        deque<int> deq(n);
        bool reversed = false, has_error = false;
        for (auto &i : deq) {
            cout << "★" << cin.get() << "○" << endl;
            cin >> i;
        }
        cin.ignore(2, '\n');
        // test
        for (int i = 0; i < n; i++) {
            cout << deq[i] << endl;
        }
    }
    return 0;
}