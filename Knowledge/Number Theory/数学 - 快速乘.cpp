#include <cstdio>

using namespace std;

typedef unsigned long long uli;
uli t, fir, sec, mod;

inline long long read();
uli qmul(uli, uli, uli);

int main() {
    t = read();
    while (t--) {
        fir = read(), sec = read(), mod = read();
        printf("%llu * %llu = %llu [mod %llu]\n", fir, sec, qmul(fir, sec, mod), mod);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
uli qmul(uli fir, uli sec, uli mod) {
    uli ans = 0;
    while (sec) {
        if (sec & 1) ans = (ans + fir) % mod;
        sec = sec >> 1;
        fir = (fir << 1) % mod;
    }
    return ans;
}