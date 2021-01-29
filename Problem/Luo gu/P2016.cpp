#include <vector>
#include <cstdio>

using namespace std;

const int maxn = 3e3 + 5;
vector <int> edge[maxn];
int n, u, k, dp[maxn][2];

inline long long read();
inline void addedge(int, int);
void dfs(int, int);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        u = read(), k = read();
        for (int j = 1; j <= k; j++) addedge(u, read());
    }
    dfs(0, 0);
    printf("%d\n", min(dp[0][1], dp[0][0]));
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void addedge(int u, int v) {
    edge[u].push_back(v);
    edge[v].push_back(u);
}
void dfs(int now, int fat) {
    dp[now][1] = 1, dp[now][0] = 0;
    for (int i = 0; i < edge[now].size(); i++) {
        int end = edge[now][i];
        if (end == fat) continue;
        dfs(end, now);
        dp[now][0] += dp[end][1];
        dp[now][1] += min(dp[end][1], dp[end][0]);
    }
}