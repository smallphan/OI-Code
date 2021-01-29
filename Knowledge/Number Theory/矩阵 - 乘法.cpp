#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 105;
struct node {
    ll data[maxn][maxn];
    node() { memset(data, 0, sizeof(data)); }
} fir, sec, ans;
ll n, m, r;

inline long long read();
void input(node&, int, int);
void ouput(node&, int, int);
node mul(node, node, int, int, int);

int main() {
    n = read(), m = read(), r = read();
    input(fir, n, m), input(sec, m, r);
    ans = mul(fir, sec, n, m, r);
    ouput(ans, n, r);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void input(node& matrix, int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) matrix.data[i][j] = read();
    }
}
void ouput(node& matrix, int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%lld ", matrix.data[i][j]);
        puts("\n");
    }
}
node mul(node fir, node sec, int n, int m, int r) {
    node ans;
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= r; j++) {
                ans.data[i][j] = (ans.data[i][j] + (fir.data[i][k] * sec.data[k][j]) % mod) % mod;
            }
        }
    }
    return ans;
}