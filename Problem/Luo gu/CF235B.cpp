#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
int n;
double pro, ans[maxn], length[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &pro);
        ans[i] = ans[i - 1] + (2 * length[i - 1] + 1) * pro;
        length[i] = (length[i - 1] + 1) * pro;
    }
    printf("%.15lf\n", ans[n]);
    return 0;
}