#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int next, end, value;
} edge[maxn << 1];
int first[maxn], cnt;
int diff[maxn], depth[maxn];
int up[maxn][30], getlog[maxn];
int n, m, s, u, v, w;

inline long long read();
void addedge(int, int, int);
void dfsfir(int, int);
void dfssec(int, int);
void init();
int getlca(int, int);
void modify(int, int, int);

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read(), s = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read(), w = read();
        addedge(u, v, w);
    }
    dfsfir(s, 0);
    init();
    while (m--) {
        u = read(), v = read(), w = read();
        modify(u, v, w);
    }
    dfssec(s, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = first[i]; j != -1; j = edge[j].next) {
            int end = edge[j].end, value = edge[j].value;
            printf("[%d->%d] [value] %d\n", i, end, value);
        }
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
void dfsfir(int point, int father) {
    up[point][0] = father;
    depth[point] = depth[father] + 1;
    for (int i = first[point]; i != -1; i = edge[i].next) {
        int end = edge[i].end;
        if (end != father) dfsfir(end, point);
    }
}
void dfssec(int point, int father) {
    for (int i = first[point]; i != -1; i = edge[i].next) {
        int end = edge[i].end;
        int& value = edge[i].value;
        if (end != father) {
            dfssec(end, point);
            diff[point] += diff[end];
            value += diff[end];
        }
    }
}
void init() {
    for (int i = 1; i <= n; i++) {
        getlog[i] = getlog[i - 1] + (1 << (getlog[i - 1] + 1) == i);
    }
    for (int step = 1; step <= getlog[n]; step++) {
        for (int i = 1; i <= n; i++) {
            up[i][step] = up[up[i][step - 1]][step - 1];
        }
    }
}
int getlca(int fir, int sec) {
    if (depth[fir] < depth[sec]) swap(fir, sec);
    while (depth[fir] > depth[sec]) {
        fir = up[fir][getlog[depth[fir] - depth[sec]]];
    }
    if (fir == sec) return fir;
    for (int step = getlog[depth[fir]]; step >= 0; step--) {
        if (up[fir][step] != up[sec][step]) {
            fir = up[fir][step];
            sec = up[sec][step];
        }
    }
    return up[fir][0];
}
void modify(int fir, int sec, int key) {
    int lca = getlca(fir, sec);
    diff[fir] += key;
    diff[sec] += key;
    diff[lca] -= key * 2;
}