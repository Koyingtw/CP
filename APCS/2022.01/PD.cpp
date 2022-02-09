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
#define MAXM 5005 
int n, m;
int x[MAXN];
int y[MAXM];

void sol()
{
	cin >> n >> m;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		mx = max(mx, x[i]);
	}
	for (int i = 0; i < m; i++)
		cin >> y[i];
	int l = 0, r = mx, mid = (l + r + 1) / 2;
	while (l < r) {
		mid = (l + r + 1) / 2;
		int now = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (x[i] >= mid)
				cnt++;
			else
				cnt = 0;
			if (now < m && cnt >= y[now]) {
				cnt -= y[now];
				now++;
			}
		}
		if (now == m)
			l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
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