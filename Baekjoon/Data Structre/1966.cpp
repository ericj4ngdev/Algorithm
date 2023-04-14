#include<bits/stdc++.h>
#include<algorithm> 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    int T = 0; cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N = 0, M = 0; cin >> N >> M;
        int max = 0;
        queue<int> Q;
        vector<int> list(N);
        int k = 0; 
        for (int j = 0; j < N; j++)
        {
            int k = 0; cin >> k;
            Q.push(k);
            list[j] = k;             
        }
        cout << list[M] << endl;        // M번째 원소 저장
        // 중요도 검사. 최대값 점검    
        for (int j = 0; j < N; j++)
        {
            if(list[j]>max) max = list[j];
        } 
        // 내림차순
        sort(list.begin(), list.end(),greater<int>());
        // max = max_element(list.begin(), list.end());
        i = 0;
        // cout << "max : " << max << endl;
        while (!Q.empty())
        {
            if(Q.front() < max)
            { 
                Q.push(Q.front());
                Q.pop();
            }
            else 
            {
                if(Q.front() == list[M]) cout << i;
                Q.pop();
                i++;
                max = list[i];
            }
        }
    }
    return 0; 
}
