#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 5005
#define MAXM 1000005 
int n, m;
int ans[MAXN];
int x[MAXN];

struct Sparse_Table {
    pii arr[30][MAXN];
    bool legal[30][MAXN];

    void build() {
        for (int i = 0; i < n; i++) {
            arr[0][i] = pii(x[i], x[i]);
            legal[0][i] = true;
        }
        for (int i = 1; i <= __lg(n); i++)
            for (int j = 0; j < n; j++) {
                arr[i][j].F = min(arr[i - 1][j].F, arr[i - 1][j + (1 << (i - 1))].F);
                arr[i][j].S = max(arr[i - 1][j].S, arr[i - 1][j + (1 << (i - 1))].S);
                legal[i][j] = (legal[i - 1][j] && legal[i - 1][j + (1 << (i - 1))] && arr[i - 1][j].F < arr[i - 1][j + (1 << (i - 1))].S);
                // cout << arr[i][j].F << ' ' << arr[i][j].S << endl;
            }
    }

    pii query(int l, int r) {
        int lg = __lg(r - l + 1);
        int rng = (1 << lg);
        pii res;
        res.F = min(arr[lg][l].F, arr[lg][r - rng + 1].F);
        res.S = max(arr[lg][l].S, arr[lg][r - rng + 1].S);

        return res;
    }

    bool islegal(int l, int r) {
        int lg = __lg(r - l + 1);
        int rng = (1 << lg);
        return legal[lg][l] && legal[lg][r - rng + 1];
    }
} ST;

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    ST.build();


    for (int i = 0; i < n; i++) {
        int l = 0, r = i;
        while (l < r) {
            int mid = (l + r) / 2;
            if (ST.query(mid, i).S <= x[i])
                r = mid;
            else
                l = mid + 1;
        }
 
        int mn = r;
 
        l = i, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (ST.query(i, mid).F >= x[i])
                l = mid;
            else
                r = mid - 1;
        }
 
        int mx = l;
 
        // cout << mn << ' ' << mx << endl;
 
        for (int j = 1; j <= mx - mn + 1; j++) {
            ans[j] += j;
            if (i - j + 1 < mn)
                ans[j] -= mn - (i - j + 1);
            if (i + j - 1 > mx)
                ans[j] -= (i + j - 1) - mx;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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