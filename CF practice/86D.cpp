#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN], ans[MAXN];
pair<pii, int> q[MAXN];

struct Mo_Algo {
    int mp[MAXM];
    int ans = 0;

    void update(int tar, int delta) {
        tar = x[tar];
        ans -= tar * mp[tar] * mp[tar];
        mp[tar] += delta;
        ans += tar * mp[tar] * mp[tar];
    }
} Mo;


void sol() {
    cin >> n >> m;
    int sq = sqrt(n);

    for (int i = 1; i <= n; i++)
        cin >> x[i];

    for (int i = 1; i <= m; i++) {
        cin >> q[i].F.F >> q[i].F.S;
        q[i].S = i;
    }

    Mo.mp[0] = 1;

    sort(q + 1, q + 1 + m, [&](auto _a, auto _b) {
        if (_a.F.F / sq != _b.F.F / sq)
            return _a.F.F < _b.F.F;
        else
            return _a.F.S < _b.F.S;
    });

    int l = 0, r = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = r + 1; j <= q[i].F.S; j++) {
            Mo.update(j, 1);
            r++;
        }
        for (int j = r; j > q[i].F.S; j--) {
            Mo.update(j, -1);
            r--;
        }

        for (int j = l - 1; j >= q[i].F.F; j--) {
            Mo.update(j, 1);
            l--;
        }
        for (int j = l; j < q[i].F.F; j++) {
            Mo.update(j, -1);
            l++;
        }
        ans[q[i].S] = Mo.ans;
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}