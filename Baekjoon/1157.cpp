#include <iostream>
#include <string>


int main(){
	int arr[26] = {0};
	int max = 0;
    int maxidx = 0;
	int count = 0;	

	std::string s;
	std::cin >> s;

    // 대소문자 구분없이 담아야 한다. 65랑 97 모두 담아야 한다. 
	for(int i = 0; i < s.size(); i++)
	{
        if(static_cast<int>(s[i])>=97)
        {
		    arr[static_cast<int>(s[i])-97]++;
        }
        else if(static_cast<int>(s[i]) >= 65 && static_cast<int>(s[i]) < 97)
        {
            arr[static_cast<int>(s[i])-65]++;
        }
	}
	
	// max찾고 max인 인덱스 체크, count++
	for(int i = 0; i < 26; i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
            maxidx = i;
		}
	}

	for(int i = 0; i < 26; i++)
	{
		if(arr[i] == max)
			count++;
	}

	if(count > 1) {
        std::cout << "?";
    }
    else std::cout << static_cast<char>(maxidx+65);          // 아스키코드로 알파벳 출력
}