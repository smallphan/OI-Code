#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 5;
int n, ans, num[maxn], dp[maxn];

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) num[i] = read();
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (num[j] < num[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    printf("[max lis] %d\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}