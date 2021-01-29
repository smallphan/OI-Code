#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e8 + 5;
int n, q, prime[maxn], cnt;
bool isprime[maxn];

inline long long read();

int main() {
    n = read(), q = read();
    memset(isprime, 1, sizeof(isprime));
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            isprime[i * prime[j]] = false;
            if (!(i % prime[j])) break;
        }
    }
    while (q--) printf("%d\n", prime[read()]);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}