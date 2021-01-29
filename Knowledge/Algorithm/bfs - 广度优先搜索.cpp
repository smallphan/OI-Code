#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int next, end;
} edge[maxn << 1];
int first[maxn], cnt;
int n, m, s, u, v;
bool vis[maxn];
queue <int> heap;

inline long long read();
void addedge(int, int);
void bfs(int);

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        addedge(u, v), addedge(v, u);
    }
    bfs(s);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void addedge(int start, int end) {
    edge[++cnt] = (node) { first[start], end };
    first[start] = cnt;
}
void bfs(int start) {
    heap.push(start);
    vis[start] = true;
    while (!heap.empty()) {
        int point = heap.front();
        heap.pop();
        printf("%d ", point);
        for (int i = first[point]; i != -1; i = edge[i].next) {
            int end = edge[i].end;
            if (!vis[end]) {
                vis[end] = true;
                heap.push(end);
            }
        }
    }
}