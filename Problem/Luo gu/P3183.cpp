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

int n, m, u, v, ans;
int in[maxn], dp[maxn];

std::vector<int> edge[maxn];
std::queue<int> que;

inline void toposort();

int main() {
    n = read(), m = read();
    while (m--) {
        u = read(), v = read();
        edge[u].pb(v), in[v]++;
    }
    toposort();
    return printf("%d\n", ans), 0;
}


inline void toposort() {
    for (int i = 1; i <= n; i++) {
        if (!in[i] && edge[i].size()) que.push(i), dp[i] = 1;
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        if (!edge[now].size()) ans += dp[now];
        for (int i = 0; i < edge[now].size(); i++) {
            int end = edge[now][i];
            dp[end] += dp[now], in[end]--;
            if (!in[end]) que.push(end);
        }
    }
}