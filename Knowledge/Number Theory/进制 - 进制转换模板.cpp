#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
int a, b, num, ans[maxn], cnt;
// [a] num [b] base to be converted

int main() {
    scanf("%d %d", &a, &b);
    num = a;
    while (a) {
        ans[++cnt] = a % b;
        a /= b;
    }
    printf("%d(%d) = ", num, b);
    for (int i = cnt; i >= 1; i--) printf("%d", ans[i]);
    return 0;
}