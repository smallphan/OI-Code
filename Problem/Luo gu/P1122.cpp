#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1.6e4 + 5;
vector <int> edge[maxn];
int n, u, v, ans, dp[maxn];

inline long long read();
void dfs(int, int);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) dp[i] = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read();
        edge[u].push_back(v), edge[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void dfs(int now, int fat) {
    for (int i = 0; i < edge[now].size(); i++) {
        int end = edge[now][i];
        if (end == fat) continue;
        dfs(end, now);
        dp[now] += max(dp[end], 0);
    }
    ans = max(ans, dp[now]);
}