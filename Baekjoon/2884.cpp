#include<iostream>

int main(){
    int H,M; std::cin >> H >> M;
    M -= 45;
    
    if (M<0)
    {
        M += 60;
        H--;
        if(H<0) H+=24;        
    }
    std::cout << H << " " << M;
}