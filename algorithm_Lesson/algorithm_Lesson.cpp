// algorithm_Lesson.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int search(int a[], int n, int x);

int main()
{
	int result = 0;
	int a[7] = { 1,2,3,4,5,6,7 };
	int x = 0;

	cin >> x;

	result = search(a, 7, x);

	cout << "찾으려는 값 "<< x <<"은(는) " << result + 1 << "번째에 있습니다.";

	return 0;
}
 

int search(int a[], int n, int x)
{
	int l, r, m;
	l = 0;
	r = n - 1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (a[m] == x)return m;
		else if (a[m] > x)r = m - 1;
		else l = m + 1;
	}
	return -1;
}