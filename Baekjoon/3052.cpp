#include<iostream>
#include<vector>

int main(){
    int v = 0;
    int count[42] = {0};
    
    for (int i = 0; i < 10; i++)
    {
        std::cin >> v;
        count[v%42]++;
    }
    
    int result = 0;
    for(int v : count) {
		if(v > 0) {		
			result++;
		}
	}
    std::cout << result;
}