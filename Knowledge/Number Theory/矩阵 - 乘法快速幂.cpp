#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 105;
struct node {
    ll data[maxn][maxn];
    node() { memset(data, 0, sizeof(data)); }
} num;
int n, index;

inline ll read();
void input(node&, int, int);
void output(node&, int, int);
node mul(node, node, int, int, int);
node pow(node, int, int);

int main() {
    n = read(), index = read();
    input(num, n, n);
    num = pow(num, n, index);
    output(num, n, n);
    return 0;
}

inline ll read() {
    ll ans = 0, flag = 1; char x = getchar();
    while (x < '0' || x > '9') { if (x == '-') flag = -1; x = getchar(); }
    while (x >= '0' && x <= '9') { ans = ans * 10 + x - '0'; x = getchar(); }
    return ans * flag;
}
void input(node& matrix, int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) matrix.data[i][j] = read();
    }
}
void output(node& matrix, int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%lld ", matrix.data[i][j]);
        printf("\n");
    }
}
node mul(node a, node b, int n, int m, int r) {
    node ans;
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= r; j++) {
                ans.data[i][j] = (ans.data[i][j] + (a.data[i][k] * b.data[k][j]) % mod) % mod;
            }
        }
    }
    return ans;
}
node pow(node num, int n, int index) {
    node ans;
    for (int i = 1; i <= n; i++) ans.data[i][i] = 1;
    while (index) {
        if (index & 1) ans = mul(ans, num, n, n, n);
        index = index >> 1;
        num = mul(num, num, n, n, n);
    }
    return ans;
}