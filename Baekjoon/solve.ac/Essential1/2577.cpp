#include<iostream>
#include<string>

int main()
{
    int a, b, c; std::cin >> a >> b >> c;
    int count = 0;
    std::string num = std::to_string(a*b*c);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < num.length(); j++)
        {
            if(std::to_string(i) == std::string(1, num[j])) count++;   
        }
        std::cout << count << "\n";
        count = 0;
    }
}