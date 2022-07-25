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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
// #define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;

int dp[205][205];

void sol() {
	cin >> n;
	vector<int> v(1, 0);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		v.pb(1);
		sum += 1;
	}
	
	for (int i = 1; i < n; i++)
		cout << v[i] << " ";
	cout << v[n] << endl;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.pb(a);
		sum += a;
	}
	
	MEM(dp, 0);
	
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			for (int k = 0; k < j; k++) {
				if (dp[i - 1][k] + v[j] <= sum / 2)
					cmax(dp[i][j], dp[i - 1][k] + v[j]);
			}
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	pii pos;
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			if (dp[i][j] == sum / 2)
				pos = {i, j};
		}
	}
	vector<int> ans;
	for (int i = pos.F; i > 0; i--) {
		for (int j = 1; j <= 2 * n; j++) {
			if (dp[i - 1][j] + v[pos.S] == dp[i][pos.S]) {
				ans.pb(v[pos.S]);
				pos.S = j;
				break;
			}
		}
	}
	for (int it: ans)
		cout << it << " ";
	cout << endl;
}

signed main() {
    // Weakoying;
    int t = 1;
    cin >> t;
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}