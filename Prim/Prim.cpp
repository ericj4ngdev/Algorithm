#include <iostream>
// #include <bits/stdc++.h>
#include <cstdio>

using namespace std;

class Triple
{
public:
    int a, b, w;        // 노드 a,b(a->b) ,엣지 웨이트 w
};

// 트리플을 저장하는 priority Queue를 만든다.
class PriorityQueue
{
public:
    int n = 0;      // 노드 수
    Triple Arr[1000];
    PriorityQueue();
    Triple Delete();
    void Insert(Triple x);
    int isEmpty();

};

PriorityQueue::PriorityQueue()
    : n(0)          // 생성자
{
    
}
int PriorityQueue::isEmpty()
{
    return n == 0;
}
void PriorityQueue::Insert(Triple x)
{
    int i = n + 1;
    Arr[n + 1] = x;
    n = n + 1;
    while (i > 1 && Arr[i].w < Arr[i / 2].w)   // 부모와 비교
    {
        swap(Arr[i].w, Arr[i / 2].w);
        i = i / 2;  // 다음 단계로 이동
    }   
    return;
}

Triple PriorityQueue::Delete()
{
    Triple returnVal = Arr[1];
    int i = 1;
    int j;          // 둘중에 작은 인덱스
    if (n == 1) { return returnVal; }
    Arr[1] = Arr[n];
    n = n - 1;    // 왼쪽 child는 곱하기 2이다.
    // 이제 왼쪽 오른쪽 검증
    while (1)
    {
        if (i * 2 < n)
        {
            break;
        }
        else if (i * 2 + 1 > n)    // 왼쪽 child만 존재
        {
            if (Arr[i * 2].w < Arr[i].w)       // Arr[i*2].w = 왼쪽 child, Arr[i].w = 본인
            {
                swap(Arr[i * 2], Arr[i]);
                i = i * 2;
            }
            else break;
        }
        else                       // 왼쪽, 오른쪽 child 존재
        {
            if (Arr[i].w > Arr[i * 2].w && Arr[i].w > Arr[i * 2 + 1].w)
            {
                if (Arr[i * 2].w < Arr[i * 2 + 1].w)
                    j = i * 2;
                else j = i * 2 + 1;
                swap(Arr[i], Arr[j]);
                i = j;
            }
            else if (Arr[i].w > Arr[i * 2].w && Arr[i].w <= Arr[i * 2 + 1].w)
            {
                j = i * 2;
                swap(Arr[i], Arr[j]);
                i = j;
            }
            else if (Arr[i].w <= Arr[i * 2].w && Arr[i].w > Arr[i * 2 + 1].w)
            {
                j = i * 2+1;
                swap(Arr[i], Arr[j]);
                i = j;
            }
            else
            {
                break;
            }
        }
    }
    return returnVal;
}

PriorityQueue Q;

int main()
{
    // 24분까지 함
    Triple s[100]{
        {1,2,3},
        {4,5,6},
        {2,2,4},
        {4,2,1},        // <-- 
        {4,2,2},
        {4,6,8}
    };
    Triple t;

    Q.Insert(s[0]);
    Q.Insert(s[1]);
    Q.Insert(s[2]);
    Q.Insert(s[3]);
    Q.Insert(s[4]);
    Q.Insert(s[5]);
    t = Q.Delete();

    cout << "Deleted ( " << t.a << " " << t.b << " " << t.w << " )" << endl;
    return 0;
}