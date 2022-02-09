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
#define MAXN 4000005
#define MAXM 1000005 
int n, k, t;
int x[MAXN], pre[MAXN], dp[MAXN][2];

void sol()
{
	cin >> n >> k >> t;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		pre[i] = pre[i - 1] + x[i];		
	}
	
	deque<pii> q;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0];
		if (i > k)
			cmax(dp[i][0], dp[i - k - 1][1] + x[i]);
		else cmax(dp[i][0], x[i]);
		while(q.size() && q.front().F + pre[i] - pre[q.front().S] <= dp[i][0])
			q.pop_front();
		if (q.size() && q.back().S <= i - t)
			q.pop_back();
		q.push_front({dp[i][0], i});
		dp[i][1] = q.back().F + pre[i] - pre[q.back().S];
		// cout << i << " " << q.back().S << endl;
	}
	// for (int i = 1; i <= n; i++)
		// cout << dp[i][0] << " " << dp[i][1] << endl;
	cout << dp[n][1] << endl;
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