#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int next, end;
} edge[maxn << 2];
int first[maxn], cnt;
int n, m, s, u, v;
int f[maxn << 2][30], g[maxn << 2][30], tot;
int getlog[maxn], appear[maxn];

inline long long read();
void addedge(int, int);
void dfs(int, int, int);
void init();
int lca(int, int);

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read(), s = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read();
        addedge(u, v), addedge(v, u);
    }
    dfs(s, 0, 1);
    init();
    while (m--) {
        u = read(), v = read();
        printf("lca [%d, %d] == %d\n", u, v, lca(u, v));
    }
}

inline long long read() {
    long long ans = 0, flag = 1;
    char str = getchar();
    while (str < '0' || str > '9') {
        if (str == '-') flag = -1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = (ans << 3) + (ans << 1) + str - '0';
        str = getchar();
    }
    return ans * flag;
}
void addedge(int start, int end) {
    edge[++cnt] = (node){first[start], end};
    first[start] = cnt;
}
void dfs(int point, int father, int depth) {
    cnt++;
    f[cnt][0] = depth;
    g[cnt][0] = point;
    appear[point] = cnt;
    for (int i = first[point]; i != -1; i = edge[i].next) {
        int end = edge[i].end;
        if (end != father) {
            dfs(end, point, depth + 1);
            cnt++;
            f[cnt][0] = depth;
            g[cnt][0] = point;
        }
    }
}
void init() {
    for (int i = 1; i <= cnt; i++) {
        getlog[i] = getlog[i - 1] + (1 << (getlog[i - 1] + 1) == i);
    }
    for (int j = 1; j <= getlog[cnt]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= cnt; i++) {
            int k = i + (1 << (j - 1));
            if (f[i][j - 1] < f[k][j - 1]) {
                f[i][j] = f[i][j - 1];
                g[i][j] = g[i][j - 1];
            } else {
                f[i][j] = f[k][j - 1];
                g[i][j] = g[k][j - 1];
            }
        }
    }
}
int lca(int u, int v) {
    u = appear[u], v = appear[v];
    if (u > v) swap(u, v);
    int j = getlog[v - u + 1], k = v - (1 << j) + 1;
    return f[u][j] < f[k][j] ? g[u][j] : g[k][j];
}