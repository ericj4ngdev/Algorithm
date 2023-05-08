#include<iostream>
#include<string>

int main()
{
    std::string str;
    std::getline(std::cin, str);
    int count = 1;
    if(str.empty())
        std::cout << 0;

    // 첫문자가 공백이어도 count는 여전함. 새 문자를 만날때까진 0개...
    
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ') count++;
    }   
    

    if(str[0] == ' ')
        count--;
    if(str[str.length()-1] == ' ')
        count--;



    std::cout << count;
    
}