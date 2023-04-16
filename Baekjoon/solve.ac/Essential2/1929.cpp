#include<bits/stdc++.h>
using namespace std;

void Eratos(int m, int n)
{
    if (n <= 1) return;
    bool* PrimeArray = new bool[n + 1];
    PrimeArray[1] = false;
    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true;

    for (int i = 2; i * i <= n; i++)
    {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
    }
    for(int i = m; i <= n; i++)
    {
        if(PrimeArray[i]) cout << i << '\n';
    }
    
    delete[] PrimeArray;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int M, N; cin >> M >> N;
    Eratos(M,N);  

    return 0;
}