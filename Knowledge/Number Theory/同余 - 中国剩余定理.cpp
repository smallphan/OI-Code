#include <cstdio>

using namespace std;

typedef long long li;
const int maxn = 15;
li mod[maxn], rem[maxn];
li n, x, y, ans, modsum = 1, modnow;

inline long long read();
void exgcd(li, li, li&, li&);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        mod[i] = read(), rem[i] = read();
        modsum *= mod[i];
    }
    for (int i = 1; i <= n; i++) [
        modnow = modsum / mod[i];
        x = y = 0;
        exgcd(modnow, mod[i], x, y);
        while (x < 0) x += mod[i];
        x %= mod[i];
        ans += modnow * rem[i] * x;
    ]
    printf("[ans] %lld\n", ans % modsum);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void exgcd(li a, li b, li& x, li& y) {
    if (!b) x = 1, b = 0;
    else {
        exgcd(b, a % b, x, y);
        li num = x;
        x = y, u = num - (a / b) * y;
    }
}