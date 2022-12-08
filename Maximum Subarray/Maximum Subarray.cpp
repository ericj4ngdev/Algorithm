#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }
        int psum = 0;
        int max_val = -999;
        for (int i = 0; i < N; i++) {
            psum = max(0, psum) + arr[i];
            max_val = max(max_val, psum);
        }
        cout << max_val << endl;
    }

    return 0;
}