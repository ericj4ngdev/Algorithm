#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    deque<int> D;

    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x = 0;
        string cmd; cin >> cmd;
        if(cmd == "push_front"){
            cin >> x;
            D.push_front(x);
        }
        if(cmd == "push_back"){
            cin >> x;
            D.push_back (x);
        }
        if(cmd == "pop_front")
        {
            if(D.empty()) cout << -1 << '\n';
            else
            {
                cout << D.front()  << '\n';
                D.pop_front();            
            }
        }
        if(cmd == "pop_back"){
            if(D.empty()) cout << -1 << '\n';
            else
            {
                cout << D.back()  << '\n';
                D.pop_back();
            }
        }
        if(cmd == "size"){
            cout <<D.size() << '\n';
        }
        if(cmd == "empty"){
            if(D.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if(cmd == "front"){
            if(D.empty()) cout << -1 << '\n';
            else cout << D.front() << '\n';
        }
        if(cmd == "back"){
            if(D.empty()) cout << -1 << '\n';
            else cout << D.back() << '\n';
        }
    }
    


}