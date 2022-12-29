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

struct Sparse_Table {
    int arr[20][MAXN];
    void build() {
        for (int i = 1; i <= n; i++)
            arr[0][i] = x[i];
        for (int i = 1; i < 20; i++) {
            for (int j = 1; j <= n; j++)
                arr[i][j] = min(arr[i - 1][j], arr[i - 1][j + (1 << (i - 1))]);
        }
    }

    int query(int l, int r) {
        int idx = __lg(r - l + 1);
        int rng = (1 << idx);
        return min(arr[idx][l], arr[idx][r - rng + 1]);
    }
} ST;

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] -= i;
    }
    ST.build();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (ST.query(i, mid) >= 1 - i)
                l = mid;
            else
                r = mid - 1;
        }
        ans += (x[i] >= (1 - i)) * (l - i + 1);
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