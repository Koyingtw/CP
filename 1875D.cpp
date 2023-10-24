#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 5005
#define MAXM 1000005 
int n, m;
int x[MAXN];
vector<pii> G[MAXN];
int dis[MAXN];

void dijkstra(int st) {
    for (int i = 0; i <= st; i++)
        dis[i] = INFLL;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[st] = 0;
    pq.push({0, st});

    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (dis[now.S] != now.F)
            continue;

        for (auto e: G[now.S]) {
            if (dis[e.F] > now.F + e.S) {
                dis[e.F] = now.F + e.S;
                pq.push(pii(dis[e.F], e.F));
            }
        }
    }
}

map<int, int> mp;

void sol() {
    cin >> n;
    mp.clear();
    int ans = INFLL;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        mp[x[i]]++;
    }

    int MEX;
    for (int i = 0; i <= n; i++) if (!mp.count(i)) {
        MEX = i;
        break;
    }

    // cout << MEX << endl;
    for (int i = 0; i <= MEX; i++)
        G[i].clear();

    for (int i = 1; i <= MEX; i++) {
        for (int j = 0; j < i; j++) {
            G[i].pb({j, i * (mp[j])});
            // cout << i << ' ' << j << ' ' << i * (mp[j] - 1) << endl;
        }
    }

    dijkstra(MEX);
    cout << dis[0] - MEX << endl;
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