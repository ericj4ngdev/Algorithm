#include<iostream>
#include<algorithm>
using namespace std;

int GDC(int a, int b)
{
    int c = a%b;
    if(c == 0) return b;
    else return GDC(b,c);
}
void DC(int a){
    for (int i = 1; i < a; i++)
    {
        if(a%i == 0) cout << i << endl;
    }    
}

int main(){
    int n; cin >> n;
    int a,b,c=0; 
    if(n == 2)
    {
        cin >> a >> b;
        DC(GDC(a,b));
        cout << GDC(a,b) << endl;
    }
    else if(n == 3)
    {
        cin >> a >> b >> c;
        int result = min({GDC(a,b),GDC(b,c),GDC(a,c)});
        DC(result);
        cout << result;
    }   

    return 0;
}