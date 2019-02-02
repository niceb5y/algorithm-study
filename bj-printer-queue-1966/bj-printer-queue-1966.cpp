#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <functional>

using namespace std;
// <= front(배출구) rear => 
/*
<중요도 - 개수> <중요도 - 개수> ...
*/
int main(void)
{
    int T, N, M, key_priority_number, priority_number, cnt;
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        // N : 문서의 수
        // M : 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue의 어떤 위치에 있는 지 알려줌
        map<int, int, greater<int>> priority_sets; // <중요도, 개수>
        queue<pair<int, bool>> que; // 중요도, 타겟 여부
        for(int i = 0; i < N; i++) {
            cin >> priority_number; // 중요도받음
            if(priority_sets[priority_number]) {
                priority_sets[priority_number]++;
            } else {
                priority_sets[priority_number] = 1;
            }
            if (i == M) {
                key_priority_number = priority_number;
                que.push(make_pair(priority_number, true));
            }
            else
                que.push(make_pair(priority_number, false));
        }
        cnt = 0;
        while(que.size())
        {
            
            int current_priority = que.front().first;
            map<int, int, greater<int>>::iterator iter = priority_sets.begin();
            //cout << cnt << " * : 우선도 : " << iter->first <<" 잔여 : " << iter->second << ", 지금 : " << current_priority << endl;
            if(current_priority < iter->first) {
                //중요도 낮으면 뒤로 보냄
                int a = que.front().first;
                bool b = que.front().second;
                que.pop();
                que.push(make_pair(a, b));
            } else {
                // 중요도 높은건 먼저 함 단, 딱 맞으면 그거 리턴
                //cout << "[[" << que.front().second << endl;
                if (que.front().second == true) break;
                ++cnt; //인쇄
                que.pop();
                if(iter->second > 0) {
                    iter->second--;
                    //cout << "적폐개수 : " << iter->second << endl; // 0도달시 삭제
                    if(iter->second == 0) {
                    //cout << "map 블랙리스트 삭제의 순간" << endl;
                    priority_sets.erase(iter);
                    }
                }
                else {
                    //노필요?
                    // map 리스트에서 삭제 할 것!
                    //cout << "map 블랙리스트 삭제의 순간" << endl;
                    priority_sets.erase(iter);
                }
            }

        }
        cout << cnt+1 << endl;
    }
    return 0;
}
