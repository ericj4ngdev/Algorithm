#include <iostream>
#include <string>
using namespace std;

int Edit[1001][1001];

int main()
{
    string from, to;

    cin >> from;
    cin >> to;


    // 테이블 생성
    for (int i = 0; i <= from.length(); i++)
        Edit[i][0] = i;

    for (int i = 0; i <= to.length(); i++)
        Edit[0][i] = i;

    for (int i = 1; i <= from.length(); i++)
    {
        for (int j = 1; j <= to.length(); j++)
        {
            // 일치
            if (from[i-1] == to[j-1])
                Edit[i][j] = Edit[i - 1][j - 1];
            else
                Edit[i][j] = min(Edit[i - 1][j - 1] + 1, min(Edit[i][j - 1], Edit[i - 1][j]) + 1);
        }
    }
    cout << Edit[from.length()][to.length()];


    return 0;
}