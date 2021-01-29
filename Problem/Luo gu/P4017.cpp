#include <bits/stdc++.h>

#define pb push_back
#define int long long

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

const int maxn = 5e3 + 5;
const int mod = 80112002;

int n, m, u, v, ans;

int dp[maxn], in[maxn];
std::vector<int> edge[maxn];

std::queue<int> que;

inline void toposort();

signed main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        edge[u].pb(v), in[v]++;
    }
    toposort();
    return printf("%lld\n", ans), 0;
}

inline void toposort() {
    for (int i = 1; i <= n; i++) {
        if (!in[i] && edge[i].size()) que.push(i), dp[i] = 1;
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        if (!edge[now].size()) ans = (ans + dp[now]) % mod;
        for (int i = 0; i < edge[now].size(); i++) {
            int v = edge[now][i];
            dp[v] = (dp[v] + dp[now]) % mod, in[v]--;
            if (!in[v]) que.push(v);
        }
    }
}