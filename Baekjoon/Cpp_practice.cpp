#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "A : ";
    int A; 
    string str = " ";
    
    cin >> A;
    str = A + '0';
    cout << "str : " << str << "\n";

    // cout << "str입력 : ";
    // cin >> str;
    // A = str[1] - '0';
    // cout << "A : " << A << "\n";
}