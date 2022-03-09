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
#define MAXN 505
#define MAXM 1000005 
int n, m;
int v[MAXN][MAXN];
int x[MAXN][MAXN];
int w[MAXN];
int ans[MAXN];

void sol1() {
	// for (int i = 1; i <= n; i++) {
		// ans[i] = i;
		// for (int j = 0; j < n; j++) {
			// cin >> x[i][j];
			// v[i][x[i][j]] = j;
		// }
	// }
	// do {
		// bool yes = 1;
		// for (int i = 1; i <= n; i++)
			// yes &= v[ans[i]]
	// } while (next_permutation(ans + 1, ans + n + 1));
}


void sol()
{
	cin >> n;
	// sol1();
	// break;
	for (int i = 1; i <= n; i++) {
		ans[i] = i;
		w[i] = i;
		for (int j = 0, a; j < n; j++) {
			cin >> x[i][j];
			v[i][x[i][j]] = j;
		}
	}	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			for (int k = 1; k <= n; k++) {
				if (k == i) continue;
				if (v[j][i] <= v[j][j] && v[k][j] <= v[k][k] && v[i][k] <= v[i][i]) {
					if (v[i][k] <= v[i][ans[i]])
						ans[i] = k;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
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