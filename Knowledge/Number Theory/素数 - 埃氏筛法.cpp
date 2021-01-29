#include <cstdio>

namespace ios {
    inline long long read() {
        long long ans = 0, tag = 1; char str = getchar();
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
    template<typename type> inline void write(type ans) {
        if (ans < 0) putchar('-'), ans = -ans;
        if (ans > 9) write(ans / 10);
        putchar(ans % 10 + '0');
    }
}

using namespace ios;
using namespace std;

const int maxn = 1e8 + 5;
int n, prime[maxn], cnt;
bool check[maxn];

int main() {
    n = read();
    for (int i = 2; i <= n; i++) {
        if (check[i]) continue;
        prime[++cnt] = i;
        for (int j = i + i; j <= n; j += i) check[j] = true;
    }
    for (int i = 1; i <= cnt; i++) write(prime[i]), putchar(' ');
    return 0;
}