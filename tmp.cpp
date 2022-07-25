#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 25
#define MAXM 1000005 
int n, m;
bitset<MAXN> b[MAXN];
string s[MAXN];

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++)
			b[i][j] = (s[i][j] == '+');
	}
	pii ans(0, 0);
	
	for (int mask = 1; mask < (1 << n); mask++) {
		int len = __builtin_popcount(mask);
		int cnt = INF;
		int pre[MAXN]{0};
		bitset<MAXN> tmp;
		tmp.set();
		
		for (int j = 0; j < n; j++) {
			if (mask & (1 << j)) {
				tmp &= b[j];
				pre[j + 1] = pre[j] + 1;
			}
			else {
				pre[j + 1] = pre[j];
			}
		}
		
		for (int i = len; i <= n; i++)
			cmin(cnt, len - (pre[i] - pre[i - len]));
		
		if (tmp.count() < len)
			continue;
			
			

		
		// pre[0] = tmp[0];
		
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + tmp[i - 1];
		
		for (int i = len; i <= n; i++) {
			cmax(ans, make_pair(len, -(cnt + len - (pre[i] - pre[i - len]))));
		}
		
		// int concnt = 0;
		// for (int l = 0, r = 0; l < n; l++) {
			// while (concnt < len && r < n) {
				// concnt += tmp[r];
				// r++;
			// }
// 			
// 			
			// if (concnt == len) {
				// // cout << l << " " << r << endl;
			// }
			// concnt -= tmp[l];
		// }
		
		
		// if (len >= 4)
			// cout << mask << " " << (cnt + len - mxcon) << endl;
	}
	cout << ans.F << "," << -ans.S << endl;
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