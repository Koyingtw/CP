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
#define MAXN 100005
#define MAXM 1000005 
int n, m, k;
int q[MAXN];
pii x[MAXN];

struct Fenwick_Tree {
    int arr[MAXN];
    void init() {
        for (int i = 1; i <= n; i++)
            arr[i] = 0;
    }

    void add(int x, int v) {
        for (; x <= n; x += lowbit(x))
            arr[x] += v;
    }

    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x))
            res += arr[x];
        return res;
    }
} BIT;

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i].F >> x[i].S;
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> q[i];
    }

    int l = 1, r = k + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        BIT.init();
        for (int i = 1; i <= mid; i++) {
            BIT.add(q[i], 1);
            // BIT.add(q[i] + 1, -1);
        }
        // cout << BIT.query(2) << endl;
        int cnt = 0;
        for (int i = 1; i <= m && cnt < 1; i++) {
            int qry = BIT.query(x[i].S) - BIT.query(x[i].F - 1);
            // cout << mid << ' ' << x[i].S - x[i].F + 1 << ' ' << x[i].S - x[i].F + 1 - qry << endl;
            if (qry > x[i].S - x[i].F + 1 - qry) {
                cnt++;
            }
        }
        if (cnt)
            r = mid;
        else
            l = mid + 1;
    }
    cout << (r == k + 1 ? -1 : r) << endl;
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