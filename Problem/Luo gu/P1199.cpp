#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 505;
int n, ans, val[maxn][maxn];

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) val[i][j] = val[j][i] = read();
    }
    for (int i = 1; i <= n; i++) {
        sort(val[i] + 1, val[i] + 1 + n);
        ans = max(ans, val[i][n - 1]);
    }
    printf("1\n%d\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}