#include <cstdio>

using namespace std;

typedef long long li;

li a, b, x, y;

void exgcd(li, li, li&, li&);

int main() {
    scanf("%lld %lld", &a, &b);
    exgcd(a, b, x, y);
    while (x < 0) x += b;
    x %= b;
    printf("%lld\n", x);
    return 0;
}

void exgcd(li a, li b, li& x, li& y) {
    if (!b) {
        x = 1, y = 0;
    } else {
        exgcd(b, a % b, x, y);
        li mid = x;
        x = y, y = mid - (a / b) * y;
    }
}