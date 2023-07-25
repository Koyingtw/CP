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
int n, m, q;
vector<pii> G[MAXN];
bitset<MAXN> vis, vis2;
vector<array<int, 3>> E;

void sol() {
    cin >> n >> m >> q;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        G[a].pb({b, c});
        G[b].pb({a, c});
        E.pb({c, a, b});
    }
    for (int i = 0, x, y; i < q; i++) {
        cin >> x >> y;
        
        int l = 0, r = INF;
        while (l < r) {
            int mid = (l + r) / 2;
            vis.reset();
            vis2.reset();
            queue<pii> que;
            que.push({x, 0});
            vis[x] = 1;
            
            while (que.size()) {
                auto now = que.front();
                que.pop();
                // cout << now.F << " " << now.S << endl;
                if (now.F == y) {
                    break;
                }
                for (auto e: G[now.F]) if (!vis[e.F]) {
                    if ((e.S > mid) < 1) {
                        vis[e.F] = 1;
                        que.push({e.F, (e.S > mid)});
                    }
                }
            }

            if (vis[y]) {
                r = mid;
                continue;
            }

            while(que.size()) que.pop();
            que.push({y, 0});
            vis2[y] = 1;

            while (que.size()) {
                auto now = que.front();
                que.pop();
                // cout << now.F << " " << now.S << endl;
                if (now.F == x) {
                    break;
                }
                for (auto e: G[now.F]) if (!vis2[e.F]) {
                    if ((e.S > mid) < 1) {
                        vis2[e.F] = 1;
                        que.push({e.F, (e.S > mid)});
                    }
                }
            }

            for (auto it: E) {
                if (vis[it[1]] && vis2[it[2]]) {
                    vis[y] = 1;
                }
                if (vis[it[2]] && vis2[it[1]]) {
                    vis[y] = 1;
                }
            }


            if (vis[y]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (r == INF) {
            put(-1);
        } else {
            put(r);
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