#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int N = 0, K = 0;
    int count = 0;
    cin >> N >> K;
    queue<int> Q;
    queue<int> P;    
    
    for(int i = 0; i < N; i++)
    {
        Q.push(i+1);
    }

    while(!Q.empty())
    {
        int x = Q.front();
        count++;
        if(count == K){
            Q.pop();
            P.push(x);
            count = 0;
        }
        else{            
            Q.pop();
            Q.push(x);
        }
        
    }
    cout << "<";
    while(!P.empty())
    {        
        if(P.size() == 1)
        {
            cout << P.front();
        }
        else cout << P.front() << ", ";
        P.pop(); 
    }
    cout << ">";

    return 0;
}