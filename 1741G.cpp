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
#define MAXN 10005
#define MAXK 10
int n, m, f, k;
int h[MAXN], p[MAXN], dis[MAXN];
vector<int> G[MAXN], homeof[MAXN];
set<int> choise[MAXN];
bitset<MAXN> hascar;
bool dp[MAXN][100];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        G[i].clear();
        homeof[i].clear();
        choise[i].clear();
        hascar[i] = true;
        for (int mask = 1; mask < (1 << 6); mask++)
            dp[i][mask] = false;
        dp[i][0] = true;
    }
    dis[1] = 0;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    cin >> f;
    for (int i = 1; i <= f; i++) {
        cin >> h[i];
        homeof[h[i]].pb(i);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        hascar[p[i]] = false;
    }

    queue<int> q;
    q.push(1);
    while (q.size()) {
        int now = q.front();
        q.pop();

        set<int> tmp;
        for (int it: homeof[now]) {
            for (int it2: choise[it]) {
                tmp.insert(it2);
            }
            if (!hascar[it])
                tmp.insert(it);
        }

        for (int e: G[now]) {
            if (dis[e] > dis[now]) {
                dis[e] = dis[now] + 1;
                q.push(e);
            }


            for (int it: tmp) {
                for (int it2: homeof[e]) {
                    choise[it2].insert(it);
                }
            }
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