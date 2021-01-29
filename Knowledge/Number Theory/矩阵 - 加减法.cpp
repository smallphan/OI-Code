#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int maxn = 105;
struct node {
    ll data[maxn][maxn];
    node() { memset(data, 0, sizeof(data)); }
} a, b, ans;
int n, m;

inline int read();
void input(node&, int, int);
void output(node&, int, int);
node add(node, node, int, int);
node sub(node, node, int, int);

int main() {
    n = read(), m = read();
    input(a, n, m);
    input(b, n, m);

    printf("[a+b]\n");
    ans = add(a, b, n, m);
    output(ans, n, m);

    printf("[a-b]\n");
    ans = sub(a, b, n, m);
    output(ans, n, m);

    return 0;
}

inline int read() {
    int ans = 0, flag = 1;
    char x = getchar();
    while (x < '0' || x > '9') {
        if (x == '-') flag = -1;
        x = getchar();
    }
    while (x >= '0' && x <= '9') {
        ans = ans * 10 + x - '0';
        x = getchar();
    }
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
node add(node a, node b, int n, int m) {
    node ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return ans;
}
node sub(node a, node b, int n, int m) {
    node ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return ans;
}