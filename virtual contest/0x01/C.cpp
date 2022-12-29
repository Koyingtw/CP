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
#define MAXN 100005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
pair<int, char> dis[MAXN];
bool to_lca[MAXN];
bitset<MAXN> vis;

void sol() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    queue<pair<int, char>> q;
    q.push({1, 'Y'});
    dis[1] = {1, 'Y'};
    q.push({n, 'P'});
    dis[n] = {1, 'P'};

    int mxy = 1, mxp = 1;
    int mxY = 1, mxP = 1;
    

    while (q.size()) {
        auto now = q.front();
        q.pop();

        for (int e: G[now.F]) {
            if (!dis[e].F) {
                q.push({e, now.S});
                dis[e] = {dis[now.F].F + 1, now.S};
            }
            if (dis[e].S != now.S) {
                to_lca[now.F] = true;
            }
        }
        for (int e: G[now.F]) {
            if (dis[e].S == now.S && dis[e].F == dis[now.F].F + 1) {
                to_lca[e] = to_lca[now.F];
                // cout << now.F << ' ' <<  e << " true" << endl;
            }
        }

        if (!to_lca[now.F]) {
            if (now.S == 'Y')
                cmax(mxy, dis[now.F].F);
            else
                cmax(mxp, dis[now.F].F);
        }
        else if (now.S == 'Y')
            cmax(mxY, dis[now.F].F);
        else if (now.S == 'P')
            cmax(mxP, dis[now.F].F);
    }

    pii lca;

    for (int i = 1; i <= n; i++) {
        for (int e: G[i]) if (dis[i].S != dis[e].S) {
            lca = {i, e};
            goto nxt;
        }
    }

    nxt:
    // cout << mxY << ' ' << mxP << endl;

    // for (int i = 1; i <= n; i++)
    //     cout << to_lca[i] << ' ';

    if (mxy > max(mxp, dis[lca.F].F + dis[lca.S].F - 1) || mxY > max(mxP, mxp)) {
        cout << "Little Y" << endl;
        return;
    }
    else if (mxY > mxP && dis[lca.F].F + dis[lca.S].F - 1 > mxp) {
        cout << "Little Y" << endl;
    }
    else {
        cout << "Little P" << endl;
    }

    // cout << (mxy > mxp ? "Little Y" : "Little P") << endl;
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