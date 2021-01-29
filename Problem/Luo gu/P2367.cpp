#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 5e6 + 6;
int n, p, l, r, w, ans = inf, scores[maxn], diff[maxn];

inline long long read();

int main() {
    n = read(), p = read();
    for (int i = 1; i <= n; i++) {
        scores[i] = read();
        diff[i] = scores[i] - scores[i - 1];
    }
    while (p--) {
        l = read(), r = read(), w = read();
        diff[l] += w;
        diff[r + 1] -= w;
    }
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        ans = min(ans, diff[i]);
    }
    printf("%d\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}