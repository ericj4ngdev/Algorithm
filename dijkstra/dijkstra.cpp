// 201710749 장명훈 dijkstra 과제
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Triple
{
public:
    int a, b, w;
};
class PriorityQueue
{
public:
    int n;      // 노드 수
    Triple Arr[1000];
    PriorityQueue();
    Triple Delete();
    void Insert(Triple x);
    int isEmpty();
};

PriorityQueue::PriorityQueue()
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
    while (i > 1 && Arr[i].w < Arr[i / 2].w)
    {
        swap(Arr[i], Arr[i / 2]);
        i = i / 2;
    }
}

Triple PriorityQueue::Delete()
{
    Triple returnVal = Arr[1];
    int i, j;
    if (n == 1) { n = 0; return returnVal; }
    Arr[1] = Arr[n];
    i = 1;
    n = n - 1;

    while (1)
    {
        if (i * 2 > n)
        {
            break;
        }
        else if (i * 2 + 1 > n)
        {
            if (Arr[i * 2].w < Arr[i].w)
            {
                swap(Arr[i * 2], Arr[i]);
                i = i * 2;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (Arr[i].w > Arr[i * 2].w && Arr[i].w > Arr[i * 2 + 1].w)
            {
                if (Arr[i * 2].w < Arr[i * 2 + 1].w)
                    j = i * 2;
                else
                    j = i * 2 + 1;
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
                j = i * 2 + 1;
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
vector<pair<int, int>> Edges[1000];
int M[1000];        // S.P. Length
// prim과 달리 루프가 하나 더 필요하다.
vector<int> P[1000];        // Previous Node

int main()
{
    int currentNode, i, a, b, w;
    Triple x, y;
    scanf_s("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf_s("%d %d %d", &a, &b, &w);
        Edges[a].push_back(make_pair(b, w));
        Edges[b].push_back(make_pair(a, w));
    }
    for (i = 1; i <= n; i++)
    {
        M[i] = 1000000;
    }
    currentNode = 1;
    M[currentNode] = 0;     // 답
    for (i = 0; i < Edges[currentNode].size(); i++)
    {
        x.a = currentNode;
        x.b = Edges[currentNode][i].first;
        x.w = M[currentNode] + Edges[currentNode][i].second;
        Q.Insert(x);
    }
    while (Q.isEmpty() == 0)
    {
        y = Q.Delete();
        if (M[y.b] < 100000)
        {
            if (M[y.b] == y.w)
            {
                printf("Edge from Node %d to Node %d of Total Path Length %d Added. Previous Node %d \n", y.a, y.b, y.w, y.a);
                P[y.b].push_back(y.a);
            }
            else
            {
                printf("IGNORED Edge from Node %d to Node %d of Total Path Length %d. \n", y.a, y.b, y.w);
            }

        }
        else
        {
            printf("Edge from Node %d to Node %d of Total Path Length %d Selected. Previous Node %d \n", y.a, y.b, y.w, y.a);
            currentNode = y.b;
            M[currentNode] = y.w;
            P[currentNode].push_back(y.a);
            for (i = 0; i < Edges[currentNode].size(); i++)
            {
                x.a = currentNode;
                x.b = Edges[currentNode][i].first;
                x.w = M[currentNode] + Edges[currentNode][i].second;
                Q.Insert(x);
            }
        }
    }
    return 0;
}

/*
5 10
1 2 10
2 3 1
1 5 7
1 4 5
2 4 4
2 4 3
4 5 2
3 4 9
3 5 2
5 3 6
*/