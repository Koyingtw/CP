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
#define MAXN 205
#define MAXM 1000005 
int n, l;
int dp[MAXN], dp2[MAXN];
pii x[MAXN];

void sol()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> x[i].F;
	}
	for (int i = 0; i < n; i++) {
		cin >> x[i].S;
	}
	sort(x, x + n);
	int ans = 0;
	for (int i = 0; i < n; i++)	{
		int cnt = 0;
		vector<int> time(n);
		for (int j = 0; j < n; j++) {
			if (j <= i)
				time[j] = x[j].F;
			else 
				time[j] = l - x[j].F + x[i].F * 2;
		}
		for (int j = 0; j < n; j++)
			cnt += time[j] <= x[j].S;
		cmax(ans, cnt);
	}
	for (int i = n - 1; i >= 0; i--) {
		int cnt = 0;
		vector<int> time(n);
		for (int j = n - 1; j >= 0; j--) {
			if (j >= i)
				time[j] = l - x[j].F;
			else
				time[j] = x[j].F + 2 * (l - x[i].F);
		}
		for (int j = 0; j < n; j++)
			cnt += time[j] <= x[j].S;
		cmax(ans, cnt);
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