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
int x[MAXN * 2];

struct Sparse_Table {
    int arr[20][MAXN * 2];

    void build() {
        for (int i = 0; i < n; i++)
            arr[0][i] = x[i];
        for (int i = 1; i < 20; i++)
            for (int j = 1; j <= 2 * n; j++)
                arr[i][j] = arr[i - 1][j] | arr[i - 1][j + (1 << (i - 1))];
    }

    int query(int l, int r) {
        int lg = __lg(r - l + 1);
        return arr[lg][l] | arr[lg][r - (1 << lg) + 1];
    }
} ST;

struct Fenwick_Tree {
    int arr[MAXN * 2];

    void init() {
        for (int i = 1; i <= n; i++)
            arr[i] = 0;
    }

    void update(int i, int v) {
        for (; i < n * 2; i += lowbit(i))
            cmax(arr[i], v);
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i))
            cmax(ans, arr[i]);
        return ans;
    }
} BIT[20];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    ST.build();

    for (int i = 0; i < 20; i++) {
        BIT[i].init();
        for (int j = 1; j <= 2 * n; j++)
            BIT[i].update(j, ST.arr[i][j]);
    }

    int q;
    while (m--) {
        cin >> q;
        int l = 0, r = __lg(n) + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (BIT[mid].query(q) >= q)
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << endl;
    }
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