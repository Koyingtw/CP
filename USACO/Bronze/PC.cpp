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
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int x[MAXN];

void sol()
{
	cin >> n;
	for (int i = 0; i < n; i++)	
		cin >> x[i];
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	if (x[0] > x[1] || x[n - 1] > x[n - 2]) {
		cout << -1 << endl;
		return;
	}
	int ans = 0;
	bool yes = 1;
	for (int i = 1; i < n; i++) {
		if (x[i] > x[i - 1]) {
			ans += (x[i] - x[i - 1]) * 2;
			int tmp = x[i] - x[i - 1];
			x[i] -= tmp;
			x[i + 1] -= tmp;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (x[i] > x[i + 1]) {
			ans += (x[i] - x[i + 1]) * 2;
			int tmp = x[i] - x[i + 1];
			x[i] -= tmp;
			x[i - 1] -= tmp;
		}
	}
	if (x[0] < 0) {
		cout << -1 << endl;
		return;
	}
	for (int i = 1; i < n; i++) {
		if (x[i] != x[i - 1] || x[i] < 0) {
			cout << -1 << endl;
			return;
		}
	}
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