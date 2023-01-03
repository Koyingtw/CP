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
#define SZ(v) ((int)v.size())
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
int x[MAXN];
int y[MAXN];
int z[MAXN];
int a[MAXN];
map<int, int> mp;

void f(int l, int r) {
    set<int> st;
    while (l < r && y[l] >= y[l + 1]) {
        mp[y[l]] -= (x[l] > y[l]);
        l++;
    }
    while (l < r && y[r] >= y[r - 1]) {
        mp[y[r]] -= (x[r] > y[r]);
        r--;
    }
    // cout << l << ' ' << r << endl;
    if (l > r)
        return;
    if(l == r) {
        mp[y[l]] -= (x[l] > y[l]);
        // cout << y[l] << endl;
        return;
    }
    int mx = *max_element(y + l, y + r + 1);
    bool need = 0;
    for (int i = l; i <= r; i++) if (y[i] == mx && x[i] > mx)
        need = 1;
    mp[mx] -= need;
    if (need) {
        // cout << mx << endl;
    }
    int now = l;
    for (int i = l; i <= r; i++) {
        if (i == now && y[i] == mx) {
            now = i + 1;
            continue;
        }
        if (y[i] == mx) {
            f(now, i - 1);
            now = i + 1;
        }
    }
    if (y[r] != mx)
        f(now, r);
}

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    mp.clear();
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        z[i] = x[i] - y[i];
        // cout << z[i] << ' ';
    }
    // cout << endl;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    if (*min_element(z, z + n) < 0) {
        cout << "NO" << endl;
        return;
    }

    f(0, n - 1);
    for (auto it: mp) {
        if (it.S < 0) {
            // cout << it.F << ' ' << it.S << endl;
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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