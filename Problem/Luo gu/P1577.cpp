#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e4 + 5;
int n, k;
double len[maxn], l, r;

inline bool check(double);

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &len[i]);
        r = max(len[i], r);
    }
    while (fabs(l - r) > 0.00001) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid; 
    }
    printf("%lf\n", l);
    return 0;
}

inline bool check(double mid) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += floor(len[i] / mid);
    return sum >= k;
}