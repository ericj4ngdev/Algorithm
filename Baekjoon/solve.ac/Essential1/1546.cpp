#include<iostream>
#include<vector>

int main(){

    int N, M = 0; std::cin >> N;
    float grade, mean, sum = 0;

    std::vector<float> v;
    for (int i = 0; i < N; i++)
    {
        std::cin >> grade;
        v.push_back(grade);
    }
    
    // 최대값 M 고르기
    for(int i = 0 ; i < N; i++)
    {
        if(v[i] > M) M = v[i];
    }
    
    // 점수 조작 및 sum 구하기
    for(int i = 0 ; i < N; i++)
    {
        v[i] = v[i]/M*100;
        sum += v[i];
    }

    // 평균 구하는 공식
    if(N == 0) mean = 0;
    else mean = sum / N;

    std::cout << mean;
}