#include<iostream>
#include<algorithm>

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
}

int main(){
    int arr[26];
    std::fill(arr, arr+26, -1); // -1로 초기화

    std::string S;
    std::cin >> S;
    
    for (int i = 0; i < S.size(); i++)
    {
        if(arr[static_cast<int>(S[i]) - 97] == -1)
            arr[static_cast<int>(S[i]) - 97] = i;
    }
    
    print(arr,26);

    return 0;
}