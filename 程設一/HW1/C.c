#include <stdio.h>
#define min(a, b) (a < b ? a : b)


int main() {
    char s[4];
    scanf("%s", s);

    double ans;
    ans = (double)(s[0] - '0' + s[2] - '0') / (double)(s[1] - '0' + s[3] - '0');
    printf("%.2f\n", ans);
    return 0;
}