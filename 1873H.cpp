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
vector<int> G[MAXN];
bitset<MAXN> vis, vis1, vis2;
int deg[MAXN];
int dis1[MAXN], dis2[MAXN], dep[MAXN];
vector<int> cir;
stack<int> stk;
bool findcir = false;
bitset<MAXN> incir;

void dfs(int i, int fa) {
    // cout << i << endl;
    if (!findcir)
        stk.push(i);
    vis[i] = true;

    for (auto e: G[i]) if (e != fa) {
        if (vis[e]) {
            // cout << i << endl;
            while (stk.size()) {
                int tmp = stk.top();
                stk.pop();
                cir.pb(tmp);
                incir[tmp] = true;
                if (tmp == e)
                    break;
            }
            findcir = true;
        }
        else
            dfs(e, i);
    }

    // vis[i] = false;
    if (!findcir && stk.size())
        stk.pop();
}

int point;
int x, y;

void dfs2(int i, int fa) {
    vis2[i] = true;
    if (incir[i]) {
        point = i;
        return;
    }
    for (auto e: G[i]) if (!vis2[e]) {
        dep[e] = dep[i] + 1;
        dfs(e, i);
    }
}

void sol() {
    cin >> n >> x >> y;
    cir.clear();
    for (int i = 1; i <= n; i++) 
        G[i].clear(), vis[i] = vis1[i] = vis2[i] = dis1[i] = dis2[i] = deg[i] = dep[i] = findcir = incir[i] = point = 0;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(1, 1);

    queue<int> q;


    if (x == y)
        cout << "NO" << endl;
    else if (incir[y]) {
        cout << "YES" << endl;
    }
    else {
        dfs2(y, y);
        q.push(point);
        vis1[point] = true;
        while (q.size()) {
            int now = q.front();
            q.pop();

            for (auto e: G[now]) if (!vis1[e]) {
                vis1[e] = true;
                q.push(e);
                dis2[e] = dis2[now] + 1;
            }
        }

        if (dis2[y] < dis2[x]) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    for (auto it: cir)
        cout << it << ' ';
    cout << endl;
    
    // cout << (can ? "YES" : "NO") << endl;
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