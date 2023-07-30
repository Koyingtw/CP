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
int n, m, q;

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];
    void init() {
        for (int i = 0; i <= n; i++)
            arr[i] = i, cnt[i] = 1;
    }

    int find(int i) {
        return arr[i] == i ? i : arr[i] = find(arr[i]);
    }

    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return;
        if (cnt[i] < cnt[j])
            swap(i, j);
        arr[j] = i;
        cnt[i] += cnt[j];
    }
} dsu;

pii x[MAXN];
vector<pii> G[MAXN];
array<int, 4> Q[MAXN];
bool ans[MAXN];

void sol() {
    cin >> n >> m;
    dsu.init();
    for (int i = 1; i <= n; i++) {
        cin >> x[i].F;
        x[i].S = i;
        G[i].clear();
    }
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb({b, x[b].F});
        G[b].pb({a, x[a].F});
    }

    cin >> q;
    for (int i = 0, a, b, c; i < q; i++) {
        cin >> Q[i][1] >> Q[i][2] >> Q[i][0];
        Q[i][3] = i;
        Q[i][0] += x[Q[i][1]].F;
        ans[i] = 0;
    }   
    sort(x + 1, x + n + 1);
    sort(Q, Q + q);

    for (int i = 0, j = 1; i < q; i++) {
        while (j <= n && x[j].F <= Q[i][0]) {
            for (auto it: G[x[j].S]) {
                if (it.S <= Q[i][0])
                    dsu.unite(x[j].S, it.F);
            }
            j++;
        }
        ans[Q[i][3]] = dsu.find(Q[i][1]) == dsu.find(Q[i][2]);
    }
    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "YES" : "NO") << endl;
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