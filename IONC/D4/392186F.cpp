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
#define MAXN 1005
#define MAXM 1000005 
int n, m;
string s[MAXN];
bitset<MAXN> vis[MAXN];

const int p[] = {1, 0, -1, 0, 1};

int bfs(int i, int j) {
    int res = 0;
    queue<pii> q;
    q.push({i, j});
    vis[i][j] = true;

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        // cout << x << " " << y << " " << q.size() << endl;

        for (int k = 0; k < 4; k++) {
            int ii = x + p[k];
            int jj = y + p[k + 1];

            if (!(ii && jj && ii <= n && jj <= m)) {
                res++;
                continue;
            }

            if (s[ii][jj] == '.')
                res++;
            else if (!vis[ii][jj]) {
                vis[ii][jj] = true;
                q.push({ii, jj});
            }
        }
    }

    return res;
}

void sol() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string tmp;
        s[i] = ".";
        cin >> tmp;
        s[i] += tmp;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#' && !vis[i][j]) {
                int tmp = bfs(i, j);
                cmax(ans, tmp);
            }
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