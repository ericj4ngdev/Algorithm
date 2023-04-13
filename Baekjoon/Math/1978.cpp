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
        
    int count = 0;
    int N; cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        if(isPrime(x)) count++;
    }
    cout << count;
    return 0;
}