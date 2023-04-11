#include <iostream>
#include <algorithm>
using namespace std;

int length[1000];
int arr[1000];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int result = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int k = 0; k < n; k++) {
        length[k] = 1;  // 끝값
        for (int i = 0; i < k; i++) // k보다 왼쪽에 있는 arr값 순회
        {
            if (arr[i] < arr[k]) // 자기보다 작으면
            {
                length[k] = max(length[k], length[i] + 1);
                // i번째 인덱스에서 끝나는 최장 증가 부분 수열의 마지막 + arr[k]를 추가했을 때의 LIS 길이
                // 추가하지 않은 기존은 length[k]
            }
        }
        result = max(result, length[k]);
    }

    for (int i = 0; i < n; i++)
        cout << length[i] << " ";

    cout << endl;
    cout << n - result;

    return 0;
}