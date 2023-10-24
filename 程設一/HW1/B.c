#include <stdio.h>
#define min(a, b) (a < b ? a : b)


int main() {
    int P, A, B, C, D;
    scanf("%d %d %d %d %d", &P, &A, &B, &C, &D);
    int ans = 0;
    int tar;

    tar = min(D, P / 50);
    ans += tar;
    P -= tar * 50;

    tar = min(C, P / 10);
    ans += tar;
    P -= tar * 10;

    tar = min(B, P / 5);
    ans += tar;
    P -= tar * 5;

    tar = min(A, P / 1);
    ans += tar;
    P -= tar * 1;

    if (P == 0) {
        printf("%d\n", ans);
    }
    else
        printf("-1\n");
    
    return 0;
}