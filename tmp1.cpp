#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
#define pii pair<int, int>hi
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
int ans[MAXN];

struct Fenwick_Tree {
    int arr[MAXN];

    void add(int x, int v) {
        for (int i = x; i < MAXN; i += lowbit(i)) {
            arr[i] += v;
        }
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += arr[i];
        }
        return ans;
    }
} BIT;

void sol() {
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> x[i].F >> x[i].S;
        nums.pb(x[i].F);
        nums.pb(x[i].S);
    }
    vector<int> L, R;
    for (int i = 0; i < n; i++) {
        L.pb(x[i].F);
        R.pb(x[i].S);
    }
    for (int i = 0; i < n; i++) {
        ans[i] = lower_bound(all(L), x[i].S - 1) - lower_bound(all(L), x[i].F);
        cout << lower_bound(all(L), x[i].S - 1) - L.begin() << " " << lower_bound(all(L), x[i].F) - L.begin() << endl;
        // ans[i] += upper_bound(all(R), x[i].S) - 1 - lower_bound(all(R), x[i].F + 1);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());
    for (int i = 0; i < n; i++) {
        x[i].F = lower_bound(all(nums), x[i].F) - nums.begin() + 1;
        x[i].S = lower_bound(all(nums), x[i].S) - nums.begin() + 1;
    }
    vector<array<int, 3>> point;
    for (int i = 0; i < n; i++) {
        point.pb({x[i].F, 1, i});
        point.pb({x[i].S, -1, i});
    }

    sort(all(point));

    for (auto p : point) {
        if (p[1] == 1) {
            // BIT.add(p[0], 1);
        } else {
            ans[p[2]] -= BIT.query(p[0]) - BIT.query(x[p[2]].F - 1);
            BIT.add(x[p[2]].F, 1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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