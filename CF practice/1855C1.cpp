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
int x[MAXN];

vector<pii> ans;

void DC(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) / 2;
    DC(l, mid);
    DC(mid + 1, r);

    if (x[mid] > x[mid + 1]) {
        if (x[mid] > 0 && x[mid + 1] >= 0) {
            for (int i = mid + 1; i <= r; i++) {
                ans.pb({i, mid});
                x[i] += x[mid];
            }
        }
        else if (x[mid] > 0 && x[mid + 1] < 0) {
            if (x[mid] > abs(x[mid] + 1)) {
                for (int i = mid + 1; i <= r; i++) {
                    ans.pb({i, mid});
                    ans.pb({i, mid});
                    x[i] += 2 * x[mid];
                }
            }
            else {
                for (int i = mid; i >= l; i--) {
                    ans.pb({i, mid + 1});
                    ans.pb({i, mid + 1});
                    x[i] += 2 * x[mid];
                }
            }
        }
        else if (x[mid] <= 0 && x[mid + 1] < 0) {
            for (int i = mid; i >= l; i--) {
                ans.pb({i, mid + 1});
                x[i] += x[mid + 1];
            }
        }
    }
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
    
    
    if (abs(mx.F) > abs(mn.F)) {
        if (mx.F > 0) {
            for (int i = 0; i < n; i++) if (x[i] < 0) {
                ans.pb({i, mx.S});
                x[i] += x[mx.S];
            }
        }
        for (int i = 1; i < n; i++) if (x[i] < x[i - 1]) {
            ans.pb({i, i - 1});
            x[i] += x[i - 1];
        }
    }
    else {
        if (mx.F > 0) {
            for (int i = 0; i < n; i++) if (x[i] > 0) {
                ans.pb({i, mn.S});
                x[i] += x[mn.S];
            }
        }
        for (int i = n - 2; ~i; i--) if (x[i] > x[i + 1]) {
            ans.pb({i, i + 1});
            x[i] += x[i + 1];
        }
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