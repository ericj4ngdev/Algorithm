#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int N,M,v; cin >> N;
    vector<int> v1;
    for (int i = 0; i < N; i++)
    {
        cin >> v;
        v1.push_back(v);
    }
    sort(v1.begin(), v1.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> v;
        cout << binary_search(v1.begin(),v1.end(), v) << '\n';
    }

    return 0;
}