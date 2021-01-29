#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
int n, q, l, r, sum[maxn];

inline long long read();
inline int getsum(int, int);

int main() {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + read();
    while (q--) {
        l = read(), r = read();
        printf("[%d,%d] %d\n", l, r, getsum(l, r));
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline int getsum(int l, int r) {
    return sum[r] - sum[l - 1];
}