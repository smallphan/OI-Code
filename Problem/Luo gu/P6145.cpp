#include <bits/stdc++.h>

#define pb push_back

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

const int maxn = 1e5 + 5;

int n, m, c, u, v, w;
int in[maxn], ans[maxn];

struct node {
    int v, w;
}; std::vector<node> edge[maxn];

std::queue<int> que;

inline void toposort();

int main() {
    n = read(), m = read(), c = read();
    for (int i = 1; i <= n; i++) {
        ans[i] = read();
    }
    for (int i = 1; i <= c; i++) {
        u = read(), v = read(), w = read();
        edge[u].pb((node) { v, w }), in[v]++;
    }
    toposort();
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

inline void toposort() {
    for (int i = 1; i <= n; i++) {
        if (!in[i]) que.push(i);
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = 0; i < edge[now].size(); i++) {
            int v = edge[now][i].v, w = edge[now][i].w;
            ans[v] = std::max(ans[v], ans[now] + w), in[v]--;
            if (!in[v]) que.push(v);
        }
    }
}