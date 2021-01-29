#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
double n, pro, ans[maxn], fir[maxn], sec[maxn];

int main() {
    scanf("%lf", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &pro);
        fir[i] = (fir[i - 1] + 1) * pro;
        sec[i] = (sec[i - 1] + 2 * fir[i - 1] + 1) * pro;
        ans[i] = ans[i - 1] + (3 * sec[i - 1] + 3 * fir[i - 1] + 1) * pro;
    }
    printf("%.1lf\n", ans[(int) n]);
    return 0;
}