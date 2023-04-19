#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    int result = 0;
    if(a>b)
    {
        result = a%b;
        if(result == 0) return b;
        else return GCD(b,result);
    }
    else
    {
        result = b%a;
        if(result == 0) return a;
        else return GCD(a,result);
    }
}

int LCM(int a, int b)
{
    int result = 0;
    result = a * b / GCD(a,b);
    return result;
}

int main()
{
    int a,b; cin >> a >> b;
    cout << GCD(a,b) << '\n';
    cout << LCM(a,b) << '\n';
}