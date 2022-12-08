#include <iostream>
#include <vector>
#define INF 10000
using namespace std;


int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int Matrix(vector<int> d, int n) {
    int i, s, k, minval;
    vector < vector <int> > D(n+1,vector<int>(n+1,0));

    for (i = 1; i <= n; i++) D[i][i] = 0;

    for (s = 1; s <= n - 1; s++) {
        for (i = 1; i <= n - s; i++) {
            minval = INF;
            for (k = i; k <= i + s - 1; k++)
                minval = min(minval, D[i][k] + D[k + 1][i + s] + d[i - 1] * d[k] * d[i + s]);
            D[i][i + s] = minval;
        }
    }
    return D[1][n];
}

int main()
{
    int n;          // 행렬 개수
    cin >> n;
    vector<int> d(n+1,0);           // 행렬 사이즈 배열 선언 
    for (int i = 0; i <= n; i++)
    {
        cin >> d[i];
    }

    cout << "최소 행렬 연산 비용 : " << Matrix(d, n) << endl;

    return 0;
}


/*
3
5 1 7 8
*/
