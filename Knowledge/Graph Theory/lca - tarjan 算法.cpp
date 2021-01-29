#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int next, end, pos;
} edge[2][maxn << 2]; // edge[i][j] i = 0 ==> gragh | i = 1 ==> query
int first[2][maxn], cnt[2];
int father[maxn], ans[maxn];
int n, q, s, u[maxn], v[maxn];
bool vis[maxn]; 

inline long long read();
void addedge(int, int, int, int);
int find(int);
void merge(int, int);
void tarjan(int, int);

int main() {
    memset(first, -1, sizeof(first));
    n = read(), q = read(), s = read();
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= n - 1; i++) {
        u[0] = read(), v[0] = read();
        addedge(u[0], v[0], 0, 0), addedge(v[0], u[0], 0, 0);
    }
    for (int i = 1; i <= q; i++) {
        u[i] = read(), v[i] = read();
        addedge(u[i], v[i], i, 1), addedge(v[i], u[i], i, 1);
        if (u[i] == v[i]) ans[i] = u[i];
    }
    tarjan(s, s);
    for (int i = 1; i <= q; i++) {
        printf("lca [%d, %d] == %d\n", u[i], v[i], ans[i]);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void addedge(int start, int end, int pos, int flag) {
    edge[flag][++cnt[flag]] = (node) { first[flag][start], end, pos };
    first[flag][start] = cnt[flag];
}
int find(int point) {
    if (point == father[point]) return point;
    else return father[point] = find(father[point]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) father[u] = v;
}
void tarjan(int point, int father) {
    for (int i = first[0][point]; i != -1; i = edge[0][i].next) {
        int end = edge[0][i].end;
        if (end != father) {
            tarjan(end, point);
            merge(end, point);
            vis[end] = true;
        }
    }
    for (int i = first[1][point]; i != -1; i = edge[1][i].next) {
        int end = edge[1][i].end;
        if (vis[end]) {
            ans[edge[1][i].pos] = find(end);
        }
    }
}