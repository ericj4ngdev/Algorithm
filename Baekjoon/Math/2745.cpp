#include<bits/stdc++.h>
using namespace std;

int change(string N, int B){
    int k = N.size();   
    int sum = 0;
    int n = 0;
    for (int i = 0; i <= k; i++)
    {
        if(static_cast<int>(N[i]) >= 48 && static_cast<int>(N[i]) <= 57)
        {
            n = N[i]-'0';
        }
        else if(static_cast<int>(N[i]) >= 65)
        {
            n = static_cast<int>(N[i])-55;
        }
        sum += n * pow(B,k-i-1);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string N;
    int B; 
    cin >> N >> B;

    cout << change(N,B) << endl;

    return 0;
}