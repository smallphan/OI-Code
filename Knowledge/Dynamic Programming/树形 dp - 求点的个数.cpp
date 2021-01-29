#include <iostream>

using namespace std;

struct Node {
    int End, Next;
} Edge[100005];
int N, M, Len, S, E;
int First[100005];
int DP[100005];

void Add_Edge(int Start, int End) {
    Edge[++Len].Next = First[Start];
    First[Start] = Len;
    Edge[Len].End = End;
}

void DFS(int Now, int Father) {
    DP[Now] = 1;
    for (int i = First[Now]; i != 0; i = Edge[i].Next) {
        if (Edge[i].End != Father) {
            DFS(Edge[i].End, Now);
            DP[Now] += DP[Edge[i].End];
        }
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
    cout << DP[1];
    return 0;
}
