#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	
	

	vector<vector<int>> D(n+1, vector<int>(n+1,0));		// n*n 벡터 생성
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++)
	//		cin >> D[i][j];
	//}

	for (int input = 1; input <= m; input++) {
		int i = 0, j = 0;
		while (i == j) { 
			cin >> i >> j; 
		}
		cin >> D[i][j];		
	}

	// 행렬 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
		}
	}

	// 행렬 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}

	return 0;
}

