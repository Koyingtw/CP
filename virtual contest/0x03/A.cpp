#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0);
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define lowbit(x) (x & (-x))
#define pb push_back
#define pf push_front
#define MEM(x, n) memset(x, n, sizeof(x))
#pragma GCC optimize("Ofast, unroll-all-loops")
const int INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 800

const int p[] = {1, 0, -1, 0, 1};
const int P = (int)1e9 + 7;

int n, m;
int x[MAXN][MAXN];
int ans[MAXN * MAXN];
pii pos[MAXN * MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x[i][j];
            pos[x[i][j]] = {i, j};
        }
    }

    ans[1] = 1;

    for (int i = 2; i <= n * n; i++) {
        auto now = pos[i];
        for (int j = 0; j < 4; j++) {
            int xx = now.F + p[j];
            int yy = now.S + p[j + 1];

            if (xx >= 0 && xx < n && yy >= 0 && yy < n && x[xx][yy] < i)
                ans[i] += ans[x[xx][yy]];
            ans[i] %= P;
        }
    }
    cout << ans[n * n] << endl;
}

signed main() {
    Koying
    sol();
    return 0;
}