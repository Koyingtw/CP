#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 45
#define MAXM 1000005 
int n, m;
pii x[MAXN];
map<pii, array<int, 45>> mp;
pii tar;
int ans[MAXN];

void sol()
{
	cin >> n;
	cin >> tar.F >> tar.S;
	for (int i = 0; i < n; i++) {
		 cin >> x[i].F >> x[i].S;
	}
	int nn = n / 2;
	for (int i = 0; i < (1 << nn); i++) {
		int cnt = 0;
		pii now = {0, 0};
		for (int j = 0; j < nn; j++) {
			if (i & (1 << j)) {
				cnt++;
				now.F += x[j].F;
				now.S += x[j].S;
			}
		}
		mp[now][cnt]++;
	}
	for (int i = 0; i < (1 << (n - nn)); i++) {
		int cnt = 0;
		pii now = {0, 0};
		for (int j = nn; j < n; j++) {
			if (i & (1 << (j - nn))) {
				cnt++;
				now.F += x[j].F;
				now.S += x[j].S;
			}
		}
		pii mid = tar;
		mid.F -= now.F;
		mid.S -= now.S;
		for (int j = 0; j <= nn; j++)
			ans[cnt + j] += mp[mid][j];
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