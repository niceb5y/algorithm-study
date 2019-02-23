#include <iostream>

using namespace std;

string sentence;

int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int N;
    int comp;
    int found;
    do {
        cin >> N;
        if(!N) break;
        string s2; getline(cin,s2);  // fucking c++ buffer problem ㅗㅗ
        comp = 0;
        found = 0;
        for (int i = 0; i < N; i++) {
            getline(cin, sentence);
            // cout << "길이 : " <<  sentence.length() << endl;
            int comp = sentence.find_first_of(" ", found);
            if (comp == -1) {
                comp = sentence.length();
            }
            if (comp > found) found = comp;
        }
        cout << found+1 << endl;
    } while (true);
    return 0;
}
