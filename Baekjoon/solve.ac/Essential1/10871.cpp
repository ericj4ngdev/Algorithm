#include<iostream>

int main()
{
    int N,X; std::cin >> N >> X;
    int input; 
    for (int i = 0; i < N; i++)
    {
        std::cin >> input;
        if(input < X) std::cout << input << " ";
    }
}