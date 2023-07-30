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
#define MAXN 25
#define MAXM 1000005 
int n, m;
int x[MAXN];

vector<pii> ans;

vector<pii> sol1() {
    vector<pii> ret;
    vector<int> y(MAXN);

    pii mn = pii(INF, 0), mx = pii(-INF, 0);

    for (int i = 0; i < n; i++){
        y[i] = x[i];
        cmin(mn, pii(x[i], i));
        cmax(mx, pii(x[i], i));
    }

    while (x[mn.S] + x[mx.S] > 0) {
        ret.pb({mn.S, mn.S});
        x[mn.S] += x[mn.S];
    }

    for (int i = 0; i < n; i++) if (x[i] > 0) {
        ret.pb({i, mn.S});
        x[i] += x[mn.S];
    }

    for (int i = n - 2; ~i; i--) if (x[i] > x[i + 1]) {
        ret.pb({i, i + 1});
        x[i] += x[i + 1];
        cmin(mn, pii(x[i], i));
    }

    for (int i = 0; i < n; i++)
        x[i] = y[i];
    return ret;
}

vector<pii> sol2() {
    vector<pii> ret;
    vector<int> y(MAXN);

    pii mn = pii(INF, 0), mx = pii(-INF, 0);

    for (int i = 0; i < n; i++){
        y[i] = x[i];
        cmin(mn, pii(x[i], i));
        cmax(mx, pii(x[i], i));
    }


    while (x[mn.S] + x[mx.S] < 0) {
        ret.pb({mx.S, mx.S});
        x[mx.S] += x[mx.S];
    }

    for (int i = 0; i < n; i++) if (x[i] < 0) {
        ret.pb({i, mx.S});
        x[i] += x[mx.S];
    }
    for (int i = 1; i < n; i++) if (x[i] < x[i - 1]) {
        ret.pb({i, i - 1});
        x[i] += x[i - 1];
    }

    for (int i = 0; i < n; i++)
        x[i] = y[i];

    return ret;
}

void sol() {
    cin >> n;
    ans.clear();
    pii mn = pii(INF, 0), mx = pii(-INF, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++){
        cin >> x[i];
        cmin(mn, pii(x[i], i));
        cmax(mx, pii(x[i], i));
        if (x[i] < 0)
            cnt++;
    }
    
    
    if (mn.F >= 0) {
        for (int i = 1; i < n; i++) if (x[i] < x[i - 1]) {
            ans.pb({i, i - 1});
            x[i] += x[i - 1];
        }
    }
    else if (mx.F <= 0) {
        for (int i = n - 2; ~i; i--) if (x[i] > x[i + 1]) {
            ans.pb({i, i + 1});
            x[i] += x[i + 1];
        }
    }
    else {
        auto s1 = sol1();
        auto s2 = sol2();
        // ans = s2;
        ans = (s1.size() < s2.size() ? s1 : s2);
    }

    cout << ans.size() << endl;
    for (auto it: ans)
        cout << it.F + 1 << ' ' << it.S + 1 << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}