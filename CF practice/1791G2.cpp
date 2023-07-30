#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
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
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
array<int, 3> x[MAXN];
int pos[MAXN];
bitset<MAXN> used;

struct Fenwick_Tree {
    ll arr[MAXN];

    void init() {
        for (int i = 1; i <= n; i++)
            arr[i] = 0;
    }

    void update(int i, int val) {
        for (; i <= n; i += lowbit(i))
            arr[i] += val;
    }

    int query(int i) {
        ll ret = 0;
        for (; i > 0; i -= lowbit(i))
            ret += arr[i];
        return ret;
    }
} BIT;

void sol() {
    cin >> n >> m;
    BIT.init();
    for (int i = 1; i <= n; i++) {
        cin >> x[i][1];
        x[i][2] = i;
        x[i][0] = min(x[i][1] + i, x[i][1] + (n - i + 1));
    }

    sort(x + 1, x + n + 1);

    for (int i = 1; i <= n; i++) {
        pos[x[i][2]] = i;
        BIT.update(i, x[i][0]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (x[i][1] + x[i][2] > m)
            continue;

        BIT.update(i, -x[i][0]);
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (BIT.query(mid) + x[i][1] + x[i][2] <= m)
                l = mid;
            else
                r = mid - 1;
        }
        cmax(ans, l + (i > l));
        BIT.update(i, x[i][0]);
    }
    cout << ans << endl;
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