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
int n, m;

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];

    void build() {
        for (int i = 0; i < MAXN; i++) {
            arr[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int x) {
        return arr[x] == x ? x : arr[x] = find(arr[x]);
    }

    int unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return 0;
        if (cnt[i] < cnt[j]) swap(i, j);
        arr[j] = i;
        cnt[i] += cnt[j];
        return 1;
    }
} dsu;

array<int, 3> edges[MAXM];
// int G[MAXN][MAXN];

void sol() {
    cin >> n >> m;
    dsu.build();
    int comp = n, ans = 0;
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }
    sort(edges, edges + m, greater<>());


    for (int i = 0; i < m; i++) {
        // cout << edges[i][0] << ' ' << edges[i][1] << ' ' << edges[i][2] << endl;
        int a = edges[i][1], b = edges[i][2];
        if (dsu.find(a) != dsu.find(b) && dsu.find(a + n) != dsu.find(b + n)) {
            dsu.unite(a, b + n);
            dsu.unite(b, a + n);
            // ans -= edges[i][0];
        }
        else {
            cmax(ans, edges[i][0]);
        }
    }
    cout << ans << endl;
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