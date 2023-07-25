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
// #define endl "\n"
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, m, q;
string s[MAXN];
const int p[] = {1, 0, -1, 0, 1};
set<pii> vis;
map<pii, int> id;

void sol() {
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> pre;
    
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.' && !vis.count({i, j})) {
                pre.pb(vector<int>(n, 0));
                queue<pii> q;
                q.push({i, j});
                pre[num][i]++;
                vis.insert({i, j});
                id[{i, j}] = num;
                while (q.size()) {
                    pii now = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int xx = now.F + p[k], yy = now.S + p[k+1];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] == '#' || vis.count({xx, yy}))
                            continue;
                        q.push({xx, yy});
                        pre[num][xx]++;
                        vis.insert({xx, yy});
                        id[{xx, yy}] = num;
                    }
                }
                for (int k = 1; k < n; k++)
                    pre[num][k] += pre[num][k-1];
                num++;
            }
        }
    }

    cin >> q;
    while (q--) {
        int x, y, k;
        cin >> x >> y >> k;
        if (s[x][y] == '#') {
            cout << 0 << endl;
            continue;
        }
        num = id[{x, y}];
        if (x - k < 0) {
            cout << pre[num][n - 1] << endl;
        }
        else {
            cout << pre[num][n - 1] - pre[num][x - k] << endl;
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