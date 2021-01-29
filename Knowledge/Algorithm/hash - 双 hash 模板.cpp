#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int basei = 13331;
const int baseii = 17341;
ull hashi[maxn], pi[maxn], hashii[maxn], pii[maxn];
char str[maxn];

ull idx(char);
ull geti(int, int);
ull getii(int, int);

int main() {
    cin >> (str + 1);
    pi[0] = pii[0] = 1;
    for (int i = 1; i <= strlen (str + 1); i++) {
        hashi[i] = hashi[i - 1] * basei + idx(str[i]);
        hashii[i] = hashii[i - 1] * baseii + idx(str[i]);
        pi[i] = pi[i - 1] * basei;
        pii[i] = pii[i - 1] * baseii;
    }
    printf("[hash]\n");
    for (int len = 1; len <= strlen(str + 1); len++) {
        for (int l = 1, r = l + len - 1; r <= strlen(str + 1); l++, r++) {
            printf("[");
            for (int i = l; i <= r; i++) printf("%c", str[i]);
            printf("] ");
            printf("<%llu, %llu>\n", geti(l, r), getii(l, r));
        }
    }
    return 0;
}

ull idx(char str) {
    return str - 'A' + 1;
}
ull geti(int l, int r) {
    return hashi[r] - hashi[l - 1] * pi[r + l - 1];
}
ull getii(int l, int r) {
    return hashii[r] - hashii[l - 1] * pii[r + l - 1];
}