#include <cstdio>

namespace ios {
    inline long long read() {
        long long ans = 0, tag = 1; char str = getchar();
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
    template<typename type> inline void write(type ans) {
        if (ans < 0) putchar('-'), ans = -ans;
        if (ans > 9) write(ans / 10);
        putchar(ans % 10 + '0');
    }
}

using namespace ios;

int main() {
    write(read() + read());
    return 0;
}