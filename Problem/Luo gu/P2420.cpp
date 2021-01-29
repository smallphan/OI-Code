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

int n, m, u, v, w;
struct node {
    int end, val;
}; std::vector<node> edge[maxn];
int func[maxn];

void dfs(int, int);

int main() {
    n = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read(), w = read();
        edge[u].pb((node) { v, w });
        edge[v].pb((node) { u, w });
    }
    dfs(1, 0);
    m = read();
    while (m--) printf("%d\n", func[read()] ^ func[read()]);
    return 0;
}

void dfs(int now, int fat) {
    for (int i = 0; i < edge[now].size(); i++) {
        int end = edge[now][i].end, val = edge[now][i].val;
        if (end != fat) {
            func[end] = func[now] ^ val;
            dfs(end, now);
        }
    }
}