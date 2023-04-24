#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T; std::cin >> T;
    for (int k = 0; k < T; k++)
    {
        int H,W,N; std::cin >> H >> W >> N;
        std::vector<int> v1;
        std::vector<std::vector<int>> v(H, std::vector<int>(W,0));
        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < H; j++)
            {
                v[j][i] = (j + 1) * 100 + (i + 1);
                // 순서는 j+i로 알수 있다. 
                v1.push_back(v[j][i]);
            }            
        }
        cout << v1[N-1] << '\n';
    }
    return 0;
}