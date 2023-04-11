#include<bits/stdc++.h>
using namespace std;

string solve(string str)
{
    stack<char> st;
    
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(') st.push('(');
        else{
            if(st.empty()) return "NO";
            st.pop();
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    while (T--)
    {   
        string cmd; 
        cin >> cmd;
        cout << solve(cmd) << endl;
    }

    return 0;
}