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
#define MAXN 1000005
#define MAXM 1000005 
int n, m, k;
int x[MAXN], cnt[MAXN], pre[MAXN];

struct Fenwick_Tree {
    int arr[MAXN];
    void add(int x, int v) {
        for (int i = x; i < MAXN; i += lowbit(i)) {
            arr[i] += v;
        }
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) {
            res += arr[i];
        }
        return res;
    }
} BIT;

void sol() {
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        v[i] = x[i];
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for (int i = 0; i < n; i++) {
        x[i] = upper_bound(all(v), x[i]) - v.begin();
        cnt[x[i]]++;
    }

    for (int i = 0, l = 0, r = k - 1; i < n; i++) {
        // cout << l << ' ' << r << endl;
        // cout << v[x[r + 1] - 1] << ' ' << v[x[i] - 1] << ' ' << v[x[l] - 1] << endl;
        if (r < n - 1 && v[x[r + 1] - 1] - v[x[i] - 1] < v[x[i] - 1] - v[x[l] - 1])
            l++, r++;

        // cout << l << ' ' << r << endl;
        
        BIT.add(x[l], 1);
        BIT.add(x[r], -1);
    }

    pii mx(0, 0);

    for (int i = 0; i < n; i++) {
        // cout << BIT.query(x[i]) << " ";
        cmax(mx, pii(BIT.query(x[i]), -x[i]));
    }
    cout << mx.F << ' ' << v[-mx.S - 1] << endl;
    return;

    for (int l = 1, r = 1; r <= v.size(); r++) {
        pre[r] = pre[r - 1] + cnt[r];
        while (pre[r] - pre[l - 1] > k - 1) {
            l++;
        }

        if (l > r)
            continue;

        BIT.add(l, min((k - 1) - (pre[r] - pre[l - 1]) + 1, cnt[r]));
        BIT.add(r + 1, -min((k - 1) - (pre[r] - pre[l - 1]) + 1, cnt[r]));
        cout << l << ' ' << r << endl;
    }

    for (int i = 1; i <= v.size(); i++)
        cout << BIT.query(i) << " ";
    cout << endl;
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