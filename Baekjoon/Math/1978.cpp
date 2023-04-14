#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
        
    int count = 0;
    
    int N; cin >> N;
    while(N>0)
    {
        // 1과 자기자신만 나누어 떨어지는 수
        // 나머지와는 나누어 떨어지지 않는다.   
        int x; cin >> x;
        if(x == 2) count++;
        for (int i = 2; i < x; i++)
        {
            // 소수 X
            if(x % i == 0) break; 
            if(i == x-1) count++;
            // 소수 O, 반복문 계속 진행
            // 끝까지 도달하면 소수임을 확인
        }
        N--;
    }
    cout << count;
    return 0;
}