#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int N; cin >> N;
    queue<int> Q;
    for (int i = 1; i <= N; i++)
    {
        Q.push(i);
    }
    // 
    while (Q.size() >= 1)
    {
        if(Q.size() == 1) break;
        Q.pop();
        if(Q.size() == 1) break;
        Q.push(Q.front());
        Q.pop();
    }

    cout << Q.front();    
    return 0;
}