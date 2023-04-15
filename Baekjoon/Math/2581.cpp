#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    if(x<=1) return false;
    for (int i = 2; i < x; i++)
        if(x % i == 0) return false;
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int M, N; cin >> M >> N;
    int sum = 0;
    vector<int> v;
    for (int i = M; i <= N; i++)
    {
        if(isPrime(i)) 
        {
            sum += i;
            v.push_back(i);
        }
    }
    if(v.empty()) cout << -1;
    else 
    {
        cout << sum << '\n';    
        cout << v[0] << '\n';
    }

    return 0;
}