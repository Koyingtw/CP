#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))
#define MEM(x, n) memset(x, n, sizeof(x))
#define pii pair<int, int>
#define F first
#define S second
#if !LOCAL
#pragma GCC optimize("Ofast, unroll-all-loops")
#define endl '\n'
#endif
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

#define MAXN 1505
#define MAXM 1000005

int n, m;
int x[MAXN][MAXN];
int pre[MAXN][MAXN];

int cal(int x1, int y1, int x2, int y2) {
    // cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << endl;
    return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> x[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x[i][j];
        }
    }

    int ans = -INF;
    pii posx(1, 1), posy(1, 1);

    for (int i = 1; i <= n; i++) {
        pii mn(0, 1);
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += x[i][j];
            if (sum - mn.F > ans) {
                ans = sum - mn.F;
                posx = pii(i, i);
                posy = pii(mn.S, j);
            }

            if (sum < mn.F) {
                mn = pii(sum, j + 1);
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        pii mn(0, 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += x[i][j];
            if (sum - mn.F > ans) {
                ans = sum - mn.F;
                posx = pii(mn.S, i);
                posy = pii(j, j);
            }

            if (sum < mn.F) {
                mn = pii(sum, i + 1);
            }
        }
    }

    cout << ans << endl;

    for (int i = 1; i < posy.F; i++)
        cout << 'L';
    for (int i = m; i > posy.S; i--)
        cout << 'R';
    for (int i = 1; i < posx.F; i++)
        cout << 'U';
    for (int i = n; i > posx.S; i--)
        cout << 'D';

    if (posx.F == posx.S)
        cout << 'U' << endl;
    else
        cout << 'L' << endl;
}

signed main() {
    IOS;
    int _ = 1;
    // cin >> _;
    while (_--) 
    {
        sol();
    }
    return 0;
}