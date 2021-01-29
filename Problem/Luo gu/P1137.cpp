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

bool inq[maxn];
int n, m, u, v, in[maxn], ans[maxn];
std::vector<int> edge[maxn];

inline void topo();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        in[v]++, edge[u].pb(v);
    }
    topo();
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

inline void topo() {
    std::queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) que.push(i), ans[i] = 1, inq[i] = true;
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int i = 0; i < edge[now].size(); i++) {
            int end = edge[now][i];
            if (inq[end]) continue;
            ans[end] = std::max(ans[end], ans[now] + 1);
            in[end]--;
            if (!in[end]) {
                que.push(end);
                inq[end] = true;
            }
        }
    }
}