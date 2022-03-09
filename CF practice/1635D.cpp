// Problem: D. Infinite Set
// Contest: Codeforces - Codeforces Round #772 (Div. 2)
// URL: https://codeforces.com/contest/1635/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int dp[2][MAXN];
int ouo[2][MAXN];
int x[MAXN];

void sol()
{
	cin >> n >> m;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		x[i] = a;
		dp[a % 2][__lg(a)]++;
	}
	sort(x, x + n);
	int ans = dp[0][0] + dp[1][0];
	int awa = 0;
	for (int i = 1; i < n; i++) {
		int tmp = x[i];
		if (tmp & 1) {
			tmp >>= 1;
		}
		else if ((!(tmp & 1)) && (!(tmp & 2)) && tmp >= 4) {
			tmp >>= 2;
		}
		else continue;
		while (tmp != 0) {
			if (binary_search(x, x + i, tmp)) {
				ouo[x[i] % 2][__lg(x[i])]++;
			}
			if (tmp & 1) {
				tmp >>= 1;
			}
			else if ((!(tmp & 1)) && (!(tmp & 2)) && tmp >= 4) {
				tmp >>= 2;
			}
			else break;			
		}
	}
	ans -= ouo[0][0] + ouo[1][0];
	for (int i = 1; i < m; i++) {
		dp[1][i] += dp[1][i - 1] + dp[0][i - 1];
		if (i > 1) {
			dp[0][i] += dp[0][i - 2] + dp[1][i - 2];
		}
		ouo[1][i] += ouo[1][i - 1] + ouo[0][i - 1];
		if (i > 1) {
			ouo[0][i] += ouo[0][i - 2] + ouo[1][i - 2];
		}
		dp[0][i] %= P;
		dp[1][i] %= P;
		ouo[0][i] %= P;
		ouo[1][i] %= P;
		ans += dp[0][i] + dp[1][i];
		ans -= ouo[0][i] + ouo[1][i];
		ans = ((ans % P) + P) % P;
	}
	cout << ans << endl;
}

// 1011111001111011 111011100110101100101000000000

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