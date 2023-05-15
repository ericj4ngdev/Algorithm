#include <iostream>
#include <string>
using namespace std;

string Add(string a , string b){
    string ans = "";
	int sum = 0;
    int size = max(a.size(),b.size());

    for (int i = 0; i < size || sum; i++) {
    
    	// sum = 이전 자리수에서 10보다 커져서 넘어온 수
        // 각 num의 수 들을 더하기
		if (a.size() > i) sum += a[i] - '0';
		if (b.size() > i) sum += b[i] - '0';

		// sum의 값을 ans에 저장
		ans += sum % 10 + '0';
        
        // sum의 값이 10을 넘었을 경우, 다음 자리 수로 넘겨주기
		sum /= 10;
	}
	return ans;
}

string CC[105][105];

string C(int n, int m) {
	if (n == m || m == 0) return "1";
    if (CC[n][m] != "") return CC[n][m];
    
    return CC[n][m] = Add(C(n-1, m-1), C(n-1, m));
}

int main(){
	int n, m; cin >> n >> m;
	C(n,m);

    for (int i = CC[n][m].size() - 1; i >= 0; i--) {
		cout << CC[n][m][i];
	}

	return 0;

}