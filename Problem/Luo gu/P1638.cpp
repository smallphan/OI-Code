#include <cstdio>

using namespace std;

const int maxn = 1e6 + 5, inf = 0x7f7f7f7f;
int l, r, tot, cnt[maxn], min, ansl, ansr;
int n, m, pic[maxn];

inline long long read();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) pic[i] = read();
    l = 1, r = 1, tot = 1, cnt[pic[1]] = 1, min = inf;
    while (l <= r && r <= n) {
        if (tot == m) {
            if (min > r - l + 1) {
                min = r - l + 1;
                ansl = l, ansr = r;
            } 
            cnt[pic[l]]--;
            if (!cnt[pic[l]]) tot--;
            l++;
        } else {
            r++;
            cnt[pic[r]]++;
            if (cnt[pic[r]] == 1) tot++;
        }
    }
    printf("%d %d\n", ansl, ansr);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}