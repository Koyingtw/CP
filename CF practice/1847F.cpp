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
int x[MAXN * 2], ans[MAXN];
pii q[MAXN];

struct Sparse_Table {
    int arr[20][MAXN * 2];

    void build() {
        int lg = __lg(2 * n);
        for (int i = 1; i <= lg; i++)
            for (int j = 1; j <= 2 * n; j++)
                arr[i][j] = 0;
        for (int i = 1; i <= n; i++)
            arr[0][i] = arr[0][i + n] = x[i];
        for (int i = 1; i <= lg; i++)
            for (int j = 1; j <= 2 * n; j++) if (j + (1 << i) - 1 <= 2 * n)
                arr[i][j] = arr[i - 1][j] | arr[i - 1][j + (1 << (i - 1))];
    }

    int query(int l, int r) {
        if (l > r)
            return 0;
        int lg = __lg(r - l + 1);
        return (arr[lg][l] | arr[lg][r - (1 << lg) + 1]);
    }
} ST;


void sol() {
    cin >> n >> m;
    vector<pii> v;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        v.pb({x[i], i});
    }
    ST.build();

    for (int i = 2; i <= n; i++) {
        int tmp = i + n;
        if (ST.query(i + 1, i + n) == ST.query(i + n, i + n))
            continue;
        for (int j = 0; j <= 30 && tmp - 1 >= i + 1; j++) {
            int l = i + 1, r = tmp - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (ST.query(mid, i + n) > ST.query(tmp, i + n))
                    l = mid;
                else    
                    r = mid - 1;
            }
            if (ST.query(l, i + n) > ST.query(tmp, i + n)) {
                v.emplace_back(ST.query(l, i + n), n + (i + n - l - 1) * (n - 1) + i - 1);
                tmp = l;
            }
            else
                break;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> q[i].F;
        q[i].S = i;
    }
    sort(q, q + m, greater<>());
    sort(all(v), greater<>());

    int mn = INFLL;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < v.size() && v[j].F > q[i].F) {
            cmin(mn, v[j].S);
            j++;
        }

        ans[q[i].S] = (mn == INFLL ? -1 : mn);
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
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

// [1, 1], [2, 2], [3, 3], [4, 4], [5, 5], [1, 2], [2, 3], [3, 4], [4, 5], [5, 2], [1, 3], [2, 4], [3, 5], [4, 2], [5, 3], [1, 4], [2, 5], [3, 2];