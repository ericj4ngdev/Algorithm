#include <iostream>
#include <vector>

using namespace std;

// 0 = 일 안하는 경우
// 1 = 일 하는 경우
// N일
// 일 안하면 둘 중에 좋은 거
// 일 하면 일 안하는거 + 오늘 받는 거

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> A(n);            // 일급 배열

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	// memoization
	vector < vector <int> > D(n + 1, vector<int>(2, 0));     

	D[1][0] = 0;
	D[1][1] = A[0];
	for (int i = 2; i <= n; i++)
	{
		D[i][0] = max(D[i - 1][0], D[i - 1][1]);
		D[i][1] = D[i - 1][0] + A[i - 1];
	}

	cout << max(D[n][0], D[n][1]);

	return 0;
}