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
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

pii operator +(pii _a, pii _b) {
    pii res;
    res.F = min(_a.F, _b.F);
    res.S = max(_a.S, _b.S);
    return res;
}

struct Sparse_Table {
    pii arr[20][MAXN];

    void build() {
        for (int i = 1; i <= n; i++)
            arr[0][i] = pii(x[i], x[i]);
        for (int i = 1; i <= __lg(n); i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j + (1 << (i - 1))];
            }
        }
    }

    pii query(int l, int r) {
        int lg = __lg(r - l + 1);
        int rng = (1 << lg);
        return arr[lg][l] + arr[lg][r - rng + 1];
    }
} ST;

void sol() {
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        mp[x[i]].pb(i);
    }
    ST.build();

    for (int i = 1; i < n; i++) {
        // cout << i << ": \n";
        int tar = ST.query(1, i).S;

        if (mp[tar].size() < 3)
            continue;

        int l = i + 1, r = mp[tar].back() - 1;
        int mid;

        while (l <= r) {
            mid = (l + r) / 2;
            // cout << l << ' ' << mid << ' ' << r << endl;
            // cout << ST.query(i + 1, mid).F << ' ' << ST.query(mid + 1, n).S << ' ' << tar << endl;
            if ((ST.query(i + 1, mid).F == tar) && (ST.query(mid + 1, n).S == tar)) {
                cout << "YES" << endl;
                cout << i << ' ' << mid - i << ' ' << n - mid << endl;
                return;
            }
            if (ST.query(i + 1, mid).F < tar || ST.query(mid + 1, n).S < tar) {
                r = mid - 1;
            }
            else if (ST.query(i + 1, mid).F > tar || ST.query(mid + 1, n).S > tar) {
                l = mid + 1;
            }
            else
                break;
        }
    }
    cout << "NO" << endl;
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