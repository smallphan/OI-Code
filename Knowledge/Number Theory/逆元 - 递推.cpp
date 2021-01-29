#include <cstdio>

using namespace std;

typedef unsigned long long ull;
const int maxn = 1e6 + 5;
ull t, num, mod, inv[maxn];

inline long long read();
inline void init();

int main() {
    t = read(), mod = read();
    init();
    for (int i = 1; i <= t; i++) {
        num = read();
        printf("case %d :\n", i);
        printf("[%llu's inverse] %llu [mod %llu]\n", num, inv[num], mod);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void init() {
    inv[1] = 1;
    for (int i = 2; i < mod; i++) {
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
}