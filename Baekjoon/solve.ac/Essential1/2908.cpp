#include<iostream>
#include<string>
#include<math.h>

int reverse(int A){
    int temp = 0;
    int ta = 0;

    std::string a = std::to_string(A);
    for (int i = 0; i < a.length(); i++)
    {
        temp = A%10;
        ta += temp*pow(10,a.length()-i-1); 
        A = A/10;
    }
    return ta;
}

int main(){
    int A, B;
    std::cin >> A >> B;

    int rA = reverse(A);
    int rB = reverse(B);
    rA > rB ? std::cout << rA : std::cout << rB;
    
}