#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N = 0; cin >> N;
    queue<int> qu;

    for (int i = 0; i < N; i++)
    {
        string cmd; cin >> cmd;
        if(cmd == "push"){
            int x; cin >> x;
            qu.push(x);
        }
        else if(cmd == "pop")
        {
            if(qu.empty()) cout << -1 << '\n';
            else 
            {
                int x = qu.front();
                cout << x << '\n';
                qu.pop();
            }
        }
        else if(cmd == "size")
        {
            cout << qu.size() << '\n';
        }
        else if(cmd == "empty") {
            if(qu.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(cmd == "front")
        {
            if(qu.empty()) cout << -1 << '\n';
            else cout << qu.front() << '\n';            
        }
        else if(cmd == "back")
        {
            if(qu.empty()) cout << -1 << '\n';
            else cout << qu.back() << '\n'; 
        }
    }
    return 0;
}