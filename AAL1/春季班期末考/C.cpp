// Problem: C. 數字配對遊戲
// Contest: Codeforces - 2021 AA 競程 Level 1 春季期末考
// URL: https://codeforces.com/gym/331434/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
#pragma optimize("O3")
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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN], y[MAXN];
void sol()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < m; i++) cin >> y[i];
	sort(x, x + n);
	sort(y, y + m);
	int l1 = 0, l2 = 0, r1 = n - 1, r2 = m - 1;
	int ans = 0;
	while(l1 <= r1 && l2 <= r2)
	{
		int mx = 0;
		cmax(mx, x[l1] * y[l2]);
		cmax(mx, x[l1] * y[r2]);
		cmax(mx, x[r1] * y[l2]);
		cmax(mx, x[r1] * y[r2]);
		if(mx < 0) break;
		ans += mx;
		if(mx == x[l1] * y[l2])
			l1++, l2++;
		else if(mx == x[l1] * y[r2])
			l1++, r2--;
		else if(mx == x[r1] * y[l2])
			r1--, l2++;
		else r1--, r2--;
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