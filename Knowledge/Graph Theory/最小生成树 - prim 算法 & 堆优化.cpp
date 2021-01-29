#include <bits/stdc++.h>

#define mp std::make_pair
#define fi first
#define se second

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        tag = str == '-' ? -1 : 1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = ans * 10 + str - '0';
        str = getchar();
    }
    return ans * tag;
}

typedef std::pair<int, int> pii;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int u, v, w;
} edge[maxn << 2];
int fir[maxn], cnt;

int n, m, s, u, v, w;
int ans;

int low[maxn];
bool join[maxn];
std::set<pii> heap;

inline void prim(int);
inline void addedge(int, int, int);

int main() {
    n = read(), m = read(), s = 1 + rand() % n;
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        addedge(u, v, w), addedge(v, u, w);
    }
    prim(s);
    return printf("[min value] %d\n", ans), 0;
}

inline void prim(int s) {
    memset(low, inf, sizeof(low));
    low[s] = 0;
    for (int i = 1; i <= n; i++) heap.insert(mp(low[i], i));
    while (!heap.empty()) {
        int dis = heap.begin() -> fi;
        int now = heap.begin() -> se;
        heap.erase(heap.begin());
        if (dis > low[now]) continue;
        join[now] = true;
        for (int i = fir[now]; i; i = edge[i].u) {
            int v = edge[i].v, w = edge[i].w;
            if (!join[v] && low[v] > w) {
                low[v] = w;
                heap.insert(mp(low[v], v));
            }
        }
    }
    for (int i = 1; i <= n; i++) ans += low[i];
}

inline void addedge(int u, int v, int w) {
    edge[++cnt] = (node) { fir[u], v, w };
    fir[u] = cnt;
}