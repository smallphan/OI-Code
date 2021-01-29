#include <cstdio>

namespace ips {
    inline long long read() {
        char str = getchar(); long long ans = 0, tag = 1;
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
}

using namespace ips;
using namespace std;

const int maxn = 1e5 + 5;
int n, lim, ans, num[maxn];
int l = 1, r = 1, sum;

#define len (r - l + 1)

int main() {
    n = read(), lim = read();
    for (int i = 1; i <= n; i++) num[i] = read();
    for (r = 1; r <= n; r++) {
        sum += num[r];
        while (sum > lim) {
            ans += len - 1;
            sum -= num[l++];
        }
    }
    while (l <= n) ans += len - 1, l++;
    printf("%d\n", ans);
    return 0;
}

#undef len