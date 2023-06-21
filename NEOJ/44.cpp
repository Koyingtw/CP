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
#define MAXN 105
#define MAXM 1000005 
int n, m;
int dis[MAXN][MAXN];
char c[MAXN][MAXN];
const int p[] = {0, 1, 0, -1, 0};

void sol() {
    cin >> n >> m;
    pii cat;
    MEM(dis, INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'K')
                cat = {i, j};
        }
    }

    queue<pii> q;
    q.push(cat);
    dis[cat.F][cat.S] = 0;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        if (c[now.F][now.S] == '@') {
            cout << dis[now.F][now.S] << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int x = now.F + p[i];
            int y = now.S + p[i + 1];
            if (x < 0 || x >= n || y < 0 || y >= m || c[x][y] == '#')
                continue;
            if (dis[x][y] > dis[now.F][now.S] + 1) {
                dis[x][y] = dis[now.F][now.S] + 1;
                q.push({x, y});
            }
        }
    }

    cout << "= =\"" << endl;
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