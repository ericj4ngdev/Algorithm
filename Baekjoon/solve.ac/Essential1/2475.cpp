#include<iostream>
#include<vector>

int main()
{
    std::vector<int> v(5);
    int sum = 0;
    for(int x: v){
        std::cin >> x;
        sum += x*x;
    }
    int c = (sum)%10;
    std::cout << c;
}