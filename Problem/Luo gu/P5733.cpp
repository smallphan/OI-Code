#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 105;
char str[maxn];

inline char find(char);

int main() {
    scanf("%s", str + 1);
    for (int i = 1; i <= strlen(str + 1); i++) printf("%c", find(str[i]));
}

inline char find(char c) {
    if (c >= 'a' && c <= 'z') return c + 'A' - 'a';
    else return c;
}