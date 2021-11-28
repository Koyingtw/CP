// Problem: E - Peddler
// Contest: AtCoder - AtCoder Beginner Contest 188
// URL: https://atcoder.jp/contests/abc188/tasks/abc188_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
#pragma optimize("O3")
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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
#define MAXM 200005 
int n, m;
vector<int> G[MAXN];
int in[MAXN];
int x[MAXN], dp[MAXN];
void sol()
{
	cin >> n >> m;
	MEM(dp, 63);
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 0, a, b; i < n; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		in[b]++;
	}
	queue<int> q;
	int ans = -INF;
	for(int i = 1; i <= n; i++)
		if(!in[i]) q.push(i);
	while(q.size())
	{
		int now = q.front();
		q.pop();
		cmax(ans, x[now] - dp[now]);
		cmin(dp[now], x[now]);
		in[now] = INF;
		for(int e: G[now])
		{
			in[e]--;
			if(!in[e])
			{
				cmin(dp[e], dp[now]);
				q.push(e);
				in[e] = INF;
			}
		}
	}
	put(ans);
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