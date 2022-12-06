#include <iostream>
#include<vector>
using namespace std;

// Variable to keep track of time
int Time = 1;

// Function to perform DFS starting from node u
void dfs(int u, vector<vector<int>> aList, vector<int>& pre, vector<int>& post, vector<int>& vis)
{

	// Storing the pre number whenever
	// the node comes into recursion stack
	pre[u] = Time;		// 방문한 시간 기록

	// Increment time
	Time++;
	vis[u] = 1;		// 방문한 노드 u 

	for (int v : aList[u])		// 각 노드u마다 인접 노드v 순회
	{
		if (vis[v] == 0)		// 방문여부 확인
			dfs(v, aList, pre, post, vis);	// 재귀
	}

	// Storing the post number whenever
	// the node goes out of recursion stack
	post[u] = Time;
	Time++;
}

// Driver Code
int main()
{

	// Number of nodes in graph
	int n = 6;

	// Adjacency list
	vector<vector<int>> aList(n + 1);

	vector<int> pre(n + 1);
	vector<int> post(n + 1);

	// Visited array
	vector<int> vis(n + 1);

	// Edges
	aList[1].push_back(2);
	aList[1].push_back(3);

	aList[2].push_back(1);
	aList[2].push_back(4);

	aList[3].push_back(5);
	aList[3].push_back(1);
	aList[3].push_back(4);

	aList[4].push_back(2);
	aList[4].push_back(3);

	aList[5].push_back(3);
	aList[5].push_back(6);

	aList[6].push_back(5);

	// DFS starting at Node 1
	dfs(1, aList, pre, post, vis);

	// Number of nodes in graph
	for (int i = 1; i <= n; i++)
		cout << "Node " << i << " Pre number "
		<< pre[i] << " Post number "
		<< post[i] << endl;

	return 0;
}