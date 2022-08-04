#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1005
#define MAXM 1000005 
int n, m;
pair<pii, pii> f[MAXN];

int dis(pii a, pii b) {
    return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}

void sol() {
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> f[i].F.F >> f[i].F.S >> f[i].S.F >> f[i].S.S;
    }
    for (int t = 0; t < m; t++) {
        int x, y, r;
        cin >> x >> y >> r;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int mn = INF;
            cmin(mn, dis(pii(x, y), pii(f[i].F.F, f[i].F.S)));
            cmin(mn, dis(pii(x, y), pii(f[i].F.F, f[i].S.S)));
            cmin(mn, dis(pii(x, y), pii(f[i].S.F, f[i].F.S)));
            cmin(mn, dis(pii(x, y), pii(f[i].S.F, f[i].S.S)));

            int foo = 0;
            if (f[i].F.F <= x && x <= f[i].S.F) {
                cmin(mn, abs(y - f[i].F.S) * abs(y - f[i].F.S));
                cmin(mn, abs(y - f[i].S.S) * abs(y - f[i].S.S));
                foo++;
            }

            if (f[i].F.S <= y && y <= f[i].S.S) {
                cmin(mn, abs(x - f[i].F.F) * abs(x - f[i].F.F));
                cmin(mn, abs(x - f[i].S.F) * abs(x - f[i].S.F));
                foo++;
            }


            if (mn <= r * r || foo == 2)
                cnt++;
        }
        cout << cnt << endl;
    }
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