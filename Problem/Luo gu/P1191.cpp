#include <cstdio>

using namespace std;

const int maxn = 155;
int n, ans, sum[maxn][maxn];
char str[maxn];

inline int getsum(int, int, int, int);
inline void work(int, int);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (str[j] == 'W' ? 0 : 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            work(i, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}

inline int getsum(int xfir, int yfir, int xsec, int ysec) {
    return sum[xsec][ysec] - sum[xfir - 1][ysec] - sum[xsec][yfir - 1] + sum[xfir - 1][yfir - 1];
}
inline void work(int i, int j) {
    if (getsum(i, j, i, j)) return;
    for (int k = i; k <= n; k++) {
        for (int l = j; l <= n; l++) {
            if (!getsum(i, j, k, l)) ans++;
            else break;
        }
    }
}