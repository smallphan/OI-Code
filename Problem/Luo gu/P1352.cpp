#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 6e3 + 5;
struct node {
    int next, end;
} edge[maxn << 1];
int first[maxn], cnt;
int n, u, v, dp[maxn][2];
bool notroot[maxn];

inline long long read();
void addedge(int, int);
void dfs(int, int);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) dp[i][1] = read();
    for (int i = 1; i <= n - 1; i++) {
        u = read(), v = read();
        addedge(u, v), addedge(v, u);
        notroot[u] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!notroot[i]) {
            dfs(i, i);
            printf("%d\n", max(dp[i][1], dp[i][0]));
            return 0;
        }
    }
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void addedge(int start, int end) {
    edge[++cnt] = (node) { first[start], end };
    first[start] = cnt;
}
void dfs(int now, int father) {
    for (int i = first[now]; i != 0; i = edge[i].next) {
        int end = edge[i].end;
        if (end == father) continue;
        dfs(end, now);
        dp[now][1] += dp[end][0];
        dp[now][0] += max(dp[end][1], dp[end][0]);
    }
}