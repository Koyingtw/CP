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
int n, q;

struct Disjoint_Set {
    int arr[MAXN], sz[MAXN], cnt[MAXN];
    vector<int> G[MAXN];
    vector<pii> h[MAXN];

    void init(int n) {
        for (int i = 0; i <= n; i++) {
            arr[i] = i;
            sz[i] = 1;
            cnt[i] = 0;
            G[i].clear();
            G[i].pb(i);
            h[i].clear();
            h[i].pb({i, 0});
        }
    }

    int find(int x) {
        return arr[x] == x ? x : arr[x] = find(arr[x]);
    }

    void unite(int a, int b, int i) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        arr[b] = a;
        sz[a] += sz[b];
        cnt[a] += cnt[b];
        for (auto it: G[b]) {
            G[a].pb(it);
            h[it].pb({a, i});
        }
        G[b].clear();
    }
} dsu;

vector<array<int, 3>> v;

void sol() {
    cin >> n >> q;
    int e, a, b, k;
    dsu.init(n);
    
    for (int i = 1; i <= q; i++) {
        cin >> e;
        if (e == 1 && cin >> a >> b) {
            dsu.unite(a, b, i);
        }
        else if (cin >> k) {
            vector<int> x;
            for (int j = 0; j < k; j++) {
                cin >> a;
                x.pb(a);
            }

            bool legal = 1;
            for (int j = 1; j < k; j++) {
                if (dsu.h[x[j]].back().F != dsu.h[x[j - 1]].back().F) {
                    cout << -1 << endl;
                    legal = false;
                    break;
                }
            }

            if (!legal) continue;

            map<int, pii> mp;

            int mn = INF;
            int god = dsu.find(x[0]);
            for (int j = 0; j < k; j++) {
                for (auto it: dsu.h[x[j]]) {
                    if (!mp.count(it.F))
                        mp[it.F] = {1, it.S};
                    else {
                        mp[it.F].F++;
                        cmax(mp[it.F].S, it.S);
                    }
                }
            }

            for (auto [a, b]: mp) {
                if (b.F == k)
                    cmin(mn, b.S);
            }

            cout << mn << endl;
        }
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