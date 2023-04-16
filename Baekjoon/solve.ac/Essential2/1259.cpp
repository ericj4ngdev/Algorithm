#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(int num)
{
    string str = to_string(num);
    deque<char> D;
    for (int i = 0; i < str.length(); i++)
    {
        D.push_back(str[i]);
    }
    
    for (int i = 0; i < (int)(str.length()/2); i++)
    {
        if(!D.empty())
        {
            if(D.back() == D.front())
            { 
                D.pop_back();
                D.pop_front();
            }
            else return false;
        }
    }
    return true;    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(true)
    {
        int x; cin >> x;
        if( x == 0 ) break;
        if(ispalindrome(x)) cout << "yes" << '\n';
        else cout << "no" << '\n';        
    }
    return 0;
}