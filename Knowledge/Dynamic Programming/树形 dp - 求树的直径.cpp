#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int End, Next;
} Edge[100005];
int N, M, Len, S, E;
int First[100005];
int F[100005], G[100005];
int Ans;

void Add_Edge(int Start, int End) {
    Edge[++Len].Next = First[Start];
    First[Start] = Len;
    Edge[Len].End = End;
}
void DFS(int Now, int Father) {
    int Max = 0, SecMax = 0;
    bool IfHaveLeaf = false;
    for (int i = First[Now]; i != 0; i = Edge[i].Next) {
        if (Edge[i].End != Father) {
            IfHaveLeaf = true;
            DFS(Edge[i].End, Now);
            if (F[Edge[i].End] > Max) {
                SecMax = Max;
                Max = F[Edge[i].End];
            }
        }
    }
    if (IfHaveLeaf) {
        F[Now] = Max + 1;
        G[Now] = SecMax + 1;
    }
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> S >> E;
        Add_Edge(S, E);
        Add_Edge(E, S);
    }
    DFS(1, 0);
    for (int i = 1; i <= N; i++) {
        Ans = max(Ans, F[i] + G[i]);
    }
    cout << Ans << endl;
    return 0;
}
