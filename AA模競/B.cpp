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
#define MAXN 500
#define MAXM 1000005 
int n, l, k;
int dp[255][505][255];// where, height, health
pii x[MAXN];

void sol()
{
	cin >> n >> k >> l;
	MEM(dp, -31);
	for (int i = 0; i < n; i++) {
		cin >> x[i].F >> x[i].S;
	}
	if (n != k) {
		cout << INF << endl;
		return; 
	}
	
	int ans = 0;
	for (int j = 0; j <= 500; j++) {
		if (j > x[0].S) {
			dp[0][j][l - 1] = j;
		}
		else {
			dp[0][j][l] = j;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 500; j++) {
			if (j > x[i].S) {
				for (int h = 0; h < l; h++) {
					cmax(dp[i][j][h], dp[i - 1][j][h + 1] + j);
					cmax(dp[i][j][h], dp[i - 1][j - (j > 0)][h + 1] + j);
					cmax(dp[i][j][h], dp[i - 1][j + (j < 500)][h + 1] + j);
				}
			}
			else {
				for (int h = 0; h <= l; h++) {
					cmax(dp[i][j][h], dp[i - 1][j][h] + j);
					cmax(dp[i][j][h], dp[i - 1][j + (j < 500)][h] + j);
					cmax(dp[i][j][h], dp[i - 1][j - (j > 0)][h] + j);
				}
			}
		}
	}
	for (int j = 0; j <= 500; j++)
		for (int h = 0; h <= l; h++)
			cmax(ans, dp[n - 1][j][h]);
	cout << ans << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}