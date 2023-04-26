#include<bits/stdc++.h>
using namespace std;

string change(int N, int B){
    string sum;
    int n = N;
    int k;
    while(n>=B)
    {
        k = n%B;
        if(k>=10) sum.push_back(static_cast<char>(k+55));        
        else sum.push_back(static_cast<char>(k+48));   
        n = n/B;
    }
    if(n>=10) sum.push_back(static_cast<char>(n+55)); 
    else sum.push_back(static_cast<char>(n+48));
    reverse(sum.begin(), sum.end());
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    int B; 
    cin >> N >> B;
    cout << change(N,B) << "\n";

    return 0;
}
