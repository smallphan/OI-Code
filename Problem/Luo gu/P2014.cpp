#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 5;
vector <int> edge[maxn];
int n, m, dp[maxn][maxn];

inline long long read();
void dfs(int);

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        edge[read()].push_back(i);
        dp[i][1] = read();
    }
    dfs(0);
    printf("%d\n", dp[0][m + 1]);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void dfs(int now) {
    for (int i = 0; i < edge[now].size(); i++) {
        int end = edge[now][i];
        dfs(end);
        for (int j = m + 1; j >= 1; j--) {
            for (int k = 0; k < j; k++) {
                dp[now][j] = max(dp[now][j], dp[now][j - k] + dp[end][k]);
            }
        }
    }
}