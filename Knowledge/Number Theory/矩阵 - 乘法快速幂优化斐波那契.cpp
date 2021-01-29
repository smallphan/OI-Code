#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 105;
struct node {
    ll data[maxn][maxn];
    node() {
        memset(data, 0, sizeof(data));
    }
    void init() {
        for (int i = 1; i <= maxn - 1; i++) data[i][i] = 1;
    }
} ans, fib;
ll n, m;

inline long long read();
node mul(node, node, int, int, int);
node pow(node, int, int);
void init();

int main() {
    init();
    m = read();
    ans = pow(ans, 2, m - 1);
    ans = mul(ans, fib, 2, 2, 1);
    printf("[fibonacci] [%d] %d\n", m, ans.data[1][1]);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
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
node pow(node mat, int n, int k) {
    node ans;
    ans.init();
    while (k) {
        if (k & 1) ans = mul(ans, mat, n, n, n);
        k = k >> 1;
        mat = mul(mat, mat, n, n, n);
    }
    return ans;
}
void init() {
    ans.data[1][1] = 1;
    ans.data[1][2] = 1;
    ans.data[2][1] = 1;
    ans.data[2][2] = 0;
    /*
    1 1
    1 0
    */
    fib.data[1][1] = 1;
    fib.data[2][1] = 0;
    /*
    1
    0
    */
}