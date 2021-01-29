#include <cstdio>
#include <algorithm>

namespace ips {
    inline long long read() {
        char str = getchar(); long long ans = 0, tag = 1;
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
}

using namespace ips;
using namespace std;

const int maxn = 1e5 + 5;

struct node {
    int lson, rson;
    int val, siz, cnt;
} tree[maxn];

int n, cnt, root, opt, num;

namespace mode {
    inline void pushup(int);
    void insert(int&, int);
    void del(int&, int);
    int delmin(int&);
    int getrnk(int, int);
    int getval(int, int);
    int getpre(int, int);
    int getnxt(int, int);
}

int main() {
    n = read();
    while (n--) {
        opt = read(), num = read();
        switch (opt) {
            case 1 : mode::insert(root, num); break;
            case 2 : mode::del(root, num); break;
            case 3 : printf("%d\n", mode::getrnk(root, num)); break;
            case 4 : printf("%d\n", mode::getval(root, num)); break;
            case 5 : printf("%d\n", tree[mode::getpre(root, num)].val); break;
            case 6 : printf("%d\n", tree[mode::getnxt(root, num)].val); break;
        }
    }
    return 0;
}

#define lson tree[now].lson
#define rson tree[now].rson
#define val(now) tree[now].val
#define siz(now) tree[now].siz
#define cnt(now) tree[now].cnt

namespace mode {
    inline void pushup(int now) {
        siz(now) = siz(lson) + siz(rson) + cnt(now);
    }

    void insert(int& now, int val) {
        if (!now) {
            tree[(now = ++cnt)] = (node) { 0, 0, val, 1, 1 };
        } else if (val(now) == val) {
            siz(now)++, cnt(now)++;
        } else if (val(now) > val) {
            insert(lson, val), pushup(now);
        } else if (val(now) < val) {
            insert(rson, val), pushup(now);
        }
    }

    void del(int& now, int val) {
        if (val(now) == val) {
            if (cnt(now) > 1) {
                siz(now)--, cnt(now)--;
            } else if (!lson) {
                now = rson;
            } else if (!rson) {
                now = lson;
            } else {
                int tmp = delmin(rson);
                val(now) = val(tmp);
                cnt(now) = cnt(tmp);
                pushup(now);
            }
        } else if (val(now) > val) {
            del(lson, val), pushup(now);
        } else if (val(now) < val) {
            del(rson, val), pushup(now);
        }
    }

    int delmin(int& now) {
        if (lson) {
            int ans = delmin(lson);
            pushup(now);
            return ans;
        } else {
            int ans = now;
            now = rson;
            return ans;
        } 
    }

    int getrnk(int now, int val) {
        if (val(now) == val) return siz(lson) + 1;
        if (val(now) > val) return getrnk(lson, val);
        if (val(now) < val) return (siz(now) - siz(rson)) + getrnk(rson, val);
    }
    
    int getval(int now, int rnk) {
        if (siz(lson) + 1 <= rnk && rnk <= siz(lson) + cnt(now)) return val(now);
        if (siz(lson) + 1 > rnk) return getval(lson, rnk);
        if (siz(lson) + 1 < rnk) return getval(rson, rnk - (siz(lson) + cnt(now)));
    }

    int getpre(int now, int val) {
        int ans = 0;
        while (now) {
            if (val(now) >= val) now = lson;
            else {
                ans = now;
                now = rson;
            }
        }
        return ans;
    }

    int getnxt(int now, int val) {
        int ans = 0;
        while (now) {
            if (val(now) <= val) now = rson;
            else {
                ans = now;
                now = lson;
            }
        }
        return ans;
    }
}

#undef lson
#undef rson
#undef val
#undef siz
#undef cnt