#include <bits/stdc++.h>

const int maxn = 705;
int n, f, s, ans, fin[maxn][maxn];
std::string a, b;

inline int idx(char c) { return c - 'A'; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        std::cin >> a >> b;
        f = idx(a[0]) * 26 + idx(a[1]), s = idx(b[0]) * 26 + idx(b[1]);
        if (f != s) {
            fin[f][s]++;
            ans += fin[s][f];
        }
    }
    printf("%d\n", ans);
}