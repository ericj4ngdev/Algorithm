#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

	int N;
	cin >> N;
	int x, y;

    // 좌표 받음
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
    // 이제 소팅하기
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
	}
}