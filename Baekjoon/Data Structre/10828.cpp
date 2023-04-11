#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	int N = 0;	cin >> N;
	
	stack<int> st;

	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;
		if(cmd == "push"){
			int x; cin >> x;
			st.push(x);
		}
		else if(cmd == "pop"){
			if(st.empty()) cout << -1 << endl;
			else
			{
				int x = st.top();
				cout << x << endl;
				st.pop();
			}
		}
		else if(cmd == "size"){
			cout << st.size() << endl;
		}
		else if(cmd == "empty"){
			if(st.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if(cmd == "top"){
			if(st.empty()) cout << -1 << endl;
			else cout << st.top() << endl;
		}
	}
	
	return 0;
}