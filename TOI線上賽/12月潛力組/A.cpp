#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 205
#define MAXM 100005 
int n, m, t, q;
int dp[MAXN][MAXN], p[5] = {1, 0, -1, 0, 1};
char x[MAXN][MAXN];
vector<tuple<int, int, int>> v[MAXN][MAXN];
bitset<MAXN> vis[MAXN];

struct trap {
	int h, w, s, e, a;
}y[MAXM];

bool check(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m);
}

void dfs(int i, int j) {
	vis[i][j] = 1;
	
	for (int k = 0; k < 4; k++) {
		if (check(i + p[k], j + p[k + 1]) && !vis[i + p[k]][j + p[k + 1]] && x[i + p[k]][j + p[k + 1]] != '#') {
			dfs(i + p[k], j + p[k + 1]);
		}
	}
}


void sol()
{
	cin >> n >> m >> t >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x[i][j];
		}
	}
	
	
	for (int i = 0; i < q; i++) {
		cin >> y[i].h >> y[i].w >> y[i].s >> y[i].e >> y[i].a;
		v[y[i].h][y[i].w].eb(y[i].s, y[i].e, y[i].a);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(all(v[i][j]));
		}
	}
	
	if (t == n + m - 2) {
		MEM(dp, 63);
		dp[0][0] = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!(i + j)) continue;
				if (x[i][j] == '#') continue;
				int step = i + j;
				int tmp = 0;
				for (int k = 0; k < v[i][j].size(); k++) {
					if (get<0>(v[i][j][k]) <= step && step <= get<1>(v[i][j][k])) {
						tmp = get<2>(v[i][j][k]);
						break;
					}
				}
				if (i > 0) {
					cmin(dp[i][j], dp[i - 1][j] + tmp);
				}
				if (j > 0) {
					cmin(dp[i][j], dp[i][j - 1] + tmp);
				}
			}
		}
		if (dp[n - 1][m - 1] != INF)
			cout << dp[n - 1][m - 1] << endl;
		else cout << -1 << endl;
	}
	
	else if (q == 0) {
		MEM(dp, 63);
		dp[0][0] = 0;
		dfs(0, 0);
		
		if (vis[n - 1][m - 1]) 
			cout << 0 << endl;
		else cout << -1 << endl;
	}
	
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}