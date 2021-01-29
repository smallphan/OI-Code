#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 5;
char fir[maxn], sec[maxn];
int lenfir, lensec, dp[maxn][maxn];

int main() {
    scanf("%s", fir + 1), scanf("%s", sec + 1);
    lenfir = strlen(fir + 1), lensec = strlen(sec + 1);
    for (int i = 1; i <= lenfir; i++) {
        for (int j = 1; j <= lensec; j++) {
            if (fir[i] == sec[j]) dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + 1);
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[lenfir][lensec]);
    return 0;
}