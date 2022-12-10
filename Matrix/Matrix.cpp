#include <iostream>
#include <vector>
#define INF 10000000000
using namespace std;

int Matrix(vector<int> d, int n) {
    int i, s, k, minval;
    vector < vector <int> > D(n+1,vector<int>(n+1,0));

    for (i = 1; i <= n; i++) D[i][i] = 0;

    for (s = 1; s <= n - 1; s++) {
        for (i = 1; i <= n - s; i++)
        {
            D[i][i + s] = INF;
            for (k = i; k <= i + s - 1; k++)
                D[i][i + s] = min(D[i][i + s], D[i][k] + D[k + 1][i + s] + d[i - 1] * d[k] * d[i + s]);
        }
    }
    return D[1][n];
}

int main()
{
    int n;          // 행렬 개수
    cin >> n;
    vector<int> d(n+1,0);           // 행렬 사이즈 배열 선언 
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> d[i+1];
    }

    cout << Matrix(d, n) << endl;

    return 0;
}