#include <cstdio>

using namespace std;

typedef long long li;
const int maxn = 3e6 + 5;
li n, p, inv[maxn];

int main() {
    scanf("%lld %lld", &n, &p);
    printf("%lld\n", inv[1] = 1);
    for (int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
        printf("%lld\n", inv[i]);
    }
    return 0;
}