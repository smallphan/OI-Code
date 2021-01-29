// the usage of [template]
#include <cstdio>

using namespace std;

int a, b;
long long c, d;
float e, f;
double g, h;

template <typename T>
T add(T, T);

int main() {
    a = 999, b = 888;
    c = 10000000000000, d = 434234324343434;
    e = 2.333, f = 88.888;
    g = 3.1415926, h = 632222222;
    printf("[a+b] %d\n", add(a, b));
    printf("[c+d] %lld\n", add(c, d));
    printf("[e+f] %f\n", add(e, f));
    printf("[g+h] %lf\n", add(g, h));
    return 0;
}

template <typename T>
T add(T a, T b) {
    return a + b;
}