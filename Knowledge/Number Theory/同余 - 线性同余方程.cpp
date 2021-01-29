#include <cstdio>

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        tag = str == '-' ? -1 : 1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = ans * 10 + str - '0';
        str = getchar();
    }
    return ans * tag;
}

using namespace std;

int a, b, m, x, y;
// formula : ax + by == m
// find    : x & y

int gcd(int, int);
void exgcd(int, int);

int main() {
    a = read(), b = read(), m = read();
    if (m % gcd(a, b)) return puts("[wrong data]"), 0;
    int num = gcd(a, b);
    a /= num, b /= num, m /= num;
    exgcd(a, b);
    x *= m;
    while (x <= 0) x += b;
    x %= b;
    printf("[x] %d [y] %d\n", x, (m - a * x) / b);
    return 0;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void exgcd(int a, int b) {
    if (!b) x = 1, y = 0;
    else {
        exgcd(b, a % b);
        int mid = x;
        x = y, y = mid - (a / b) * y;
    }
}