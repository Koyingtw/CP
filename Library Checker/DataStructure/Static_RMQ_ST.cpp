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

/** 適用於初始化後不修改的情況，只能查極值。 **/
#define cc(a) floor(log2(a)) // 加速
struct SparseTable {
    // 不會 overflow 的話可以情況全部換成 vector<int>
    vector<vector<ll>> a;
    // 建立空的 sparse table ，元素初始為 data 。不可更改。
    SparseTable(vector<ll>& data) {
        int n = data.size();
        a.assign(cc(n) + 1, vector<ll>(n));
        a[0] = data;
        for (int i = 1; (1 << i) <= n; i++) {
            int k = n - (1 << i);
            for (int j = 0; j <= k; j++) {
                a[i][j] = min(a[i - 1][j],
                            a[i - 1][j + (1 << (i - 1))]);
    }}}
    // 查詢 [l, r] 區間最大值。0/1-based 都安全。
    ll maxx(int l, int r) {
        int k = cc(r - l + 1);
        return min(a[k][l], a[k][r - (1 << k) + 1]);
    }
};


vector<int> v;

void sol() {
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    SparseTable ST(v);
    
    int l, r;
    while (m--) {
        cin >> l >> r;
        cout << ST.maxx(l + 1, r) << endl;
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