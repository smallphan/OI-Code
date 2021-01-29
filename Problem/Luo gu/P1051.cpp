#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
struct node {
    string nam;
    int ter, cla, art, pos, val;
    bool mas, wes;
    inline void ana() {
        if (ter > 80 && art >= 1) val += 8e3;
        if (ter > 85 && cla > 80) val += 4e3;
        if (ter > 90) val += 2e3;
        if (ter > 85 && wes) val += 1e3;
        if (cla > 80 && mas) val += 850;
    }
    inline bool operator < (const node& data) const {
        return (val == data.val) ? (pos < data.pos) : (val > data.val);
    }
} stu[maxn];
int n, sum;
char op[2];

inline void input(int);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        input(i), stu[i].ana();
    }
    sort(stu + 1, stu + 1 + n);
    for (int i = 1; i <= n; i++) sum += stu[i].val;
    cout << stu[1].nam << endl;
    printf("%d\n%d\n", stu[1].val, sum);
    return 0;
}

inline void input(int i) {
    cin >> stu[i].nam;
    scanf("%d %d %s", &stu[i].ter, &stu[i].cla, op);
    stu[i].mas = op[0] == 'Y';
    scanf("%s", op);
    stu[i].wes = op[0] == 'Y';
    scanf("%d", &stu[i].art);
    stu[i].pos = i;
}