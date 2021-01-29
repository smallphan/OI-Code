#include <cstdio>

using namespace std;

const int maxn = 25;
int n, val[maxn];

inline long long read();
inline void work();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) val[i] = read();
    work();
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void work() {
    for (int i = 1; i <= n; i++) {
        if (!val[i]) {
            if (!(i & 1)) {
                puts("YES");
                return;
            }
            break;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (!val[i]) {
            if (!((n - i + 1) & 1)) {
                puts("YES");
                return;
            }
            break;
        }
    }
    puts("NO");
}