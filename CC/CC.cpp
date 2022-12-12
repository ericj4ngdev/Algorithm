#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[1001];	// 노드별 인접한 노드 리스트
bool visited[1001];		// 방문한 노드 배열(초기값 : false)

void dfs(int x) {
	visited[x] = true;	// 방문 체크
	// cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];	// y = x에 인접한 노드
		if (!visited[y]) {		// 방문X -> 호출
			dfs(y);
		}
	}
}

int main() {
	// undirected graph
	int n,m;
	cin >> n >> m;		// 정점수, 엣지수

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int cc = 0;
	for (int i = 1; i <=n ; i++)
	{
		if (!visited[i]) {
			dfs(i);
			cc++;
		}
	}

	cout << cc;

	return 0;
}