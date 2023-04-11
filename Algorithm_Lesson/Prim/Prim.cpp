#include <iostream>
#include <cstdio>
#include <vector>

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
    int n;      // 노드 수
    Triple Arr[1000];
    PriorityQueue();
    Triple Delete();
    void Insert(Triple x);
    int isEmpty();
    // w가 작을수록 먼저 나옴
};

PriorityQueue::PriorityQueue()          // 생성자
{
    n = 0;
}
int PriorityQueue::isEmpty()
{
    return n == 0;
}
void PriorityQueue::Insert(Triple x)
{
    int i;
    Arr[n + 1] = x;
    i = n + 1;
    n = n + 1;
    while (i > 1 && Arr[i].w < Arr[i / 2].w)   // 부모와 비교
    {
        swap(Arr[i], Arr[i / 2]);
        i = i / 2;  // 다음 단계로 이동
    }
} 

Triple PriorityQueue::Delete()
{
    Triple returnVal = Arr[1];
    int i, j;          // 둘중에 작은 인덱스
    if (n == 1) { n = 0; return returnVal; }
    Arr[1] = Arr[n];
    i = 1;
    n = n - 1;    // 왼쪽 child는 곱하기 2이다.
    // 이제 왼쪽 오른쪽 검증
    while (1)
    {
        if (i*2>n)
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
            else 
            { 
                break; 
            }
        }
        else                       // 왼쪽, 오른쪽 child 존재
        {
            if (Arr[i].w > Arr[i * 2].w && Arr[i].w > Arr[i * 2 + 1].w)     // 둘 다 작은 경우 - 인덱스 하나 더 필요(17:20)
            {
                if (Arr[i * 2].w < Arr[i * 2 + 1].w)        // 왼쪽이 작은 경우
                    j = i * 2;
                else
                    j = i * 2 + 1;
                // 둘중에 작은게 j
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
int n, m;   // n = 노드수, m = 엣지수
vector<pair<int,int>> Edges[1000];
int M[1000];

int main()
{
    //// 23분 코딩부분
    //Triple s[100] = {
    //    {1,2,3},
    //    {4,5,6},
    //    {2,2,4},
    //    {4,2,1},        // <-- 
    //    {4,2,2},
    //    {4,6,8}
    //};
    //Triple t; 
    //Q.Insert(s[0]);
    //Q.Insert(s[1]);
    //Q.Insert(s[2]);
    //Q.Insert(s[3]);
    //Q.Insert(s[4]);
    //Q.Insert(s[5]);
    //t = Q.Delete();
    //cout << "Deleted ( " << t.a << " " << t.b << " " << t.w << " )" << endl;
    
    int currentNode, i, a, b, w;
    // i 는 
    Triple x, y;        // 35:21
    //printf("n입력 : ");
    //scanf_s("%d", &n);
    //printf("m입력 : ");
    //scanf_s("%d", &m);
    scanf_s("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        // printf("a,b,weight를 입력하세요 : ");
        scanf_s("%d %d %d", &a, &b, &w);
        Edges[a].push_back(make_pair(b, w));
        Edges[b].push_back(make_pair(a, w));
    }
    // PriorityQueue Q;
    // 1번 노드에 대해서다 집어넣음
    currentNode = 1;
    M[currentNode] = 1;
    for (i = 0; i < Edges[currentNode].size(); i++)
    {
        // 모든 엣지를 Q에 넣는다.
        x.a = currentNode;
        x.b = Edges[currentNode][i].first;
        x.w = Edges[currentNode][i].second;
        Q.Insert(x);
    }
    // 엣지 꺼내기
    while (Q.isEmpty() == 0)
    {
        y = Q.Delete();             // y.a는 마킹을 하고 집어넣은 것.
        if (M[y.a]==1 && M[y.b] == 1)
        {
            // 엣지 버리기, M[y.a]==1
            continue;
        }       
        else
        { 
            printf("Edge from Node %d to Node %d of Weight %d Selected. \n", y.a, y.b, y.w);        // 38:10
            currentNode = y.b;  
            M[currentNode] = 1;     // y.b 마킹 시작
            // printf("Edge from Node %d to Node %d of Weight %d Selected. \n", y.a, y.b, y.w);        // 38:10

            for (i = 0; i < Edges[currentNode].size(); i++)
            {
                // 모든 엣지를 Q에 넣는다.
                x.a = currentNode;
                x.b = Edges[currentNode][i].first;
                x.w = Edges[currentNode][i].second;
                Q.Insert(x);
            }       // 39:15
        }
    }
    return 0;
}

/*
* 43:50 부터 
* 실행은 44:05
5 = 노드수
10 = 엣지수
노드 번호, 노드 번호, weight
5 10
1 2 10
2 3 1
1 5 6
1 4 5
2 4 4
2 4 3
4 5 2
3 4 9
3 5 4
5 3 6
*/