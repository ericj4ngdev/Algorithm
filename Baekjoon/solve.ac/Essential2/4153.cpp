#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int a,b,c; 
    while(true){
        cin >> a >> b >> c;
        
        if(a==0 && b==0 && c==0) break;
        
        if((pow(a,2) == pow(b,2) + pow(c,2))||
            (pow(b,2) == pow(a,2) + pow(c,2))||
            (pow(c,2) == pow(a,2) + pow(b,2)))
            {
                cout << "right" << endl;
            }
        else cout << "wrong" << endl;
    }
    return 0;
}