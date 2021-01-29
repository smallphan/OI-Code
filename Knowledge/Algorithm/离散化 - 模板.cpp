#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int n, num[maxn], init[maxn];

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) num[i] = init[i] = read();
    sort(init + 1, init + 1 + n);
    int size = unique(init + 1, init + 1 + n) - (init + 1);
    for (int i = 1; i <= n; i++) {
        num[i] = lower_bound(init + 1, init + 1 + size, num[i]) - init;
    }
    for (int i = 1; i <= n; i++) printf("%d ", num[i]);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}