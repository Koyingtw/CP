// Problem: Maximum Building I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1147
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
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
#define MAXN 1005
#define MAXM 1000005 
int n, m;
int h[MAXN][MAXN], d[MAXN][MAXN], l[MAXN][MAXN];
char c[MAXN][MAXN];
pii up[MAXN][MAXN], down[MAXN][MAXN];

void sol()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		h[0][i] = c[0][i] == '.';
		d[n - 1][i] = c[n - 1][i] == '.';
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			h[i][j] = (c[i][j] == '.') * (h[i - 1][j]) + (c[i][j] == '.');
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = (c[i][j] == '.') * (d[i + 1][j]) + (c[i][j] == '.');
		}
	}
	
	for (int i = 0; i < n; i++) {
		stack<pii> stl, str;
		for (int j = 0; j < m; j++) {
			while (stl.size() && stl.top().F >= h[i][j]) {
				stl.pop();
			}
			if (stl.empty())
				up[i][j].F = 0;
			else 
				up[i][j].F = stl.top().S + 1;
			stl.push({h[i][j], j});
		}
		for (int j = m - 1; j >= 0; j--) {
			while (str.size() && str.top().F >= h[i][j]) {
				str.pop();
			}
			if (str.empty())
				up[i][j].S = m - 1;
			else 
				up[i][j].S = str.top().S - 1;
			str.push({h[i][j], j});
		}
	}
	
	for (int i = 0; i < n; i++) {
		stack<pii> stl, str;
		for (int j = 0; j < m; j++) {
			while (stl.size() && stl.top().F >= d[i][j]) {
				stl.pop();
			}
			if (stl.empty())
				down[i][j].F = 0;
			else 
				down[i][j].F = stl.top().S + 1;
			stl.push({d[i][j], j});
		}
		for (int j = m - 1; j >= 0; j--) {
			while (str.size() && str.top().F >= d[i][j]) {
				str.pop();
			}
			if (str.empty())
				down[i][j].S = m - 1;
			else 
				down[i][j].S = str.top().S - 1;
			str.push({d[i][j], j});
		}
	}
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cmax(ans, h[i][j] * (up[i][j].S - up[i][j].F + 1));
			cmax(ans, d[i][j] * (down[i][j].S - down[i][j].F + 1));
			
			cmax(ans, (h[i][j] + d[i][j] - 1) * (min(up[i][j].S, down[i][j].S) - max(up[i][j].F, down[i][j].F)) + 1);
			// cout << up[i][j].S << " ";
		}
		
		// cout << endl;
	}
	cout << ans << endl;
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