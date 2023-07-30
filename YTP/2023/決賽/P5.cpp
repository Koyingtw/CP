#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
pii x[MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i].F >> x[i].S;
    }
    sort(x, x + n);
    int mnx = x[0].F;
    int mxx = x[n - 1].F;

    sort(x, x + n, [&](auto a, auto b) {
        return (a.S == b.S ? a.F < b.F : a.S < b.S);
    });

    int mny = x[0].S;
    int mxy = x[n - 1].S;
    pii ans;
    int dis;
    if (mxx - mnx < mxy - mny) {
        ans.S = max(mny + (mxy - mny) / 2, 0);
        dis = max(ans.S - mny, mxy - ans.S);
        ans.F = max(mnx + ((mxx - mnx) - dis), 0);
    }
    else if (mxx - mnx == mxy - mny) {
        cout << (mxx - mnx + 1) / 2 << endl;
        cout << mnx + (mxx - mnx) / 2 << ' ' << mny + (mxy - mny) / 2 << endl;
        return;
    }
    else {
        ans.F = mnx + (mxx - mnx) / 2;
        dis = max(ans.F - mnx, mxx - ans.F);
        ans.S = max(mny + ((mxy - mny) - dis), 0);
    }
    cout << dis << endl;
    cout << ans.F << ' ' << ans.S << endl;
}

// 30 / 10 / 10 / 10 / 10 / 10 / 15 / 20 / 20 / 20 / 20 / 20 / 25 / 25 / 25

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