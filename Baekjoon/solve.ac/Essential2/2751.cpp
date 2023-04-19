#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x; 
    int N; cin >> N;
    vector<int> v; 
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < N; i++)
    {
        cout << v[i] << '\n';
    }

    return 0;
}