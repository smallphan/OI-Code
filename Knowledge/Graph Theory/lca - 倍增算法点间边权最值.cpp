#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct node {
    int next, end, value;
} edge[maxn << 1];
int first[maxn], cnt;
int depth[maxn], up[maxn][35], minvalue[maxn][35], getlog[maxn];
int n, m, s, u, v, w;

inline long long read();
void addedge(int, int, int);
void dfs(int, int);
void init();
void work(int, int, int&, int&);

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read(), s = read();
    for (int i = 1; i <= n - 1; i ++) {
        u = read(), v = read(), w = read();
        addedge(u, v, w), addedge(v, u, w);
    }
    dfs(s, 0);
    init();
    while (m--) {
        u = read(), v = read();
        int lca = 0, ans = 0;
        work(u, v, lca, ans);
        printf("[%d->%d] [lca] %d [min value] %d\n", u, v, lca, ans);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void addedge(int start, int end, int value) {
    edge[++cnt] = (node) { first[start], end, value };
    first[start] = cnt;
}
void dfs(int point, int father) {
    up[point][0] = father;
    depth[point] = depth[father] + 1;
    for (int i = first[point]; i != -1; i = edge[i].next) {
        int end = edge[i].end, value = edge[i].value;
        if (end != father) {
            minvalue[end][0] = value;
            dfs(end, point);
        }
    }
}
void init() {
    for (int i = 1; i <= n; i++) getlog[i] = getlog[i - 1] + (1 << (getlog[i - 1] + 1) == i);
    for (int step = 1; step <= getlog[n]; step++) {
        for (int i = 1; i <= n; i++) {
            up[i][step] = up[up[i][step - 1]][step - 1];
            minvalue[i][step] = min(minvalue[i][step - 1], minvalue[up[i][step - 1]][step - 1]);
        }
    }
} 
void work(int fir, int sec, int& lca, int& ans) {
    if (fir == sec) { lca = fir; ans = 0; return; } 
    ans = inf;
    if (depth[fir] < depth[sec]) swap(fir, sec);
    while (depth[fir] > depth[sec]) {
        ans = min(ans, minvalue[fir][getlog[depth[fir] - depth[sec]]]);
        fir = up[fir][getlog[depth[fir] - depth[sec]]];
    }
    if (fir == sec) { lca = fir; return; }
    for (int step = getlog[depth[fir]]; step >= 0; step--) {
        if (up[fir][step] != up[sec][step]) {
            ans = min(ans, min(minvalue[fir][step], minvalue[sec][step]));
            fir = up[fir][step], sec = up[sec][step];
        }
    }
    lca = up[fir][0];
    ans = min(ans, min(minvalue[fir][0], minvalue[sec][0]));
}