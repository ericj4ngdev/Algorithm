#include <iostream>
#include <vector>
using namespace std;

int n, m, dfn;
vector<int> Edge[1000];
vector<int> Type[1000]; // 1 = parent, 2 = child, 3 = back/forward
int Dfn[1000];
/// <summary>
/// Dfn = 0  미방문
/// Dfn >= 1 방문
/// </summary>
int L[1000];
int Cut[1000];

// L값
// 1. 자기 dfn
// 2. 모든 backedge의 dfn
// 3. child에서 받은 dfn
// 이 셋중의 최소값

void dfs(int x, int p)
{
    int i, s;
    Dfn[x] = ++dfn;                     // 노드 x에 방문했으면 Dfn[x] = x
    s = Edge[x].size();                 // x에 인접한 노드 개수
    
    // 엣지 타입 구분 코드
    for (i = 0; i < s; i++) {
        if (Edge[x][i] == p)            // 부모노드 이면 dfs는 안한다.
            Type[x][i] = 1;             // 부모 표시
        else if (Dfn[Edge[x][i]] == 0)  // 노드x에 인접한 i번째 노드에 방문하지 않았으면 실행
        {       
            Type[x][i] = 2;             // 일반 child
            dfs(Edge[x][i], x);         // dfs진행
        }
        else
            Type[x][i] = 3;             // 방문도 안하면 back/forward
    }
}

int dfs2(int x, int p)
{
    int i, s, rv, cc;
    L[x] = Dfn[x];
    s = Edge[x].size();

    // L값 계산
    for (i = 0; i < s; i++) {
        if (Type[x][i] == 1)        // 부모노드이면 상관없음
            ;
        else if (Type[x][i] == 2) {       // 노드x에 인접한 i번째 노드에 방문하지 않았으면 실행
            rv = dfs2(Edge[x][i], x);   // child의 l값 저장
            L[x] = min(L[x], rv);   // 자기 L과 자식 L값 비교
        }
        else
            L[x] = min(L[x], Dfn[Edge[x][i]]);         // 나에게 붙은 모든 back/forward edge의 dfn번호
    }

    if (p == 0) {
        cc = 0;
        for (i = 0; i < s; i++) if (Type[x][i] == 2) cc++;
        if (cc > 1) Cut[x] = 1;
    }
    else {
        for (i = 0; i < s; i++)
        {
            // child일때만 생각
            if ((Type[x][i]) == 2) {
                if (L[Edge[x][i]] >= Dfn[x])        // child의 L값이 내 Dfn값보다 크면 내가 커진 것
                    Cut[x] = 1;
            }
        }
    }
    return L[x];
}

int main()
{
    int i, x, y;
    cin >> n >> m;          // 노드, 엣지 입력
    for (int i = 0; i < m; i++)     //엣지 개수만큼 인접한 노드 입력
    {
        cin >> x >> y;
        Edge[x].push_back(y);       // 노드x에 인접한 노드 y추가
        Type[x].push_back(0);
        Edge[y].push_back(x);
        Type[y].push_back(0);
    }
    dfn = 0;
    dfs(1, 0);
    for (i = 1; i <= n; i++)
        if (Dfn[i] == 0) break;     // 다 방문했으면 끝, 하나라도 0이면 밑에꺼 실행
    if (i <= n) { cout << "Disconnected Graph!\n"; exit(1); }
    // 다 연결되어 방문한 상태라면 i는 n+1이라 마지막 if문을 pass한다.
    // 하지만 위에 if에서 방문하지 않은 노드에서 break가 걸리면 i는 n보다 작은 수가 들어와 disconnect를 출력한다. 

    // L값을 위한 dfs
    dfs2(1, 0);
    cout << "Cut vertex: ";
    for (i = 1; i <= n; i++)
        if (Cut[i] == 1)
            cout << i << " ";
    cout << endl;

    return 0;
}

/*

5 4
3 2
2 1
1 4
4 5

16 20
1 2
1 3
2 4
3 4
4 5
5 6
4 6
5 7
7 8
4 12
12 13
4 11
11 13
11 10
10 9
9 11
13 14
14 15
15 16
14 16


*/



